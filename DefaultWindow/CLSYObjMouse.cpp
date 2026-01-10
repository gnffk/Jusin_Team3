#include "pch.h"
#include "CLSYObjMouse.h"
#include "CKeyMgr.h"
#include "CObjMgr.h"
#include "CLSYObjKnifeMark.h"
#include "CAbstractFactory.h"

CLSYObjMouse::CLSYObjMouse():
	m_iCnt(0),
	m_bMarking(false)
{
	ZeroMemory(&m_ptBefore, sizeof(m_ptBefore));
	ZeroMemory(&m_ptCurr, sizeof(m_ptCurr));
}

CLSYObjMouse::~CLSYObjMouse()
{
}

void CLSYObjMouse::Initialize()
{
	m_tRectSides = { 10, 10 };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };
}

int CLSYObjMouse::Update()
{
	POINT		ptMouse{};
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);
	m_tInfo.vPos.x = ptMouse.x;
	m_tInfo.vPos.y = ptMouse.y;

	

	
	if (false)
	{
		if (!(m_ptCurr.x == ptMouse.x && m_ptCurr.y == ptMouse.y))
		{
			++m_iCnt;

			if (m_iCnt == 1)
			{
				m_iCnt = 0;

				m_ptBefore = m_ptCurr;
				m_ptCurr = ptMouse;
				LONG width = m_ptCurr.x - m_ptBefore.x;
				LONG height = m_ptCurr.y - m_ptBefore.y;
				float r = atan2f(height, width);
				m_fAngle = D3DXToDegree(r) + 90.f;
				cout << "--" << endl;
				cout << "m_ptBefore" << m_ptBefore.x << ", " << m_ptBefore.y << endl;
				cout << "m_ptCurr" << m_ptCurr.x << ", " << m_ptCurr.y << endl;
				cout << "m_fAngle" << m_fAngle << endl;
			}
		}
	}

	if (false)
	{
		if (!(m_ptCurr.x == ptMouse.x && m_ptCurr.y == ptMouse.y))
		{
			LONG width = ptMouse.x - m_ptCurr.x;
			LONG height = ptMouse.y - m_ptCurr.y;
			float distance = sqrtf(width * width + height * height);

			if (distance > 10)
			{
				m_ptBefore = m_ptCurr;
				m_ptCurr = ptMouse;
				LONG width = m_ptCurr.x - m_ptBefore.x;
				LONG height = m_ptCurr.y - m_ptBefore.y;
				float r = atan2f(height, width);
				m_fAngle = D3DXToDegree(r) + 90.f;
			}
		}
	}


	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	{
		int x = 0;
		if (!m_bMarking)
		{
			m_bMarking = true;

			{
				m_ptBefore = m_ptCurr;
				m_ptCurr = ptMouse;
			}
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Up(VK_LBUTTON))
	{
		if (m_bMarking)
		{
			m_bMarking = false;

			{

			}
		}
	}
	
	if (m_bMarking)
	{
		if (!(m_ptCurr.x == ptMouse.x && m_ptCurr.y == ptMouse.y))
		{
			LONG width = ptMouse.x - m_ptCurr.x;
			LONG height = ptMouse.y - m_ptCurr.y;
			float distance = sqrtf(width * width + height * height);

			if (distance > 5)
			{
				cout << "mark!" << endl;
				m_ptBefore = m_ptCurr;
				m_ptCurr = ptMouse;
				LONG width = m_ptCurr.x - m_ptBefore.x;
				LONG height = m_ptCurr.y - m_ptBefore.y;
				float r = atan2f(height, width);
				m_fAngle = D3DXToDegree(r) + 90.f;

				{
					CLSYObjKnifeMark* pKnifeMark = dynamic_cast<CLSYObjKnifeMark*>(CAbstractFactory<CLSYObjKnifeMark>::Create());
					pKnifeMark->Set_Pos(m_tInfo.vPos);
					pKnifeMark->Set_Angle(m_fAngle);
					pKnifeMark->Get_VertexList().push_back({
						{-5.f, -distance, 0.f},
						{5.f, -distance, 0.f},
						{5.f, distance, 0.f},
						{-5.f, distance, 0.f},
						{-5.f, -distance, 0.f}
						});
					CObjMgr::Get_Instance()->AddObject(OBJ_LSY_MOUSE, pKnifeMark);


					if (PtInRect(&m_pTmpFruit->Get_Rect(), ptMouse))
					{
						if (!m_pTmpFruit->Get_Cut())
						{
							m_pTmpFruit->CalcKnifeMark(m_ptCurr, m_ptBefore);
						}
					}
				}
			}
		}
	}
	

	CLSYObj::Update();
	return OBJ_NOEVENT;
}

int CLSYObjMouse::Late_Update()
{
	return OBJ_NOEVENT;
}

void CLSYObjMouse::Render(HDC hDC)
{
	CLSYObj::Render(hDC);
}

void CLSYObjMouse::Release()
{
}
