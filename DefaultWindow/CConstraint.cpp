#include "pch.h"
#include "CConstraint.h"

CConstraint::CConstraint()
{
}

CConstraint::~CConstraint()
{
}

void CConstraint::Initialize()
{
}

int CConstraint::Update()
{
	D3DXMATRIX		matScale, matRotZ, matTrans, matParMat;


	if (m_pParentObject) {
		m_tInfo.vPos = m_pParentObject->Get_Info().vPos;
		matParMat = m_pParentObject->Get_Info().matWorld;
	}

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	m_tInfo.matWorld = matScale * matRotZ * matTrans * matParMat;

	return 0;
}

int CConstraint::Late_Update()
{
	return 0;
}

void CConstraint::Render(HDC hDC)
{
	
}

void CConstraint::Release()
{
}

void CConstraint::Key_Input()
{
}
