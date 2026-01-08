#pragma once
#include "CKMSObj.h"

class CKMSPlayer : public CKMSObj
{
public:
	CKMSPlayer();
	virtual ~CKMSPlayer();

public:
	void Initialize() override;

	int Update() override;

	int Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;
};

