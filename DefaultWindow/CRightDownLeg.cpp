#include "pch.h"
#include "CRightDownLeg.h"
#include "CKeyMgr.h"
#include "CScrollMgr.h"

CRightDownLeg::CRightDownLeg()
{
}

CRightDownLeg::~CRightDownLeg()
{
}

void CRightDownLeg::Initialize()
{
	m_fArm = nullptr;
	m_fAngle = +0.5f;
	// 자기 자신 vertex

	m_vPoint[0] = { -25.f, +0.f, 0.f };
	m_vPoint[1] = { +25.f, +0.f, 0.f };
	m_vPoint[2] = { +25.f, +100.f, 0.f };
	m_vPoint[3] = { -25.f, +100.f, 0.f };
	m_vPoint[4] = { -25.f, +0.f, 0.f };

	m_OriginVector = { 0.f,   150.f, 0.f };

	for (int i = 0; i < 5; ++i)
		m_vOriginPoint[i] = m_vPoint[i];
}

int CRightDownLeg::Update()
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


	//cout << m_fAngle << endl;


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
	if (m_fAngle > 1.2f) {
		m_fAngle = 1.2f;
	}
	if (m_fAngle < 0.f) {
		m_fAngle = 0.f;
	}

	if (m_fArm) {
		dynamic_cast<CKMSObj*>(m_fArm)->Set_Angle(m_fAngle);
	}
	return 0;
}

int CRightDownLeg::Late_Update()
{
	return 0;
}

void CRightDownLeg::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	MoveToEx(hDC, (int)m_vPoint[0].x + iScrollX, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 5; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x + iScrollX, (int)m_vPoint[i].y);

	}
}

void CRightDownLeg::Release()
{
}

void CRightDownLeg::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('P')) {
		//cout << m_fAngle << endl;
		m_fAngle += D3DXToRadian(3.f);
	
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('O')) {
		//cout << m_fAngle << endl;
		m_fAngle -= D3DXToRadian(3.f);
		
	}
}
