#pragma once

#define		WINCX 800
#define		WINCY 600

#define		PURE = 0

#define		OBJ_NOEVENT 0
#define		OBJ_DEAD    1

#define		PI	3.141592f

#define		VK_MAX		0xff


// 2601081647 김종진 망치머리 추가
enum OBJID
{
	OBJ_PLAYER,
	OBJ_HAMMER,
	OBJ_FRUIT,
	OBJ_RUNLINE,
	OBJ_END
};

// 2601081647 김종진 씬아이디 추가
//enum SCENEID { SC_MENU,SC_STAGE,SC_KJJ, SC_END };
enum SCENEID
{
	SC_MENU,
	SC_STAGE,
	SC_MINSU,
	SC_KJJ,
	SC_LSY_TEST,
	SC_END
};

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
	D3DXVECTOR3		vPos;		// 위치 벡터
	D3DXVECTOR3		vDir;		// 방향 벡터

	D3DXVECTOR3		vLook;
	D3DXVECTOR3		vNormal;	// 법선 벡터

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

// 2601081425 KJJ 마우스 위치 좌표 함수 추가
static D3DXVECTOR3		Get_Mouse()
{
	POINT		ptMouse{};
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	return { (float)ptMouse.x, (float)ptMouse.y, 0.f };
}