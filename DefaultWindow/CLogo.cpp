#include "pch.h"
#include "CLogo.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CBmpMgr.h"
#include "CObjMgr.h"

CLogo::CLogo()
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Logo.bmp", L"Logo");
}

CLogo::~CLogo()
{
}

void CLogo::Initialize()
{
	CObjMgr::Get_Instance()->Release();
}

int CLogo::Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_KJJ);
	}
	else if (CKeyMgr::Get_Instance()->Key_Down(VK_RBUTTON))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_MENU);
	}

    return 0;
}

void CLogo::Late_Update()
{
}

void CLogo::Render(HDC hDC)
{
	BitBlt(hDC,
		0, 0,
		800, 600,
		CBmpMgr::Get_Instance()->Find_Image(L"Logo"),
		0, 0,
		SRCCOPY);
}

void CLogo::Release()
{
}
