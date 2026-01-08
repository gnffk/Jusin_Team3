#pragma once

#include "Define.h"


class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize();
	void	Update();
	void	Late_Update();
	void	Render();
	void	Release();

private:
	HDC			m_hDC;




	RECT _rect;
	HDC _hdcBack{};
	HBITMAP _bmpBack{};


	TCHAR		m_szFPS[128];
	int			m_iFPS;
	DWORD		m_dwTime;


};
