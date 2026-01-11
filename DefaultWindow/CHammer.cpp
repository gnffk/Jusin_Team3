#include "pch.h"
#include "CHammer.h"
#include "CKJJ_Player.h"
#include "CKeyMgr.h"


CHammer::CHammer() :
	m_pPlayer(nullptr),
	m_fPlayerAngle(0.f),
	m_bIs_Col(false),
	m_bClockWise(false),
	m_bColDir(false),
	m_Super_Wennie_Hut(false)
{
	m_fAngle =-90.f;
	m_fHead_Distance = 100.f;
	m_fHammer_Length = 100.f;

	m_tInfo.vPos = { m_fHead_Distance,0.f,0.f };

	m_vSize = { 6.f, 10.f, 0.f };
	m_vScale = { 2.f,2.f,2.f };
}

CHammer::~CHammer()
{
}

void CHammer::Initialize()
{
	m_vAxisX = { m_vSize.x / 2.f, 0.f,0.f };
	m_vAxisY = { 0.f, -m_vSize.y / 2.f, 0.f };

	m_vPoint[0] = { -m_vSize.x / 2.f,-m_vSize.y / 2.f, 0.f };
	m_vPoint[1] = { m_vSize.x / 2.f,-m_vSize.y / 2.f, 0.f };
	m_vPoint[2] = { m_vSize.x / 2.f,m_vSize.y / 2.f, 0.f };
	m_vPoint[3] = { -m_vSize.x / 2.f,m_vSize.y / 2.f, 0.f };

	for (int i = 0; i < 4; ++i)
		m_vOriginPoint[i] = m_vPoint[i];

	m_vCurrMouse = ::Get_Mouse();
	m_vPrevMouse = m_vCurrMouse;
}

int CHammer::Update()
{
	D3DXMATRIX		matScale, matRotZ, matTrans, matTrans2;

	D3DXMatrixScaling(&matScale,
		m_vScale.x,
		m_vScale.y,
		m_vScale.z);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&matTrans, m_fHead_Distance, 0.f, 0.f);
	D3DXMatrixTranslation(&matTrans2,
		m_pPlayer->Get_Info().vPos.x,
		m_pPlayer->Get_Info().vPos.y,
		m_pPlayer->Get_Info().vPos.z);

	m_tInfo.matWorld = matScale * matTrans * matRotZ * matTrans2;

	m_tInfo.vPos = { 0.f,0.f,0.f };
	D3DXVec3TransformCoord(&m_tInfo.vPos, &m_tInfo.vPos, &m_tInfo.matWorld);

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);

	}
	return 0;
}

int CHammer::Late_Update()
{
	D3DXVECTOR3 vMouse_Movement = { 0,0,0 };

	if (GetAsyncKeyState(VK_RBUTTON))
	{
		if (m_Super_Wennie_Hut)
			m_Super_Wennie_Hut = false;
		else
			m_Super_Wennie_Hut = true;
	}

	if (m_Super_Wennie_Hut)
	{
#pragma region 자동해머
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
		{
			m_vPrevMouse = m_vCurrMouse;
			m_vCurrMouse = ::Get_Mouse();
		}
		vMouse_Movement = m_vCurrMouse - m_vPrevMouse;
#pragma endregion
	}
	else
	{
		m_vPrevMouse = m_vCurrMouse;
		m_vCurrMouse = ::Get_Mouse();
#pragma region 수동해머
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
		{
			vMouse_Movement = m_vCurrMouse - m_vPrevMouse;
		}
	}
#pragma endregion

	if (vMouse_Movement.x > 0)
	{
		m_bClockWise = true;
	}
	else
	{
		m_bClockWise = false;
	}

	if (m_bIs_Col)
	{
		if (m_bColDir == m_bClockWise)
		{
			m_fPlayerAngle = vMouse_Movement.x / 3;

			if (m_fPlayerAngle > 180.f)
			{
				m_fPlayerAngle -= 360.f;
			}
			else if (m_fPlayerAngle < -180.f)
			{
				m_fPlayerAngle += 360.f;
			}

			D3DXVECTOR3 vPlayerMove = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;
			D3DXMATRIX	matRotZ;
			D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fPlayerAngle));
			D3DXVec3TransformCoord(&vPlayerMove, &vPlayerMove, &matRotZ);
			D3DXVECTOR3 vNewPlayerPos = m_tInfo.vPos + vPlayerMove;
			m_pPlayer->Set_Pos(vNewPlayerPos);
		}
	}
	
	m_fAngle += vMouse_Movement.x / 3;

	if (m_fAngle > 180.f)
	{
		m_fAngle -= 360.f;
	}
	else if (m_fAngle < -180.f)
	{
		m_fAngle += 360.f;
	}


	m_fHead_Distance -= vMouse_Movement.y / 3;

	if (m_fHead_Distance < 40.f)
		m_fHead_Distance = 40.f;
	else if (m_fHead_Distance > 150.f)
		m_fHead_Distance = 150.f;

	m_bIs_Col = false;
	return 0;
}

void CHammer::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, nullptr);

	D3DXVECTOR3 vHandPoint = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;
	D3DXVec3Normalize(&vHandPoint, &vHandPoint);
	vHandPoint = (m_fHammer_Length * vHandPoint) + m_tInfo.vPos;

	LineTo(hDC, vHandPoint.x, vHandPoint.y);

	Ellipse(hDC, vHandPoint.x - 5, vHandPoint.y - 5, vHandPoint.x + 5, vHandPoint.y + 5);


	MoveToEx(hDC, m_vPoint[3].x, m_vPoint[3].y, nullptr);

	for (int i = 0; i < 4; ++i)
	{
		LineTo(hDC, m_vPoint[i].x, m_vPoint[i].y);
	}
}

void CHammer::Release()
{
}

void CHammer::Collision(CKJJObj* pObj, D3DXVECTOR3 Vec)
{
	m_bIs_Col = true;
	m_bColDir = m_bClockWise;
	m_pPlayer->Set_Falling(false);
	if (Vec.x != 0.f)
	{
		if (m_tInfo.vPos.x < pObj->Get_Info().vPos.x)
		{
			m_tInfo.vPos += 1.1f * Vec;
			m_pPlayer->Move_Pos(1.1f * Vec);
		}
		else
		{
			m_tInfo.vPos -= 1.1f * Vec;
			m_pPlayer->Move_Pos(-1.1f * Vec);
		}
	}
	if (Vec.y != 0.f)
	{
		if (m_tInfo.vPos.y < pObj->Get_Info().vPos.y)
		{
			m_tInfo.vPos += Vec;
			m_pPlayer->Move_Pos(Vec);
		}
		else
		{
			m_tInfo.vPos -= Vec;
			m_pPlayer->Move_Pos(-Vec);
		}
	}
	m_pPlayer->Move_Pos(Vec);
}