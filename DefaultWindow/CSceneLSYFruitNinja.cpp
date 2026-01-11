#include "pch.h"
#include "CSceneLSYFruitNinja.h"
#include "CObjMgr.h"
#include "CLSYObjFruit.h"
#include "CAbstractFactory.h"
#include "CLSYObjMouse.h"
#include "CKeyMgr.h"
#include "CDeltaMgr.h"

CSceneLSYFruitNinja::CSceneLSYFruitNinja():
	m_fSpawnTimer(0.f)
{
}

CSceneLSYFruitNinja::~CSceneLSYFruitNinja()
{
	Release();
}

void CSceneLSYFruitNinja::Initialize()
{
	CLSYObjMouse* pMouse = dynamic_cast<CLSYObjMouse*>(CAbstractFactory<CLSYObjMouse>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJ_LSY_MOUSE, pMouse);
}

int CSceneLSYFruitNinja::Update()
{
	m_fSpawnTimer += CDeltaMgr::Get_Instance()->Get_Delta();
	CObjMgr::Get_Instance()->Update();

	if (m_fSpawnTimer > 0.4f)
	{
		m_fSpawnTimer = 0.f;

		Spawn();
	}

	if (CKeyMgr::Get_Instance()->Key_Down('T'))
	{
		Spawn();
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
}

void CSceneLSYFruitNinja::Spawn()
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
