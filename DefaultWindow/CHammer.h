#pragma once
#include "CKJJObj.h"
#include "CKJJ_Player.h"

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

    void Set_Player(CKJJ_Player* pPlayer) { m_pPlayer = pPlayer; }
    void Collision(CKJJObj* pObj, D3DXVECTOR3 Vec) override;

private:
    float m_fHead_Distance;
    float m_fHammer_Length;
    float m_fPlayerAngle;

    bool m_bIs_Col;
    bool m_bClockWise;
    bool m_bColDir;

    CKJJ_Player* m_pPlayer;

    D3DXVECTOR3 m_vPrevMouse, m_vCurrMouse;
};

