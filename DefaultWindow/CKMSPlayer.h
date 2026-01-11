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
	void Set_RightIs(bool _bRight) { m_bRightIs = _bRight; }
	void Set_LeftIs(bool _bLeft) { m_bLeftIs = _bLeft; }
	void Set_AngleIs(bool _bAngle) { m_bAngleIs = _bAngle; }


	D3DXVECTOR3 Get_PrevPos() { return m_prePos; }
public:
	CObj* m_pCollisionLine;

	bool m_bGravity;

	D3DXVECTOR3 m_prePos;

	bool m_bRightIs;
	bool m_bLeftIs;
	bool m_bAngleIs;
	
};

