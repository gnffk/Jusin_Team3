#include "pch.h"
#include "CKMSObj.h"

CKMSObj::CKMSObj() : m_pParentObject(nullptr), m_fGravity(9.8f)
{
	m_fArm = nullptr;
	m_vecSubObject.reserve(20);
	m_vPoint.resize(10);
	m_vOriginPoint.resize(10);
	m_eKMSObjType = KMSOBJ_NONE;
	m_fPrevAngle = 0;
}

CKMSObj::~CKMSObj()
{
}

