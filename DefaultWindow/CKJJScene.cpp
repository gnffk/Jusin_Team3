#include "pch.h"
#include "CKJJScene.h"
#include "CAbstractFactory.h"
#include "CObjMgr.h"
#include "CKJJ_Player.h"

void CKJJScene::Initialize()
{
	CObj* pPlayer = CAbstractFactory<CKJJ_Player>::Create();
	CObjMgr::Get_Instance()->AddObject(OBJ_PLAYER, pPlayer);
}

int CKJJScene::Update()
{
	CObjMgr::Get_Instance()->Update();
	return 0;
}

void CKJJScene::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CKJJScene::Render(HDC hDC)
{
	CObjMgr::Get_Instance()->Render(hDC);
}

void CKJJScene::Release()
{
}
