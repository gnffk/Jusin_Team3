#include "pch.h"
#include "CKJJScene.h"
#include "CAbstractFactory.h"
#include "CObjMgr.h"
#include "CKJJ_Player.h"
#include "CBox.h"

void CKJJScene::Initialize()
{
	CObj* pPlayer = new CKJJ_Player;
	CObjMgr::Get_Instance()->AddObject(OBJ_PLAYER, pPlayer);

	CObj* pBox = new CBox;

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
