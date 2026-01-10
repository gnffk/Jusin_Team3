#pragma once
#include "CScene.h"
class CSceneLSYFruitNinja final: public CScene
{
public:
	CSceneLSYFruitNinja();
	~CSceneLSYFruitNinja() override;

public:
	void	Initialize()	override;
	int		Update()		override;
	void	Late_Update()	override;
	void	Render(HDC hDC)	override;
	void	Release()		override;

private:
	void Spawn();

private:
	float m_fSpawnTimer;
};

