#include"intro.h"
#include"WinSock2-Example.h"
#include<iostream>
#include<string>
#include<format>

using namespace std;

int main(int argc, char* argv[])
{
	string IntroSuccessMSG = format(
		"\n"
		"This will just check if everything builds correctly!\n\n"
		"{}\n"
		"Build successfully! :)\n\n",
		IntroMSG
	);

	cout << IntroSuccessMSG;

	WinSock_2_Demo Demo;

	cout << "Step 1: Finding WinSock.\n\n";

	Demo.FindWinsock2();

	cout << "\nStep 2: Setup an Server Socket.\n";

	Demo.addServerSocket();

	cout << "\nStep 3: Bind IP/Port to Server Socket.\n";

	Demo.addServerSocket();

	return 0;
}