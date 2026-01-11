#include "pch.h"
#include "CKJJScene2.h"
#include "CAbstractFactory.h"
#include "CObjMgr.h"
#include "CKJJ_Player.h"
#include "CBox.h"
#include "KJJ_CollisionMgr.h"
#include "CSceneMgr.h"
#include "KJJ_CheckPoint.h"	
#include "CBmpMgr.h"

CKJJScene2::CKJJScene2()
{
}

CKJJScene2::~CKJJScene2()
{
}

void CKJJScene2::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Mario.bmp", L"Mario");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Jar.bmp", L"Jar");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/KJJBack.bmp", L"KJJBack");

	CObj* pPlayer = new CKJJ_Player;
	pPlayer->Initialize();

	CObj* pCheckPoint = new KJJ_CheckPoint;
	static_cast<CKJJObj*>(pCheckPoint)->Set_Pos(pPlayer->Get_Info().vPos);
	pCheckPoint->Initialize();

	CObjMgr::Get_Instance()->AddObject(OBJ_PLAYER, pPlayer);
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, pCheckPoint);


	CBox* pFloor = new CBox;
	pFloor->Set_Size(700, 100, 0);
	pFloor->Set_Pos(350, 550, 0);
	pFloor->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pFloor));

	CBox* pWall = new CBox;
	pWall->Set_Size(100, 600, 0);
	pWall->Set_Pos(0, 300, 0);
	pWall->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pWall));

	CBox* pWall2 = new CBox;
	pWall2->Set_Size(30, 400, 0);
	pWall2->Set_Pos(250, 200, 0);
	pWall2->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pWall2));

	CBox* pWall3 = new CBox;
	pWall3->Set_Size(30, 400, 0);
	pWall3->Set_Pos(700, 400, 0);
	pWall3->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pWall3));

	CBox* pBox1 = new CBox;
	pBox1->Set_Size(50, 50, 0);
	pBox1->Set_Pos(690, 475, 0);
	pBox1->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pBox1));

	CBox* pBox2 = new CBox;
	pBox2->Set_Size(350, 30, 0);
	pBox2->Set_Pos(450, 380, 0);
	pBox2->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pBox2));

	CBox* pBox3 = new CBox;
	pBox3->Set_Size(370, 50, 0);
	pBox3->Set_Angle(-12.f);
	pBox3->Set_Pos(520, 230, 0);
	pBox3->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pBox3));

	CBox* pBox4 = new CBox;
	pBox4->Set_Size(50, 50, 0);
	pBox4->Set_Pos(280, 340, 0);
	pBox4->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pBox4));
	
	CBox* pBox5 = new CBox;
	pBox5->Set_Size(250, 30, 0);
	pBox5->Set_Pos(580, 200, 0);
	pBox5->Initialize();
	CObjMgr::Get_Instance()->AddObject(OBJ_BOX, static_cast<CObj*>(pBox5));
}

int CKJJScene2::Update()
{
	//system("cls");
	CObjMgr::Get_Instance()->Update();

	if (CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER)->size() == 0)
	{
		CObjMgr::Get_Instance()->Delete_ID(OBJ_BOX);
		CSceneMgr::Get_Instance()->Scene_Change(SC_LSY_FRUIT_NINJA);
	}
    return 0;
}

void CKJJScene2::Late_Update()
{
	KJJ_CollisionMgr::OBB_Collision(
		*CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER),
		*CObjMgr::Get_Instance()->Get_ObjList(OBJ_BOX));

	KJJ_CollisionMgr::OBB_Collision(
		*CObjMgr::Get_Instance()->Get_ObjList(OBJ_HAMMER),
		*CObjMgr::Get_Instance()->Get_ObjList(OBJ_BOX));

	CObjMgr::Get_Instance()->Late_Update();
}

void CKJJScene2::Render(HDC hDC)
{
	CObjMgr::Get_Instance()->Render(hDC);
}

void CKJJScene2::Release()
{
}
