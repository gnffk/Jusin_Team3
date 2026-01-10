#include "pch.h"
#include "CLSYObjFruit.h"
#include "CKeyMgr.h"
#include "CDeltaMgr.h"
#include "CObjMgr.h"
#include "CAbstractFactory.h"
//Get_VertexList().push_back({
		//	{-10.f, -10.f, 0.f},
		//	{10.f, -10.f, 0.f},
		//	{10.f, 10.f, 0.f},
		//	{-10.f, 10.f, 0.f},
		//	{-10.f, -10.f, 0.f}
		//	});

CLSYObjFruit::CLSYObjFruit():
	m_bCut(false),
	m_fTimer(0.f),
	m_bDead(false)
{
}

CLSYObjFruit::~CLSYObjFruit()
{
	Release();
}

void CLSYObjFruit::GenerateVertexList()
{
	switch (m_iOption)
	{
	case FROPT_TEST:
	{
		{
			list<D3DXVECTOR3> v = GetCircleVertex(50);
			v.push_back(v.front());
			Get_VertexList().push_back(v);
		}
		
		//{
		//	list<D3DXVECTOR3> v = GetCircleVertex(100, 30);
		//	v.push_back(v.front());
		//	Get_VertexList().push_back(v);
		//}

		//{
		//	list<D3DXVECTOR3> v = GetCircleVertex(70, 30);
		//	v.push_back(v.front());
		//	Get_VertexList().push_back(v);
		//}
	}
	break;
	default:
		break;
	}
}

bool CLSYObjFruit::CalcKnifeMark(POINT& pt1, POINT& pt2)
{
	list< D3DXVECTOR3> crossPointList;
	for (list<D3DXVECTOR3>& vertexList : Get_VertexList())
	{
		bool bFirstSet = false;
		D3DXVECTOR3 posTmp;
		for (D3DXVECTOR3& vertex: vertexList)
		{
			if (bFirstSet)
			{
				D3DXVECTOR3 tmp = vertex + m_tInfo.vPos;

				POINT pt3 = { tmp.x, tmp.y};
				POINT pt4 = { posTmp.x, posTmp.y };

				LONG err = ((pt1.x - pt2.x) * (pt3.y - pt4.y) - (pt1.y - pt2.y) * (pt3.x - pt4.x));
				if (err == 0)
				{
					continue;
				}

				POINT ptCross = CrossPointBy2LinePoint(pt1, pt2, pt3, pt4);

				LONG minx = min(pt3.x, pt4.x);
				LONG maxx = max(pt3.x, pt4.x);
				LONG miny = min(pt3.y, pt4.y);
				LONG maxy = max(pt3.y, pt4.y);

				if (ptCross.x >= minx && ptCross.x <= maxx
					&& ptCross.y >= miny && ptCross.y <= maxy)
				{
					D3DXVECTOR3 a = { (float)ptCross.x, (float)ptCross.y, 0.f };

					//a -= m_tInfo.vPos;
					a.x -= m_tInfo.vPos.x;
					a.y -= m_tInfo.vPos.y;
					crossPointList.push_back(a);
				}

				posTmp = vertex + m_tInfo.vPos;
				if (crossPointList.size() >= 2)
				{
					break;
				}
			}
			else
			{
				posTmp = vertex + m_tInfo.vPos;
				bFirstSet = true;
			}
		}
	}
	if (crossPointList.size() == 2)
	{
		D3DXVECTOR3 crossPos1 = crossPointList.front();
		crossPointList.pop_front();
		D3DXVECTOR3 crossPos2 = crossPointList.front();
		crossPointList.pop_front();
		LONG err = ((LONG)crossPos2.x - (LONG)crossPos1.x);
		if (err == 0)
		{
			return false;
		}

		float gi = (crossPos2.y - crossPos1.y) / (crossPos2.x - crossPos1.x);

		list<list<D3DXVECTOR3>> part1VertexList;
		list<list<D3DXVECTOR3>> part2VertexList;

		for (list<D3DXVECTOR3> vertexList : Get_VertexList())
		{
			//vertexList.push_front(crossPos1);
			//vertexList.push_back(crossPos2);

			//vertexList.sort();

			list<D3DXVECTOR3> part1;
			list<D3DXVECTOR3> part2;

			/*part1.push_back(crossPos1);
			part1.push_back(crossPos2);*/
			for (D3DXVECTOR3& vertex : vertexList)
			{
				LONG y = LineEquation({ (LONG)crossPos1.x, (LONG)crossPos1.y }, { (LONG)crossPos2.x, (LONG)crossPos2.y }, (LONG)vertex.x);

				if ((LONG)vertex.y >= y)
				{
					part1.push_back(vertex);
				}
				else
				{
					part2.push_back(vertex);
				}
			}

	


			if (part1.front() != part1.back())
			{
				int x = 0;
				//part2.push_back(part1.front());
				//part1.push_back(part1.front());
			}
			if (part2.front() != part2.back())
			{
				//part2.push_back(part2.front());
			}

			if (gi < 0)
			{
				// 양의방향

				//part2.push_front(part1.back());
				//part2.push_back(part1.front());
			}

			part1VertexList.push_back(part1);
			part2VertexList.push_back(part2);
		}

		m_bDead = true;
		{
			CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());
			pFruit->Set_Option(CLSYObjFruit::FROPT_PART);
			pFruit->Set_VertexList(part1VertexList);
			CObjMgr::Get_Instance()->AddObject(OBJ_LSY_FRUIT, pFruit);
		}

		{
			CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());
			pFruit->Set_Option(CLSYObjFruit::FROPT_PART);
			D3DXVECTOR3 tmp = { 300.f, 300.f, 0 };
			pFruit->Set_Pos(tmp);
			pFruit->Set_VertexList(part2VertexList);
			CObjMgr::Get_Instance()->AddObject(OBJ_LSY_FRUIT, pFruit);
		}
	}
	if (false && crossPointList.size() == 2)
	{
		D3DXVECTOR3 crossPos1 = crossPointList.front();
		crossPointList.pop_front();
		D3DXVECTOR3 crossPos2 = crossPointList.front();
		crossPointList.pop_front();
		LONG err = ((LONG)crossPos2.x - (LONG)crossPos1.x);
		if (err == 0)
		{
			return false;
		}

		float gi = (crossPos2.y - crossPos1.y) / (crossPos2.x - crossPos1.x);

		list<list<D3DXVECTOR3>> part1VertexList;
		list<list<D3DXVECTOR3>> part2VertexList;

		for (list<D3DXVECTOR3>& vertexList : Get_VertexList())
		{
			list<D3DXVECTOR3> part1;
			list<D3DXVECTOR3> part2;

			
			for (D3DXVECTOR3& vertex : vertexList)
			{
				LONG y = LineEquation({ (LONG)crossPos1.x, (LONG)crossPos1.y }, { (LONG)crossPos2.x, (LONG)crossPos2.y }, (LONG)vertex.x);

				if ((LONG)vertex.y > y)
				{
					part1.push_back(vertex);
				}
				else
				{
					part2.push_back(vertex);
				}
			}
			

			if (part1.front() != part1.back())
			{
				int x = 0;
				//part2.push_back(part1.front());
				part1.push_back(part1.front());
			}
			if (part2.front() != part2.back())
			{
				part2.push_back(part2.front());
			}

			if (gi < 0)
			{
				// 양의방향

				//part2.push_front(part1.back());
				//part2.push_back(part1.front());
			}

			part1VertexList.push_back(part1);
			part2VertexList.push_back(part2);
		}

		m_bDead = true;
		{
			CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());
			pFruit->Set_Option(CLSYObjFruit::FROPT_PART);
			pFruit->Set_VertexList(part1VertexList);
			CObjMgr::Get_Instance()->AddObject(OBJ_LSY_FRUIT, pFruit);
		}

		{
			CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());
			pFruit->Set_Option(CLSYObjFruit::FROPT_PART);
			D3DXVECTOR3 tmp = { 300.f, 300.f, 0 };
			pFruit->Set_Pos(tmp);
			pFruit->Set_VertexList(part2VertexList);
			CObjMgr::Get_Instance()->AddObject(OBJ_LSY_FRUIT, pFruit);
		}
	}

	//Get_VertexList().push_back(crossPointList);

	m_bCut = true;
	return false;
}

void CLSYObjFruit::Initialize()
{
	m_fTimer = 0.f;

	//m_tInfo.vPos = { 50.f, WINCY >> 1, 0.f };
	m_tInfo.vPos = { WINCX >> 1, WINCY >> 1, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };
	m_fSpeed = 3.f;

	m_tRectSides = { 100, 100 };
}

int CLSYObjFruit::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	float delta = CDeltaMgr::Get_Instance()->Get_Delta();
	m_fTimer += delta;
	if (false)
	{
		float vzero = 7.f;
		float cosx = vzero * cosf(D3DXToRadian(70.f)) * m_fTimer;
		float siny = vzero * sinf(D3DXToRadian(70.f)) * m_fTimer;

		D3DXVECTOR3 dirGravity = { 0.f, 9.81f, 0.f };
		m_tInfo.vPos += 1.f * dirGravity * 0.5 * m_fTimer * m_fTimer;
		m_tInfo.vPos.x += cosx;
		m_tInfo.vPos.y -= siny;
	}


	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	{
		m_fAngle -= 3.f;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	{
		m_fAngle += 3.f;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
	{
		D3DXVECTOR3 dirTmp;
		D3DXVec3TransformNormal(&dirTmp, &m_tInfo.vLook, &m_tInfo.matWorld);
		m_tInfo.vPos += dirTmp * m_fSpeed;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
	{
		D3DXVECTOR3 dirTmp;
		D3DXVec3TransformNormal(&dirTmp, &m_tInfo.vLook, &m_tInfo.matWorld);
		m_tInfo.vPos -= dirTmp * m_fSpeed;
	}

	CLSYObj::Update();
	return OBJ_NOEVENT;
}

int CLSYObjFruit::Late_Update()
{
	
	return OBJ_NOEVENT;
}

void CLSYObjFruit::Render(HDC hDC)
{
	CLSYObj::Render(hDC);
}

void CLSYObjFruit::Release()
{
}
