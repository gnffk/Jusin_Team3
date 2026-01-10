#include "pch.h"
#include "CKJJ_Player.h"
#include "CObjMgr.h"
#include "CHammer.h"

CKJJ_Player::CKJJ_Player() :m_pHammer(nullptr)
{
	m_vSize = { 100.f,100.f,0.f };
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_vScale = { 1.f,1.f,1.f };
}

CKJJ_Player::~CKJJ_Player()
{
}

void CKJJ_Player::Initialize()
{
	m_vAxisX = { m_vSize.x / 2.f, 0.f,0.f };
	m_vAxisY = { 0.f, -m_vSize.y / 2.f, 0.f };

	m_vPoint[0] = { -m_vSize.x / 2.f,-m_vSize.y / 2.f, 0.f };
	m_vPoint[1] = { m_vSize.x / 2.f,-m_vSize.y / 2.f, 0.f };
	m_vPoint[2] = { m_vSize.x / 2.f,m_vSize.y / 2.f, 0.f };
	m_vPoint[3] = { -m_vSize.x / 2.f,m_vSize.y / 2.f, 0.f };

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
	CKJJObj::Update_matWorld();

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	return 0;
}

int CKJJ_Player::Late_Update()
{
	D3DXVECTOR3	vMovement = m_fSpeed * m_tInfo.vDir;

	m_vecMovement.push_back({ 0.f,1.f,0.f });		// ม฿ทย

	for (vector<D3DXVECTOR3>::iterator iter = m_vecMovement.begin();
		iter != m_vecMovement.end(); ++iter)
	{
		vMovement += (*iter);
	}

	m_tInfo.vPos += vMovement;

	m_fSpeed = D3DXVec3Length(&vMovement);
	D3DXVec3Normalize(&m_tInfo.vDir, &vMovement);

	m_vecMovement.clear();

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

void CKJJ_Player::Collision(CKJJObj* pObj)
{
	m_fSpeed = 0.f;
	m_tInfo.vPos += {0.f, -10.f, 0.f };
}
