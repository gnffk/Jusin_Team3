#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CCollisionMgr.h"
#include "CObjMgr.h"
#include "CScrollMgr.h"
#include "CKeyMgr.h"
#include "CBmpMgr.h"
#include "CSceneMgr.h"

CMainGame::CMainGame()
	: m_iFPS(0), m_dwTime(GetTickCount())
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);
	


	CSceneMgr::Get_Instance()->Scene_Change(SC_MENU);
}

void CMainGame::Update()
{		
	CSceneMgr::Get_Instance()->Update();

}

void CMainGame::Late_Update()
{	
	CKeyMgr::Get_Instance()->Update();
	CSceneMgr::Get_Instance()->Late_Update();
	CScrollMgr::Get_Instance()->Scroll_Lock();
}

void CMainGame::Render()
{
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		m_iFPS = 0;

		SetWindowText(g_hWnd, m_szFPS);

		m_dwTime = GetTickCount();
	}

	HDC		hBackDC = CBmpMgr::Get_Instance()->Find_Image(L"Back");

	CSceneMgr::Get_Instance()->Render(hBackDC);

	BitBlt(m_hDC,				// 복사 받을 DC
		0,	// 복사 받을 공간의 LEFT	
		0,	// 복사 받을 공간의 TOP
		WINCX,			// 복사 받을 공간의 가로 
		WINCY,			// 복사 받을 공간의 세로 
		hBackDC,				// 복사 할 DC
		0,					// 복사할 이미지의 LEFT, TOP
		0,
		SRCCOPY);			// 그대로 복사

}

void CMainGame::Release()
{
	CBmpMgr::Destroy_Instacne();
	CKeyMgr::Destroy_Instacne();
	CScrollMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instacne();
	CObjMgr::Destroy_Instacne();

	ReleaseDC(g_hWnd, m_hDC);
}
