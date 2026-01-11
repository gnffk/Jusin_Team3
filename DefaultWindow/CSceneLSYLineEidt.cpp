#include "pch.h"
#include "CSceneLSYLineEidt.h"
#include "CKeyMgr.h"
#include "CLSYObjFruit.h"
#include "CObjMgr.h"
#include "CAbstractFactory.h"

static int g_padding = 10;

CSceneLSYLineEidt::CSceneLSYLineEidt():
	m_bGrid(true),
	m_bFirstSelect(true),
	m_pFruit(nullptr)
{
	ZeroMemory(&m_ptMouseOver, sizeof(m_ptMouseOver));
	ZeroMemory(&m_ptSelectBefore, sizeof(m_ptSelectBefore));
	ZeroMemory(&m_ptSelectCurrent, sizeof(m_ptSelectCurrent));
}

CSceneLSYLineEidt::~CSceneLSYLineEidt()
{
}

void CSceneLSYLineEidt::Initialize()
{
	//CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());
	//pFruit->Set_Option(CLSYObjFruit::FROPT_DRAW);
	//pFruit->GenerateVertexList();
	//CObjMgr::Get_Instance()->AddObject(OBJ_LSY_FRUIT, pFruit);
	//m_pFruit = pFruit;
}

int CSceneLSYLineEidt::Update()
{
	CObjMgr::Get_Instance()->Update();
	POINT		ptMouse{};
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	m_ptMouseOver.x = (ptMouse.x / g_padding) * g_padding;
	m_ptMouseOver.y = (ptMouse.y / g_padding) * g_padding;

	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	{
		if (m_bFirstSelect)
		{
			m_bFirstSelect = false;
			m_ptSelectCurrent.x = m_ptMouseOver.x;
			m_ptSelectCurrent.y = m_ptMouseOver.y;
		}
		else
		{
			m_ptSelectBefore = m_ptSelectCurrent;
			m_ptSelectCurrent.x = m_ptMouseOver.x;
			m_ptSelectCurrent.y = m_ptMouseOver.y;

			m_selectPtList.push_back({ m_ptSelectCurrent , m_ptSelectBefore });
		}
	}


	if (CKeyMgr::Get_Instance()->Key_Down(VK_RBUTTON))
	{
		for (auto iter = m_selectPtList.begin(); iter != m_selectPtList.end();)
		{
			if (iter->first.x == m_ptMouseOver.x && iter->first.y == m_ptMouseOver.y)
			{
				iter = m_selectPtList.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Down('G'))
	{
		m_bGrid = !m_bGrid;
	}

	if (CKeyMgr::Get_Instance()->Key_Down('R'))
	{
		m_bFirstSelect = true;
		ZeroMemory(&m_ptSelectBefore, sizeof(m_ptSelectBefore));
		ZeroMemory(&m_ptSelectCurrent, sizeof(m_ptSelectCurrent));
		m_selectPtList.clear();
	}


	//{
	//	Get_VertexList().push_back({
	//		{ {-50.f, -50.f, 0.f}, {50.f, -50.f, 0.f} },
	//		{ {50.f, -50.f, 0.f}, {50.f, 50.f, 0.f} },
	//		{ {50.f, 50.f, 0.f}, {-50.f, 50.f, 0.f} },
	//		{ {-50.f, 50.f, 0.f}, {-50.f, -50.f, 0.f} },
	//	});
	//}
	if (CKeyMgr::Get_Instance()->Key_Down('P'))
	{
		cout << "-----------------------------" << endl;
		cout << "size: " << m_selectPtList.size() << endl;
		cout << "-----------------------------" << endl;
		cout << "" << rand() << endl;
		for (pair<POINT, POINT> ptPair : m_selectPtList)
		{
			ptPair.first.x -= WINCX >> 1;
			ptPair.first.y -= WINCY >> 1;
			ptPair.second.x -= WINCX >> 1;
			ptPair.second.y -= WINCY >> 1;

			cout << "{ {" << ptPair.first.x << ".f, " << ptPair.first.y << ".f, 0.f }, ";
			cout << "  {" << ptPair.second.x << ".f, " << ptPair.second.y << ".f, 0.f } }," << endl;
		}
		
		cout << "-----------------------------" << endl;
	}


    return 0;
}

void CSceneLSYLineEidt::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CSceneLSYLineEidt::Render(HDC hDC)
{

	if (m_bGrid)
	{
		int xCnt = WINCX / g_padding;
		int yCnt = WINCY / g_padding;
		int left = (g_padding * 0);
		for (int i = 0; i < xCnt; ++i)
		{
			MoveToEx(hDC, left + i * g_padding, 0, nullptr);
			LineTo(hDC, left + i * g_padding, WINCY);
		}

		for (int i = 0; i < yCnt; ++i)
		{
			MoveToEx(hDC, 0, left + i * g_padding, nullptr);
			LineTo(hDC, WINCX, left + i * g_padding);
		}

		

	}

	{
		HPEN hNewPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
		HPEN hOldPen = (HPEN)SelectObject(hDC, hNewPen);

		MoveToEx(hDC, WINCX * 0.5, 0, nullptr);
		LineTo(hDC, WINCX * 0.5, WINCY);

		MoveToEx(hDC, 0, WINCY * 0.5, nullptr);
		LineTo(hDC, WINCX, WINCY * 0.5);

		{
			int size = 5;
			int left = WINCX * 0.5 - size;
			int top = WINCY * 0.5 - size;
			int right = WINCX * 0.5 + size;
			int bottom = WINCY * 0.5 + size;
			Ellipse(hDC, left, top, right, bottom);
		}

		HPEN hOldPen2 = (HPEN)SelectObject(hDC, hOldPen);
		DeleteObject(hOldPen2);
		DeleteObject(hNewPen);
	}

	{
		MoveToEx(hDC, m_ptMouseOver.x - (g_padding * 0.5), m_ptMouseOver.y - (g_padding * 0.5), nullptr);
		LineTo(hDC, m_ptMouseOver.x + (g_padding * 0.5), m_ptMouseOver.y + (g_padding * 0.5));

		MoveToEx(hDC, m_ptMouseOver.x + (g_padding * 0.5), m_ptMouseOver.y - (g_padding * 0.5), nullptr);
		LineTo(hDC, m_ptMouseOver.x - (g_padding * 0.5), m_ptMouseOver.y + (g_padding * 0.5));
	}

	{
		for (pair<POINT, POINT>& ptPair : m_selectPtList)
		{
			HPEN hNewPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			HPEN hOldPen = (HPEN)SelectObject(hDC, hNewPen);

			MoveToEx(hDC, ptPair.first.x, ptPair.first.y, nullptr);
			LineTo(hDC, ptPair.second.x, ptPair.second.y);

			HPEN hOldPen2 = (HPEN)SelectObject(hDC, hOldPen);
			DeleteObject(hOldPen2);
			DeleteObject(hNewPen);

			{
				int size = 2;
				int left = ptPair.first.x - size;
				int top = ptPair.first.y - size;
				int right = ptPair.first.x + size;
				int bottom = ptPair.first.y + size;
				Ellipse(hDC, left, top, right,bottom);
			}

			{
				int size = 2;
				int left = ptPair.second.x - size;
				int top = ptPair.second.y - size;
				int right = ptPair.second.x + size;
				int bottom = ptPair.second.y + size;
				Ellipse(hDC, left, top, right, bottom);
			}
		}
	}
	

	CObjMgr::Get_Instance()->Render(hDC);
}

void CSceneLSYLineEidt::Release()
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_LSY_FRUIT);
}
