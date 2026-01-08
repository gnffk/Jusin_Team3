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
	

	GetClientRect(g_hWnd, &_rect);

	_hdcBack = CreateCompatibleDC(m_hDC);
	_bmpBack = CreateCompatibleBitmap(m_hDC, _rect.right, _rect.bottom);
	HBITMAP prev = (HBITMAP)SelectObject(_hdcBack, _bmpBack);
	DeleteObject(prev);

	CSceneMgr::Get_Instance()->Scene_Change(SC_MINSU);
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

	
	Rectangle(_hdcBack, 0, 0, WINCX, WINCY);

	CSceneMgr::Get_Instance()->Render(_hdcBack);
	BitBlt(m_hDC, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);

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
