#include "pch.h"
#include "CRightUpLeg.h"
#include "CKeyMgr.h"
#include "CPelvis.h"

CRightUpLeg::CRightUpLeg()
{
}

CRightUpLeg::~CRightUpLeg()
{
}

void CRightUpLeg::Initialize()
{
	m_fAngle = -0.5f;
	// 자기 자신 vertex
	if (m_pParentObject) {

		m_tInfo.vPos = m_pParentObject->Get_Info().vPos;
	}
	m_vPoint[0] = { -25.f, 0.f , 0.f };
	m_vPoint[1] = { +25.f, 0.f , 0.f };
	m_vPoint[2] = { +25.f, 0.f + 150.f, 0.f };
	m_vPoint[3] = { -25.f, 0.f + 150.f, 0.f };
	m_vPoint[4] = { -25.f, 0.f , 0.f };

	m_OriginVector = { m_tInfo.vPos.x,  m_tInfo.vPos.y , 0.f };
	for (int i = 0; i < 5; ++i)
		m_vOriginPoint[i] = m_vPoint[i];

}

int CRightUpLeg::Update()
{	// 크 -> 자 -> 이 -> 공 -> 부
	Key_Input();
	D3DXMATRIX		matScale, matRotZ, matTrans, matParMat;


	if (m_pParentObject) {

		matParMat = m_pParentObject->Get_Info().matWorld;
	}

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	m_tInfo.matWorld = matScale * matRotZ * matTrans * matParMat;
	

	for (int i = 0; i < 5; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);

	}

	
	if (m_pParentObject) {
		dynamic_cast<CPelvis*>(m_pParentObject)->Set_RightAngle(m_fAngle);
	}

	if (m_fAngle <= -1.2f) {
		m_fAngle = -1.2f;
		
	}
	else if (m_fAngle >= 1.2f) {
		m_fAngle = 1.2f;
		
	}

	return 0;
}

int CRightUpLeg::Late_Update()
{
	return 0;
}

void CRightUpLeg::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);
	for (int i = 0; i < 5; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);

	}
}

void CRightUpLeg::Release()
{
}

void CRightUpLeg::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('O')) {
		//cout << m_fAngle << endl;
		m_fAngle -= D3DXToRadian(1.f);

	
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('P')) {
		//cout << m_fAngle << endl;
		m_fAngle += D3DXToRadian(1.f);
		
	}
}

