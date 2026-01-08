#include "pch.h"
#include "CLSYObj.h"

int CLSYObj::Update()
{
	D3DXMATRIX matTrans, matRotZ;
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);
	m_tInfo.matWorld = matRotZ * matTrans;

	for (auto& vertexList : Get_VertexList())
	{
		list<POINT> ptList;
		for (D3DXVECTOR3& vertex : vertexList)
		{
			D3DXVECTOR3 posWorldVertex;
			D3DXVec3TransformCoord(&posWorldVertex, &vertex, &m_tInfo.matWorld);
			ptList.push_back({ (LONG)posWorldVertex.x, (LONG)posWorldVertex.y });
		}
		Get_PointList().push_back(ptList);
	}

#ifdef _DEBUG
	Update_Rect();
#endif // DEBUG

	return OBJ_NOEVENT;
}

void CLSYObj::Render(HDC hDC)
{
#ifdef _DEBUG
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
#endif // DEBUG

	if (!Get_PointList().empty())
	{
		for (auto& ptList : Get_PointList())
		{
			if (!ptList.empty())
			{
				POINT frontPt = ptList.front();
				ptList.pop_front();
				MoveToEx(hDC, frontPt.x, frontPt.y, nullptr);
				for (POINT& pt : ptList)
				{
					LineTo(hDC, pt.x, pt.y);
				}
			}
			ptList.clear();
		}
	}

	Get_PointList().clear();
}

void CLSYObj::Update_Rect()
{
	LONG widthHalf = m_tRectSides.x * 0.5;
	LONG heightHalf = m_tRectSides.y * 0.5;
	if (widthHalf >= 0 && heightHalf >= 0)
	{
		m_tRect.left = (m_tInfo.vPos.x - widthHalf);
		m_tRect.right = (m_tInfo.vPos.x + widthHalf);
		m_tRect.top = (m_tInfo.vPos.y - heightHalf);
		m_tRect.bottom = (m_tInfo.vPos.y + heightHalf);
	}
	
}
