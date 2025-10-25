#pragma once
#include "HangmanLogic.h"

namespace Szablon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;	
	/// <summary>
	/// Podsumowanie informacji o GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(HangmanLogic* game);

		void initGame();
		void initName();

		HangmanLogic* getGame();
	private:
		HangmanLogic* game;
		void charGuess(System::Windows::Forms::Keys v);
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ user_lives;
	private: System::Windows::Forms::Label^ kto_gra_okno;
	private: void nowa_gra_Click(System::Object^ sender, System::EventArgs^ e);
	private: void podpowiedz__Click(System::Object^ sender, System::EventArgs^ e);
	private: void GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
		   
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ zgadywane_slowo_;
	private: System::Windows::Forms::PictureBox^ zdjecie_bledy;
	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ podpowiedz_;
	protected:


	private: System::Windows::Forms::Button^ nowa_gra;



	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->podpowiedz_ = (gcnew System::Windows::Forms::Button());
			this->nowa_gra = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->zgadywane_slowo_ = (gcnew System::Windows::Forms::TextBox());
			this->zdjecie_bledy = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->kto_gra_okno = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->user_lives = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zdjecie_bledy))->BeginInit();
			this->SuspendLayout();
			// 
			// podpowiedz_
			// 
			this->podpowiedz_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->podpowiedz_->Location = System::Drawing::Point(12, 426);
			this->podpowiedz_->Name = L"podpowiedz_";
			this->podpowiedz_->Size = System::Drawing::Size(136, 48);
			this->podpowiedz_->TabIndex = 0;
			this->podpowiedz_->Text = L"PODPOWIED";
			this->podpowiedz_->UseVisualStyleBackColor = true;
			this->podpowiedz_->Click += gcnew System::EventHandler(this, &GameForm::podpowiedz__Click);
			// 
			// nowa_gra
			// 
			this->nowa_gra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->nowa_gra->Location = System::Drawing::Point(12, 489);
			this->nowa_gra->Name = L"nowa_gra";
			this->nowa_gra->Size = System::Drawing::Size(136, 48);
			this->nowa_gra->TabIndex = 3;
			this->nowa_gra->Text = L"NOWA GRA";
			this->nowa_gra->UseVisualStyleBackColor = true;
			this->nowa_gra->Click += gcnew System::EventHandler(this, &GameForm::nowa_gra_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->zgadywane_slowo_);
			this->panel1->Controls->Add(this->zdjecie_bledy);
			this->panel1->Location = System::Drawing::Point(283, 44);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(450, 460);
			this->panel1->TabIndex = 8;
			// 
			// zgadywane_slowo_
			// 
			this->zgadywane_slowo_->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zgadywane_slowo_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->zgadywane_slowo_->Location = System::Drawing::Point(0, 0);
			this->zgadywane_slowo_->Name = L"zgadywane_slowo_";
			this->zgadywane_slowo_->ReadOnly = true;
			this->zgadywane_slowo_->Size = System::Drawing::Size(450, 35);
			this->zgadywane_slowo_->TabIndex = 9;
			// 
			// zdjecie_bledy
			// 
			this->zdjecie_bledy->BackColor = System::Drawing::Color::Transparent;
			this->zdjecie_bledy->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->zdjecie_bledy->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zdjecie_bledy->Location = System::Drawing::Point(0, 0);
			this->zdjecie_bledy->Name = L"zdjecie_bledy";
			this->zdjecie_bledy->Size = System::Drawing::Size(450, 460);
			this->zdjecie_bledy->TabIndex = 8;
			this->zdjecie_bledy->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(12, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 20);
			this->label1->TabIndex = 9;
			this->label1->Text = L"GRA";
			// 
			// kto_gra_okno
			// 
			this->kto_gra_okno->AutoSize = true;
			this->kto_gra_okno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->kto_gra_okno->Location = System::Drawing::Point(80, 21);
			this->kto_gra_okno->Name = L"kto_gra_okno";
			this->kto_gra_okno->Size = System::Drawing::Size(89, 20);
			this->kto_gra_okno->TabIndex = 10;
			this->kto_gra_okno->Text = L"user_name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(12, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 20);
			this->label2->TabIndex = 11;
			this->label2->Text = L"¯YCIA";
			// 
			// user_lives
			// 
			this->user_lives->AutoSize = true;
			this->user_lives->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->user_lives->Location = System::Drawing::Point(80, 41);
			this->user_lives->Name = L"user_lives";
			this->user_lives->Size = System::Drawing::Size(79, 20);
			this->user_lives->TabIndex = 12;
			this->user_lives->Text = L"user_lives";
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->user_lives);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->kto_gra_okno);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->nowa_gra);
			this->Controls->Add(this->podpowiedz_);
			this->KeyPreview = true;
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zdjecie_bledy))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
