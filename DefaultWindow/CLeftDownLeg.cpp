#include "pch.h"
#include "CLeftDownLeg.h"

CLeftDownLeg::CLeftDownLeg()
{
}

CLeftDownLeg::~CLeftDownLeg()
{
}

void CLeftDownLeg::Initialize()
{
	m_fAngle = 0.f;
	// 자기 자신 vertex
	if (m_pParentObject) {

		m_tInfo.vPos = m_pParentObject->Get_Info().vPos;
	}
	m_vPoint[0] = { m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y , 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y , 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y + 80.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y + 80.f, 0.f };

	for (int i = 0; i < 4; ++i)
		m_vOriginPoint[i] = m_vPoint[i];
}

int CLeftDownLeg::Update()
{
	// 크 -> 자 -> 이 -> 공 -> 부
	D3DXMATRIX		matScale, matRotZ, matTrans, matParRotZ, matParMat;
	D3DXVECTOR3		VecParPos;
	float			ParAngle = 0;
	if (m_pParentObject) {
		m_tInfo.vPos = m_pParentObject->Get_Info().vPos;
		matParMat = m_pParentObject->Get_Info().matWorld;
		m_fAngle = dynamic_cast<CKMSObj*>(m_pParentObject)->Get_Angle();

	}

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);



	m_tInfo.matWorld = matScale * matRotZ * matTrans * matParMat;

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];
		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}
	return 0;
}

int CLeftDownLeg::Late_Update()
{
	return 0;
}

void CLeftDownLeg::Render(HDC hDC)
{
}

void CLeftDownLeg::Release()
{
}
