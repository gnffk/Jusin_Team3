#include "pch.h"
#include "CLeftUpLeg.h"
#include "CKeyMgr.h"

CLeftUpLeg::CLeftUpLeg()
{
}

CLeftUpLeg::~CLeftUpLeg()
{
}

void CLeftUpLeg::Initialize()
{
	m_fAngle = 0.f;
	// 자기 자신 vertex
	if (m_pParentObject) {

		m_tInfo.vPos = m_pParentObject->Get_Info().vPos;
	}
	m_vPoint[0] = { m_tInfo.vPos.x - 25.f, m_tInfo.vPos.y , 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 25.f, m_tInfo.vPos.y , 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 25.f, m_tInfo.vPos.y + 150.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 25.f, m_tInfo.vPos.y + 150.f, 0.f };
	m_vPoint[4] = { m_tInfo.vPos.x - 25.f, m_tInfo.vPos.y , 0.f };

	for (int i = 0; i < 5; ++i)
		m_vOriginPoint[i] = m_vPoint[i];
}

int CLeftUpLeg::Update()
{
	// 크 -> 자 -> 이 -> 공 -> 부
	Key_Input();
	D3DXMATRIX		matScale, matRotZ, matTrans, matParMat;


	if (m_pParentObject) {

		matParMat = m_pParentObject->Get_Info().matWorld;
	}

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);



	m_tInfo.matWorld = matScale * matRotZ * matTrans *  matParMat;

	for (int i = 0; i < 5; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		
		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	
	}
	return 0;
}

int CLeftUpLeg::Late_Update()
{
	return 0;
}

void CLeftUpLeg::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y,nullptr);
	for (int i = 0; i < 5; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);

	}
}

void CLeftUpLeg::Release()
{
}


void CLeftUpLeg::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('Q')) {
		cout << m_fAngle << endl;
		m_fAngle -= D3DXToRadian(3.f);
	}
}
