#include "pch.h"
#include "CLeftShose.h"

CLeftShose::CLeftShose()
{
}

CLeftShose::~CLeftShose()
{
}

void CLeftShose::Initialize()
{
	m_fAngle = 0.f;
	// 자기 자신 vertex

	m_vPoint[0] = { -25.f, +0.f, 0.f };
	m_vPoint[1] = { 50.f, +0.f, 0.f };
	m_vPoint[2] = { 50.f, +20.f, 0.f };
	m_vPoint[3] = { -25.f, 20.f, 0.f };
	m_vPoint[4] = { -25.f, +0.f, 0.f };

	m_OriginVector = { 0.f, 100.f, 0.f };

	for (int i = 0; i < 5; ++i)
		m_vOriginPoint[i] = m_vPoint[i];
}

int CLeftShose::Update()
{
	Key_Input();
	// 크 -> 자 -> 이 -> 공 -> 부
	D3DXMATRIX		matScale, matRotZ, matTrans, matParRotZ, matParMat;
	D3DXVECTOR3		VecParPos;
	float			ParAngle = 0;
	if (m_pParentObject) {

		matParMat = m_pParentObject->Get_Info().matWorld;
	}

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);

	D3DXMATRIX orbitXMat, orbitYMat, orbitZMat, orbitMat, orbitOffsetMat;


	D3DXMatrixTranslation(&orbitOffsetMat, m_OriginVector.x - m_tInfo.vPos.x,
		m_OriginVector.y - m_tInfo.vPos.y, m_OriginVector.z - m_tInfo.vPos.z);





	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);



	m_tInfo.matWorld = matScale * matRotZ * matTrans;
	m_tInfo.matWorld *= orbitOffsetMat * matParMat;

	for (int i = 0; i < 5; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];


		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);


	}

	if (m_pConstraint) {
		D3DXVECTOR3 Constraint_Pos = { 0.f,0.f,0.f };

		D3DXVec3TransformCoord(&(Constraint_Pos), &(Constraint_Pos), &m_tInfo.matWorld);

		dynamic_cast<CKMSObj*>(m_pConstraint)->Set_Pos(Constraint_Pos);
	}


	return 0;
}

int CLeftShose::Late_Update()
{
	return 0;
}

void CLeftShose::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);
	for (int i = 0; i < 5; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);

	}
}

void CLeftShose::Release()
{
}

void CLeftShose::Key_Input()
{
	
}
