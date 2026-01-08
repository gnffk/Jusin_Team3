#pragma once
#include "CKMSObj.h"
class CRightLeg : public CKMSObj
{
public:
	CRightLeg();
	virtual ~CRightLeg();

public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

