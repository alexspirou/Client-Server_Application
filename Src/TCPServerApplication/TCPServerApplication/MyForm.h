
#pragma once
#include "CSocket.h"
CSocket cs;

void init()
{
	cs.init();
	

}

namespace TCPServerApplication
{
	
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
		int timer = 0;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			System::Threading::Thread^ oThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(&init));
			oThread->Start();
		}

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
			cs.clear();
		}
	private: System::Windows::Forms::RichTextBox^ msgPanelShow;
	private: System::Windows::Forms::RichTextBox^ msgSendBox;
	private: System::Windows::Forms::Button^ buttonSend;


	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxName;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ buttonUpdateInfo;
	private: System::Windows::Forms::Label^ labelShowName;

	private: System::ComponentModel::IContainer^ components;
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->buttonUpdateInfo = (gcnew System::Windows::Forms::Button());
			this->labelShowName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// msgPanelShow
			// 
			this->msgPanelShow->BackColor = System::Drawing::Color::White;
			this->msgPanelShow->Location = System::Drawing::Point(12, 3);
			this->msgPanelShow->Name = L"msgPanelShow";
			this->msgPanelShow->ReadOnly = true;
			this->msgPanelShow->Size = System::Drawing::Size(557, 442);
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
			this->buttonSend->Click += gcnew System::EventHandler(this, &MyForm::buttonSend_Click);
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(575, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Enter Your Name";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(575, 45);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(110, 22);
			this->textBoxName->TabIndex = 6;
			// 
			// buttonUpdateInfo
			// 
			this->buttonUpdateInfo->Location = System::Drawing::Point(575, 73);
			this->buttonUpdateInfo->Name = L"buttonUpdateInfo";
			this->buttonUpdateInfo->Size = System::Drawing::Size(110, 26);
			this->buttonUpdateInfo->TabIndex = 8;
			this->buttonUpdateInfo->Text = L"Update";
			this->buttonUpdateInfo->UseVisualStyleBackColor = true;
			this->buttonUpdateInfo->Click += gcnew System::EventHandler(this, &MyForm::buttonUpdateInfo_Click);
			// 
			// labelShowName
			// 
			this->labelShowName->AutoSize = true;
			this->labelShowName->Location = System::Drawing::Point(578, 118);
			this->labelShowName->Name = L"labelShowName";
			this->labelShowName->Size = System::Drawing::Size(0, 17);
			this->labelShowName->TabIndex = 9;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(697, 556);
			this->Controls->Add(this->labelShowName);
			this->Controls->Add(this->buttonUpdateInfo);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonSend);
			this->Controls->Add(this->msgSendBox);
			this->Controls->Add(this->msgPanelShow);
			this->Name = L"MyForm";
			this->Text = L"Server";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonSend_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		
		System::String^ s = msgSendBox->Text;
		cs.sendData(s);
		msgPanelShow->Text = msgPanelShow->Text + "\nMe : " + s + "\n";
		msgSendBox->Text = "";

	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonInit_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		timer++;
		if (timer == 2)
		{
			if (!backgroundWorker1->IsBusy)
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
			msgPanelShow->Text = msgPanelShow->Text  + msg;
			backgroundWorker1->CancelAsync();
		}
	}
private: System::Void buttonUpdateInfo_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		cs.setName(textBoxName->Text);
		labelShowName->Text ="Name : " + textBoxName->Text;
		textBoxName->Text = "";
	}
};
}
