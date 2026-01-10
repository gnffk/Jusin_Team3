#include "pch.h"
#include "CKMSScene.h"
#include "CAbstractFactory.h"
#include "CPelvis.h"
#include "CKMSPlayer.h"
#include "CObjMgr.h"

#include "CLeftUpLeg.h"
#include "CLeftDownLeg.h"
#include "CConstraint.h"
#include "CLeftShose.h"
#include "CRightUpLeg.h"
#include "CRightDownLeg.h"
#include "CRightShose.h"
#include "CKMSLine.h"
#include "CKMSCollisionMgr.h"

CKMSScene::CKMSScene()
{
}

CKMSScene::~CKMSScene()
{
}

void CKMSScene::Initialize()
{
    p_Line = CAbstractFactory<CKMSLine>::Create();
	CObjMgr::Get_Instance()->AddObject(OBJ_RUNLINE, p_Line);

	CObj* p_Player = CAbstractFactory<CKMSPlayer>::Create();
	CObjMgr::Get_Instance()->AddObject(OBJ_PLAYER,p_Player);
	dynamic_cast<CKMSPlayer*>(p_Player)->Set_CollisionLine(p_Line);

	CObj* p_Pelvis = CAbstractFactory<CPelvis>::Create();
	dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_Pelvis);
	dynamic_cast<CKMSObj*>(p_Pelvis)->Set_ParentObject(p_Player);
	// Left Leg
	{
		// Left Up Leg
		CObj* p_LeftUpLeg = CAbstractFactory<CLeftUpLeg>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_LeftUpLeg);
		dynamic_cast<CKMSObj*>(p_LeftUpLeg)->Set_ParentObject(p_Pelvis);


		// Left Down Leg
		CObj* p_LeftDownLeg = CAbstractFactory<CLeftDownLeg>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_LeftDownLeg);
		dynamic_cast<CKMSObj*>(p_LeftDownLeg)->Set_ParentObject(p_LeftUpLeg);

		// Left Shose
		p_LeftShose = CAbstractFactory<CLeftShose>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_LeftShose);
		dynamic_cast<CKMSObj*>(p_LeftShose)->Set_ParentObject(p_LeftDownLeg);
		dynamic_cast<CKMSObj*>(p_LeftShose)->Set_RootObject(p_Player);

		// Constraint - Left Up  <-> Left Down
		CObj* p_LeftUpDownConstraint = CAbstractFactory<CConstraint>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_LeftUpDownConstraint);
		dynamic_cast<CKMSObj*>(p_LeftDownLeg)->Set_Constraint(p_LeftUpDownConstraint);
		dynamic_cast<CKMSObj*>(p_LeftUpDownConstraint)->Set_ParentObject(p_Player);
		dynamic_cast<CConstraint*>(p_LeftUpDownConstraint)->Set_Up(p_LeftUpLeg);
		dynamic_cast<CConstraint*>(p_LeftUpDownConstraint)->Set_Down(p_LeftDownLeg);

		dynamic_cast<CConstraint*>(p_LeftUpDownConstraint)->Set_MaxAngle(1.2f);
		dynamic_cast<CConstraint*>(p_LeftUpDownConstraint)->Set_MinAngle(0.f);

		// Constraint - Left Down  <-> Left Shose
		CObj* p_LeftDownShoseConstraint = CAbstractFactory<CConstraint>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_LeftDownShoseConstraint);
		dynamic_cast<CKMSObj*>(p_LeftShose)->Set_Constraint(p_LeftDownShoseConstraint);
		dynamic_cast<CKMSObj*>(p_LeftDownShoseConstraint)->Set_ParentObject(p_Player);
		dynamic_cast<CConstraint*>(p_LeftDownShoseConstraint)->Set_Up(p_LeftDownLeg);
		dynamic_cast<CConstraint*>(p_LeftDownShoseConstraint)->Set_Down(p_LeftShose);
		dynamic_cast<CConstraint*>(p_LeftDownShoseConstraint)->Set_Visible(false);
		dynamic_cast<CConstraint*>(p_LeftDownShoseConstraint)->Set_MaxAngle(1.2f);
		dynamic_cast<CConstraint*>(p_LeftDownShoseConstraint)->Set_MinAngle(0.f);

	}
	
	// Right Leg
	{
		// Right Up Leg
		CObj* p_RightUpLeg = CAbstractFactory<CRightUpLeg>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_RightUpLeg);
		dynamic_cast<CKMSObj*>(p_RightUpLeg)->Set_ParentObject(p_Pelvis);


		// Right Down Leg
		CObj* p_RightDownLeg = CAbstractFactory<CRightDownLeg>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_RightDownLeg);
		dynamic_cast<CKMSObj*>(p_RightDownLeg)->Set_ParentObject(p_RightUpLeg);

		// Right Shose
		CObj* p_RightShose = CAbstractFactory<CRightShose>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_RightShose);
		dynamic_cast<CKMSObj*>(p_RightShose)->Set_ParentObject(p_RightDownLeg);
		dynamic_cast<CKMSObj*>(p_RightShose)->Set_RootObject(p_Player);

		// Constraint - Right Up  <-> Right Down
		CObj* p_RightUpDownConstraint = CAbstractFactory<CConstraint>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_RightUpDownConstraint);
		dynamic_cast<CKMSObj*>(p_RightDownLeg)->Set_Constraint(p_RightUpDownConstraint);
		dynamic_cast<CKMSObj*>(p_RightUpDownConstraint)->Set_ParentObject(p_Player);
		dynamic_cast<CConstraint*>(p_RightUpDownConstraint)->Set_Up(p_RightUpLeg);
		dynamic_cast<CConstraint*>(p_RightUpDownConstraint)->Set_Down(p_RightDownLeg);
		dynamic_cast<CConstraint*>(p_RightUpDownConstraint)->Set_MaxAngle(1.2f);
		dynamic_cast<CConstraint*>(p_RightUpDownConstraint)->Set_MinAngle(0.f);

		// Constraint - Right Down  <-> Right Shose
		CObj* p_RightDownShoseConstraint = CAbstractFactory<CConstraint>::Create();
		dynamic_cast<CKMSObj*>(p_Player)->Add_SubObject(p_RightDownShoseConstraint);
		dynamic_cast<CKMSObj*>(p_RightShose)->Set_Constraint(p_RightDownShoseConstraint);
		dynamic_cast<CKMSObj*>(p_RightDownShoseConstraint)->Set_ParentObject(p_Player);
		dynamic_cast<CConstraint*>(p_RightDownShoseConstraint)->Set_Up(p_RightDownLeg);
		dynamic_cast<CConstraint*>(p_RightDownShoseConstraint)->Set_Down(p_RightShose);
		dynamic_cast<CConstraint*>(p_RightDownShoseConstraint)->Set_Visible(false);
		dynamic_cast<CConstraint*>(p_RightDownShoseConstraint)->Set_MaxAngle(1.2f);
		dynamic_cast<CConstraint*>(p_RightDownShoseConstraint)->Set_MinAngle(0.f);
	}
	
	p_Player->Initialize();



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
