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

	void Set_MaxAngle(float _MaxAngle) { m_fMax_Angle = _MaxAngle; }
	void Set_MinAngle(float _MinAngle) { m_fMin_Angle = _MinAngle; }

	void Set_Size(D3DXVECTOR3 _Size) { m_Size = _Size; }
public:
	CObj* m_pUpObject;
	CObj* m_pDownObject;

	float m_fMax_Angle;
	float m_fMin_Angle;
	bool  m_bVisible;

	D3DXVECTOR3 m_Size;
};

