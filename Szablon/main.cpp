#include "MainForm.h"
using namespace Szablon;
[STAThreadAttribute]
int main(cli::array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm());
	return 0;
}
