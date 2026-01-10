#include "pch.h"
#include "CKMSObj.h"

CKMSObj::CKMSObj() : m_pParentObject(nullptr), m_fGravity(9.8f)
{
	m_vecSubObject.reserve(15);
	m_vPoint.resize(10);
	m_vOriginPoint.resize(10);
}

CKMSObj::~CKMSObj()
{
}

