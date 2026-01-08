#include "pch.h"
#include "CKJJ_Player.h"
#include "CObjMgr.h"
#include "CHammer.h"

CKJJ_Player::CKJJ_Player() :m_pHammer(nullptr)
{
}

CKJJ_Player::~CKJJ_Player()
{
}

void CKJJ_Player::Initialize()
{
	m_vPoint[0] = { -50.f, -50.f, 0.f };
	m_vPoint[1] = { 50.f, -50.f, 0.f };
	m_vPoint[2] = { 50.f, 50.f, 0.f };
	m_vPoint[3] = { -50.f, 50.f, 0.f };

	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_tInfo.vDir = { 0.f, 1.f, 0.f };

	for (int i = 0; i < 4; ++i)
	{
		m_vOriginPoint[i] = m_vPoint[i];
	}

	if (m_pHammer == nullptr)
	{
		m_pHammer = new CHammer;
		static_cast<CHammer*>(m_pHammer)->Set_Player(this);
		m_pHammer->Initialize();

		CObjMgr::Get_Instance()->AddObject(OBJ_HAMMER, m_pHammer);
	}
}	

int CKJJ_Player::Update()
{

	D3DXMATRIX		matScale, matTrans;

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixTranslation(&matTrans, 
		m_tInfo.vPos.x,
		m_tInfo.vPos.y,
		m_tInfo.vPos.z);

	m_tInfo.matWorld = matScale * matTrans;

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	return 0;
}

int CKJJ_Player::Late_Update()
{
	return 0;
}

void CKJJ_Player::Render(HDC hDC)
{
	MoveToEx(hDC, m_vPoint[3].x, m_vPoint[3].y, nullptr);

	for (int i = 0; i < 4; ++i)
	{
		LineTo(hDC, m_vPoint[i].x, m_vPoint[i].y);
	}

}

void CKJJ_Player::Release()
{
}