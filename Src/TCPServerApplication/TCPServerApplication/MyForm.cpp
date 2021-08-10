#include "MyForm.h"
#include "CSocket.h"
using namespace System;
using namespace System::Windows::Forms;




void main(array < String^ >^ args) 
{
	//Running second thread to avoid block


	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	TCPServerApplication::MyForm frm;
	
	Application::Run(% frm);

	
}