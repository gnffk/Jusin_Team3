#include "pch.h"
#include "CSceneMgr.h"
#include "CMenu.h"
#include "CKJJScene.h"
#include "CKMSScene.h"
#include "CSceneLSYTest.h"

CSceneMgr* CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr() : m_pScene(nullptr), m_ePreScene(SC_END), m_eCurScene(SC_MINSU)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change(SCENEID eID)
{
	m_eCurScene = eID;

	if (m_ePreScene != m_eCurScene)	// 씬 변경이 가능
	{
		Safe_Delete(m_pScene);

		switch (m_eCurScene)
		{
		case SC_MENU:
			m_pScene = new CMenu;

			break;

		case SC_STAGE:
		
			break;

		case SC_LSY_TEST:
			m_pScene = new CSceneLSYTest;
			break;

		case SC_KJJ:

			m_pScene = new CKJJScene;
			break;
		case SC_MINSU:
			m_pScene = new CKMSScene;
			break;
		}

		m_pScene->Initialize();
		m_ePreScene = m_eCurScene;
	}

}

void CSceneMgr::Update()
{
	m_pScene->Update();
}

void CSceneMgr::Late_Update()
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
}
