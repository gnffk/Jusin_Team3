#include "pch.h"
#include "CKJJScene.h"
#include "CAbstractFactory.h"
#include "CObjMgr.h"
#include "CKJJ_Player.h"
#include "CBox.h"
#include "KJJ_CollisionMgr.h"
#include "CSceneMgr.h"
#include "KJJ_CheckPoint.h"	
#include "CBmpMgr.h"

void CKJJScene::Initialize()
{
	CObjMgr::Get_Instance()->Release();
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Mario.bmp", L"Mario");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Jar.bmp", L"Jar");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/KJJBack.bmp", L"KJJBack");

	CObj* pPlayer = new CKJJ_Player;
	pPlayer->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_PLAYER, pPlayer);

	CObj* pCheckPoint = new KJJ_CheckPoint;
	pCheckPoint->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, pCheckPoint);

	CBox* pFloor = new CBox;
	pFloor->Set_Size(600, 100, 0);
	pFloor->Set_Pos(300, 550, 0);
	pFloor->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pFloor));

	CBox* pWall = new CBox;
	pWall->Set_Size(100, 1200, 0);
	pWall->Set_Pos(0, 300, 0);
	pWall->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pWall));
	
	CBox* pBox[8];
	for (int i = 0; i < 8; ++i)
	{
		pBox[i] = new CBox;
		pBox[i]->Set_Size((8 - i) * 50, 50, 0);
		pBox[i]->Set_Pos(600 - (8 - i) * 25, 475 - 50 * i, 0);
		pBox[i]->Initialize();
		CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pBox[i]));
	}
}

int CKJJScene::Update()
{
	//system("cls");
	CObjMgr::Get_Instance()->Update();
	if (CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER)->size() == 0)
	{
		CObjMgr::Get_Instance()->Delete_ID(OBJ_BOX);
		CSceneMgr::Get_Instance()->Scene_Change(SC_KJJ2);
	}
	return 0;
}

void CKJJScene::Late_Update()
{
	KJJ_CollisionMgr::OBB_Collision(
		*CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER),
		*CObjMgr::Get_Instance()->Get_ObjList(OBJ_BOX));

	KJJ_CollisionMgr::OBB_Collision(
		*CObjMgr::Get_Instance()->Get_ObjList(OBJ_HAMMER),
		*CObjMgr::Get_Instance()->Get_ObjList(OBJ_BOX));

	CObjMgr::Get_Instance()->Late_Update();
}

void CKJJScene::Render(HDC hDC)
{
	BitBlt(hDC,
		0, 0,
		800, 600,
		CBmpMgr::Get_Instance()->Find_Image(L"KJJBack"),
		0, 0,
		SRCCOPY);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CKJJScene::Release()
{
}
