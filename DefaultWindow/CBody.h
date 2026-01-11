#pragma once
#include "CKMSObj.h"

class CBody : public CKMSObj
{
public:
	CBody();
	virtual ~CBody();
public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Key_Input() override;
};

