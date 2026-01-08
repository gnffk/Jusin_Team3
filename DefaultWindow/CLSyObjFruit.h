#pragma once
#include "CLSYObj.h"
class CLSYObjFruit final: public CLSYObj
{
public:
	enum FRUIT_OPT
	{
		FROPT_TEST,
		FRUIT_OPT_END
	};
public:
	~CLSYObjFruit() override;

public:
	void GenerateVertexList();

public:
	void	Initialize()	override;
	int		Update()		override;
	int		Late_Update()	override;
	void	Render(HDC hDC)	override;
	void	Release()		override;
};

