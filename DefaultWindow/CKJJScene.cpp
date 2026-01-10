#include "pch.h"
#include "CKJJScene.h"
#include "CAbstractFactory.h"
#include "CObjMgr.h"
#include "CKJJ_Player.h"
#include "CBox.h"
#include "KJJ_CollisionMgr.h"

void CKJJScene::Initialize()
{
	CObj* pPlayer = new CKJJ_Player;
	pPlayer->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_PLAYER, pPlayer);

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
	CObjMgr::Get_Instance()->Update();
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
	CObjMgr::Get_Instance()->Render(hDC);
}

void CKJJScene::Release()
{
}
