#include "CSocket.h"
#include <string>

using namespace std;
void CSocket::init()
{
	WSADATA WinSocketdata;
	int	iWsaStartup;
	int	iWasCleanup;

	struct sockaddr_in TCPServerAdd;
	struct sockaddr_in TCPClientAdd;
	int iTCPClientAdd = sizeof(TCPClientAdd);
	int iBind;

	int iListen;

	//Start Up Function
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSocketdata);
	if (iWsaStartup != 0)
	{
	}

	//Fill the struct
	TCPServerAdd.sin_family = AF_INET;
	TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
	TCPServerAdd.sin_port = htons(8000);

	//Step 3 Socket Creation
	m_TCPServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_TCPServerSocket == INVALID_SOCKET)
	{
	}

	//Step 4 bind fun
	iBind = bind(m_TCPServerSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));

	if (iBind == SOCKET_ERROR)
	{

	}
	//Step 5 Listen function

	iListen = listen(m_TCPServerSocket, 2);
	if (iListen == SOCKET_ERROR)
	{

	}
	////Step 6 Accept
	m_sAcceptSocket = accept(m_TCPServerSocket, (SOCKADDR*)&TCPClientAdd, &iTCPClientAdd);
	if (m_sAcceptSocket == INVALID_SOCKET)
	{
		
	}

	//Send data

	int iSend{};
	char SenderBuffer[512] = "***geia sou re malaka, ti kaneis re arxidi***";
	int iSenderBuffer = sizeof(SenderBuffer) + 1;

	iSend = send(m_sAcceptSocket, SenderBuffer, iSenderBuffer, 0);

	if (iSend == SOCKET_ERROR)
	{

	}


	

}

void CSocket::sendData(System::String^ s_msg)
{

	////Send
	int iSend{};
	char SenderBuffer[512];
	int iSenderBuffer = sizeof(SenderBuffer) + 1;
	std::string msg = msclr::interop::marshal_as<std::string>(s_msg);
	
	//std::cout << "You : ";

	memset(SenderBuffer, 0, sizeof SenderBuffer);
	for (int i = 0; i < msg.size(); i++)
		SenderBuffer[i] = msg[i];

	iSend = send(m_sAcceptSocket, SenderBuffer, iSenderBuffer, 0);

	if (iSend == SOCKET_ERROR)
	{
		//cout << "Send  FAILED ERROR NO - >" << WSAGetLastError() << std::endl;

	}


}


System::String^ CSocket::receiveData(int& rcv)
{
	 
	//Recieve
	int iRecieve;
	char ReceiveBuffer[5000];
	int iReceiveBuffer = sizeof(ReceiveBuffer) + 1;
	iRecieve = recv(m_sAcceptSocket, ReceiveBuffer, iReceiveBuffer, 0);
	if (iRecieve == SOCKET_ERROR)
	{
		//cout << "Receive data  FAILED ERROR NO - >" << WSAGetLastError() << std::endl;
		System::String^ receivedMsg = gcnew System::String("SOCKET ERROR");
		rcv = iRecieve;
		return receivedMsg;
		
	}
	rcv = iRecieve;
	System::String^ receivedMsg = gcnew System::String(ReceiveBuffer);
	return receivedMsg;

}

void CSocket::clear()
{

	//Close Socket
	int iWsaCleanup;
	int iCloseSocket;
	iCloseSocket = closesocket(m_TCPServerSocket);
	if (iCloseSocket == SOCKET_ERROR)
	{
		//cout << "Closing Socket FAILED ERROR NO - >" << WSAGetLastError() << std::endl;

	}
	//cout << "Closing Socket Success\n";


	//Clean up
	iWsaCleanup = WSACleanup();
	if (iWsaCleanup == SOCKET_ERROR)
	{
		//cout << "Cleanup FAILED ERROR NO - >" << WSAGetLastError() << std::endl;

	}
	//cout << "Cleanup Socket Success\n";
}