// Created 2015.03.30 by Daniel L. Watkins

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

using Integer = unsigned short;

void print(const string &message, Integer what)
{
	std::cout << message << "\t\t: " << bitset<sizeof(Integer)*8>(what) << endl;
}


int numberOfOnes(Integer value)
{
	int count = 0;
	Integer test = 1;

	for (int i=0; i<sizeof(Integer)*8; i++)
	{
		if (value & test)
			count++;

		test *= 2;
	}

	return count;
}


inline Integer searchForSameNumberOfOnes(Integer what, int direction)
{
	Integer test = what;
	const int whatOneCount = numberOfOnes(what);

	while (numberOfOnes(test += direction) != whatOneCount);

	return test;
}


Integer above(Integer what)
{
	return searchForSameNumberOfOnes(what, 1);
}


Integer below(Integer what)
{
	return searchForSameNumberOfOnes(what, -1);
}


int main()
{
	print("Above", above(bitset<sizeof(Integer)*8>("1000").to_ulong()));
	print("Above", below(bitset<sizeof(Integer)*8>("1000").to_ulong()));
}