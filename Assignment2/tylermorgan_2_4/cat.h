#include <iostream>
#include <cstring>
#include <string>

char *cat(char *string_one, char *string_two)
{
	
	int total_len = strlen(string_one) + strlen(string_two);
	char *final_string = new char[total_len];
	total_len = 0;
	for(int x = 0;x<strlen(string_one);x++)
	{
		final_string[total_len] = string_one[x];
		total_len++;
	}
	for(int x = 0;x<strlen(string_two);x++)
	{
		final_string[total_len] = string_two[x];
		total_len++;
	}
	
	return final_string;
}


std::string cat_string(std::string string_one, std::string string_two)
{
	std::string final_string;
	final_string = string_one + string_two;
	return final_string;

}