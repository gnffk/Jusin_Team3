#pragma once
#include "CKMSObj.h"
class CHead : public CKMSObj
{
public:
	CHead();
	virtual ~CHead();

public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Key_Input() override;
};

