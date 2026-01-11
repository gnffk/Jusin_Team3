#pragma once
#include "CLSYObj.h"
class CLSYObjFruit final: public CLSYObj
{
public:
	enum FRUIT_OPT
	{
		FROPT_ARROW,
		//FROPT_JUSIN,
		FROPT_MS,
		FROPT_JJ,
		FROPT_SY,

		FROPT_TEST,

		FROPT_SCROLL_STAR,
		FROPT_SCROLL_CLOUD,

		FROPT_PART,
		FROPT_DRAW,
		FRUIT_OPT_END
	};
public:
	CLSYObjFruit();
	~CLSYObjFruit() override;

	bool Get_Cut()
	{
		return m_bCut;
	}
	void Set_Throw(bool bThrow)
	{
		m_bThrow = bThrow;
	}
	bool Get_Throw()
	{
		return m_bThrow;
	}

	void Set_ThrowAngle(float fTrhowAngle)
	{
		m_fThrowAngle = fTrhowAngle;
	}

	void Set_ThrowVelocityZero(float fVelocity)
	{
		m_fThrowVelocityZero = fVelocity;
	}

	void Set_Scroll(bool bScroll)
	{
		m_bScroll = bScroll;
	}

public:
	void GenerateVertexList();


	bool Slice(POINT& pt1, POINT& pt2);

public:
	void	Initialize()	override;
	int		Update()		override;
	int		Late_Update()	override;
	void	Render(HDC hDC)	override;
	void	Release()		override;

private:
	float m_fTimer;

	float m_fThrowAngle;

	float m_fThrowVelocityZero;

	bool m_bCut;


	bool m_bThrow;

	bool m_bScroll;

};

