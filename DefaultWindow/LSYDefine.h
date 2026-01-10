#pragma once

constexpr LONG DBG_ELLIPSE_R = 2;

static void DrawEllipseByPoint(HDC hDC, POINT& pt, LONG r)
{
	int left = pt.x - r;
	int right = pt.x + r;
	int top = pt.y - r;
	int bottom = pt.y + r;
	Ellipse(hDC, left, top, right, bottom);
}

static void DrwaRectangleByPoint(HDC hDC, POINT&& pt, LONG x, LONG y)
{
	int left = pt.x - x * 0.5;
	int right = pt.x + x * 0.5;
	int top = pt.y - y * 0.5;
	int bottom = pt.y + y * 0.5;
	Rectangle(hDC, left, top, right, bottom);
}

static list<pair<D3DXVECTOR3, D3DXVECTOR3>> GetCircleVertex(int r, int vertexCnt = 10)
{
	//if (vertexCnt < 10)
	//{
	//	vertexCnt = 10;
	//}

	float sideAngle = D3DX_PI * 2.f / (float)vertexCnt;

	list<pair<D3DXVECTOR3, D3DXVECTOR3>> list;
	for (int i = 1; i < vertexCnt; ++i)
	{
		float x1 = cosf((i - 1) * sideAngle) * r;
		float y1 = sinf((i - 1) * sideAngle) * r;

		float x2 = cosf(i * sideAngle) * r;
		float y2 = sinf(i * sideAngle) * r;
		D3DXVECTOR3 left{x1, y1, 0.f};
		D3DXVECTOR3 right{ x2, y2, 0.f };
		list.push_back({ left , right });
	}
	{
		float x1 = cosf((vertexCnt - 1) * sideAngle) * r;
		float y1 = sinf((vertexCnt - 1) * sideAngle) * r;

		float x2 = cosf(0 * sideAngle) * r;
		float y2 = sinf(0 * sideAngle) * r;
		D3DXVECTOR3 left{ x1, y1, 0.f };
		D3DXVECTOR3 right{ x2, y2, 0.f };
		list.push_back({ left , right });
	}
	return list;
}

static D3DXVECTOR3 CrossPointBy2LinePoint(
	POINT& pt1, POINT& pt2,
	D3DXVECTOR3& pt3, D3DXVECTOR3& pt4
)
{ 
	// tq
	// https://gaussian37.github.io/math-algorithm-intersection_point/

	float x = (float(pt1.x * pt2.y - pt1.y * pt2.x) * float(pt3.x - pt4.x) - float(pt1.x - pt2.x) * float(pt3.x * pt4.y - pt3.y * pt4.x)) / (float(pt1.x - pt2.x) * float(pt3.y - pt4.y) - float(pt1.y - pt2.y) * float(pt3.x - pt4.x));
	float y = (float(pt1.x * pt2.y - pt1.y * pt2.x) * float(pt3.y - pt4.y) - float(pt1.y - pt2.y) * float(pt3.x * pt4.y - pt3.y * pt4.x)) / (float(pt1.x - pt2.x) * float(pt3.y - pt4.y) - float(pt1.y - pt2.y) * float(pt3.x - pt4.x));
	
	return { x, y, 0.f };
}

static float LineEquation(POINT& pt1, POINT& pt2, float x)
{
	//*pY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;
	return (float(pt2.y - pt1.y) / float(pt2.x - pt1.x)) * float(x - pt1.x) + pt1.y;
}