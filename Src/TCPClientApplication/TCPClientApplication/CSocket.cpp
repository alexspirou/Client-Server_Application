
#include "CSocket.h"
#include <string>


using namespace std;
void CSocket::init()
{
/*    cout << "\t\t------ TCP CLIENT --------" << endl;
    cout << endl*/;

    WSADATA WinSockData;
    struct sockaddr_in TCPServerAdd;
    int  iConnect;

    //STEP-1 WSASatrtUp Fun
    m_iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSockData);
    if (m_iWsaStartup != 0)
    {
       // cout << "WSAStartUp Failed" << endl;
    }
    //cout << "WSAStartUp Success" << endl;
    // STEP-2 Socket Creation
    m_TCPClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_TCPClientSocket == INVALID_SOCKET)
    {
        //cout << "TCP Client Socket Creation Failed" << endl;
        //cout << "Error Code - " << WSAGetLastError() << endl;
    }
   // cout << "TCP Client Socket Creation Success" << endl;

    // STEP-3 Fill Server Structure
    TCPServerAdd.sin_family = AF_INET;
    TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
    TCPServerAdd.sin_port = htons(8000);

    // STEP-4 Connect Fun
    iConnect = connect(
        m_TCPClientSocket,
        (SOCKADDR*)&TCPServerAdd,
        sizeof(TCPServerAdd));
    if (iConnect == SOCKET_ERROR)
    {
        //cout << "Connection Failed " << endl;
        //cout << "Error No-> " << WSAGetLastError() << endl;
    }
    //cout << "Connection Success" << endl;

    // STEP-5 RECV Data From Server Side

}

int CSocket::sendData(System::String^& s_msg)
{
    // STEP-6 Send Data to Server
    char SenderBuffer[512];
    int iSenderBuffer = sizeof(SenderBuffer) + 1;
    int iSend{};

    std::string msg = msclr::interop::marshal_as<std::string>(s_msg);
    msg = m_ClientName + " : " + msg;
    memset(SenderBuffer, 0, sizeof SenderBuffer);

    for (int i = 0; i < msg.size(); i++)
        SenderBuffer[i] = msg[i];

    iSend = send(m_TCPClientSocket, SenderBuffer, iSenderBuffer, 0);

    if (iSend == SOCKET_ERROR)
    {
        //cout << "Sending Failed " << endl;
        //cout << "Error No-> " << WSAGetLastError() << endl;
    }

    return iSend;
}


System::String^ CSocket::receiveData(int& rcv)
{
    //Receive data

    int iRecv;
    char RecvBuffer[5000];
    int  iRecvBuffer = sizeof(RecvBuffer) + 1;
    iRecv = recv(m_TCPClientSocket, RecvBuffer, iRecvBuffer, 0);

    if (iRecv == SOCKET_ERROR)
    {
        //cout << "Receive Data Failed " << endl;
        //cout << "Error No-> " << WSAGetLastError() << endl;
    }
   // cout << "Server :  " << RecvBuffer << endl;
    System::String^ s_msg = gcnew System::String(RecvBuffer);

   
    rcv = iRecv;

    return s_msg;

}

void CSocket::clean()
{

    int iWsaCleanup;
    int iCloseSocket;

    //Close Socket Fun
    iCloseSocket = closesocket(m_TCPClientSocket);
    if (iCloseSocket == SOCKET_ERROR)
    {
        //cout << "Closing Socket Failed " << endl;
        //cout << "Error No-> " << WSAGetLastError() << endl;
    }
   //cout << "Closing Socket Success" << endl;

    // STEP-8 WSA CleanUp Fun;
    iWsaCleanup = WSACleanup();
    if (iWsaCleanup == SOCKET_ERROR)
    {
        cout << "CleanUp Fun Failed " << endl;
        cout << "Error No-> " << WSAGetLastError() << endl;
    }
    //cout << "CleanUp Fun Success" << endl;

}