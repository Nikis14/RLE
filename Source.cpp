#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iterator>
#include <conio.h>

using std::cout;
using std::endl;

//Write RLE form of str in dist
//str - string for transformation to RLE form
//dist - result of transformation
//return false if the exception was called
//otherwise return true
bool ToRLE(const char* str, char* &dist)
{
	char* res = dist; //point for recording
	while (*str)
	{
		//exception processing
		try
		{
			if (*str < 'A' || *str > 'Z')
				throw 1;
		}
		catch (int i)
		{
			cout << "Error " << " - input string contains stranger symbol\n";
			return false;
		}

		//main algorithm
		int cnt = 1; //count of repeated symbols
		char prev = *str;
		*res++ = *str++;
		while (prev == *str) //while symbols repeat
		{
			++cnt; //increase counter
			++str;
		}
		if (cnt != 1) //if 2 or more same letters were counted
		{
			//add following number to result
			std::stringstream ss;
			ss << cnt;
			for (const char &c : ss.str())
				*res++ = c;
		}

	}
	*res = '\0';
	return true;
}


int main()
{
	cout << "The programm transforms input string (contains only A-Z) to RLE form.\n\n";

	//examples
	cout << "Examples" << endl;
	cout << "================================================================================" << endl;
	char* test1 = "AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB";
	cout << "1) " << test1 << " -> ";
	char* res1 = new char[strlen(test1) + 1];
	if(ToRLE(test1, res1)) //if the exception wasn't called
		cout << res1 << endl;
	delete res1;

	char* test2 = "ABCDEFGH";
	cout << "2) " << test2 << " -> ";
	char* res2 = new char[strlen(test2) + 1];
	if(ToRLE(test2, res2)) //if the exception wasn't called
		cout << res2 << endl;
	delete res2;

	char* test3 = "aaaaaaaa";
	cout << "3) " << test3 << " -> ";
	char* res3 = new char[strlen(test3) + 1];
	if(ToRLE(test3, res3)) //if the exception wasn't called
		cout << res3 << endl;
	delete res3;
	cout << "================================================================================" << endl;

	//MAIN PROGRAM
	for (;;)
	{
		cout << endl << "Please, write string here: ";

		//reading and preprocessing
		std::string input_str;
		std::getline(std::cin, input_str);
		const char* input = input_str.c_str();

		//calling of the function and printing of results
		char* result = new char[strlen(input) + 1];
		if (ToRLE(input, result))
			cout << "Result: " << result << endl;
	}
	return 0;
}