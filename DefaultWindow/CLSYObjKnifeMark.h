#pragma once
#include "CLSYObj.h"
class CLSYObjKnifeMark final : public CLSYObj
{
public:
	CLSYObjKnifeMark();
	~CLSYObjKnifeMark() override;

public:
	void Set_EndPt(POINT ptEnd)
	{
		m_ptEnd = ptEnd;
	}

public:
	void	Initialize()	override;
	int		Update()		override;
	int		Late_Update()	override;
	void	Render(HDC hDC)	override;
	void	Release()		override;

public:
	void Slicing(POINT& ptMouse, int* plusCnt, int* minusCnt);
	void Reset();

private:
	float m_fDeathTimer;

	POINT m_ptEnd;

	bool m_bThick;
	bool m_bRewind;
};

