#pragma once
#include "CKMSObj.h"

class CKMSPlayer : public CKMSObj
{
public:
	CKMSPlayer();
	virtual ~CKMSPlayer();

public:
	void Initialize() override;

	int Update() override;

	int Late_Update() override;

	void Render(HDC hDC) override;
	
	void Release() override;

public:
	void Key_Input() override;

	void Add_Point();

	void Set_CollisionLine(CObj* _pCollisionLine) { m_pCollisionLine = _pCollisionLine; };

	void Set_Gravity(bool _bGravity) { m_bGravity = _bGravity; }

	D3DXVECTOR3 Get_PrevPos() { return m_prePos; }
public:
	CObj* m_pCollisionLine;

	bool m_bGravity;

	D3DXVECTOR3 m_prePos;
};

