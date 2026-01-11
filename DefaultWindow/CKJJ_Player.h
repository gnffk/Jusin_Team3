#pragma once

#include "CKJJObj.h"
#define DEBUG false

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
    void Collision(CKJJObj* pObj, D3DXVECTOR3 Vec) override;

    void Set_Falling(bool state) { bIs_falling = state; }

private:
    CObj* m_pHammer;
    bool bIs_falling;
    bool m_bStart;
    bool m_bEnd;
};