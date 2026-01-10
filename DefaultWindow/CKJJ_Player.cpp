#include "pch.h"
#include "CKJJ_Player.h"
#include "CObjMgr.h"
#include "CHammer.h"

CKJJ_Player::CKJJ_Player() :
	m_pHammer(nullptr),
	bIs_falling(true)
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
	return 0;
}

int CKJJ_Player::Late_Update()
{
	D3DXVECTOR3	vMovement = m_fSpeed * m_tInfo.vDir;

	if (bIs_falling)
	{
		m_vecMovement.push_back({ 0.f,1.f,0.f });		// 중력
	}

	for (vector<D3DXVECTOR3>::iterator iter = m_vecMovement.begin();
		iter != m_vecMovement.end(); ++iter)
	{
		vMovement += (*iter);
	}

	m_tInfo.vPos += vMovement;

	m_fSpeed = D3DXVec3Length(&vMovement);
	D3DXVec3Normalize(&m_tInfo.vDir, &vMovement);

#pragma region 초기화 구간
	bIs_falling = true;
	m_vecMovement.clear();
#pragma endregion
	return 0;
}

void CKJJ_Player::Render(HDC hDC)
{
	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	MoveToEx(hDC, m_vPoint[3].x, m_vPoint[3].y, nullptr);

	for (int i = 0; i < 4; ++i)
	{
		LineTo(hDC, m_vPoint[i].x, m_vPoint[i].y);
	}

}

void CKJJ_Player::Release()
{
}

void CKJJ_Player::Collision(CKJJObj* pObj, D3DXVECTOR3 Vec)
{
	m_fSpeed = 0.f;
	m_tInfo.vDir = { 0.f,0.f,0.f };
	m_tInfo.vPos += Vec;
	if (Vec.y < 0)
	{
		bIs_falling = false;
		m_tInfo.vPos += {0.f, 2.f, 0.f};
	}
}