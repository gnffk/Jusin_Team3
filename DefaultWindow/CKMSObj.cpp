#include "pch.h"
#include "CKMSObj.h"

CKMSObj::CKMSObj() : m_pParentObject(nullptr)
{
	m_vecSubObject.reserve(15);
}

CKMSObj::~CKMSObj()
{
}

