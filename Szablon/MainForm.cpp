#include "MainForm.h"
#include <msclr/marshal_cppstd.h>
namespace Szablon {
	MainForm::MainForm(void) {
		InitializeComponent();
	}
	void MainForm::start_Click(System::Object^ sender, System::EventArgs^ e){
		std::string name = msclr::interop::marshal_as<std::string>(this->nazwa_gracza->Text);
		if (name.empty()) {
			System::String^ message = "Najpierw, wpisz nazwê urzytkownika!";
			MessageBox::Show(message, "Informacje", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		HangmanLogic* game = new HangmanLogic();
		game->setPlayerName(name);

		GameForm^ okno = gcnew GameForm(game);
		okno->initName();
		okno->initGame();
		okno->Show();
		this->Hide();
	}
	void MainForm::clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
		this->nazwa_gracza->Text = "Jakub Jakubik";
	}
	void MainForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
		this->Close();
	}
	void MainForm::aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
		System::String^ message = "test";
		MessageBox::Show(message, "Informacje", MessageBoxButtons::OK, MessageBoxIcon::Information);
		//AboutForm^ aboutForm = gcnew AboutForm();
		//aboutForm->Show();
	}
}
