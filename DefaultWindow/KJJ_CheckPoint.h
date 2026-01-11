#pragma once
#include "CKJJObj.h"
class KJJ_CheckPoint :
    public CKJJObj
{
public:
    KJJ_CheckPoint();
    virtual~KJJ_CheckPoint() {}
    // CKJJObj을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    int Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
    void Collision(CKJJObj* pObj, D3DXVECTOR3 Vec) override;

private:
    bool m_bStart;
};

