#include "pch.h"
#include "CKJJObj.h"

CKJJObj::CKJJObj()
{
	ZeroMemory(&m_vSize, sizeof(D3DXVECTOR3));
	ZeroMemory(&m_vScale, sizeof(D3DXVECTOR3));

    for (int i = 0; i < 4; ++i)
    {
		ZeroMemory(&m_vPoint[i], sizeof(D3DXVECTOR3));
		ZeroMemory(&m_vOriginPoint[i], sizeof(D3DXVECTOR3));
	}
}