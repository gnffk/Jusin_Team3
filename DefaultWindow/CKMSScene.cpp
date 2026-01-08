#include "pch.h"
#include "CKMSScene.h"
#include "CAbstractFactory.h"
#include "CPelvis.h"
#include "CKMSPlayer.h"
#include "CObjMgr.h"

CKMSScene::CKMSScene()
{
}

CKMSScene::~CKMSScene()
{
}

void CKMSScene::Initialize()
{
	CObj* p_Player = CAbstractFactory<CKMSPlayer>::Create();
	CObjMgr::Get_Instance()->AddObject(OBJ_PLAYER,p_Player);

	CObj* p_Pelvis = CAbstractFactory<CPelvis>::Create();
	dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_Pelvis);
	dynamic_cast<CKMSObj*>(p_Pelvis)->Set_ParentObject(p_Player);


}

int CKMSScene::Update()
{
	CObjMgr::Get_Instance()->Update();

	return 0;
}

void CKMSScene::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CKMSScene::Render(HDC hDC)
{
	CObjMgr::Get_Instance()->Render(hDC);
}

void CKMSScene::Release()
{
	CObjMgr::Get_Instance()->Release();
}
