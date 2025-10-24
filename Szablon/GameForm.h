#pragma once
#include "HangmanLogic.h"
#include "User.h"

namespace Szablon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static HangmanLogic gra;   // Wspólny egzemplarz dla obu guzikow

	
	/// <summary>
	/// Podsumowanie informacji o GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(User* user);

		User* getUser();

	public:
		//zdjecie_bledy->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
	private:
		User* user;

		void initName();
	
	private: System::Windows::Forms::TextBox^ kto_gra;
	private: System::Windows::Forms::TextBox^ kto_gra_okno;


	private: System::Windows::Forms::PictureBox^ zdjecie_bledy;
	private: System::Windows::Forms::TextBox^ liczba_zyc;
	public:
	//public:	int count_hint;
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
	private: System::Windows::Forms::Button^ zgadnij_;
	private: System::Windows::Forms::TextBox^ zgadywane_slowo_;
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
			this->zgadnij_ = (gcnew System::Windows::Forms::Button());
			this->zgadywane_slowo_ = (gcnew System::Windows::Forms::TextBox());
			this->nowa_gra = (gcnew System::Windows::Forms::Button());
			this->liczba_zyc = (gcnew System::Windows::Forms::TextBox());
			this->kto_gra = (gcnew System::Windows::Forms::TextBox());
			this->kto_gra_okno = (gcnew System::Windows::Forms::TextBox());
			this->zdjecie_bledy = (gcnew System::Windows::Forms::PictureBox());
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
			// zgadnij_
			// 
			this->zgadnij_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->zgadnij_->Location = System::Drawing::Point(12, 364);
			this->zgadnij_->Name = L"zgadnij_";
			this->zgadnij_->Size = System::Drawing::Size(136, 48);
			this->zgadnij_->TabIndex = 1;
			this->zgadnij_->Text = L"ZGADNIJ";
			this->zgadnij_->UseVisualStyleBackColor = true;
			this->zgadnij_->Click += gcnew System::EventHandler(this, &GameForm::zgadnij__Click);
			// 
			// zgadywane_slowo_
			// 
			this->zgadywane_slowo_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->zgadywane_slowo_->Location = System::Drawing::Point(217, 91);
			this->zgadywane_slowo_->Name = L"zgadywane_slowo_";
			this->zgadywane_slowo_->ReadOnly = true;
			this->zgadywane_slowo_->Size = System::Drawing::Size(321, 35);
			this->zgadywane_slowo_->TabIndex = 2;
			this->zgadywane_slowo_->TextChanged += gcnew System::EventHandler(this, &GameForm::zgadywane_slowo__TextChanged);
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
			// liczba_zyc
			// 
			this->liczba_zyc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->liczba_zyc->Location = System::Drawing::Point(12, 316);
			this->liczba_zyc->Name = L"liczba_zyc";
			this->liczba_zyc->ReadOnly = true;
			this->liczba_zyc->Size = System::Drawing::Size(136, 29);
			this->liczba_zyc->TabIndex = 4;
			// 
			// kto_gra
			// 
			this->kto_gra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->kto_gra->Location = System::Drawing::Point(12, 12);
			this->kto_gra->Name = L"kto_gra";
			this->kto_gra->ReadOnly = true;
			this->kto_gra->Size = System::Drawing::Size(58, 29);
			this->kto_gra->TabIndex = 5;
			this->kto_gra->Text = L"GRA:";
	
			// 
			// kto_gra_okno
			// 
			this->kto_gra_okno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->kto_gra_okno->Location = System::Drawing::Point(12, 47);
			this->kto_gra_okno->Name = L"kto_gra_okno";
			this->kto_gra_okno->ReadOnly = true;
			this->kto_gra_okno->Size = System::Drawing::Size(121, 31);
			this->kto_gra_okno->TabIndex = 6;
	
			// 
			// zdjecie_bledy
			// 
			this->zdjecie_bledy->BackColor = System::Drawing::SystemColors::Window;
			this->zdjecie_bledy->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->zdjecie_bledy->Location = System::Drawing::Point(316, 149);
			this->zdjecie_bledy->Name = L"zdjecie_bledy";
			this->zdjecie_bledy->Size = System::Drawing::Size(400, 400);
			this->zdjecie_bledy->TabIndex = 7;
			this->zdjecie_bledy->TabStop = false;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->zdjecie_bledy);
			this->Controls->Add(this->kto_gra_okno);
			this->Controls->Add(this->kto_gra);
			this->Controls->Add(this->liczba_zyc);
			this->Controls->Add(this->nowa_gra);
			this->Controls->Add(this->zgadywane_slowo_);
			this->Controls->Add(this->zgadnij_);
			this->Controls->Add(this->podpowiedz_);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zdjecie_bledy))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void zgadnij__Click(System::Object^ sender, System::EventArgs^ e) {
		// Tworzymy ma³e okno dialogowe (Form) do wpisania litery
		System::Windows::Forms::Form^ dlg = gcnew System::Windows::Forms::Form(); // nowy formularz
		dlg->Text = L"Wpisz literê";                                              // tytu³ okna
		dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent; // wyœrodkowanie wzglêdem okna g³ównego
		dlg->ClientSize = System::Drawing::Size(220, 90);                         // rozmiar okna w pikselach

		// Etykieta z instrukcj¹
		System::Windows::Forms::Label^ lbl = gcnew System::Windows::Forms::Label(); // nowa etykieta
		lbl->Text = L"Litera (A–Z):";                                              // tekst etykiety
		lbl->AutoSize = true;                                                      // dopasuj rozmiar do tekstu
		lbl->Location = System::Drawing::Point(10, 10);                            // pozycja w oknie
		dlg->Controls->Add(lbl);                                                   // dodaj etykietê do okna

		// Pole tekstowe na jedn¹ literê
		System::Windows::Forms::TextBox^ tb = gcnew System::Windows::Forms::TextBox(); // nowe pole tekstowe
		tb->Location = System::Drawing::Point(10, 35);                                // pozycja pola
		tb->Width = 120;                                                              // szerokoœæ pola
		tb->MaxLength = 1;                                                            // pozwól wpisaæ tylko 1 znak
		dlg->Controls->Add(tb);                                                       // dodaj pole do okna

		// Przycisk OK
		System::Windows::Forms::Button^ ok = gcnew System::Windows::Forms::Button();  // nowy przycisk
		ok->Text = L"OK";                                                             // napis na przycisku
		ok->DialogResult = System::Windows::Forms::DialogResult::OK;                  // naciœniêcie = zatwierdŸ
		ok->Location = System::Drawing::Point(140, 33);                               // pozycja przycisku
		dlg->AcceptButton = ok;                                                       // Enter = OK
		dlg->Controls->Add(ok);                                                       // dodaj przycisk do okna

		// Poka¿ okno i sprawdŸ, czy u¿ytkownik zatwierdzi³ (OK)
		if (dlg->ShowDialog(this) != System::Windows::Forms::DialogResult::OK) return; // anulowano -> wyjdŸ
		if (System::String::IsNullOrWhiteSpace(tb->Text)) return;                      // nic nie wpisano -> wyjdŸ

		// Pobierz pierwszy znak i upewnij siê, ¿e to litera
		wchar_t wc = tb->Text[0];                                                      // pierwszy znak z pola
		if (!System::Char::IsLetter(wc)) {                                             // jeœli to nie litera...
			System::Windows::Forms::MessageBox::Show(L"To nie jest litera.");          // komunikat o b³êdzie
			return;                                                                     // wyjdŸ z funkcji
		}

		// Zamieñ na wielk¹ literê i na zwyk³y 'char' (A..Z) dla logiki C++
		wchar_t up = System::Char::ToUpper(wc);                                        // wielka litera
		char lit = (char)up;                                                            // rzutowanie na char (ASCII)

		// Zgadywanie litery w logice gry
		bool traf = gra.Zgadnij(lit);                                                  // true = trafione, false = pud³o

		// Odœwie¿ maskê s³owa w TextBoxie (np. "K _ O M P _ T E R")
		this->zgadywane_slowo_->Text = gcnew System::String(gra.PobierzMaskowane().c_str());

		// === DODAJ TE 2 LINIE: poka¿ aktualn¹ liczbê ¿yæ ===
		this->liczba_zyc->Text = System::String::Format(L"Liczba ¿yæ: {0}", gra.PobierzZycia());

		this->liczba_zyc->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// ====================================================


		// Gdy pud³o – poka¿ komunikat
		if (!traf) {
			System::Windows::Forms::MessageBox::Show(L"B³¹d – tej litery nie ma.");
		}

		// SprawdŸ, czy gra siê skoñczy³a (wygrana/przegrana) i poka¿ has³o
		if (gra.CzyWygrana()) {
			System::Windows::Forms::MessageBox::Show(L"Wygrana! Has³o: " + gcnew System::String(gra.PobierzHaslo().c_str()));
		}
		else if (gra.CzyPrzegrana()) {
			System::Windows::Forms::MessageBox::Show(L"Przegrana. Has³o: " + gcnew System::String(gra.PobierzHaslo().c_str()));
		bool traf = gra.Zgadnij(lit);
		}
		gra.z = gra.PobierzZycia();
		System::String^ file =
			(gra.z >= 3) ? "wisielec_1.png" :
			(gra.z == 2) ? "wisielec_2.png" :
			(gra.z == 1) ? "wisielec_3.png" :
			(gra.z == 0) ? "wisielec_4.png" :
			"png\\wisielec_4.png"; // fallback (np. <0)

			zdjecie_bledy->BackgroundImage = System::Drawing::Image::FromFile(file);
	}
	private: System::Void podpowiedz__Click(System::Object^ sender, System::EventArgs^ e) {
		// po dwoch uzyciach 
		if (gra.count_hint >= 2) { // jesli wykorzystano dwie pdopowidzi
			MessageBox::Show(L"Wykorzystano wszystkie podpowiedzi."); // pokazuje komunikat w oknie
			return;
		}

		
		char L = gra.Podpowiedz(); //odlania pierwsz¹ nieodkryta 
		this->zgadywane_slowo_->Text = gcnew System::String(gra.PobierzMaskowane().c_str()); 
		if (L == '\0') return;    // gdy nie ma co odslonic nie zwiekszaj licznika wyjdz

		gra.count_hint++;            // zlicza uzycie
	}

private: System::Void zgadywane_slowo__TextChanged(System::Object^ sender, System::EventArgs^ e) {	
}
private: System::Void nowa_gra_Click(System::Object^ sender, System::EventArgs^ e) {
	gra.NowaGra(4, 12, 4);                     // start nowej gry: losuj s³owo o d³ugoœci 4-12 ustawia 4 zyc czyscii maske i liczniki w logice
	gra.count_hint = 0;                         // zeruje licznik podpowiedzi
	//this->podpowiedz_->Enabled = true;      // odblokuj guzik

	this->zgadywane_slowo_->Text =
		gcnew System::String(gra.PobierzMaskowane().c_str()); // ustawia startowy widok w textboxie ____
	// poka¿ liczbê ¿yæ w textboxie
	this->liczba_zyc->Text = System::String::Format(L"Liczba ¿yæ: {0}", gra.PobierzZycia());
	this->liczba_zyc->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
	zdjecie_bledy->BackgroundImage = nullptr;

}
};
}
