#include "pch.h"
#include "CHead.h"
#include "CScrollMgr.h"

CHead::CHead()
{
}

CHead::~CHead()
{
}

void CHead::Initialize()
{
	m_fAngle = 0.f;
	m_eKMSObjType = KMSOBJ_HEAD;
	m_vPoint[0] = { -25.f, -25.f, 0.f };
	m_vPoint[1] = { 25.f, -25.f, 0.f };
	m_vPoint[2] = { 25.f, +25.f, 0.f };
	m_vPoint[3] = { -25.f, 25.f, 0.f };
	m_vPoint[4] = { -25.f, -25.f, 0.f };

	m_OriginVector = { 0.f, -105.f, 0.f };


	for (int i = 0; i < 5; ++i)
		m_vOriginPoint[i] = m_vPoint[i];
}

int CHead::Update()
{
	D3DXMATRIX		matScale, matRotZ, matTrans, matParRotZ, matParMat;
	D3DXVECTOR3		VecParPos;

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
    return 0;
}

int CHead::Late_Update()
{
    return 0;
}

void CHead::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	MoveToEx(hDC, (int)m_vPoint[0].x + iScrollX, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 5; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x + iScrollX, (int)m_vPoint[i].y);

	}
}

void CHead::Release()
{
}

void CHead::Key_Input()
{
}
