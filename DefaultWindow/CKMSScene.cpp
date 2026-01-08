#include "pch.h"
#include "CKMSScene.h"
#include "CAbstractFactory.h"
#include "CPelvis.h"
#include "CKMSPlayer.h"
#include "CObjMgr.h"

#include "CLeftUpLeg.h"
#include "CLeftDownLeg.h"

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

	// Left Leg
	CObj* p_LeftUpLeg = CAbstractFactory<CLeftUpLeg>::Create();
	dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_LeftUpLeg);
	dynamic_cast<CKMSObj*>(p_LeftUpLeg)->Set_ParentObject(p_Pelvis);
	p_LeftUpLeg->Initialize();

	//CObj* p_LeftDownLeg = CAbstractFactory<CPelvis>::Create();
	//dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_LeftDownLeg);
	//dynamic_cast<CKMSObj*>(p_LeftDownLeg)->Set_ParentObject(p_LeftUpLeg);



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
