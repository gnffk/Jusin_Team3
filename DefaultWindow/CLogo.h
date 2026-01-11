#pragma once
#include "CScene.h"
class CLogo :
    public CScene
{
public:
    CLogo();
    virtual~CLogo();
    // CScene을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

private:
    RECT rc[3];
    POINT size[3];
    POINT pt[3];
};

