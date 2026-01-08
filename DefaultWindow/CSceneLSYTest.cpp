#include "pch.h"
#include "CSceneLsyTest.h"
#include "CObjMgr.h"
#include "CLSYObjFruit.h"
#include "CAbstractFactory.h"
#include "CDeltaMgr.h"

CSceneLSYTest::~CSceneLSYTest()
{
	Release();
}

void CSceneLSYTest::Initialize()
{
	CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());
	pFruit->Set_Option(CLSYObjFruit::FROPT_TEST);
	pFruit->GenerateVertexList();
	CObjMgr::Get_Instance()->AddObject(OBJ_FRUIT, pFruit);
}

int CSceneLSYTest::Update()
{
	CObjMgr::Get_Instance()->Update();
	return 0;
}

void CSceneLSYTest::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CSceneLSYTest::Render(HDC hDC)
{
	CObjMgr::Get_Instance()->Render(hDC);
}

void CSceneLSYTest::Release()
{
}
