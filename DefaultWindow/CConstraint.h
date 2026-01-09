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
};

