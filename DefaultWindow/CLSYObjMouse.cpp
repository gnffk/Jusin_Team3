#include "pch.h"
#include "CLSYObjMouse.h"
#include "CKeyMgr.h"
#include "CObjMgr.h"
#include "CLSYObjKnifeMark.h"
#include "CAbstractFactory.h"
#include "CDeltaMgr.h"

CLSYObjMouse::CLSYObjMouse():
	m_iCnt(0),
	m_bMarking(false),
	m_fCoolTime(0.f),
	m_pKnifeMark(nullptr),
	m_bSkill(false),
	m_fSkillIntervalTimer(0.f),
	m_fSkillTimer(0.f),
	m_bSceneEnd(false)
{
	ZeroMemory(&m_ptBefore, sizeof(m_ptBefore));
	ZeroMemory(&m_ptCurr, sizeof(m_ptCurr));
	ZeroMemory(&m_szCnt, sizeof(m_szCnt));
}

CLSYObjMouse::~CLSYObjMouse()
{
}

void CLSYObjMouse::Initialize()
{
	m_tRectSides = { 10, 10 };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };

	//ShowCursor(false);
}

int CLSYObjMouse::Update()
{
	
	POINT		ptMouse{};
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);
	m_tInfo.vPos.x = ptMouse.x;
	m_tInfo.vPos.y = ptMouse.y;


	if (m_fCoolTime <= 1.f)
	{
		m_fCoolTime += 0.005f;
	}

	int coolTimeHalfWidth = 5;
	int coolTimeHalfHeight = 20;
	int coolTimeMoveX = 20;
	int coolTimeMoveY = 10;

	m_tCoolTimeEdgeRect.left = coolTimeMoveX + m_tInfo.vPos.x - coolTimeHalfWidth;
	m_tCoolTimeEdgeRect.right = coolTimeMoveX + m_tInfo.vPos.x + coolTimeHalfWidth;
	m_tCoolTimeEdgeRect.top = coolTimeMoveY + m_tInfo.vPos.y - coolTimeHalfHeight;
	m_tCoolTimeEdgeRect.bottom = coolTimeMoveY + m_tInfo.vPos.y + coolTimeHalfHeight;

	m_tCoolTimeFillRect.left = coolTimeMoveX + m_tInfo.vPos.x - coolTimeHalfWidth;
	m_tCoolTimeFillRect.right = coolTimeMoveX + m_tInfo.vPos.x + coolTimeHalfWidth;
	m_tCoolTimeFillRect.top = coolTimeMoveY + m_tInfo.vPos.y + coolTimeHalfHeight - (coolTimeHalfHeight * 2.f * m_fCoolTime);
	m_tCoolTimeFillRect.bottom = coolTimeMoveY + m_tInfo.vPos.y + coolTimeHalfHeight;
	

	if (m_bSkill)
	{
		m_fSkillTimer += CDeltaMgr::Get_Instance()->Get_Delta();
		if (m_fSkillTimer > 0.5f)
		{
			m_bSkill = false;
			m_fSkillTimer = 0.f;
		}

		m_fSkillIntervalTimer += CDeltaMgr::Get_Instance()->Get_Delta();
		if (m_fSkillIntervalTimer > 0.01f)
		{
			m_fSkillIntervalTimer = 0.f;

			int midX = WINCX >> 1;
			int midY = WINCY >> 1;
			int halfPadding = 400;
			int left = midX - halfPadding;
			int right = midX + halfPadding;
			int top = midY - halfPadding;
			int bottom = midY + halfPadding;

			int randVal;

			randVal = rand() % halfPadding;
			left += randVal;

			randVal = rand() % halfPadding;
			right -= randVal;

			randVal = rand() % halfPadding;
			top += randVal;

			randVal = rand() % halfPadding;
			bottom -= randVal;

			//cout << "left:" << left << "top;:" << top << "right:" << right << "bottom:" << bottom << endl;

			

			CLSYObjKnifeMark* pKnifeMark = dynamic_cast<CLSYObjKnifeMark*>(CAbstractFactory<CLSYObjKnifeMark>::Create());
			D3DXVECTOR3 posMark;
			POINT ptMarkEnd;
			if (rand() % 2)
			{
				posMark = { (float)left, (float)bottom, 0.f };
				ptMarkEnd = { right,top };
			}
			else
			{
				posMark = { (float)right, (float)bottom, 0.f };
				ptMarkEnd = { left,top };
			}
			pKnifeMark->Set_Pos(posMark);
			pKnifeMark->Set_EndPt(ptMarkEnd);
			int plus = 0;
			int minus = 0;
			pKnifeMark->Slicing(ptMarkEnd, &plus, &minus);
			m_iCnt += (plus - minus);
			CObjMgr::Get_Instance()->AddObject(OBJ_LSY_MOUSE, pKnifeMark);
		}
	}
	
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
	{
		if (!m_bPressed)
		{
			m_bPressed = true;

			
			//Keydown
			{
				if (m_fCoolTime > 1.f)
				{
					m_bSkill = true;
					m_fCoolTime = 0.f;

					

				}
				else
				{
					CLSYObjKnifeMark* pKnifeMark = dynamic_cast<CLSYObjKnifeMark*>(CAbstractFactory<CLSYObjKnifeMark>::Create());
					CObjMgr::Get_Instance()->AddObject(OBJ_LSY_MOUSE, pKnifeMark);
					m_pKnifeMark = pKnifeMark;

					cout << "Down" << endl;
					m_pKnifeMark->Reset();
					m_pKnifeMark->Set_Pos(m_tInfo.vPos);
				}
			}
		}

		// Keypressing
		{
			cout << "pressing" << endl;
			if (m_pKnifeMark)
			{
				m_pKnifeMark->Set_EndPt(ptMouse);
			}
		}
	}
	else
	{
		if (m_bPressed)
		{
			m_bPressed = false;

			// Keyup
			{
				cout << "UP" << endl;
				if (m_pKnifeMark)
				{
					int plus = 0;
					int minus = 0;
					m_pKnifeMark->Slicing(ptMouse, &plus, &minus);
					m_iCnt += (plus - minus);
				}
				
				m_pKnifeMark = nullptr;
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
	Rectangle(hDC, m_tCoolTimeEdgeRect.left, m_tCoolTimeEdgeRect.top, m_tCoolTimeEdgeRect.right, m_tCoolTimeEdgeRect.bottom);
	
	if (m_fCoolTime < 1.f)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		FillRect(hDC, &m_tCoolTimeFillRect, brush);
		DeleteObject(brush);
	}
	else
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		FillRect(hDC, &m_tCoolTimeFillRect, brush);
		DeleteObject(brush);
	}

	if (!m_bSceneEnd)
	{
		swprintf_s(m_szCnt, L"%i/20", m_iCnt);
		TextOut(hDC, m_tInfo.vPos.x - 30, m_tInfo.vPos.y + 30, m_szCnt, lstrlen(m_szCnt));
	}
	
	CLSYObj::Render(hDC);
}

void CLSYObjMouse::Release()
{
}
