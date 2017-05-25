#pragma once  //______________________________________ EjerciciosFiles.h  
#include "Resource.h"
class EjerciciosFiles: public Win::Dialog
{
public:
	EjerciciosFiles()
	{
	}
	~EjerciciosFiles()
	{
	}
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Button btOpen;
	Win::Button bt2;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(383);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(77);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"EjerciciosFiles";
		btOpen.Create(NULL, L"Open", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 269, 8, 107, 28, hWnd, 1000);
		bt2.Create(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 269, 47, 107, 23, hWnd, 1001);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		btOpen.Font = fontArial014A;
		bt2.Font = fontArial014A;
	}
	//_________________________________________________
	void btOpen_Click(Win::Event& e);
	void bt2_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btOpen.IsEvent(e, BN_CLICKED)) {btOpen_Click(e); return true;}
		if (bt2.IsEvent(e, BN_CLICKED)) {bt2_Click(e); return true;}
		return false;
	}
};
