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

	void Set_StartPos(D3DXVECTOR3 _StartVector) { m_StartVector = _StartVector; }

	void Set_Pos(D3DXVECTOR3 _Vector) { m_tInfo.vPos = _Vector; }

public:
	virtual void Key_Input() PURE;
protected:
	CObj* m_pParentObject;
	CObj* m_pConstraint;
	vector<CObj*>m_vecSubObject;

	float m_fAngle;
	D3DXVECTOR3	m_StartVector;
	D3DXVECTOR3	m_OriginVector;
};

