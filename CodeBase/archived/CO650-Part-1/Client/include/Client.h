#ifndef CLIENT_H
#define CLIENT_H

#include<iostream>
#include<string>

// Winsock Library tools 
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

//#include <stdio.h> not needed for now Since we are using C++ not C.

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

string name = "Dave";

#endif // !CLIENT_H
