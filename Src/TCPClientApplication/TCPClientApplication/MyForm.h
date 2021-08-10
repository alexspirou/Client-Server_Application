#pragma once
#include "CSocket.h"
CSocket cs;
int timer = 0;
void init()
{
	cs.init();


}



namespace TCPClientApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:

		MyForm(void)
		{

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::TextBox^ NameTextBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonUpdateClientsInfo;
	private: System::Windows::Forms::Label^ labelShowName;

	private: System::Windows::Forms::Label^ labelForIP;
	private: System::Windows::Forms::TextBox^ textBoxIP;



	public:
	public:
		int timer = 0;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ msgPanelShow;
	private: System::Windows::Forms::RichTextBox^ msgSendBox;
	private: System::Windows::Forms::Button^ buttonSend;
	private: System::Windows::Forms::Button^ buttonInit;

	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->msgPanelShow = (gcnew System::Windows::Forms::RichTextBox());
			this->msgSendBox = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonSend = (gcnew System::Windows::Forms::Button());
			this->buttonInit = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonUpdateClientsInfo = (gcnew System::Windows::Forms::Button());
			this->labelShowName = (gcnew System::Windows::Forms::Label());
			this->labelForIP = (gcnew System::Windows::Forms::Label());
			this->textBoxIP = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// msgPanelShow
			// 
			this->msgPanelShow->BackColor = System::Drawing::Color::White;
			this->msgPanelShow->Location = System::Drawing::Point(12, 2);
			this->msgPanelShow->Name = L"msgPanelShow";
			this->msgPanelShow->ReadOnly = true;
			this->msgPanelShow->Size = System::Drawing::Size(557, 443);
			this->msgPanelShow->TabIndex = 0;
			this->msgPanelShow->Text = L"";
			// 
			// msgSendBox
			// 
			this->msgSendBox->Location = System::Drawing::Point(12, 464);
			this->msgSendBox->Name = L"msgSendBox";
			this->msgSendBox->Size = System::Drawing::Size(557, 66);
			this->msgSendBox->TabIndex = 1;
			this->msgSendBox->Text = L"";
			// 
			// buttonSend
			// 
			this->buttonSend->Location = System::Drawing::Point(575, 464);
			this->buttonSend->Name = L"buttonSend";
			this->buttonSend->Size = System::Drawing::Size(110, 66);
			this->buttonSend->TabIndex = 2;
			this->buttonSend->Text = L"Send";
			this->buttonSend->UseVisualStyleBackColor = true;
			this->buttonSend->Click += gcnew System::EventHandler(this, &MyForm::buttonSendClick);
			// 
			// buttonInit
			// 
			this->buttonInit->Location = System::Drawing::Point(572, 181);
			this->buttonInit->Name = L"buttonInit";
			this->buttonInit->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->buttonInit->Size = System::Drawing::Size(117, 26);
			this->buttonInit->TabIndex = 3;
			this->buttonInit->Text = L"Init";
			this->buttonInit->UseVisualStyleBackColor = true;
			this->buttonInit->Click += gcnew System::EventHandler(this, &MyForm::buttonInit_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(572, 213);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(117, 26);
			this->buttonClear->TabIndex = 5;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MyForm::buttonClear_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// NameTextBox
			// 
			this->NameTextBox->Location = System::Drawing::Point(575, 45);
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->Size = System::Drawing::Size(117, 22);
			this->NameTextBox->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(575, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Enter Your Name";
			// 
			// buttonUpdateClientsInfo
			// 
			this->buttonUpdateClientsInfo->Location = System::Drawing::Point(575, 73);
			this->buttonUpdateClientsInfo->Name = L"buttonUpdateClientsInfo";
			this->buttonUpdateClientsInfo->Size = System::Drawing::Size(117, 26);
			this->buttonUpdateClientsInfo->TabIndex = 8;
			this->buttonUpdateClientsInfo->Text = L"Update";
			this->buttonUpdateClientsInfo->UseVisualStyleBackColor = true;
			this->buttonUpdateClientsInfo->Click += gcnew System::EventHandler(this, &MyForm::buttonUpdateClientsInfo_Click);
			// 
			// labelShowName
			// 
			this->labelShowName->AutoSize = true;
			this->labelShowName->Location = System::Drawing::Point(575, 98);
			this->labelShowName->Name = L"labelShowName";
			this->labelShowName->Size = System::Drawing::Size(0, 17);
			this->labelShowName->Text = "Name : ";
			this->labelShowName->TabIndex = 9;
			// 
			// labelForIP
			// 
			this->labelForIP->AutoSize = true;
			this->labelForIP->Location = System::Drawing::Point(572, 132);
			this->labelForIP->Name = L"labelForIP";
			this->labelForIP->Size = System::Drawing::Size(114, 17);
			this->labelForIP->TabIndex = 11;
			this->labelForIP->Text = L"Enter Server\'s IP";
			// 
			// textBoxIP
			// 
			this->textBoxIP->Location = System::Drawing::Point(572, 152);
			this->textBoxIP->Name = L"textBoxIP";
			this->textBoxIP->Size = System::Drawing::Size(117, 22);
			this->textBoxIP->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(697, 556);
			this->Controls->Add(this->textBoxIP);
			this->Controls->Add(this->labelForIP);
			this->Controls->Add(this->labelShowName);
			this->Controls->Add(this->buttonUpdateClientsInfo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NameTextBox);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonInit);
			this->Controls->Add(this->buttonSend);
			this->Controls->Add(this->msgSendBox);
			this->Controls->Add(this->msgPanelShow);
			this->Name = L"MyForm";
			this->Text = L"Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void buttonSendClick(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ s = msgSendBox->Text;
		cs.sendData(s);
		msgPanelShow->Text = msgPanelShow->Text + "\nMe : " + s + "\n";
		msgSendBox->Text = "";



	}
	private: System::Void buttonInit_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		cs.setIP(textBoxIP->Text);
		//textBoxIP->Text = "";
		textBoxIP->ReadOnly = true;
		System::Threading::Thread^ oThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(&init));
		oThread->Start();
		oThread->EndThreadAffinity();
		System::String^ s;
		//cs.receiveData(s);
		msgPanelShow->Text = s;
	}
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		cs.clean();
	}
	private: System::Void buttonRead_Click(System::Object^ sender, System::EventArgs^ e)
	{
		
		//System::String^ s;
		//if(cs.receiveData(s) <= 0) msgPanelShow->Text = "NOT RECEIVE DATA";
		//else { msgPanelShow->Text = msgPanelShow->Text + "\n" + "Server : " + s; }
		//
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{

		timer++;
		if (timer == 2)
		{
			if(!backgroundWorker1->IsBusy)
				backgroundWorker1->RunWorkerAsync();
			timer = 0;
		}
		
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) 
	{



		int receivedData;
		System::String^ msg = cs.receiveData(receivedData);
		if (receivedData <= 0)
		{

		}
		else
		{
			msgPanelShow->Text = msgPanelShow->Text + "Server : " + msg;
			backgroundWorker1->CancelAsync();
		}
	}

	private: System::Void buttonUpdateClientsInfo_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		cs.setName(NameTextBox->Text);
		labelShowName->Text += NameTextBox->Text;
		NameTextBox->Text = "";


	}
};
}
