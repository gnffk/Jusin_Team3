#include "pch.h"
#include "CSceneLSYFruitNinja.h"
#include "CObjMgr.h"
#include "CLSYObjFruit.h"
#include "CAbstractFactory.h"
#include "CLSYObjMouse.h"
#include "CKeyMgr.h"
#include "CDeltaMgr.h"
#include "CSceneMgr.h"

CSceneLSYFruitNinja::CSceneLSYFruitNinja():
	m_fThrowSpawnTimer(0.f),
	m_fScrollSpawnTimer(0.f),
	m_fEndSceneTimer(0.f),
	m_pMouse(nullptr),
	m_bEnd(false)
{
}

CSceneLSYFruitNinja::~CSceneLSYFruitNinja()
{
	Release();
}

void CSceneLSYFruitNinja::Initialize()
{
	CObjMgr::Get_Instance()->Release();
	CLSYObjMouse* pMouse = dynamic_cast<CLSYObjMouse*>(CAbstractFactory<CLSYObjMouse>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJ_LSY_MOUSE, pMouse);
	m_pMouse = pMouse;
}

int CSceneLSYFruitNinja::Update()
{
	if (!m_bEnd)
	{
		m_fThrowSpawnTimer += CDeltaMgr::Get_Instance()->Get_Delta();
		m_fScrollSpawnTimer += CDeltaMgr::Get_Instance()->Get_Delta();

		CObjMgr::Get_Instance()->Update();

		if (m_fThrowSpawnTimer > 0.4f)
		{
			m_fThrowSpawnTimer = 0.f;

			SpawnThrow();
		}

		if (m_fScrollSpawnTimer > 0.7f)
		{
			m_fScrollSpawnTimer = 0.f;

			SpawnScroll();
		}

		if (CKeyMgr::Get_Instance()->Key_Down('T'))
		{
			SpawnThrow();
		}

		if (m_pMouse->Get_Count() >= 20)
		{
			m_pMouse->Scene_End();
			m_bEnd = true;
		}
	}
	else
	{
		m_fScrollSpawnTimer += CDeltaMgr::Get_Instance()->Get_Delta();
		m_fEndSceneTimer += CDeltaMgr::Get_Instance()->Get_Delta();
		CObjMgr::Get_Instance()->Update();

		if (m_fScrollSpawnTimer > 0.7f)
		{
			m_fScrollSpawnTimer = 0.f;

			//SpawnScroll();
		}

		if (m_fEndSceneTimer > 3.f)
		{
			CSceneMgr::Get_Instance()->Scene_Change(SC_MINSU);
		}
	}
	
	return 0;
}

void CSceneLSYFruitNinja::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CSceneLSYFruitNinja::Render(HDC hDC)
{
	CObjMgr::Get_Instance()->Render(hDC);
}

void CSceneLSYFruitNinja::Release()
{
	//CObjMgr::Get_Instance()->Delete_ID(OBJ_LSY_MOUSE);
	//CObjMgr::Get_Instance()->Delete_ID(OBJ_LSY_FRUIT);
	CObjMgr::Get_Instance()->Release();
}

void CSceneLSYFruitNinja::SpawnThrow()
{
	CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());

	int r = rand();
	int opt = r % (CLSYObjFruit::FROPT_TEST + 1);
	pFruit->Set_Option(opt);

	pFruit->GenerateVertexList();
	pFruit->Set_Throw(true);


	CObjMgr::Get_Instance()->AddObject(OBJ_LSY_FRUIT, pFruit);
	if (rand() % 2)
	{
		D3DXVECTOR3 pos{ 0.f, WINCY, 0.f };
		pFruit->Set_Pos(pos);
		pFruit->Set_ThrowAngle(60.f);
	}
	else
	{
		D3DXVECTOR3 pos{ WINCX, WINCY, 0.f };
		pFruit->Set_Pos(pos);
		pFruit->Set_ThrowAngle(120.f);
	}
}



void CSceneLSYFruitNinja::SpawnScroll()
{
	CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());

	if (rand() % 2)
	{
		pFruit->Set_Option(CLSYObjFruit::FROPT_SCROLL_STAR);
	}
	else
	{
		pFruit->Set_Option(CLSYObjFruit::FROPT_SCROLL_CLOUD);
	}
	
	pFruit->GenerateVertexList();
	pFruit->Set_Scroll(true);
	int randX = rand() % WINCX;
	D3DXVECTOR3 pos{ (float)randX, WINCY, 0.f};
	pFruit->Set_Pos(pos);
	CObjMgr::Get_Instance()->AddObject(OBJ_LSY_FRUIT, pFruit);
	
	//if (rand() % 2)
	//{
	//	D3DXVECTOR3 pos{ 0.f, WINCY, 0.f };
	//	pFruit->Set_Pos(pos);
	//	pFruit->Set_ThrowAngle(60.f);
	//}
	//else
	//{
	//	D3DXVECTOR3 pos{ WINCX, WINCY, 0.f };
	//	pFruit->Set_Pos(pos);
	//	pFruit->Set_ThrowAngle(120.f);
	//}
}