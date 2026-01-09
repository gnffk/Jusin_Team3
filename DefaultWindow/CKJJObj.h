#pragma once
#include "CObj.h"
class CKJJObj :
    public CObj
{
    // CObj을(를) 통해 상속됨
public:
	CKJJObj();
	virtual~CKJJObj() {}
public:
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual int		Late_Update()	PURE;
	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;

	virtual void	Collision(CKJJObj* pObj) PURE;

	void Set_Pos(float x, float y, float z)
	{
		m_tInfo.vPos.x = x;
		m_tInfo.vPos.y = y;
		m_tInfo.vPos.z = z;
	}
	void Set_Pos(D3DXVECTOR3 Pos) { m_tInfo.vPos = Pos; }

	void Set_Size(float x, float y, float z)
	{
		m_vSize.x = x;
		m_vSize.y = y;
		m_vSize.z = z;
	}
	void Set_Size(D3DXVECTOR3 Size) { m_vSize = Size; }	
	D3DXVECTOR3 Get_Size() { return m_vSize; }

	void Set_Scale(float x, float y, float z)
	{
		m_vScale.x = x;
		m_vScale.y = y;
		m_vScale.z = z;
	}
	void Set_Scale(D3DXVECTOR3 Scale) { m_vScale = Scale; }
	D3DXVECTOR3 Get_Scale() { return m_vScale; }

	D3DXVECTOR3 Get_Point(int Num) { return m_vPoint[Num]; }
	D3DXVECTOR3 Get_AxisX() { return m_vAxisX; }
	D3DXVECTOR3 Get_AxisY() { return m_vAxisY; }

	void Set_Angle(float Angle) { m_fAngle = Angle; }
	float Get_Angle() { return m_fAngle; }

protected:
	float m_fAngle;
	D3DXVECTOR3 m_vSize;
	D3DXVECTOR3 m_vAxisX, m_vAxisY;
	D3DXVECTOR3 m_vScale;
	D3DXVECTOR3 m_vPoint[4], m_vOriginPoint[4];
};