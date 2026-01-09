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

	CBox* pBox = new CBox;
	pBox->Set_Size(800, 100, 0);
	pBox->Set_Pos(400, 600, 0);
	pBox->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, pBox);
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
	CObjMgr::Get_Instance()->Late_Update();
}

void CKJJScene::Render(HDC hDC)
{
	CObjMgr::Get_Instance()->Render(hDC);
}

void CKJJScene::Release()
{
}
