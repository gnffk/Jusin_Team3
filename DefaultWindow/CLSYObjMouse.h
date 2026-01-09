#pragma once
#include "CLSYObj.h"
#include "CLSYObjFruit.h"
class CLSYObjMouse final : public CLSYObj
{
public:
	CLSYObjMouse();
	~CLSYObjMouse() override;

public:
	void Set_TmpFruit(CLSYObjFruit* TmpFruit)
	{
		m_pTmpFruit = TmpFruit;
	}

public:
	void	Initialize()	override;
	int		Update()		override;
	int		Late_Update()	override;
	void	Render(HDC hDC)	override;
	void	Release()		override;

private:
	POINT m_ptBefore;
	POINT m_ptCurr;
	int m_iCnt;

	bool m_bMarking;


	CLSYObjFruit* m_pTmpFruit;
	
};

