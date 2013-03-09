#include "Calculator.h"

#include <string>
#include <map>
#include <istream>
#include <sstream>
#include <iostream>

enum Token_value
{
    NAME,
    NUMBER,
    END,
    PLUS = '+',
    MINUS = '-',
    MUL = '*',
    DIV = '/',
    PRINT = ';',
    ASSIGN = '=',
    LP = '(',
    RP = ')'
};

Token_value curr_tok = PRINT;
double number_value;
std::string string_value;
std::map<std::string, double> table;
int no_of_errors;

double expr(bool get, std::istream& stream);

double error(const std::string& s)
{
    no_of_errors++;
    std::cerr << "error: " << s << std::endl;
    return 1;
}

Token_value get_token(std::istream& stream)
{
    char ch = 0;
    do
    {
        if (!stream.get(ch))
        {
            return curr_tok = END;
        }
    } while (ch != '\n' && isspace(ch));

    switch (ch)
    {
    case 0:
        return curr_tok=END;
    case ';':
    case '\n':
        return curr_tok=PRINT;
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
        return curr_tok=Token_value(ch);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
        stream.putback(ch);
        stream >> number_value;
        return curr_tok=NUMBER;
    default:
        if (::isalpha(ch))
        {
            string_value = ch;
            while (stream.get(ch) && ::isalnum(ch))
            {
                string_value.push_back(ch);
            }

            stream.putback(ch);
            return curr_tok=NAME;
        }
        error("bad token");
        return curr_tok=PRINT;
    }
}

double prim(bool get, std::istream& stream)
{
    if (get) get_token(stream);

    switch (curr_tok)
    {
    case NUMBER:
    {
        double v = number_value;
        get_token(stream);
        return v;
    }
    case NAME:
    {
        double& v = table[string_value];
        if (get_token(stream) == ASSIGN)
        {
            v = expr(true, stream);
        }

        return v;
    }
    case MINUS:    // unary minus
        return -prim(true, stream);
    case LP:
    {
        double e = expr(true, stream);
        if (curr_tok != RP)
        {
            return error(") expected");
        }

        get_token(stream);  // eat ')'
        return e;
    }
    default:
        return error("primary expected");
    }
}

double term(bool get, std::istream& stream)
{
    double left = prim(get, stream);

    for (;;)
    {
        switch (curr_tok)
        {
        case MUL:
            left *= prim(true, stream);
            break;
        case DIV:
            if (double d = prim(true, stream))
            {
                left /= d;
                break;
            }
            return error("divide by 0");
        default:
            return left;
        }
    }
}

double expr(bool get, std::istream& stream)
{
    double left = term(get, stream);

    for (;;)
    {
        switch (curr_tok)
        {
        case PLUS:
            left += term(true, stream);
            break;
        case MINUS:
            left -= term(true, stream);
            break;
        default:
            return left;
        }
    }
}

std::string Calculator(
    std::istream& stream)
{
    table["pi"] = 3.14159;
    table["e"] = 2.71828;

    std::stringstream results;

    bool firstTime = true;
    while (stream)
    {
        if (!firstTime)
        {
            results << std::endl;
        }
        else
        {
            firstTime = false;
        }

        get_token(stream);
        if (curr_tok == END) break;
        if (curr_tok == PRINT) continue;
        results << expr(false, stream);
    }

    return results.str();
}