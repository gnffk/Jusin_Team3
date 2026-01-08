#pragma once

#include "CScene.h"

class CSceneLSYTest final: public CScene
{
public:
	~CSceneLSYTest() override;

public:
	void	Initialize()	override;
	int		Update()		override;
	void	Late_Update()	override;
	void	Render(HDC hDC)	override;
	void	Release()		override;
};

