#pragma once

#define		WINCX 800
#define		WINCY 600

#define		PURE = 0

#define		OBJ_NOEVENT 0
#define		OBJ_DEAD    1

#define		PI	3.141592f

#define		VK_MAX		0xff


enum OBJID { OBJ_PLAYER, OBJ_END };

enum SCENEID { SC_MENU,SC_STAGE, SC_END };

template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

struct tagObjDelete
{
	template<typename T>
	void operator()(T& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};


struct tagDeleteMap
{
	template<typename T>
	void operator()(T& pair)
	{
		if (pair.second)
		{
			delete pair.second;
			pair.second = nullptr;
		}
	}
};



struct tagFinder
{
	tagFinder(const TCHAR* pTag) : m_pTag(pTag) {}
	
	template<typename T>
	bool operator()(T& Pair)
	{
		return !lstrcmp(Pair.first, m_pTag);
	}


	const TCHAR* m_pTag;
};




typedef struct tagInfo
{
	D3DXVECTOR3		vPos;		// À§Ä¡ º¤ÅÍ
	D3DXVECTOR3		vDir;		// ¹æÇâ º¤ÅÍ

	D3DXVECTOR3		vLook;
	D3DXVECTOR3		vNormal;	// ¹ý¼± º¤ÅÍ

	D3DXMATRIX		matWorld;

}INFO;


typedef struct tagLinePoint
{
	float		fX;
	float		fY;

	tagLinePoint()	{ZeroMemory(this, sizeof(tagLinePoint));	}
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY) {}

}LINEPOINT;

typedef struct tagLine
{
	tagLinePoint		tLeft;
	tagLinePoint		tRight;

	tagLine() { ZeroMemory(this, sizeof(tagLine)); }
	tagLine(tagLinePoint _tLeft, tagLinePoint _tRight)
		: tLeft(_tLeft), tRight(_tRight) {}

}LINE;

typedef struct tagFrame
{
	int		iStart;
	int		iEnd;
	int		iMotion;
	DWORD	dwSpeed;
	DWORD	dwTime;

}FRAME;


extern HWND g_hWnd;