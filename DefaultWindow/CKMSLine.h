#pragma once
#include "CKMSObj.h"
class CKMSLine : public CKMSObj
{
public:
	CKMSLine();
	virtual ~CKMSLine();

public:
	void Initialize() override;
	int Update() override;
	int Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Key_Input() override;

public:
	D3DXVECTOR3 Get_RightVector() { return m_RightVector; }
	D3DXVECTOR3 Get_UpVector() { return m_UpVector; }
private:
	D3DXVECTOR3 m_UpVector;
	D3DXVECTOR3 m_RightVector;
};

