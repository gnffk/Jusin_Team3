#pragma once
#include "CKMSObj.h"
class CKMSBox : public CKMSObj
{
public:
	CKMSBox();
	virtual ~CKMSBox();

public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Key_Input() override;
};

