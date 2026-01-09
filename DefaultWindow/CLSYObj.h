#pragma once
#include "CObj.h"
#include "LSYDefine.h"
class CLSYObj :public CObj
{
public:
	CLSYObj():
		m_fAngle(0.f),
		m_iOption(0)
	{
		ZeroMemory(&m_tRect, sizeof(m_tRect));
		ZeroMemory(&m_tRectSides, sizeof(m_tRectSides));
	};

public:
	RECT& Get_Rect() { return m_tRect; }

	void Set_Angle(float fAngle) { m_fAngle = fAngle; }
	float Get_Angle() const { return m_fAngle; }

	list<list<D3DXVECTOR3>>& Get_VertexList() { return m_vertexList; }
	void Set_VertexList(list<list<D3DXVECTOR3>> list) { m_vertexList = list; }
	list<list<POINT>>& Get_PointList() { return m_pointList; }
	
	void Set_Pos(D3DXVECTOR3& pos) { m_tInfo.vPos = pos; }
	void Set_Dir(D3DXVECTOR3& dir) { m_tInfo.vDir = dir; }
	//void Set_WorldMat(D3DXMATRIX& matWorld) { m_tInfo.matWorld = matWorld; }

	void Set_Speed(float fSpeed) { m_fSpeed = fSpeed; }

	int Get_Option() const { return m_iOption; }
	void Set_Option(float iOption) { m_iOption = iOption; }

public:
	int Update() override;
	void Render(HDC hDC) override;

public:
	//void PhysicsUpdate();

protected:
	void Update_Rect();

protected:
	list<list<D3DXVECTOR3>> m_vertexList;
	list<list<POINT>> m_pointList;
	int m_iOption;
	float m_fAngle;

	bool m_bGravity;

	RECT m_tRect;
	POINT m_tRectSides;

	//D3DXVECTOR3 m_posRectOrigin;


};

