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

private:

	SOCKET m_TCPClientSocket;
	int    m_iWsaStartup;
	std::string m_ClientName{ "Alex" };
	int m_test;



};
