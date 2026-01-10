#pragma once
// CObj.h입니다. 허허 ^^
// 안농
#include "Define.h"

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	INFO			Get_Info() { return m_tInfo; }

	float	Get_Speed() { return m_fSpeed; }

public:
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual int		Late_Update()		PURE;
	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;

protected:
	INFO		m_tInfo;

	float		m_fSpeed;
};


