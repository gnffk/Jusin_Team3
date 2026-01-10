#include "pch.h"
#include "CKJJObj.h"

CKJJObj::CKJJObj():m_fAngle(0.f), m_fWeight(-1.f)
{
	ZeroMemory(&m_vSize, sizeof(D3DXVECTOR3));
	m_vScale = { 1.f,1.f,1.f };
	m_vAxisX = { 1.f,0.f,0.f };
	m_vAxisY = { 0.f,1.f,0.f };
    for (int i = 0; i < 4; ++i)
    {
		ZeroMemory(&m_vPoint[i], sizeof(D3DXVECTOR3));
		ZeroMemory(&m_vOriginPoint[i], sizeof(D3DXVECTOR3));
	}
}


void CKJJObj::Update_matWorld()
{
	D3DXMATRIX		matScale, matRotZ, matTrans, matScaleRotZ;

	D3DXMatrixScaling(&matScale,
		m_vScale.x,
		m_vScale.y,
		m_vScale.z);

	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));

	D3DXMatrixTranslation(&matTrans,
		m_tInfo.vPos.x,
		m_tInfo.vPos.y,
		m_tInfo.vPos.z);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	matScaleRotZ = matScale * matRotZ;

	m_vAxisX = { m_vSize.x / 2.f, 0.f, 0.f };
	m_vAxisY = { 0.f, m_vSize.y / 2.f, 0.f };

	D3DXVec3TransformCoord(&m_vAxisX, &m_vAxisX, &matScaleRotZ);
	D3DXVec3TransformCoord(&m_vAxisY, &m_vAxisY, &matScaleRotZ);
}
