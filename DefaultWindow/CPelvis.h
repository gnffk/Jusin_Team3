#pragma once
#include "CKMSPlayer.h"
class CPelvis : public CKMSObj
{
public:
	CPelvis();
	virtual ~CPelvis();

public:
	void Initialize() override;

	int Update() override;

	int Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

public:
	void Key_Input() override;

};

