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
	m_bThrow(false),
	m_fThrowAngle(60.f),
	m_fThrowVelocityZero(10.f)
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
			list<pair<D3DXVECTOR3, D3DXVECTOR3>> v = GetCircleVertex(60, 20);
			Get_VertexList().push_back(v);
		}

		{
			list<pair<D3DXVECTOR3, D3DXVECTOR3>> v = GetCircleVertex(80, 30);
			Get_VertexList().push_back(v);
		}

		{
			list<pair<D3DXVECTOR3, D3DXVECTOR3>> v = GetCircleVertex(30, 10);
			Get_VertexList().push_back(v);
		}



	}
	break;
	case FROPT_JUSIN:
	{
		Get_VertexList().push_back({
			{ {-100.f, -20.f, 0.f },   {-100.f, -30.f, 0.f } },
{ {-100.f, -10.f, 0.f },   {-100.f, -20.f, 0.f } },
{ {-100.f, 0.f, 0.f },   {-100.f, -10.f, 0.f } },
{ {-100.f, 10.f, 0.f },   {-100.f, 0.f, 0.f } },
{ {-100.f, 20.f, 0.f },   {-100.f, 10.f, 0.f } },
{ {-110.f, 30.f, 0.f },   {-100.f, 20.f, 0.f } },
{ {-120.f, 30.f, 0.f },   {-110.f, 30.f, 0.f } },
{ {-130.f, 20.f, 0.f },   {-120.f, 30.f, 0.f } },
{ {-130.f, 10.f, 0.f },   {-130.f, 20.f, 0.f } },
{ {-140.f, 10.f, 0.f },   {-130.f, 10.f, 0.f } },
{ {-140.f, 20.f, 0.f },   {-140.f, 10.f, 0.f } },
{ {-140.f, 30.f, 0.f },   {-140.f, 20.f, 0.f } },
{ {-130.f, 40.f, 0.f },   {-140.f, 30.f, 0.f } },
{ {-120.f, 40.f, 0.f },   {-130.f, 40.f, 0.f } },
{ {-110.f, 40.f, 0.f },   {-120.f, 40.f, 0.f } },
{ {-100.f, 40.f, 0.f },   {-110.f, 40.f, 0.f } },
{ {-90.f, 30.f, 0.f },   {-100.f, 40.f, 0.f } },
{ {-90.f, 20.f, 0.f },   {-90.f, 30.f, 0.f } },
{ {-90.f, 10.f, 0.f },   {-90.f, 20.f, 0.f } },
{ {-90.f, 0.f, 0.f },   {-90.f, 10.f, 0.f } },
{ {-90.f, -10.f, 0.f },   {-90.f, 0.f, 0.f } },
{ {-90.f, -30.f, 0.f },   {-90.f, -10.f, 0.f } },
{ {-100.f, -30.f, 0.f },   {-90.f, -30.f, 0.f } },
{ {-70.f, -20.f, 0.f },   {-70.f, -20.f, 0.f } },
{ {-70.f, -10.f, 0.f },   {-70.f, -20.f, 0.f } },
{ {-70.f, 0.f, 0.f },   {-70.f, -10.f, 0.f } },
{ {-70.f, 10.f, 0.f },   {-70.f, 0.f, 0.f } },
{ {-70.f, 20.f, 0.f },   {-70.f, 10.f, 0.f } },
{ {-60.f, 30.f, 0.f },   {-70.f, 20.f, 0.f } },
{ {-50.f, 40.f, 0.f },   {-60.f, 30.f, 0.f } },
{ {-40.f, 40.f, 0.f },   {-50.f, 40.f, 0.f } },
{ {-30.f, 40.f, 0.f },   {-40.f, 40.f, 0.f } },
{ {-20.f, 30.f, 0.f },   {-30.f, 40.f, 0.f } },
{ {-10.f, 20.f, 0.f },   {-20.f, 30.f, 0.f } },
{ {-10.f, 10.f, 0.f },   {-10.f, 20.f, 0.f } },
{ {-10.f, 0.f, 0.f },   {-10.f, 10.f, 0.f } },
{ {-10.f, -10.f, 0.f },   {-10.f, 0.f, 0.f } },
{ {-10.f, -20.f, 0.f },   {-10.f, -10.f, 0.f } },
{ {-10.f, -30.f, 0.f },   {-10.f, -20.f, 0.f } },
{ {-20.f, -30.f, 0.f },   {-10.f, -30.f, 0.f } },
{ {-20.f, -20.f, 0.f },   {-20.f, -30.f, 0.f } },
{ {-20.f, -10.f, 0.f },   {-20.f, -20.f, 0.f } },
{ {-20.f, 0.f, 0.f },   {-20.f, -10.f, 0.f } },
{ {-20.f, 10.f, 0.f },   {-20.f, 0.f, 0.f } },
{ {-30.f, 20.f, 0.f },   {-20.f, 10.f, 0.f } },
{ {-40.f, 20.f, 0.f },   {-30.f, 20.f, 0.f } },
{ {-50.f, 20.f, 0.f },   {-40.f, 20.f, 0.f } },
{ {-60.f, 10.f, 0.f },   {-50.f, 20.f, 0.f } },
{ {-60.f, 0.f, 0.f },   {-60.f, 10.f, 0.f } },
{ {-60.f, -10.f, 0.f },   {-60.f, 0.f, 0.f } },
{ {-60.f, -20.f, 0.f },   {-60.f, -10.f, 0.f } },
{ {-60.f, -30.f, 0.f },   {-60.f, -20.f, 0.f } },
{ {-70.f, -30.f, 0.f },   {-60.f, -30.f, 0.f } },
{ {-70.f, -20.f, 0.f },   {-70.f, -30.f, 0.f } },
{ {50.f, -30.f, 0.f },   {50.f, -30.f, 0.f } },
{ {40.f, -30.f, 0.f },   {50.f, -30.f, 0.f } },
{ {30.f, -30.f, 0.f },   {40.f, -30.f, 0.f } },
{ {20.f, -30.f, 0.f },   {30.f, -30.f, 0.f } },
{ {10.f, -20.f, 0.f },   {20.f, -30.f, 0.f } },
{ {10.f, -10.f, 0.f },   {10.f, -20.f, 0.f } },
{ {10.f, 0.f, 0.f },   {10.f, -10.f, 0.f } },
{ {20.f, 10.f, 0.f },   {10.f, 0.f, 0.f } },
{ {30.f, 10.f, 0.f },   {20.f, 10.f, 0.f } },
{ {40.f, 10.f, 0.f },   {30.f, 10.f, 0.f } },
{ {50.f, 10.f, 0.f },   {40.f, 10.f, 0.f } },
{ {60.f, 20.f, 0.f },   {50.f, 10.f, 0.f } },
{ {60.f, 30.f, 0.f },   {60.f, 20.f, 0.f } },
{ {50.f, 40.f, 0.f },   {60.f, 30.f, 0.f } },
{ {40.f, 40.f, 0.f },   {50.f, 40.f, 0.f } },
{ {30.f, 40.f, 0.f },   {40.f, 40.f, 0.f } },
{ {20.f, 40.f, 0.f },   {30.f, 40.f, 0.f } },
{ {10.f, 40.f, 0.f },   {20.f, 40.f, 0.f } },
{ {10.f, 50.f, 0.f },   {10.f, 40.f, 0.f } },
{ {20.f, 50.f, 0.f },   {10.f, 50.f, 0.f } },
{ {30.f, 50.f, 0.f },   {20.f, 50.f, 0.f } },
{ {40.f, 50.f, 0.f },   {30.f, 50.f, 0.f } },
{ {50.f, 50.f, 0.f },   {40.f, 50.f, 0.f } },
{ {60.f, 50.f, 0.f },   {50.f, 50.f, 0.f } },
{ {70.f, 40.f, 0.f },   {60.f, 50.f, 0.f } },
{ {70.f, 30.f, 0.f },   {70.f, 40.f, 0.f } },
{ {70.f, 20.f, 0.f },   {70.f, 30.f, 0.f } },
{ {70.f, 10.f, 0.f },   {70.f, 20.f, 0.f } },
{ {60.f, 0.f, 0.f },   {70.f, 10.f, 0.f } },
{ {50.f, 0.f, 0.f },   {60.f, 0.f, 0.f } },
{ {40.f, 0.f, 0.f },   {50.f, 0.f, 0.f } },
{ {30.f, 0.f, 0.f },   {40.f, 0.f, 0.f } },
{ {20.f, -10.f, 0.f },   {30.f, 0.f, 0.f } },
{ {30.f, -20.f, 0.f },   {20.f, -10.f, 0.f } },
{ {40.f, -20.f, 0.f },   {30.f, -20.f, 0.f } },
{ {50.f, -20.f, 0.f },   {40.f, -20.f, 0.f } },
{ {60.f, -20.f, 0.f },   {50.f, -20.f, 0.f } },
{ {70.f, -20.f, 0.f },   {60.f, -20.f, 0.f } },
{ {70.f, -30.f, 0.f },   {70.f, -20.f, 0.f } },
{ {60.f, -30.f, 0.f },   {70.f, -30.f, 0.f } },
{ {50.f, -30.f, 0.f },   {60.f, -30.f, 0.f } },
{ {110.f, -60.f, 0.f },   {110.f, -60.f, 0.f } },
{ {100.f, -60.f, 0.f },   {110.f, -60.f, 0.f } },
{ {100.f, -50.f, 0.f },   {100.f, -60.f, 0.f } },
{ {110.f, -50.f, 0.f },   {100.f, -50.f, 0.f } },
{ {110.f, -60.f, 0.f },   {110.f, -50.f, 0.f } },
{ {100.f, -30.f, 0.f },   {100.f, -30.f, 0.f } },
{ {100.f, -20.f, 0.f },   {100.f, -30.f, 0.f } },
{ {100.f, -10.f, 0.f },   {100.f, -20.f, 0.f } },
{ {100.f, 0.f, 0.f },   {100.f, -10.f, 0.f } },
{ {100.f, 10.f, 0.f },   {100.f, 0.f, 0.f } },
{ {100.f, 20.f, 0.f },   {100.f, 10.f, 0.f } },
{ {100.f, 30.f, 0.f },   {100.f, 20.f, 0.f } },
{ {100.f, 40.f, 0.f },   {100.f, 30.f, 0.f } },
{ {100.f, 50.f, 0.f },   {100.f, 40.f, 0.f } },
{ {110.f, 50.f, 0.f },   {100.f, 50.f, 0.f } },
{ {110.f, 40.f, 0.f },   {110.f, 50.f, 0.f } },
{ {110.f, 30.f, 0.f },   {110.f, 40.f, 0.f } },
{ {110.f, 20.f, 0.f },   {110.f, 30.f, 0.f } },
{ {110.f, 10.f, 0.f },   {110.f, 20.f, 0.f } },
{ {110.f, 0.f, 0.f },   {110.f, 10.f, 0.f } },
{ {110.f, -10.f, 0.f },   {110.f, 0.f, 0.f } },
{ {110.f, -20.f, 0.f },   {110.f, -10.f, 0.f } },
{ {110.f, -30.f, 0.f },   {110.f, -20.f, 0.f } },
{ {100.f, -30.f, 0.f },   {110.f, -30.f, 0.f } },
{ {150.f, 50.f, 0.f },   {150.f, 50.f, 0.f } },
{ {150.f, 40.f, 0.f },   {150.f, 50.f, 0.f } },
{ {150.f, 30.f, 0.f },   {150.f, 40.f, 0.f } },
{ {150.f, 20.f, 0.f },   {150.f, 30.f, 0.f } },
{ {150.f, 10.f, 0.f },   {150.f, 20.f, 0.f } },
{ {150.f, 0.f, 0.f },   {150.f, 10.f, 0.f } },
{ {150.f, -10.f, 0.f },   {150.f, 0.f, 0.f } },
{ {150.f, -20.f, 0.f },   {150.f, -10.f, 0.f } },
{ {150.f, -30.f, 0.f },   {150.f, -20.f, 0.f } },
{ {160.f, -30.f, 0.f },   {150.f, -30.f, 0.f } },
{ {160.f, -20.f, 0.f },   {160.f, -30.f, 0.f } },
{ {170.f, -30.f, 0.f },   {160.f, -20.f, 0.f } },
{ {180.f, -30.f, 0.f },   {170.f, -30.f, 0.f } },
{ {190.f, -30.f, 0.f },   {180.f, -30.f, 0.f } },
{ {200.f, -30.f, 0.f },   {190.f, -30.f, 0.f } },
{ {210.f, -20.f, 0.f },   {200.f, -30.f, 0.f } },
{ {210.f, -10.f, 0.f },   {210.f, -20.f, 0.f } },
{ {210.f, 0.f, 0.f },   {210.f, -10.f, 0.f } },
{ {210.f, 10.f, 0.f },   {210.f, 0.f, 0.f } },
{ {210.f, 20.f, 0.f },   {210.f, 10.f, 0.f } },
{ {210.f, 30.f, 0.f },   {210.f, 20.f, 0.f } },
{ {210.f, 40.f, 0.f },   {210.f, 30.f, 0.f } },
{ {210.f, 50.f, 0.f },   {210.f, 40.f, 0.f } },
{ {200.f, 50.f, 0.f },   {210.f, 50.f, 0.f } },
{ {200.f, 40.f, 0.f },   {200.f, 50.f, 0.f } },
{ {200.f, 30.f, 0.f },   {200.f, 40.f, 0.f } },
{ {200.f, 20.f, 0.f },   {200.f, 30.f, 0.f } },
{ {200.f, 10.f, 0.f },   {200.f, 20.f, 0.f } },
{ {200.f, 0.f, 0.f },   {200.f, 10.f, 0.f } },
{ {200.f, -10.f, 0.f },   {200.f, 0.f, 0.f } },
{ {190.f, -20.f, 0.f },   {200.f, -10.f, 0.f } },
{ {180.f, -20.f, 0.f },   {190.f, -20.f, 0.f } },
{ {170.f, -10.f, 0.f },   {180.f, -20.f, 0.f } },
{ {160.f, 0.f, 0.f },   {170.f, -10.f, 0.f } },
{ {160.f, 10.f, 0.f },   {160.f, 0.f, 0.f } },
{ {160.f, 20.f, 0.f },   {160.f, 10.f, 0.f } },
{ {160.f, 30.f, 0.f },   {160.f, 20.f, 0.f } },
{ {160.f, 40.f, 0.f },   {160.f, 30.f, 0.f } },
{ {160.f, 50.f, 0.f },   {160.f, 40.f, 0.f } },
{ {150.f, 50.f, 0.f },   {160.f, 50.f, 0.f } },
			});
	}
	break;
	case FROPT_ARROW:
	{
		Get_VertexList().push_back({
			{ {-80.f, -40.f, 0.f },   {-90.f, -30.f, 0.f } },
			{ {-70.f, -50.f, 0.f },   {-80.f, -40.f, 0.f } },
			{ {-60.f, -60.f, 0.f },   {-70.f, -50.f, 0.f } },
			{ {-50.f, -70.f, 0.f },   {-60.f, -60.f, 0.f } },
			{ {-40.f, -80.f, 0.f },   {-50.f, -70.f, 0.f } },
			{ {-30.f, -90.f, 0.f },   {-40.f, -80.f, 0.f } },
			{ {-20.f, -100.f, 0.f },   {-30.f, -90.f, 0.f } },
			{ {-10.f, -110.f, 0.f },   {-20.f, -100.f, 0.f } },
			{ {0.f, -120.f, 0.f },   {-10.f, -110.f, 0.f } },
			{ {10.f, -110.f, 0.f },   {0.f, -120.f, 0.f } },
			{ {20.f, -100.f, 0.f },   {10.f, -110.f, 0.f } },
			{ {30.f, -90.f, 0.f },   {20.f, -100.f, 0.f } },
			{ {40.f, -80.f, 0.f },   {30.f, -90.f, 0.f } },
			{ {50.f, -70.f, 0.f },   {40.f, -80.f, 0.f } },
			{ {60.f, -60.f, 0.f },   {50.f, -70.f, 0.f } },
			{ {70.f, -50.f, 0.f },   {60.f, -60.f, 0.f } },
			{ {80.f, -40.f, 0.f },   {70.f, -50.f, 0.f } },
			{ {90.f, -30.f, 0.f },   {80.f, -40.f, 0.f } },
			{ {80.f, -30.f, 0.f },   {90.f, -30.f, 0.f } },
			{ {70.f, -30.f, 0.f },   {80.f, -30.f, 0.f } },
			{ {60.f, -30.f, 0.f },   {70.f, -30.f, 0.f } },
			{ {50.f, -30.f, 0.f },   {60.f, -30.f, 0.f } },
			{ {40.f, -30.f, 0.f },   {50.f, -30.f, 0.f } },
			{ {40.f, -20.f, 0.f },   {40.f, -30.f, 0.f } },
			{ {40.f, -10.f, 0.f },   {40.f, -20.f, 0.f } },
			{ {40.f, 0.f, 0.f },   {40.f, -10.f, 0.f } },
			{ {40.f, 10.f, 0.f },   {40.f, 0.f, 0.f } },
			{ {40.f, 20.f, 0.f },   {40.f, 10.f, 0.f } },
			{ {40.f, 30.f, 0.f },   {40.f, 20.f, 0.f } },
			{ {40.f, 40.f, 0.f },   {40.f, 30.f, 0.f } },
			{ {40.f, 50.f, 0.f },   {40.f, 40.f, 0.f } },
			{ {40.f, 60.f, 0.f },   {40.f, 50.f, 0.f } },
			{ {40.f, 70.f, 0.f },   {40.f, 60.f, 0.f } },
			{ {40.f, 80.f, 0.f },   {40.f, 70.f, 0.f } },
			{ {30.f, 80.f, 0.f },   {40.f, 80.f, 0.f } },
			{ {20.f, 80.f, 0.f },   {30.f, 80.f, 0.f } },
			{ {10.f, 80.f, 0.f },   {20.f, 80.f, 0.f } },
			{ {0.f, 80.f, 0.f },   {10.f, 80.f, 0.f } },
			{ {-10.f, 80.f, 0.f },   {0.f, 80.f, 0.f } },
			{ {-20.f, 80.f, 0.f },   {-10.f, 80.f, 0.f } },
			{ {-30.f, 80.f, 0.f },   {-20.f, 80.f, 0.f } },
			{ {-40.f, 80.f, 0.f },   {-30.f, 80.f, 0.f } },
			{ {-40.f, 70.f, 0.f },   {-40.f, 80.f, 0.f } },
			{ {-40.f, 60.f, 0.f },   {-40.f, 70.f, 0.f } },
			{ {-40.f, 50.f, 0.f },   {-40.f, 60.f, 0.f } },
			{ {-40.f, 40.f, 0.f },   {-40.f, 50.f, 0.f } },
			{ {-40.f, 30.f, 0.f },   {-40.f, 40.f, 0.f } },
			{ {-40.f, 20.f, 0.f },   {-40.f, 30.f, 0.f } },
			{ {-40.f, 10.f, 0.f },   {-40.f, 20.f, 0.f } },
			{ {-40.f, 0.f, 0.f },   {-40.f, 10.f, 0.f } },
			{ {-40.f, -10.f, 0.f },   {-40.f, 0.f, 0.f } },
			{ {-40.f, -20.f, 0.f },   {-40.f, -10.f, 0.f } },
			{ {-40.f, -30.f, 0.f },   {-40.f, -20.f, 0.f } },
			{ {-50.f, -30.f, 0.f },   {-40.f, -30.f, 0.f } },
			{ {-60.f, -30.f, 0.f },   {-50.f, -30.f, 0.f } },
			{ {-70.f, -30.f, 0.f },   {-60.f, -30.f, 0.f } },
			{ {-80.f, -30.f, 0.f },   {-70.f, -30.f, 0.f } },
			{ {-90.f, -30.f, 0.f },   {-80.f, -30.f, 0.f } },
			});

		break;
	}
	

	default:
		break;
	}
}


bool CLSYObjFruit::Slice(POINT& pt1, POINT& pt2)
{
	//float EPSILON = 1.414f;
	float EPSILON = 0.5f;
	if (pt1.x == pt2.x)
	{
		pt2.x += 1;
	}
	LONG err = (pt1.x - pt2.x);
	if (err == 0)
	{
		return false;
	}

	list< D3DXVECTOR3> crossPointList;

	float veryLeft = WINCX;
	float veryRight = 0;
	float veryBottom = 0;
	float veryTop = WINCY;

	for (list<pair<D3DXVECTOR3, D3DXVECTOR3>>& vertexList : Get_VertexList())
	{
		for (auto iter = vertexList.begin(); iter != vertexList.end();)
		{
			pair<D3DXVECTOR3, D3DXVECTOR3> vectorPair = *iter;

			D3DXVECTOR3 pt3;
			D3DXVECTOR3 pt4;

			D3DXVec3TransformCoord(&pt3, &vectorPair.first, &m_tInfo.matWorld);
			D3DXVec3TransformCoord(&pt4, &vectorPair.second, &m_tInfo.matWorld);

			;
			veryLeft = min(veryLeft, pt3.x);
			veryRight = max(veryRight, pt3.x);
			veryBottom = max(veryBottom, pt3.y);
			veryTop = min(veryTop, pt3.y);

			//pt3 += m_tInfo.vPos;
			//pt4 += m_tInfo.vPos;

			if (pt1.x == pt2.x)
			{
				pt2.x += 0.001f;
			}
			if (pt3.y == pt4.y)
			{
				pt4.y += 0.001f;
			}
			if (pt1.y == pt2.y)
			{
				pt2.y += 0.001f;
			}
			if (pt3.x == pt4.x)
			{
				pt4.x += 0.001f;
			}

			float err = ((pt1.x - pt2.x) * (pt3.y - pt4.y) - (pt1.y - pt2.y) * (pt3.x - pt4.x));
			if (err == 0)
			{
				return false;
				//continue;
			}

			D3DXVECTOR3 ptCross = CrossPointBy2LinePoint(pt1, pt2, pt3, pt4);

			float minx = min(pt3.x, pt4.x);
			float maxx = max(pt3.x, pt4.x);
			float miny = min(pt3.y, pt4.y);
			float maxy = max(pt3.y, pt4.y);

			if (ptCross.x >= (minx - EPSILON) && ptCross.x <= (maxx + EPSILON)
				&& ptCross.y >= (miny - EPSILON) && ptCross.y <= (maxy + EPSILON))
			{
				D3DXVECTOR3 a = { (float)ptCross.x, (float)ptCross.y, 0.f };
				crossPointList.push_back(a);
				++iter;
			}
			else
			{
				++iter;
			}
		}
	}

	RECT thisRect = { veryLeft, veryTop, veryRight, veryBottom };
	int width = fabsf(pt2.x - pt1.x);
	int height = fabsf(pt2.y - pt1.y);
	int left = min(pt1.x, pt2.x);
	int top = min(pt1.y, pt2.y);
	RECT mouseRect = { left, top, left + width, top + height };
	RECT rc;
	if(!IntersectRect(&rc, &thisRect, &mouseRect))
	{
		return false;
	}
	//RECT mouseRect = {}

	if (false)
	{
		bool bFirstSet = false;
		D3DXVECTOR3 posBefore;
		for (D3DXVECTOR3 crossPoint : crossPointList)
		{

			if (bFirstSet)
			{
				Get_VertexList().push_back({
					{ posBefore - m_tInfo.vPos, crossPoint - m_tInfo.vPos},
					});
			}
			else
			{
				bFirstSet = true;
				posBefore = crossPoint;
			}
		}
	}

	cout << "crossPointList: " << crossPointList.size() << endl;
	

	if (true)
	{
		for (list<pair<D3DXVECTOR3, D3DXVECTOR3>>& vertexList : Get_VertexList())
		{

			for (D3DXVECTOR3 crossPoint : crossPointList)
			{
				for (auto iter = vertexList.begin(); iter != vertexList.end();)
				{
					pair<D3DXVECTOR3, D3DXVECTOR3> vectorPair = *iter;

					//D3DXVECTOR3 pt3 = vectorPair.first;
					//D3DXVECTOR3 pt4 = vectorPair.second;
					//pt3 += m_tInfo.vPos;
					//pt4 += m_tInfo.vPos;

					D3DXVECTOR3 pt3;
					D3DXVECTOR3 pt4;

					D3DXVec3TransformCoord(&pt3, &vectorPair.first, &m_tInfo.matWorld);
					D3DXVec3TransformCoord(&pt4, &vectorPair.second, &m_tInfo.matWorld);


					float minx = min(pt3.x, pt4.x);
					float maxx = max(pt3.x, pt4.x);
					float miny = min(pt3.y, pt4.y);
					float maxy = max(pt3.y, pt4.y);

					if (crossPoint.x >= (minx - EPSILON) && crossPoint.x <= (maxx + EPSILON)
						&& crossPoint.y >= (miny - EPSILON) && crossPoint.y <= (maxy + EPSILON))
					{
						iter = vertexList.erase(iter);
					}
					else
					{
						++iter;
					}

				}
			}
		}
	}




	list<list<pair<D3DXVECTOR3, D3DXVECTOR3>>> part1VertexList;
	list<list<pair<D3DXVECTOR3, D3DXVECTOR3>>> part2VertexList;
	{
		for (list<pair<D3DXVECTOR3, D3DXVECTOR3>> vertexList : Get_VertexList())
		{
			list<pair<D3DXVECTOR3, D3DXVECTOR3>> part1;
			for (pair<D3DXVECTOR3, D3DXVECTOR3> vertexPair : vertexList)
			{
				D3DXVECTOR3 pt3;
				D3DXVECTOR3 pt4;

				D3DXVec3TransformCoord(&pt3, &vertexPair.first, &m_tInfo.matWorld);
				D3DXVec3TransformCoord(&pt4, &vertexPair.second, &m_tInfo.matWorld);

				float judgePt3Y = LineEquation(pt1, pt2, pt3.x);
				float judgePt4Y = LineEquation(pt1, pt2, pt4.x);

				if (pt3.y > judgePt3Y && pt3.y > judgePt3Y)
				{
					part1.push_back(vertexPair);
				}
			}

			if (!part1.empty())
			{
				part1VertexList.push_back(part1);
			}
		}

	}

	

	{
		for (list<pair<D3DXVECTOR3, D3DXVECTOR3>> vertexList : Get_VertexList())
		{
			list<pair<D3DXVECTOR3, D3DXVECTOR3>> part2;
			for (pair<D3DXVECTOR3, D3DXVECTOR3> vertexPair : vertexList)
			{
				D3DXVECTOR3 pt3;
				D3DXVECTOR3 pt4;

				D3DXVec3TransformCoord(&pt3, &vertexPair.first, &m_tInfo.matWorld);
				D3DXVec3TransformCoord(&pt4, &vertexPair.second, &m_tInfo.matWorld);

				float judgePt3Y = LineEquation(pt1, pt2, pt3.x);
				float judgePt4Y = LineEquation(pt1, pt2, pt4.x);

				if (pt3.y < judgePt3Y && pt3.y < judgePt3Y)
				{
					part2.push_back(vertexPair);
				}
			}

			if (!part2.empty())
			{
				part2VertexList.push_back(part2);
			}
		}
		
	}

	

		if (!part1VertexList.empty() && !part2VertexList.empty())
		{
			{
				if (!part1VertexList.empty())
				{
					//part1
					CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());
					pFruit->Set_Option(CLSYObjFruit::FROPT_PART);
					pFruit->Set_VertexList(part1VertexList);
					pFruit->Set_Angle(m_fAngle);
					pFruit->Set_Pos(m_tInfo.vPos);
					int randSpeed = rand() % 5;
					pFruit->Set_Speed(randSpeed + 1);
					pFruit->Set_Throw(m_bThrow);
					pFruit->Set_ThrowAngle(m_fAngle - 90);
					pFruit->Update();
					CObjMgr::Get_Instance()->AddObject(OBJ_LSY_FRUIT, pFruit);

					m_bDead = true;
				}
			}
			{
				if (!part2VertexList.empty())
				{
					//part2
					CLSYObjFruit* pFruit = dynamic_cast<CLSYObjFruit*>(CAbstractFactory<CLSYObjFruit>::Create());
					pFruit->Set_Option(CLSYObjFruit::FROPT_PART);
					pFruit->Set_VertexList(part2VertexList);
					D3DXVECTOR3 tmpPos = { 100.f, 300.f, 0.f };
					pFruit->Set_Angle(m_fAngle);
					pFruit->Set_Pos(m_tInfo.vPos);
					int randSpeed = rand() % 5;
					pFruit->Set_Speed(randSpeed + 1);
					pFruit->Set_Throw(m_bThrow);
					pFruit->Set_ThrowAngle(m_fAngle + 90);
					pFruit->Update();
					CObjMgr::Get_Instance()->AddObject(OBJ_LSY_FRUIT, pFruit);

					m_bDead = true;
				}
			}
		}

	

	
	

	return true;
}

void CLSYObjFruit::Initialize()
{
	m_fTimer = 0.f;

	//m_tInfo.vPos = { 50.f, WINCY >> 1, 0.f };
	m_tInfo.vPos = { WINCX >> 1, WINCY >> 1, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };
	m_fSpeed = 3.f;

	//m_tRectSides = { 200, 200 };
}

int CLSYObjFruit::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	float delta = CDeltaMgr::Get_Instance()->Get_Delta();
	m_fTimer += delta;
	if (m_bThrow)
	{
		float cosx = m_fThrowVelocityZero * cosf(D3DXToRadian(m_fThrowAngle)) * m_fTimer;
		float siny = m_fThrowVelocityZero * sinf(D3DXToRadian(m_fThrowAngle)) * m_fTimer;

		D3DXVECTOR3 dirGravity = { 0.f, 9.81f, 0.f };
		m_tInfo.vPos += 1.f * dirGravity * 0.5 * m_fTimer * m_fTimer;
		m_tInfo.vPos.x += cosx;
		m_tInfo.vPos.y -= siny;

		m_fAngle += m_fSpeed;
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
	// culling
	//m_tInfo.vPos
	int margin = 50;
	if (m_tInfo.vPos.x > WINCX + margin || m_tInfo.vPos.x < 0 - margin || m_tInfo.vPos.y > WINCY + margin || m_tInfo.vPos.y < 0 - margin)
	{
		m_bDead = true;
	}
	return OBJ_NOEVENT;
}

void CLSYObjFruit::Render(HDC hDC)
{
	CLSYObj::Render(hDC);
}

void CLSYObjFruit::Release()
{
}
