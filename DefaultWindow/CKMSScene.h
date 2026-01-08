#pragma once
#include "CScene.h"

class CKMSScene : public CScene
{
public:
	CKMSScene();
	virtual ~CKMSScene();
public:
	
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

public:

};

