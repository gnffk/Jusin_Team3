#include "pch.h"
#include "CKMSPlayer.h"
#include "CKeyMgr.h"
#include "CKMSCollisionMgr.h"
#include "CScrollMgr.h"

CKMSPlayer::CKMSPlayer() // 얜 부모
{
	m_vecSubObject.reserve(1);
}

CKMSPlayer::~CKMSPlayer()
{
}

void CKMSPlayer::Initialize()
{
	
	// 크 -> 자 -> 이 -> 공 -> 부
	// 월드 좌표계 차이
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_prePos = { 400.f, 300.f, 0.f };

	m_tInfo.vLook = { 0.f, -1.f, 0.f };
	m_fAngle = 0.f;
	m_fSpeed = 2.f;
	m_bGravity = true;

	m_fAngle = 0.f;

	m_bRightIs= false;
	m_bLeftIs= false;	
	m_bAngleIs= false;
	/*m_bRightIs= true;
	m_bLeftIs=  true;	
	m_bAngleIs= true;*/

}

int CKMSPlayer::Update()
{
	


	D3DXVECTOR3 Dis = m_prePos - m_tInfo.vPos;

	m_prePos = m_tInfo.vPos;
	
	m_fPrevAngle = m_fAngle;
	Key_Input();

	// 크 -> 자 -> 이 -> 공 -> 부
	D3DXMATRIX		matScale, matRotZ, matTrans, matParRotZ, matParMat;
	D3DXVECTOR3		VecParPos;
	float			ParAngle = 0;

	 



	m_tInfo.vDir.y = m_tInfo.vLook.x * sinf(m_fAngle) + m_tInfo.vLook.y * cosf(m_fAngle);
	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);


	
	// 만약에 모두가 true 이면 실행 X
	if (!m_bLeftIs || !m_bRightIs || !m_bAngleIs) {
		m_tInfo.vPos.y -= m_tInfo.vDir.y * m_fGravity * 0.7f;
	}
	//m_tInfo.vPos -= Dis/10;
	//cout << "Pos x : " << m_tInfo.vPos.x << " Pos y : " << m_tInfo.vPos.y << endl;
	//cout << "Angle : " << m_fAngle << endl;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);



	m_tInfo.matWorld = matScale * matRotZ * matTrans;


	for (auto iter : m_vecSubObject) {

		iter->Update();

		CKMSCollisionMgr::CheckLine(iter, m_pCollisionLine);
	}

	cout << "Prev.x : " << m_prePos.x<< " Cur.x" << m_tInfo.vPos.x<< endl;
	cout << "차이값 : " << Dis.x << endl;
	CScrollMgr::Get_Instance()->Set_ScrollX(Dis.x);

	return OBJ_NOEVENT;
}

int CKMSPlayer::Late_Update()
{
	for (auto iter : m_vecSubObject) {
		iter->Late_Update();
		
	}

	for (auto iter : m_vecSubObject) {
		if (CKMSCollisionMgr::CheckCorrect(iter, m_pCollisionLine)) {
			Update();
		}

	}

	
	return 0;
}

void CKMSPlayer::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	Rectangle(hDC, m_tInfo.vPos.x - 10 + iScrollX, m_tInfo.vPos.y - 10, m_tInfo.vPos.x + 10 + iScrollX, m_tInfo.vPos.y + 10);
	for (auto iter : m_vecSubObject) {
		
		iter->Render(hDC);
	}

}

void CKMSPlayer::Release()
{
	for (auto iter : m_vecSubObject) {
		iter->Release();
	}
}

void CKMSPlayer::Key_Input()
{
	//if (CKeyMgr::Get_Instance()->Key_Pressing('Q')|| CKeyMgr::Get_Instance()->Key_Pressing('O')) {
	//	m_fAngle -= D3DXToRadian(1.f);
	//}
	//
	//if (CKeyMgr::Get_Instance()->Key_Pressing('W')|| CKeyMgr::Get_Instance()->Key_Pressing('P')) {
	//	m_fAngle += D3DXToRadian(1.f);
	//}

	if (CKeyMgr::Get_Instance()->Key_Pressing('R')) {
		m_tInfo.vPos = { 400.f, 300.f, 0.f };

		m_tInfo.vLook = { 0.f, -1.f, 0.f };
		m_fAngle = 0.f;
		m_fSpeed = 2.f;
	}


	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.vDir.x = m_tInfo.vLook.x * cosf(m_fAngle) - m_tInfo.vLook.y * sinf(m_fAngle) * -1;
		m_tInfo.vDir.y = m_tInfo.vLook.x * sinf(m_fAngle) + m_tInfo.vLook.y * cosf(m_fAngle);

		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);

		m_tInfo.vPos -= m_tInfo.vDir * m_fSpeed;
	}
}


void CKMSPlayer::Add_Point() {
	m_tInfo.vDir.x = m_tInfo.vLook.x * cosf(m_fAngle) - m_tInfo.vLook.y * sinf(m_fAngle) ;
	m_tInfo.vDir.y = m_tInfo.vLook.x * sinf(m_fAngle) + m_tInfo.vLook.y * cosf(m_fAngle);
	//cout << "Dir x : " << m_tInfo.vDir.x << " Dir y : " << m_tInfo.vDir.y << endl;
	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);

	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed * 10;
}