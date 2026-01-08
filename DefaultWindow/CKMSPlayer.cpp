#include "pch.h"
#include "CKMSPlayer.h"

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
	m_tInfo.vPos = { 0.f, 0.f, 0.f };

	m_tInfo.vLook = { 0.f, 1.f, 0.f };
}

int CKMSPlayer::Update()
{
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
	Rectangle(hDC, 0, 0, 100, 100);
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

