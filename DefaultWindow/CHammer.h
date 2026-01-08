#pragma once
#include "CKJJObj.h"

class CHammer :
    public CKJJObj
{
public:
    CHammer();
    virtual~CHammer();
    // CKJJObj을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    int Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

    void Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }

private:
    float m_fAngle;
    float m_fHead_Distance;
    float m_fHammer_Length;

    CObj* m_pPlayer;

    D3DXVECTOR3 m_vPrevMouse, m_vCurrMouse;
    D3DXVECTOR3 m_vPoint[5], m_vOriginPoint[5];
};

