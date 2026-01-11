#pragma once
#include "CScene.h"
class CKJJScene2 :
    public CScene
{
public:
    CKJJScene2();
    virtual~CKJJScene2();

    // CScene을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
};

