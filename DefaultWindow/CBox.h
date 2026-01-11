#pragma once
#include "CKJJObj.h"
class CBox :
    public CKJJObj
{
public:
    CBox() {}
    virtual~CBox() {}
    // CKJJObj을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    int Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

    void Set_Angle(float Angle) { m_fAngle = Angle; }

    void Collision(CKJJObj* pObj, D3DXVECTOR3 Vec) override;
private:
};

