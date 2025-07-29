#include"Client.h"

int main(int argc, char* argv[])
{
	cout << "\n" << name;

    SOCKET clientSocket, AcceptSocket;
    int port;
    WSADATA wasDATA;
    int waserr;
    WORD wVersionRequested;
    sockaddr_in service;

    port = 55555;
    wVersionRequested = MAKEWORD(2, 2);
    waserr = WSAStartup(wVersionRequested, &wasDATA);

	if (waserr != 0)
	{
		cout << "\nThe Winsock dll not found or Failed to load.\n";
		return 0;
	}

	else
	{
		cout << "\n\nWinsock found!\n";
		cout << "Status: " << wasDATA.szSystemStatus << " ~ Success!\n\n";
	}

	cout << "Step:2 Setup client socket!\n";

	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (clientSocket == INVALID_SOCKET)
	{
		cout << "Error at Socket() " << WSAGetLastError() << "\n";
		WSACleanup();
		return 0;
	}
	else
	{
		cout << "\nSocket() Added Correctly!\n\n";
	}

	cout << "Step:3 Connect to server!\n";

	sockaddr_in clientService;
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, L"127.0.0.1", &clientService.sin_addr.S_un);
	clientService.sin_port = htons(port);

	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
	{
		cout << "Client: connection failed! " << WSAGetLastError() << "\n";
		WSACleanup();
		return 0;
	}
	else
	{
		cout << "\nClient: Connection Successful!\n";
		cout << "\nClient can now send and revise data...\n";
	}

	system("Pause");
	WSACleanup();
	return 0;

	return 0;
}
