#include "pch.h"
#include "CConstraint.h"

CConstraint::CConstraint() : m_pUpObject(nullptr), m_pDownObject(nullptr), m_bVisible(true)
{
}

CConstraint::~CConstraint()
{
}

void CConstraint::Initialize()
{
	m_StartVector = { 0.f,0.f,0.f };
	m_fMax_Angle = 0.f;
	m_fMin_Angle = 0.f;
}

int CConstraint::Update()
{
	D3DXMATRIX		matScale, matRotZ, matTrans, matParMat;

	if (m_pUpObject) {
		if (m_fMax_Angle < dynamic_cast<CKMSObj*>(m_pUpObject)->Get_Angle()) {
			dynamic_cast<CKMSObj*>(m_pUpObject)->Set_Angle(m_fMax_Angle);
		}
	}

	//if (m_pParentObject) {
	//	m_tInfo.vPos = m_pParentObject->Get_Info().vPos + m_StartVector;
	//	matParMat = m_pParentObject->Get_Info().matWorld;
	//}

	//D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	//D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	//D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	//m_tInfo.matWorld = matScale * matRotZ * matTrans * matParMat;

	return 0;
}

int CConstraint::Late_Update()
{
	return 0;
}

void CConstraint::Render(HDC hDC)
{
	if (m_bVisible) {

		Ellipse(hDC, m_tInfo.vPos.x-25, m_tInfo.vPos.y - 25, m_tInfo.vPos.x+25, m_tInfo.vPos.y+25);
	}
}

void CConstraint::Release()
{
}

void CConstraint::Key_Input()
{
}
