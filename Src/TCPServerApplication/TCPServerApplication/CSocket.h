#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#pragma warning(disable:4996) 

#include "Ws2tcpip.h" 
#include <iostream>
#include <msclr\marshal_cppstd.h>

class CSocket
{
public:
	CSocket() { }
	~CSocket() {}
	void init();
	void sendData(System::String^ s_msg);
	System::String^ receiveData(int& rcv);
	void clear();
	void setName(System::String^ name) { m_serverName = systemStringToString(name); }
	std::string systemStringToString(System::String^ toString)
	{
		std::string nameToString = msclr::interop::marshal_as<std::string>(toString);
		return nameToString;
	}
	void setIP(System::String^ IP)
	{
		std::string stringIP = systemStringToString(IP);
		memset(m_ServerIP, 0, sizeof m_ServerIP);

		for (int i = 0; i < stringIP.size(); i++)
			m_ServerIP[i] = stringIP[i];
	}

private:
	SOCKET m_sAcceptSocket;
	SOCKET m_TCPServerSocket;
	std::string m_serverName{ "Server" };
	char m_ServerIP[200];

};

