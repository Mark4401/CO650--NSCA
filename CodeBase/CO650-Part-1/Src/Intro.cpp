#include"intro.h"
#include<iostream>
#include<string>
#include<format>

using namespace std;

int main()
{
	string IntroSuccessMSG = format(
		"\n"
		"This will just check if everything builds correctly!\n\n"
		"{}\n"
		"Build successfully! :)\n\n",
		IntroMSG
	);

	cout << IntroSuccessMSG;

	return 0;
}