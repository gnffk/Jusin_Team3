#pragma once
#include "CKMSObj.h"

class CConstraint : public CKMSObj
{
public:
	CConstraint();
	virtual ~CConstraint();

public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Key_Input() override;

	void Set_Up(CObj* _up) { UpObject = _up; }
	void Set_Down(CObj* _down) { DownObject = _down; }
public:
	CObj* UpObject;
	CObj* DownObject;
};

