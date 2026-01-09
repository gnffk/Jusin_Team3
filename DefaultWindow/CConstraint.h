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

	void Set_Up(CObj* _up) { m_pUpObject = _up; }
	void Set_Down(CObj* _down) { m_pDownObject = _down; }

	void Set_Visible(bool _bVisilbe) { m_bVisible = _bVisilbe; }
public:
	CObj* m_pUpObject;
	CObj* m_pDownObject;

	bool  m_bVisible;
};

