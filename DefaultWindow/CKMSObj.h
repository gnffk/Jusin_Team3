#pragma once
#include "CObj.h"
class CKMSObj : public CObj
{
public:
	CKMSObj();
	virtual ~CKMSObj();

public:
	float Get_Angle() { return m_fAngle; }

	void Set_ParentObject(CObj* m_fParentObject) {m_pParentObject = m_fParentObject;}
	CObj* Get_ParentObject() { return m_pParentObject; }

	void Set_Constraint(CObj* _Constraint) { m_pConstraint = _Constraint; }
	CObj* Get_Constraint() { return m_pConstraint; }

	void Add_SubObject(CObj* m_fPelvisObject) { m_vecSubObject.push_back(m_fPelvisObject); }


public:
	virtual void Key_Input() PURE;
protected:
	CObj* m_pParentObject;
	CObj* m_pConstraint;
	vector<CObj*>m_vecSubObject;

	float m_fAngle;
	D3DXVECTOR3	m_StartVector;
};

