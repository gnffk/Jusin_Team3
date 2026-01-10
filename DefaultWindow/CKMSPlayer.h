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

	void Set_CollisionLine(CObj* _pCollisionLine) { m_pCollisionLine = _pCollisionLine; };

public:
	CObj* m_pCollisionLine;
};

