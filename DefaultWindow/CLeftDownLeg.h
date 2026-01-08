#pragma once
#include "CKMSObj.h"
class CLeftDownLeg : public CKMSObj
{
public:
	CLeftDownLeg();
	virtual ~CLeftDownLeg();

public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
public:
	void Key_Input();
private:
	D3DXVECTOR3		m_vPoint[5];
	D3DXVECTOR3		m_vOriginPoint[5];


};

