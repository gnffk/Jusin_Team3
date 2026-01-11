#include "pch.h"
#include "CLSYObjKnifeMark.h"
#include "CDeltaMgr.h"
#include "CObjMgr.h"
#include "CLSYObjFruit.h"

CLSYObjKnifeMark::CLSYObjKnifeMark():
	m_fDeathTimer(0.f),
	m_bThick(false),
	m_bRewind(false)
{
	ZeroMemory(&m_ptEnd, sizeof(m_ptEnd));
}

CLSYObjKnifeMark::~CLSYObjKnifeMark()
{
}

void CLSYObjKnifeMark::Initialize()
{
	//Get_VertexList().push_back({
	//	{-5.f, -10.f, 0.f},
	//	{5.f, -10.f, 0.f},
	//	{5.f, 10.f, 0.f},
	//	{-5.f, 10.f, 0.f},
	//	{-5.f, -10.f, 0.f}
	//	});

	//Get_VertexList().push_back({
	//	{ {-50.f, -50.f, 0.f}, {50.f, -50.f, 0.f} },
	//	{ {-50.f, -50.f, 0.f}, {50.f, -50.f, 0.f} },
	//	});

	m_tInfo.vLook = { 0.f, -1.f, 0.f };
}

int CLSYObjKnifeMark::Update()
{
	if (m_bThick)
	{
		m_fDeathTimer += CDeltaMgr::Get_Instance()->Get_Delta();
		if (m_fDeathTimer > 0.3f)
		{
			m_bRewind = true;
		}
	}

	if (m_bRewind)
	{
		D3DXVECTOR3 posEnd{ (float)m_ptEnd .x, (float)m_ptEnd.y, 0.f};
		D3DXVECTOR3 dirEnd = posEnd - m_tInfo.vPos;
		D3DXVec3Normalize(&dirEnd, &dirEnd);
		m_tInfo.vPos += dirEnd * 30.f;
		D3DXVECTOR3 len = posEnd - m_tInfo.vPos;
		float a = D3DXVec3Length(&len);
		if (D3DXVec3Length(&len) < 30.f)
		{
			return OBJ_DEAD;
		}
	}
	
	CLSYObj::Update();
	
    return OBJ_NOEVENT;
}

int CLSYObjKnifeMark::Late_Update()
{
    return OBJ_NOEVENT;
}

void CLSYObjKnifeMark::Render(HDC hDC)
{
	//CLSYObj::Render(hDC);
	if (m_bThick)
	{
		HPEN hNewPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		HPEN hOldPen = (HPEN)SelectObject(hDC, hNewPen);

		MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, nullptr);
		LineTo(hDC, m_ptEnd.x, m_ptEnd.y);

		HPEN hOldPen2 = (HPEN)SelectObject(hDC, hOldPen);
		DeleteObject(hOldPen2);
		DeleteObject(hNewPen);
	}
	else
	{
		MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, nullptr);
		LineTo(hDC, m_ptEnd.x, m_ptEnd.y);
	}
}

void CLSYObjKnifeMark::Release()
{
}

void CLSYObjKnifeMark::Slicing(POINT& ptMouse)
{
	{
		list<CObj*> fruits = *CObjMgr::Get_Instance()->Get_ObjList(OBJ_LSY_FRUIT);
		//cout << "fruits1"<<fruits.size() << endl;
		for (auto iter = fruits.begin(); iter != fruits.end(); ++iter)
		{
			CLSYObjFruit* pFruits = dynamic_cast<CLSYObjFruit*>(*iter);
			D3DXVECTOR3 posMark = m_tInfo.vPos;
			POINT ptMark{ (LONG)posMark.x, (LONG)posMark.y };
			//cout << "//" << endl;
			//cout << "x" << ptMark.x << "y" << ptMark.y << endl;
			//cout << "x" << ptMouse.x << "y" << ptMouse.y << endl;
			pFruits->Slice(ptMark, ptMouse);
		}

		m_bThick = true;
	}
}

void CLSYObjKnifeMark::Reset()
{
	m_bThick = false;
}
