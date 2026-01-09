#pragma once
#include "CKMSObj.h"
class CLeftUpLeg : public CKMSObj
{
public:
	CLeftUpLeg();
	virtual ~CLeftUpLeg();

public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
public:
	void Key_Input() override;


};

