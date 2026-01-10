#pragma once
#include "CLSYObj.h"
class CLSYObjFruit final: public CLSYObj
{
public:
	enum FRUIT_OPT
	{
		FROPT_TEST,
		FROPT_PART,
		FRUIT_OPT_END
	};
public:
	CLSYObjFruit();
	~CLSYObjFruit() override;

	bool Get_Cut()
	{
		return m_bCut;
	}

public:
	void GenerateVertexList();

	bool CalcKnifeMark(POINT& pt1, POINT& pt2);

public:
	void	Initialize()	override;
	int		Update()		override;
	int		Late_Update()	override;
	void	Render(HDC hDC)	override;
	void	Release()		override;

private:
	float m_fTimer;

	bool m_bCut;

	bool m_bDead;
};

