#pragma once
#include "CKMSObj.h"
class CRightUpLeg : public CKMSObj
{
public:
	CRightUpLeg();
	virtual ~CRightUpLeg();

public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	
public:
	void Key_Input() override;

};

