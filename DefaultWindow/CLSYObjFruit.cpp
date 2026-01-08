#include "pch.h"
#include "CLSYObjFruit.h"
#include "CKeyMgr.h"

CLSYObjFruit::~CLSYObjFruit()
{
	Release();
}

void CLSYObjFruit::GenerateVertexList()
{
	switch (m_iOption)
	{
	case FROPT_TEST:
	{
		Get_VertexList().push_back({
			{-10.f, -10.f, 0.f},
			{10.f, -10.f, 0.f},
			{10.f, 10.f, 0.f},
			{-10.f, 10.f, 0.f},
			{-10.f, -10.f, 0.f}
			});
	}
	break;
	default:
		break;
	}
}

void CLSYObjFruit::Initialize()
{
	m_tInfo.vPos = { 50.f, 50.f, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };
	m_fSpeed = 3.f;

	m_tRectSides = { 50, 50 };
}

int CLSYObjFruit::Update()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	{
		m_fAngle -= D3DXToRadian(3.f);
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	{
		m_fAngle += D3DXToRadian(3.f);
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
	{
		D3DXVECTOR3 dirTmp;
		D3DXVec3TransformNormal(&dirTmp, &m_tInfo.vLook, &m_tInfo.matWorld);
		m_tInfo.vPos += dirTmp * m_fSpeed;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
	{
		D3DXVECTOR3 dirTmp;
		D3DXVec3TransformNormal(&dirTmp, &m_tInfo.vLook, &m_tInfo.matWorld);
		m_tInfo.vPos -= dirTmp * m_fSpeed;
	}


	CLSYObj::Update();
	return OBJ_NOEVENT;
}

int CLSYObjFruit::Late_Update()
{
	
	return OBJ_NOEVENT;
}

void CLSYObjFruit::Render(HDC hDC)
{
	CLSYObj::Render(hDC);
}

void CLSYObjFruit::Release()
{
}
