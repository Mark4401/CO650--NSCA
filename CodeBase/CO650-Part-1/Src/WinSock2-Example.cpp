#include "WinSock2-Example.h"
#include<iostream>
#include<string>
#include <WS2tcpip.h>

using namespace std;

WinSock_2_Demo::WinSock_2_Demo()
{
	port = 55555;
	wVersionRequested = MAKEWORD(2, 2);
	waserr = WSAStartup(wVersionRequested, &wasDATA);
}

WinSock_2_Demo::~WinSock_2_Demo()
{
	WSACleanup();
}

int WinSock_2_Demo::FindWinsock2()
{	
	if (waserr != 0)
	{
		cout << "\nThe Winsock dll not found or Failed to load.\n";
		return 0;
	}

	else
	{
		cout << "Winsock found!\n";
		cout << "Status: " << wasDATA.szSystemStatus << " ~ Success!\n";
	}

	return 0;
}

int WinSock_2_Demo::addServerSocket()
{
	ServerSocket = INVALID_SOCKET;
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (ServerSocket == INVALID_SOCKET)
	{
		cout << "Error at Socket() " << WSAGetLastError() << "\n";
		WSACleanup();
		return 0;
	}
	else
	{
		cout << "\nSocket() Added Correctly!\n";
	}
}

int WinSock_2_Demo::BindServerSocket()
{
	service.sin_family = AF_INET;

	InetPton(AF_INET, L"127.0.0.1", &service.sin_addr);
	service.sin_port = htons(port);

	if ( bind(ServerSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR )
	{
		cout << "\nBind() failed: " << WSAGetLastError() << "\n";
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}
	else
	{
		cout << "\nBind() Successfully Added!\n";
	}
	//return 0;
}
