#pragma once
#include "CScene.h"
#include "CLSYObjFruit.h"

class CSceneLSYLineEidt final: public CScene
{
public:
	CSceneLSYLineEidt();
	~CSceneLSYLineEidt() override;

public:
	void	Initialize()	override;
	int		Update()		override;
	void	Late_Update()	override;
	void	Render(HDC hDC)	override;
	void	Release()		override;

private:
	CLSYObjFruit* m_pFruit;

	bool m_bGrid;

	POINT m_ptMouseOver;

	POINT m_ptSelectBefore;
	POINT m_ptSelectCurrent;
	bool m_bFirstSelect;

	list<pair<POINT, POINT>> m_selectPtList;
};

