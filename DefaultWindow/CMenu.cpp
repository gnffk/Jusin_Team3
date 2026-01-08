#include "pch.h"
#include "CMenu.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"

static RECT g_mouseRect = { 0,0, 10, 10 };
static RECT g_msRect = { 0,0, 100, 100 };
static RECT g_jjRect = { 0,0, 100, 100 };
static RECT g_syRect = { 0,0, 100, 100 };

static POINT g_ptMs = { 100, 100 };
static POINT g_ptJj = { 300, 100 };
static POINT g_ptSy = { 500, 100 };

CMenu::CMenu()
{
	ZeroMemory(&m_mouseRect, sizeof(m_mouseRect));
	ZeroMemory(&m_msRect, sizeof(m_msRect));
	ZeroMemory(&m_jjRect, sizeof(m_jjRect));
	ZeroMemory(&m_syRect, sizeof(m_syRect));
}

CMenu::~CMenu()
{
}

void CMenu::Initialize()
{
	m_mouseRect = g_mouseRect;
	m_msRect = g_msRect;
	m_jjRect = g_jjRect;
	m_syRect = g_syRect;
}

int CMenu::Update()
{
	CKeyMgr* keyMgr = CKeyMgr::Get_Instance();
	
	POINT		ptMouse{};
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	float halfX = 0;
	float halfY = 0;

	{
		halfX = (m_mouseRect.right - m_mouseRect.left) * 0.5f;
		halfY = (m_mouseRect.bottom - m_mouseRect.top) * 0.5f;
		m_mouseRect.left = ptMouse.x - halfX;
		m_mouseRect.right = ptMouse.x + halfX;
		m_mouseRect.top = ptMouse.y - halfY;
		m_mouseRect.bottom = ptMouse.y + halfY;
	}

	{
		halfX = (m_msRect.right - m_msRect.left) * 0.5f;
		halfY = (m_msRect.bottom - m_msRect.top) * 0.5f;
		m_msRect.left = g_ptMs.x - halfX;
		m_msRect.right = g_ptMs.x + halfX;
		m_msRect.top = g_ptMs.y - halfY;
		m_msRect.bottom = g_ptMs.y + halfY;
	}

	{

		halfX = (m_jjRect.right - m_jjRect.left) * 0.5f;
		halfY = (m_jjRect.bottom - m_jjRect.top) * 0.5f;
		m_jjRect.left = g_ptJj.x - halfX;
		m_jjRect.right = g_ptJj.x + halfX;
		m_jjRect.top = g_ptJj.y - halfY;
		m_jjRect.bottom = g_ptJj.y + halfY;
	}


	{
		halfX = (m_syRect.right - m_syRect.left) * 0.5f;
		halfY = (m_syRect.bottom - m_syRect.top) * 0.5f;
		m_syRect.left = g_ptSy.x - halfX;
		m_syRect.right = g_ptSy.x + halfX;
		m_syRect.top = g_ptSy.y - halfY;
		m_syRect.bottom = g_ptSy.y + halfY;
	}

	return 0;
}

void CMenu::Late_Update()
{
	RECT rc;
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON) && IntersectRect(&rc, &m_mouseRect, &m_msRect))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_MINSU);
	}
	if ( CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON) && IntersectRect(&rc, &m_mouseRect, &m_jjRect))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_KJJ);
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON) && IntersectRect(&rc, &m_mouseRect, &m_syRect))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_LSY_TEST);
	}
}

void CMenu::Render(HDC hDC)
{
	Rectangle(hDC, m_msRect.left, m_msRect.top, m_msRect.right, m_msRect.bottom);
	Rectangle(hDC, m_jjRect.left, m_jjRect.top, m_jjRect.right, m_jjRect.bottom);
	Rectangle(hDC, m_syRect.left, m_syRect.top, m_syRect.right, m_syRect.bottom);

	Rectangle(hDC, m_mouseRect.left, m_mouseRect.top, m_mouseRect.right, m_mouseRect.bottom);

	TCHAR szMs[10] = _T("¹Î¼ö");
	TCHAR szJj[10] = _T("Á¾Áø");
	TCHAR szSy[10] = _T("¼ºÀ±");
	TextOut(hDC, g_ptMs.x, g_ptMs.y, szMs, lstrlen(szMs));
	TextOut(hDC, g_ptJj.x, g_ptJj.y, szJj, lstrlen(szJj));
	TextOut(hDC, g_ptSy.x, g_ptSy.y, szSy, lstrlen(szSy));

	m_mouseRect = g_mouseRect;
	m_msRect = g_msRect;
	m_jjRect = g_jjRect;
	m_syRect = g_syRect;
}

void CMenu::Release()
{
}
