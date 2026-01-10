#include "pch.h"
#include "CLSYObj.h"

int CLSYObj::Update()
{
	D3DXMATRIX matTrans, matRotZ;
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
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

	Update_Rect();

	return OBJ_NOEVENT;
}

void CLSYObj::Render(HDC hDC)
{
#ifdef _DEBUG
	// debug rect area
	//DrwaRectangleByPoint(hDC, { (LONG)m_tInfo.vPos.x ,(LONG)m_tInfo.vPos.y }, m_tRectSides.x, m_tRectSides.y);
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
#ifdef _DEBUG
				DrawEllipseByPoint(hDC, move(frontPt), DBG_ELLIPSE_R);
#endif // DEBUG
				for (POINT& pt : ptList)
				{
					LineTo(hDC, pt.x, pt.y);
#ifdef _DEBUG
					DrawEllipseByPoint(hDC, move(pt), DBG_ELLIPSE_R);
#endif // DEBUG
				}
			}
			ptList.clear();
		}
	}

#ifdef _DEBUG
	// debug line dir vector
	MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, nullptr);
	D3DXVECTOR3 dirTmp;
	D3DXVec3TransformNormal(&dirTmp, &m_tInfo.vLook, &m_tInfo.matWorld);
	D3DXVECTOR3 tmp = m_tInfo.vPos + m_tInfo.vDir;
	dirTmp *= 20;
	dirTmp += m_tInfo.vPos;
	LineTo(hDC, dirTmp.x, dirTmp.y);
	DrawEllipseByPoint(hDC, { (LONG)dirTmp .x, (LONG)dirTmp .y}, DBG_ELLIPSE_R);
#endif // DEBUG

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
