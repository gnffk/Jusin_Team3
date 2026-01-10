#pragma once

constexpr LONG DBG_ELLIPSE_R = 2;

static void DrawEllipseByPoint(HDC hDC, POINT&& pt, LONG r)
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

static list<D3DXVECTOR3> GetCircleVertex(int r, int vertexCnt = 10)
{
	if (vertexCnt < 10)
	{
		vertexCnt = 10;
	}

	float sideAngle = D3DX_PI * 2.f / (float)vertexCnt;

	list<D3DXVECTOR3> list;
	for (int i = 0; i < vertexCnt; ++i)
	{
		float x = cosf(i * sideAngle) * r;
		float y = sinf(i * sideAngle) * r;
		list.push_back({x, y, 0.f});
	}
	return list;
}

static POINT CrossPointBy2LinePoint(
	POINT& pt1, POINT& pt2,
	POINT& pt3, POINT& pt4
)
{ 
	// tq
	// https://gaussian37.github.io/math-algorithm-intersection_point/

	LONG x = ((pt1.x * pt2.y - pt1.y * pt2.x) * (pt3.x - pt4.x) - (pt1.x - pt2.x) * (pt3.x * pt4.y - pt3.y * pt4.x)) / ((pt1.x - pt2.x) * (pt3.y - pt4.y) - (pt1.y - pt2.y) * (pt3.x - pt4.x));
	LONG y = ((pt1.x * pt2.y - pt1.y * pt2.x) * (pt3.y - pt4.y) - (pt1.y - pt2.y) * (pt3.x * pt4.y - pt3.y * pt4.x)) / ((pt1.x - pt2.x) * (pt3.y - pt4.y) - (pt1.y - pt2.y) * (pt3.x - pt4.x));
	
	return { x, y };
}

static LONG LineEquation(POINT&& pt1, POINT&& pt2, LONG x)
{
	//*pY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;
	return ((pt2.y - pt1.y) / (pt2.x - pt1.x)) * (x - pt1.x) + pt1.y;
}