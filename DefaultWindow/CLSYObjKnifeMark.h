#pragma once
#include "CLSYObj.h"
class CLSYObjKnifeMark final : public CLSYObj
{
public:
	CLSYObjKnifeMark();
	~CLSYObjKnifeMark() override;

public:
	void	Initialize()	override;
	int		Update()		override;
	int		Late_Update()	override;
	void	Render(HDC hDC)	override;
	void	Release()		override;

private:
	float m_fDeathTimer;
};

