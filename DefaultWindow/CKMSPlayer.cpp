#include "pch.h"
#include "CKMSPlayer.h"
#include "CKeyMgr.h"

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
	m_tInfo.vPos = { 400.f, 350.f, 0.f };

	m_tInfo.vLook = { 0.f, -1.f, 0.f };
	m_fAngle = 0.f;
	m_fSpeed = 2.f;

}

int CKMSPlayer::Update()
{
	Key_Input();


	for (auto iter : m_vecSubObject) {
		iter->Update();
	}

	return OBJ_NOEVENT;
}

int CKMSPlayer::Late_Update()
{
	for (auto iter : m_vecSubObject) {
		iter->Late_Update();
	}

	return 0;
}

void CKMSPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tInfo.vPos.x - 10, m_tInfo.vPos.y - 10, m_tInfo.vPos.x + 10, m_tInfo.vPos.y + 10);
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
	if (CKeyMgr::Get_Instance()->Key_Pressing('Q')) {
		m_fAngle -= D3DXToRadian(3.f);
	}
	
	if (CKeyMgr::Get_Instance()->Key_Pressing('W')) {
		m_fAngle += D3DXToRadian(3.f);
	}



	if (GetAsyncKeyState(VK_UP))
	{
		//m_tInfo.vDir.x = m_tInfo.vLook.x * cosf(m_fAngle) - m_tInfo.vLook.y * sinf(m_fAngle);
		//m_tInfo.vDir.y = m_tInfo.vLook.x * sinf(m_fAngle) + m_tInfo.vLook.y * cosf(m_fAngle);

		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);

		m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		//m_tInfo.vDir.x = m_tInfo.vLook.x * cosf(m_fAngle) - m_tInfo.vLook.y * sinf(m_fAngle);
		//m_tInfo.vDir.y = m_tInfo.vLook.x * sinf(m_fAngle) + m_tInfo.vLook.y * cosf(m_fAngle);

		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);

		m_tInfo.vPos -= m_tInfo.vDir * m_fSpeed;
	}
}

