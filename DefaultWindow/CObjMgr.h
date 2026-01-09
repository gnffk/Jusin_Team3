#pragma once

#include "CObj.h"

class CObjMgr
{
private:
	CObjMgr();
	CObjMgr& operator=(CObjMgr&) = delete;
	CObjMgr(const CObjMgr& rhs) = delete;
	~CObjMgr();

public:
	CObj* Get_Target(OBJID eID, CObj* pObj);

public:
	void	AddObject(OBJID eID, CObj* pObj = nullptr);
	void	Update();
	void	Late_Update();
	void	Render(HDC hDC);
	void	Release();

	void	Delete_ID(OBJID eID);

public:
	static CObjMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CObjMgr;

		return m_pInstance;
	}
	
	static void		Destroy_Instacne()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

	list<CObj*>* Get_ObjList() { return m_ObjList; }
	list<CObj*>* Get_ObjList(OBJID eID) { return &m_ObjList[eID]; }

private:
	list<CObj*>	m_ObjList[OBJ_END];

	static CObjMgr*			m_pInstance;
};

