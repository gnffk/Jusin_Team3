#include "pch.h"
#include "CBox.h"

void CBox::Initialize()
{
    m_vPoint[0] = { -m_vSize.x / 2.f, -m_vSize.y / 2.f, 0.f };
    m_vPoint[1] = { m_vSize.x / 2.f, -m_vSize.y / 2.f, 0.f };
    m_vPoint[2] = { m_vSize.x / 2.f, m_vSize.y / 2.f, 0.f };
    m_vPoint[3] = { -m_vSize.x / 2.f, m_vSize.y / 2.f, 0.f };

    m_vAxisX = { m_vSize.x/2.f,0.f,0.f };
    m_vAxisY = { 0.f,-m_vSize.y/2.f, 0.f };

    for (int i = 0; i < 4; ++i)
    {
        m_vOriginPoint[i] = m_vPoint[i];
    }

    CKJJObj::Update_matWorld();

    //D3DXMATRIX		matScale, matRotZ, matTrans;

    //float fRadian = D3DXToRadian(m_fAngle);

    //D3DXMatrixScaling(&matScale,
    //    m_vScale.x,
    //    m_vScale.y,
    //    m_vScale.z);
    //D3DXMatrixRotationZ(&matRotZ, fRadian);
    //D3DXMatrixTranslation(&matTrans,
    //    m_tInfo.vPos.x,
    //    m_tInfo.vPos.y,
    //    m_tInfo.vPos.z);
    //
    //m_tInfo.matWorld = matScale * matRotZ * matTrans;


    for (int i = 0; i < 4; ++i)
    {
        D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
    }
}

int CBox::Update()
{
    return 0;
}

int CBox::Late_Update()
{
    return 0;
}

void CBox::Render(HDC hDC)
{
    MoveToEx(hDC, m_vPoint[3].x, m_vPoint[3].y, nullptr);

    for (int i = 0; i < 4; ++i)
    {
        LineTo(hDC, m_vPoint[i].x, m_vPoint[i].y);
    }

}

void CBox::Release()
{
}

void CBox::Collision(CKJJObj* pObj, D3DXVECTOR3 Vec)
{
    cout << "Ãæ?" << endl;
}

