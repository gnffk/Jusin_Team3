#pragma once
#include "CObj.h"
class CKMSObj : public CObj
{
public:
	CKMSObj();
	virtual ~CKMSObj();

public:
	void Set_ParentObject(CObj* m_fParentObject) {m_pParentObject = m_fParentObject;}
	void Add_SubObject(CObj* m_fPelvisObject) { m_vecSubObject.push_back(m_fPelvisObject); }

protected:
	CObj* m_pParentObject;
	vector<CObj*>m_vecSubObject;

};

