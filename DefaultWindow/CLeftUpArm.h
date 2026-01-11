#pragma once
#include "CKMSObj.h"
class CLeftUpArm : public CKMSObj
{
public:
	CLeftUpArm();
	virtual ~CLeftUpArm();

public:


	void Initialize() override;

	int Update() override;

	int Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void Key_Input() override;

};

