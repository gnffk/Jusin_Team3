#include "pch.h"
#include "KJJ_CheckPoint.h"
#include "CBmpMgr.h"

KJJ_CheckPoint::KJJ_CheckPoint()
{
    m_bStart = false;
    m_fWeight = -2.f;

    m_vSize = { 21.f, 25.f, 0.f };
    m_tInfo.vPos = { 140.f, 400.f, 0.f };
    m_vScale = { 1.f,1.f,1.f };

    m_vPoint[0] = { -m_vSize.x / 2.f, -m_vSize.y / 2.f, 0.f };
    m_vPoint[1] = { m_vSize.x / 2.f, -m_vSize.y / 2.f, 0.f };
    m_vPoint[2] = { m_vSize.x / 2.f, m_vSize.y / 2.f, 0.f };
    m_vPoint[3] = { -m_vSize.x / 2.f, m_vSize.y / 2.f, 0.f };

    m_vAxisX = { m_vSize.x / 2.f,0.f,0.f };
    m_vAxisY = { 0.f,-m_vSize.y / 2.f, 0.f };

    CKJJObj::Update_matWorld();

    for (int i = 0; i < 4; ++i)
    {
        m_vOriginPoint[i] = m_vPoint[i];
        D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
    }

}

void KJJ_CheckPoint::Initialize()
{

}

int KJJ_CheckPoint::Update()
{
    if (m_bStart)
    {
        return OBJ_DEAD;
    }
    return 0;
}

int KJJ_CheckPoint::Late_Update()
{
    return 0;
}

void KJJ_CheckPoint::Render(HDC hDC)
{
    HDC Jar = CBmpMgr::Get_Instance()->Find_Image(L"Jar");

    GdiTransparentBlt(hDC,
        m_vPoint[0].x, m_vPoint[0].y,
        42, 25,
        Jar,
        0, 0,
        12, 7,
        RGB(89, 186, 255));
}

void KJJ_CheckPoint::Release()
{
}

void KJJ_CheckPoint::Collision(CKJJObj* pObj, D3DXVECTOR3 Vec)
{
    m_bStart = true;
}
