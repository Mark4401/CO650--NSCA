#ifndef WINSOCK2_EXAMPLE_H
#define WINSOCK2_EXAMPLE_H

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


class WinSock_2_Demo
{

public:

	WinSock_2_Demo();     
	~WinSock_2_Demo();    

	int FindWinsock2();
    int addServerSocket();
    int BindServerSocket();

private:
    SOCKET ServerSocket, AcceptSocket;
    int port;
    WSADATA wasDATA;
    int waserr;
    WORD wVersionRequested;
    sockaddr_in service;

};

#endif // !WINSOCK2_EXAMPLE_H
