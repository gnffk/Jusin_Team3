#include "pch.h"
#include "CKJJObj.h"

CKJJObj::CKJJObj():m_fAngle(0.f)
{
	ZeroMemory(&m_vSize, sizeof(D3DXVECTOR3));
	m_vScale = { 1.f,1.f,1.f };

    for (int i = 0; i < 4; ++i)
    {
		ZeroMemory(&m_vPoint[i], sizeof(D3DXVECTOR3));
		ZeroMemory(&m_vOriginPoint[i], sizeof(D3DXVECTOR3));
	}
}