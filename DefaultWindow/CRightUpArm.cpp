#include "pch.h"
#include "CRightUpArm.h"
#include "CScrollMgr.h"

CRightUpArm::CRightUpArm()
{
}

CRightUpArm::~CRightUpArm()
{
}

void CRightUpArm::Initialize()
{
	m_fAngle = 0.f;
	m_eKMSObjType = KMSOBJ_BODY;
	m_vPoint[0] = { -15.f, 0.f, 0.f };
	m_vPoint[1] = { 15.f, 0.f, 0.f };
	m_vPoint[2] = { 15.f, 100.f, 0.f };
	m_vPoint[3] = { -15.f, 100.f, 0.f };
	m_vPoint[4] = { -15.f, -0.f, 0.f };

	m_OriginVector = { 0.f, -50.f, 0.f };

	for (int i = 0; i < 5; ++i)
		m_vOriginPoint[i] = m_vPoint[i];
}

int CRightUpArm::Update()
{
	D3DXMATRIX		matScale, matRotZ, matTrans, matParRotZ, matParMat;
	D3DXVECTOR3		VecParPos;
	float			ParAngle = 0;
	if (m_pParentObject) {

		matParMat = m_pParentObject->Get_Info().matWorld;
	}

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, -m_fAngle);

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
	return 0;
}

int CRightUpArm::Late_Update()
{
	return 0;
}

void CRightUpArm::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	MoveToEx(hDC, (int)m_vPoint[0].x + iScrollX, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 5; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x + iScrollX, (int)m_vPoint[i].y);

	}
}

void CRightUpArm::Release()
{
}

void CRightUpArm::Key_Input()
{
}
