#include "pch.h"
#include "CLSYObjKnifeMark.h"
#include "CDeltaMgr.h"

CLSYObjKnifeMark::CLSYObjKnifeMark():
	m_fDeathTimer(0.f)
{
}

CLSYObjKnifeMark::~CLSYObjKnifeMark()
{
}

void CLSYObjKnifeMark::Initialize()
{
	//Get_VertexList().push_back({
	//	{-5.f, -10.f, 0.f},
	//	{5.f, -10.f, 0.f},
	//	{5.f, 10.f, 0.f},
	//	{-5.f, 10.f, 0.f},
	//	{-5.f, -10.f, 0.f}
	//	});

	m_tInfo.vLook = { 0.f, -1.f, 0.f };
}

int CLSYObjKnifeMark::Update()
{
	m_fDeathTimer += CDeltaMgr::Get_Instance()->Get_Delta();
	if (m_fDeathTimer > 0.5f)
	{
		return OBJ_DEAD;
	}
	CLSYObj::Update();
	
    return OBJ_NOEVENT;
}

int CLSYObjKnifeMark::Late_Update()
{
    return OBJ_NOEVENT;
}

void CLSYObjKnifeMark::Render(HDC hDC)
{
	CLSYObj::Render(hDC);
}

void CLSYObjKnifeMark::Release()
{
}
