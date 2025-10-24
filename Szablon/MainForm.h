#pragma once
#include "GameForm.h"
#include "HangmanLogic.h"   // widac nowa gra i maskowanie

namespace Szablon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//static HangmanLogic gra; 

	/// <summary>
	/// Podsumowanie informacji o MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);
	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ start_;
	protected:

	private: System::Windows::Forms::TextBox^ nazwa_gracza;
	private: System::Windows::Forms::TextBox^ nad_nazwa_gracza;
	private: System::Windows::Forms::PictureBox^ nazwa_gry;

	private: void start_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->start_ = (gcnew System::Windows::Forms::Button());
			this->nazwa_gracza = (gcnew System::Windows::Forms::TextBox());
			this->nad_nazwa_gracza = (gcnew System::Windows::Forms::TextBox());
			this->nazwa_gry = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nazwa_gry))->BeginInit();
			this->SuspendLayout();
			// 
			// start_
			// 
			this->start_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->start_->Location = System::Drawing::Point(70, 412);
			this->start_->Name = L"start_";
			this->start_->Size = System::Drawing::Size(200, 75);
			this->start_->TabIndex = 0;
			this->start_->Text = L"START";
			this->start_->UseVisualStyleBackColor = true;
			this->start_->Click += gcnew System::EventHandler(this, &MainForm::start_Click);
			// 
			// nazwa_gracza
			// 
			this->nazwa_gracza->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->nazwa_gracza->Location = System::Drawing::Point(500, 456);
			this->nazwa_gracza->Name = L"nazwa_gracza";
			this->nazwa_gracza->Size = System::Drawing::Size(200, 31);
			this->nazwa_gracza->TabIndex = 1;
			this->nazwa_gracza->TextChanged += gcnew System::EventHandler(this, &MainForm::nazwa_gracza_TextChanged);
			// 
			// nad_nazwa_gracza
			// 
			this->nad_nazwa_gracza->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->nad_nazwa_gracza->Location = System::Drawing::Point(500, 419);
			this->nad_nazwa_gracza->Name = L"nad_nazwa_gracza";
			this->nad_nazwa_gracza->Size = System::Drawing::Size(200, 31);
			this->nad_nazwa_gracza->TabIndex = 2;
			this->nad_nazwa_gracza->Text = L"Nazwa Gracza:";
			// 
			// nazwa_gry
			// 
			this->nazwa_gry->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nazwa_gry.BackgroundImage")));
			this->nazwa_gry->Location = System::Drawing::Point(193, 12);
			this->nazwa_gry->Name = L"nazwa_gry";
			this->nazwa_gry->Size = System::Drawing::Size(400, 60);
			this->nazwa_gry->TabIndex = 3;
			this->nazwa_gry->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->nazwa_gry);
			this->Controls->Add(this->nad_nazwa_gracza);
			this->Controls->Add(this->nazwa_gracza);
			this->Controls->Add(this->start_);
			this->Name = L"MainForm";
			this->Text = L"Hangman";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nazwa_gry))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Load += gcnew System::EventHandler(this, &Szablon::MainForm::MainForm_Load);
	}
	private: System::Void nazwa_gracza_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	};
}

