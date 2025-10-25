#include "GameForm.h"

namespace Szablon {
	GameForm::GameForm(HangmanLogic* game) {
		InitializeComponent();
		this->game = game;
	}
	void GameForm::initGame() {
		this->game->startNewGame(4, 12, 4);
		this->game->setHintUsed(0);

		this->zgadywane_slowo_->Text = gcnew System::String(this->game->getMasked().c_str());
		this->user_lives->Text = System::String::Format(L"{0}", this->game->getLives());
		this->zdjecie_bledy->BackgroundImage = nullptr;
	}
    void GameForm::podpowiedz__Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->game->getHintUsed() >= 2) {
			System::Windows::Forms::MessageBox::Show(L"Wykorzystano wszystkie podpowiedzi.");
			return;
		}
		char L = this->game->hint();
		this->zgadywane_slowo_->Text = gcnew System::String(this->game->getMasked().c_str());
		if (L == '\0') return;
		this->game->incrementHintUsed();
	}
	void GameForm::GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
		this->charGuess(e->KeyCode);
	}
    void GameForm::charGuess(System::Windows::Forms::Keys key) {
        if (key < System::Windows::Forms::Keys::A || key > System::Windows::Forms::Keys::Z) {
            System::Windows::Forms::MessageBox::Show(L"To nie jest litera A–Z.");
            return;
        }
        wchar_t wc = L'A' + static_cast<int>(key - System::Windows::Forms::Keys::A);
        char lit = static_cast<char>(wc);

        bool hit = this->game->guess(lit);

        this->zgadywane_slowo_->Text = gcnew System::String(this->game->getMasked().c_str());
        this->user_lives->Text = this->game->getLives().ToString();

        if (!hit) {
            System::Windows::Forms::MessageBox::Show(L"B³¹d – tej litery nie ma.");
        }
        if (this->game->isWin()) {
            System::Windows::Forms::MessageBox::Show(L"Wygrana! Has³o: " + gcnew System::String(this->game->getWord().c_str()));
        }
        else if (this->game->isLoss()) {
            System::Windows::Forms::MessageBox::Show(L"Przegrana. Has³o: " + gcnew System::String(this->game->getWord().c_str()));
        }
        int lives = this->game->getLives();
        if (lives >= 4) return;
        System::String^ file;
        switch (lives) {
            case 3: file = L"\\wisielec_1.png"; break;
            case 2: file = L"\\wisielec_2.png"; break;
            case 1: file = L"\\wisielec_3.png"; break;
            case 0: file = L"\\wisielec_4.png"; break;
            default: file = L"\\wisielec_4.png"; break;
        }

        auto oldImg = zdjecie_bledy->BackgroundImage;
        if (oldImg != nullptr) {
            zdjecie_bledy->BackgroundImage = nullptr;
            delete oldImg;
        }
        if (System::IO::File::Exists(file)) {
            zdjecie_bledy->BackgroundImage = System::Drawing::Image::FromFile(file);
        }
        else {
            System::Windows::Forms::MessageBox::Show(L"Brak pliku obrazka: " + file);
        }
        
    }

	void GameForm::initName() {
		this->kto_gra_okno->Text = gcnew System::String(this->game->getPlayerName().c_str());
	}
	HangmanLogic* GameForm::getGame() {
		return this->game;
	}

	void GameForm::nowa_gra_Click(System::Object^ sender, System::EventArgs^ e){
		this->initGame();
	}

}