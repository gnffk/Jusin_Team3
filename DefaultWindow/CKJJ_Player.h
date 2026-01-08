#pragma once

#include "CKJJObj.h"

class CKJJ_Player :
    public CKJJObj
{
public:
    CKJJ_Player();
    virtual~CKJJ_Player();
    // CKJJObj을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    int Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

private:
    float m_fHand_Distance;
    float m_fAngle;

    CObj* m_pHammer;

    D3DXVECTOR3 m_vPoint[4], m_vOriginPoint[4];
    D3DXVECTOR3 m_vHandPoint, m_vOriginHandPoint;
};

