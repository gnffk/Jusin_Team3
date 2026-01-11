#include "pch.h"
#include "CKJJ_Player.h"
#include "CObjMgr.h"
#include "CHammer.h"
#include "CBmpMgr.h"

CKJJ_Player::CKJJ_Player() :
	m_pHammer(nullptr),
	bIs_falling(true),
	m_bStart(false),m_bEnd(false)
{
	m_vSize = { 21.f,56.f,0.f };
	m_tInfo.vPos = { 150.f, 300.f, 0.f };
	m_vScale = { 1.f,1.f,1.f };
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Mario.bmp", L"Mario");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Jar.bmp", L"Jar");

}

CKJJ_Player::~CKJJ_Player()
{
}

void CKJJ_Player::Initialize()
{
	m_vAxisX = { m_vSize.x, 0.f,0.f };
	m_vAxisY = { 0.f, -m_vSize.y, 0.f };

	m_vPoint[0] = { -m_vSize.x,-m_vSize.y/2.f, 0.f };
	m_vPoint[1] = { m_vSize.x ,-m_vSize.y/2.f, 0.f };
	m_vPoint[2] = { m_vSize.x ,m_vSize.y/2.f, 0.f };
	m_vPoint[3] = { -m_vSize.x ,m_vSize.y/2.f, 0.f };

	for (int i = 0; i < 4; ++i)
	{
		m_vOriginPoint[i] = m_vPoint[i];
	}


}	

int CKJJ_Player::Update()
{
	if (m_tInfo.vPos.y > 800)
	{
		m_pHammer = nullptr;
		CObjMgr::Get_Instance()->Delete_ID(OBJ_HAMMER);
		return OBJ_DEAD;
	}

	CKJJObj::Update_matWorld();
	return 0;
}

int CKJJ_Player::Late_Update()
{
	D3DXVECTOR3	vMovement = m_fSpeed * m_tInfo.vDir;

	if (bIs_falling)
	{
		m_vecMovement.push_back({ 0.f,0.5f,0.f });		// 중력
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
	HDC Mario = CBmpMgr::Get_Instance()->Find_Image(L"Mario");
	HDC Jar = CBmpMgr::Get_Instance()->Find_Image(L"Jar");

	GdiTransparentBlt(hDC,
		m_vPoint[0].x, m_vPoint[0].y,
		42, 56,
		Mario,
		0,0,
		12, 16,
		RGB(89, 186, 255));

	if (m_bStart)
	{
		GdiTransparentBlt(hDC,
			m_vPoint[0].x, m_vPoint[0].y + 31,
			42, 25,
			Jar,
			0, 0,
			12, 7,
			RGB(89, 186, 255));
	}

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
	if (pObj->Get_Weight() == -2.f)
	{
		m_bStart = true;
		if (m_pHammer == nullptr)
		{
			m_pHammer = new CHammer;
			static_cast<CHammer*>(m_pHammer)->Set_Player(this);
			m_pHammer->Initialize();
			CObjMgr::Get_Instance()->AddObject(OBJ_HAMMER, m_pHammer);
		}
		return;
	}
	m_tInfo.vDir = { 0.f,0.f,0.f };
	if (Vec.x != 0.f)
	{
		if (m_tInfo.vPos.x < pObj->Get_Info().vPos.x)
		{
			m_tInfo.vPos += Vec;
		}
		else
		{
			m_tInfo.vPos -= Vec;
		}
	}
	if (Vec.y != 0.f)
	{
		if (m_tInfo.vPos.y < pObj->Get_Info().vPos.y)
		{
			m_tInfo.vPos += Vec;
		}
		else
		{
			m_tInfo.vPos -= Vec;
		}
	}

	if (Vec.y < 0)
	{
		bIs_falling = false;
		m_tInfo.vPos += {0.f, 2.f, 0.f};
	}
}