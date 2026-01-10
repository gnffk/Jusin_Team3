#pragma once
#include "CKMSPlayer.h"
class CPelvis : public CKMSObj
{
public:
	CPelvis();
	virtual ~CPelvis();

public:
	void Initialize() override;

	int Update() override;

	int Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

public:
	void Key_Input() override;

	void Set_RightAngle(float _fRightAngle) { m_fRightAngle = _fRightAngle; };
	void Set_LeftAngle(float _fLeftAngle) { m_fLeftAngle = _fLeftAngle; }
	void Set_SubAngle(float _fSubAngle) { m_fdisAngle += _fSubAngle; }

public:
	float m_fRightAngle;
	float m_fLeftAngle;
	float m_fdisAngle;
};

