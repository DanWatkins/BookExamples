// Created 2015.03.16 by Daniel L. Watkins

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string normalizedDecimalToBinary(double value)
{
	if (value >= 1.0 || value <= 0.0)
		return "ERROR";

	const int maxPlaces = 32;
	string buffer;
	buffer.reserve(maxPlaces);
	buffer.append(".");

	double track = value;

	while (track > 0.0)
	{
		if (buffer.size() > maxPlaces)
			return "ERROR";

		track *= 2.0;

		if (track >= 1.0)
		{
			buffer.append("1");
			track -= 1.0;
		}
		else
		{
			buffer.append("0");
		}
	}

	return buffer;
}

int main()
{
	cout << normalizedDecimalToBinary(0.125) << endl;

	return 0;
}