#include "pch.h"
#include "CHammer.h"

CHammer::CHammer() : m_fAngle(-90.f)
{
	m_fHead_Distance = 100.f;
	m_fHammer_Length = 100.f;
}

CHammer::~CHammer()
{
}

void CHammer::Initialize()
{
	m_vPoint[0] = { 0.f,0.f,0.f };
	m_vPoint[1] = { -3.f, -5.f, 0.f };
	m_vPoint[2] = { 3.f, -5.f, 0.f };
	m_vPoint[3] = { 3.f, 5.f, 0.f };
	m_vPoint[4] = { -3.f, 5.f, 0.f };

	for (int i = 0; i < 5; ++i)
		m_vOriginPoint[i] = m_vPoint[i];
}

int CHammer::Update()
{
	m_vPrevMouse = m_vCurrMouse;
	m_vCurrMouse = ::Get_Mouse();

	D3DXVECTOR3 vMouse_Movement = m_vCurrMouse - m_vPrevMouse;

	m_fAngle			+= vMouse_Movement.x;
	m_fHead_Distance	-= vMouse_Movement.y;

	if (m_fAngle > 180.f)
	{
		m_fAngle -= 360.f;
	}
	else if (m_fAngle < -180.f)
	{
		m_fAngle += 360.f;
	}

	if (m_fHead_Distance < 50.f)
		m_fHead_Distance = 50.f;
	else if (m_fHead_Distance > 150.f)
		m_fHead_Distance = 150.f;

	D3DXMATRIX		matScale, matRotZ, matTrans;

	float fRadian = D3DXToRadian(m_fAngle);

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, fRadian);
	D3DXMatrixTranslation(&matTrans,
		m_pPlayer->Get_Info().vPos.x + m_fHead_Distance,
		m_pPlayer->Get_Info().vPos.y,
		m_pPlayer->Get_Info().vPos.z);

	m_tInfo.matWorld = matScale * matTrans * matRotZ;

	for (int i = 0; i < 5; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}
	return 0;
}

int CHammer::Late_Update()
{
	return 0;
}

void CHammer::Render(HDC hDC)
{
	MoveToEx(hDC, m_vPoint[0].x, m_vPoint[0].y, nullptr);

	D3DXVECTOR3 vHandPoint = m_pPlayer->Get_Info().vPos - m_vPoint[0];
	D3DXVec3Normalize(&vHandPoint, &vHandPoint);
	vHandPoint = (m_fHammer_Length * vHandPoint) + m_vPoint[0];

	LineTo(hDC, vHandPoint.x, vHandPoint.y);

	Ellipse(hDC, vHandPoint.x - 5, vHandPoint.y - 5, vHandPoint.x + 5, vHandPoint.y + 5);


	MoveToEx(hDC, m_vPoint[4].x, m_vPoint[4].y, nullptr);

	for (int i = 1; i < 5; ++i)
	{
		LineTo(hDC, m_vPoint[i].x, m_vPoint[i].y);
	}
}

void CHammer::Release()
{
}
