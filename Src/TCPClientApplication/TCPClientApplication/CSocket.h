#pragma once
#include <WinSock2.h>
#include <iostream>
#include <msclr\marshal_cppstd.h>

class CSocket
{
public:
	CSocket() { }
	~CSocket() {}
	void init();
	int sendData(System::String^& s_msg);
	System::String^ receiveData(int& rcv);
	void clean();
	void setRevc(int r) { m_test = r;  }
	void setName(System::String^ name) { m_ClientName = systemStringToString(name); }
   
	std::string systemStringToString(System::String^ toString)
	{ 
		std::string nameToString = msclr::interop::marshal_as<std::string>(toString);
		return nameToString;
	}
	void setIP(System::String^ IP)
	{
		std::string stringIP = systemStringToString(IP);
		memset(m_ServerIP, 0, sizeof m_ServerIP);

		for(int i = 0; i < stringIP.size(); i++)
			m_ServerIP[i] = stringIP[i];
	}
private:

	SOCKET m_TCPClientSocket;
	int    m_iWsaStartup;
	std::string m_ClientName{ "Alex" };
	char m_ServerIP[200];

	int m_test;



};
