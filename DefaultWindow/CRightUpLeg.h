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
private:
	D3DXVECTOR3		m_vPoint[5];
	D3DXVECTOR3		m_vOriginPoint[5];
};

