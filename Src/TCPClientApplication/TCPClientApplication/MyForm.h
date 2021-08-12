#pragma once
#include "CSocket.h"

CSocket soc;
void init(){ soc.init(); } //Function for thread

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
		int timer = 0;
		bool isConnect = false;
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


	private: System::Windows::Forms::Label^ labelForIP;
	private: System::Windows::Forms::Button^ buttonClearMessages;

	private: System::Windows::Forms::TextBox^ textBoxIP;



	public:
	public:
		

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
	private: System::Windows::Forms::Button^ buttonConnect;

	private: System::Windows::Forms::Button^ buttonDisconnect;


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
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->buttonDisconnect = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonUpdateClientsInfo = (gcnew System::Windows::Forms::Button());
			this->labelForIP = (gcnew System::Windows::Forms::Label());
			this->textBoxIP = (gcnew System::Windows::Forms::TextBox());
			this->buttonClearMessages = (gcnew System::Windows::Forms::Button());
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
			this->msgSendBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::msgSendBox_KeyDown);
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
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(572, 181);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->buttonConnect->Size = System::Drawing::Size(117, 26);
			this->buttonConnect->TabIndex = 3;
			this->buttonConnect->Text = L"Connect";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &MyForm::buttonConnect_Click);
			// 
			// buttonDisconnect
			// 
			this->buttonDisconnect->Location = System::Drawing::Point(572, 213);
			this->buttonDisconnect->Name = L"buttonDisconnect";
			this->buttonDisconnect->Size = System::Drawing::Size(117, 26);
			this->buttonDisconnect->TabIndex = 5;
			this->buttonDisconnect->Text = L"Disconnect";
			this->buttonDisconnect->UseVisualStyleBackColor = true;
			this->buttonDisconnect->Click += gcnew System::EventHandler(this, &MyForm::buttonDisconnect_Click);
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
			this->NameTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::NameTextBox_KeyDown);
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
			this->textBoxIP->Text = L"127.0.0.1";
			// 
			// buttonClearMessages
			// 
			this->buttonClearMessages->Location = System::Drawing::Point(572, 245);
			this->buttonClearMessages->Name = L"buttonClearMessages";
			this->buttonClearMessages->Size = System::Drawing::Size(117, 26);
			this->buttonClearMessages->TabIndex = 13;
			this->buttonClearMessages->Text = L"Clear Messages";
			this->buttonClearMessages->UseVisualStyleBackColor = true;
			this->buttonClearMessages->Click += gcnew System::EventHandler(this, &MyForm::buttonClearMessages_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(697, 556);
			this->Controls->Add(this->buttonClearMessages);
			this->Controls->Add(this->textBoxIP);
			this->Controls->Add(this->labelForIP);
			this->Controls->Add(this->buttonUpdateClientsInfo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NameTextBox);
			this->Controls->Add(this->buttonDisconnect);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->buttonSend);
			this->Controls->Add(this->msgSendBox);
			this->Controls->Add(this->msgPanelShow);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"Client";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void buttonSendClick(System::Object^ sender, System::EventArgs^ e)
	{
		if (!msgPanelShow->Text->Empty && isConnect)
		{
			System::String^ s = msgSendBox->Text;
			soc.sendData(s);
			msgPanelShow->Text = msgPanelShow->Text + "\nMe : " + s;

			msgSendBox->Text = "";
		}
		if (!isConnect)
		{
			MessageBox::Show("There Is No Connection With Server", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
	}
	private: System::Void buttonConnect_Click(System::Object^ sender, System::EventArgs^ e)
	{
		soc.setIP(textBoxIP->Text);
		textBoxIP->ReadOnly = true;
		System::Threading::Thread^ oThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(&init));
		oThread->Start();
		oThread->EndThreadAffinity();
		System::String^ s = "***INIT MESSAGE FROM CLIENT***";
		soc.sendData(s);
		buttonConnect->Enabled = false;
	}
	private: System::Void buttonDisconnect_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		soc.clean();
		buttonConnect->Enabled = true;
		textBoxIP->ReadOnly = false;

	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{

		if(!backgroundWorker1->IsBusy)
			backgroundWorker1->RunWorkerAsync();		
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) 
	{



		int receivedData;
		System::String^ msg = soc.receiveData(receivedData);
		if (receivedData <= 0)
		{
			isConnect = false;

		}
		else
		{
			isConnect = true;
			msgPanelShow->Text += msg;
			System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();
			player->SoundLocation = "Sounds\\messageSound.wav";
			player->Load();
			player->PlaySync();
			backgroundWorker1->CancelAsync();
		}
	}

	private: System::Void buttonUpdateClientsInfo_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		soc.setName(NameTextBox->Text);
		NameTextBox->Enabled = false;


	}



	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
		{
			

		}
	private: System::Void NameTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{


		if (e->KeyCode == Keys::Enter && !e->Shift && e->KeyCode == Keys::Enter)
		{

			if (NameTextBox->Text != "")
			{
				soc.setName(NameTextBox->Text);
				NameTextBox->Enabled = false;
			}
			
			if (NameTextBox->Text->Length == 0)
			{
				//System::Media::SystemSounds^  player = gcnew System::Media::SystemSounds();
				//player->Beep->Play();
				MessageBox::Show("The User Name Must Be Less Than 10 Characters", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}



		}
	}
	private: System::Void msgSendBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode == Keys::Enter && !e->Shift && e->KeyCode == Keys::Enter )
			{
				if (msgSendBox->Text!= "" && isConnect)
				{
					msgSendBox->ReadOnly = true;
					System::String^ s = msgSendBox->Text;
					soc.sendData(s);
					msgPanelShow->Text = msgPanelShow->Text + "\nMe : " + s;
					msgSendBox->Text = "";
				}
				if (!isConnect)
				{
					MessageBox::Show("There Is No Connection With Server", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

				}
			}
			else
			{

				msgSendBox->ReadOnly = false;
			}

		}


	private: System::Void buttonClearMessages_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		msgPanelShow->Text = "";
	}

};
}
