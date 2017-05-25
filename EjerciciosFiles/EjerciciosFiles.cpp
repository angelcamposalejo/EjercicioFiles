#include "stdafx.h"  //________________________________________ EjerciciosFiles.cpp
#include "EjerciciosFiles.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	EjerciciosFiles app;
	return app.BeginDialog(IDI_EjerciciosFiles, hInstance);
}

void EjerciciosFiles::Window_Open(Win::Event& e)
{

}

void EjerciciosFiles::btOpen_Click(Win::Event& e)
{
	Win::FileDlg dlg;
	dlg.SetFilter(L"Text Documents (*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0", 0, L"txt");
	if (dlg.BeginDialog(hWnd, L"Open a text file", false) == true)
	{
		this->Text = dlg.GetFileNameFullPath();
	}
}

void EjerciciosFiles::btSave_Click(Win::Event& e)
{
	Win::FileDlg dlg;
	dlg.SetFilter(L"Unicode Text (*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0", 0, L"txt");
	if (dlg.BeginDialog(hWnd, L"Save unicode text", true) == true)
	{
		Sys::File file;
		if (file.CreateForWritting(dlg.GetFileNameFullPath()) == false)
		{
			Sys::DisplayLastError(hWnd, L"Save");
			return;
		}
		wstring texto;
		for (int i = 1000; i <= 1010; i++)
		{
			Sys::Format(texto, L"%d\r\n", i);
			file.WriteText(texto);
		}
	}
}

