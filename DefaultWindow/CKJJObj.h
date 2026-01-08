#pragma once
#include "CObj.h"
class CKJJObj :
    public CObj
{
    // CObj을(를) 통해 상속됨
public:
	CKJJObj() { ZeroMemory(&m_tRect, sizeof(RECT)); }
	virtual~CKJJObj() {}
public:
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual int		Late_Update()	PURE;
	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;

protected:

	RECT			m_tRect;
};