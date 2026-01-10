#include "pch.h"
#include "CPelvis.h"
#include "CKMSObj.h"

CPelvis::CPelvis()
{
}

CPelvis::~CPelvis()
{
}

void CPelvis::Initialize()
{
	m_fdisAngle = 0.f;
	m_fAngle = 0.f;
	// 자기 자신 vertex
	if (m_pParentObject) {

		m_tInfo.vPos = m_pParentObject->Get_Info().vPos;
	}
	m_vPoint[0] = { - 25.f, - 10.f, 0.f };
	m_vPoint[1] = { + 25.f, - 10.f, 0.f };
	m_vPoint[2] = { + 25.f, + 30.f, 0.f };
	m_vPoint[3] = { - 25.f, + 30.f, 0.f };
	m_vPoint[4] = { - 25.f, - 10.f, 0.f };

	for (int i = 0; i < 5; ++i)
		m_vOriginPoint[i] = m_vPoint[i];

}

int CPelvis::Update()
{
	// 크 -> 자 -> 이 -> 공 -> 부
	D3DXMATRIX		matScale, matRotZ, matTrans, matParRotZ, matParMat;
	D3DXVECTOR3		VecParPos;
	float			ParAngle = 0;
	if (m_pParentObject) {
	
		matParMat = m_pParentObject->Get_Info().matWorld;
		m_fAngle = dynamic_cast<CKMSObj*>(m_pParentObject)->Get_Angle();
		m_fAngle += m_fLeftAngle + m_fRightAngle + m_fdisAngle;
	}

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x,m_tInfo.vPos.y,m_tInfo.vPos.z);
	
	//cout << "RightAngle :" << m_fRightAngle << " LeftAngle :" << m_fLeftAngle << endl;
	cout << "Angle : " << m_fAngle << endl;
	
	m_tInfo.matWorld = matScale * matRotZ * matTrans  * matParMat;

	for (int i = 0; i < 5; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}


	/*if (m_pParentObject) {
		dynamic_cast<CKMSObj*>(m_pParentObject)->Set_Angle(m_fAngle);
	}*/

	return 0;
}

int CPelvis::Late_Update()
{
	return 0;
}

void CPelvis::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);
	for (int i = 0; i < 5; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);
	}

}

void CPelvis::Release()
{
}

void CPelvis::Key_Input()
{
}


