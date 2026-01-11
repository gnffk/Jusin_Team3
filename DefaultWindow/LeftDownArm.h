#pragma once
#include "CKMSObj.h"
class LeftDownArm : public CKMSObj
{
public:
	LeftDownArm();
	virtual ~LeftDownArm();

public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Key_Input() override;
};

