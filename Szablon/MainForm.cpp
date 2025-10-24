#include "MainForm.h"
#include <msclr/marshal_cppstd.h>
namespace Szablon {
	MainForm::MainForm(void) {
		InitializeComponent();
	}
	void MainForm::start_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::string name = msclr::interop::marshal_as<std::string>(this->nazwa_gracza->Text);
		User* user = new User(name);
		Szablon::GameForm^ okno = gcnew Szablon::GameForm(user);
		okno->Show();
		this->Hide();
	}
}
