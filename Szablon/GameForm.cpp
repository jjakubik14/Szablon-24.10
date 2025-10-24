#include "GameForm.h"

namespace Szablon {
	GameForm::GameForm(User* user) {
		InitializeComponent();
		this->user = user;

		this->initName();
	}
	User* GameForm::getUser() {
		return this->user;
	}
	void GameForm::initName() {
		this->kto_gra_okno->Text = gcnew System::String(this->user->getName().c_str());
	}

}