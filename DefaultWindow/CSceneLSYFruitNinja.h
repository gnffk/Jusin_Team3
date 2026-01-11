#pragma once
#include "CScene.h"
#include "CLSYObjMouse.h"
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
	void SpawnThrow();
	void SpawnScroll();

private:
	float m_fThrowSpawnTimer;
	float m_fScrollSpawnTimer;

	CLSYObjMouse* m_pMouse;

	float m_fEndSceneTimer;
	bool m_bEnd;
};

