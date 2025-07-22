# Introduction - Winsock & Network Fundamentals

## 
- Sockets were initially developed for Unix systems.
- Winsock is Windows implementation of sockets.
- Window Sockets API (`WSA`)
- ws2_32.dll location - (C:\WINDOWS\System32)
- Winsock 2 extends Winsock 1.1 support for several protocols.


## Network Protocol Stack

![OSI 7 Layers](../Materials/Pictures/OSI-7-layperStack.png)

### Architecture 

- The connection is always between two devices, and each side uses its own IP and port number. usually:
	- **Client:** The Sender & requester of server data.
	- **Server:** The Provider & processor of data.

For the **Server's** job consists of the following:
	- Primary: Listing - for incoming request from client applications. with their IP/port number.
	- Secondary: Process & Store Client data.

time - 9.44