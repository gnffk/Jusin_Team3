#pragma once
#include "CKMSObj.h"
class CRightDownArm : public CKMSObj
{
public:
	CRightDownArm();
	virtual ~CRightDownArm();

public:
	void Initialize() override;

	int Update() override;

	int Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void Key_Input() override;

};

