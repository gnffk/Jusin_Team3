#pragma once
#include "CObj.h"
class CKMSObj : public CObj
{

public:
	CKMSObj();
	virtual ~CKMSObj();
	
public:
	void Set_RootObject(CObj* _pRoot) { RootObj = _pRoot; }
	CObj* Get_RootObject() {return RootObj; }

	void Set_ParentObject(CObj* m_fParentObject) {m_pParentObject = m_fParentObject;}
	CObj* Get_ParentObject() { return m_pParentObject; }

	void Set_Constraint(CObj* _Constraint) { m_pConstraint = _Constraint; }
	CObj* Get_Constraint() { return m_pConstraint; }

	void Add_SubObject(CObj* m_fPelvisObject) { m_vecSubObject.push_back(m_fPelvisObject); }

	void Set_StartPos(D3DXVECTOR3 _StartVector) { m_StartVector = _StartVector; }

	void Set_Pos(D3DXVECTOR3 _Vector) { m_tInfo.vPos = _Vector; }
	void Set_PlusPos(D3DXVECTOR3 _Vector) { m_tInfo.vPos += _Vector; }

	vector<D3DXVECTOR3> Get_Point() { return m_vPoint; }

	float Get_Angle() { return m_fAngle; }
	void Plus_Angle(float _Angle) { m_fAngle += _Angle; }
	void Set_Angle(float _Angle) { m_fAngle = _Angle; }

	KMSOBJTYPE GetKMSObjType() { return m_eKMSObjType; }
public:
	virtual void Key_Input() PURE;
protected:
	CObj* m_pParentObject;
	CObj* m_pConstraint;
	vector<CObj*>m_vecSubObject;
	vector<D3DXVECTOR3>m_vPoint;
	vector<D3DXVECTOR3>m_vOriginPoint;


	float m_fAngle;
	float m_fGravity;
	D3DXVECTOR3	m_StartVector;
	D3DXVECTOR3	m_OriginVector;

	KMSOBJTYPE m_eKMSObjType;

	CObj* RootObj;
};

