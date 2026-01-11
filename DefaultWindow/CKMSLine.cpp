#include "pch.h"
#include "CKMSLine.h"

CKMSLine::CKMSLine()
{
}

CKMSLine::~CKMSLine()
{
}

void CKMSLine::Initialize()
{
	m_fAngle = 0.5f;
	// 자기 자신 vertex
	m_eKMSObjType = KMSOBJ_LINE;
	m_vPoint[0] = { -200.f, 560.f, 0.f };
	m_vPoint[1] = { 4000.f, 560.f, 0.f };

	m_UpVector = { 0.f, -1.f, 0.f };
	m_RightVector = m_vPoint[1] - m_vPoint[0];


	for (int i = 0; i < 5; ++i)
		m_vOriginPoint[i] = m_vPoint[i];
}

int CKMSLine::Update()
{
    return 0;
}

int CKMSLine::Late_Update()
{
    return 0;
}

void CKMSLine::Render(HDC hDC)
{
	//MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);
	//for (int i = 0; i < 5; ++i)
	//{
	//	LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);

	//}
}

void CKMSLine::Release()
{
}

void CKMSLine::Key_Input()
{
}
