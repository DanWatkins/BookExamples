// Created 2015.03.01 by Daniel L. Watkins

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

using tsize = unsigned short;

void print(const string &message, tsize what)
{
	std::cout << message << "\t\t: " << bitset<sizeof(tsize)*8>(what) << endl;
}

tsize insertBits(tsize what, tsize source, tsize i, tsize j)
{
	int left = (~0) << (j+1);
	int right = (1 << i)-1;

	int mask = left | right;

	int cleared = source & mask;
	int shifted = what << i;

	return cleared | shifted;
}


tsize main()
{
	print("Result", insertBits(2, 202, 3, 6));
}