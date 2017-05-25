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
	dlg.SetFilter(L"Excel Files(*.xlsx)\0*.xlsx\0All Files(*.*)\0*.*\0\0", 0, L"xlsx");
	if (dlg.BeginDialog(hWnd, L"Open a Microsoft Excel file", true) == true)
	{
		this->Text = dlg.GetFileNameFullPath();
	}
}

