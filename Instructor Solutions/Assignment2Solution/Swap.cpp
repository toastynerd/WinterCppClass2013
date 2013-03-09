#include "Swap.h"

// see http://en.wikipedia.org/wiki/XOR_swap_algorithm for details of this swap algorithm

void swap(int* n1, int* n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

void swap(int& n1, int& n2)
{
    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
}