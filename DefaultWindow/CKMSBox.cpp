#include "pch.h"
#include "CKMSBox.h"
#include "CScrollMgr.h"

CKMSBox::CKMSBox()
{
}

CKMSBox::~CKMSBox()
{
}

void CKMSBox::Initialize()
{
    m_tInfo.vPos = { 1000,590 ,0};
}

int CKMSBox::Update()
{
    return 0;
}

int CKMSBox::Late_Update()
{
    return 0;
}

void CKMSBox::Render(HDC hDC)
{
    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    HBRUSH brush = CreateSolidBrush(RGB(242, 163, 100));
    RECT i = { m_tInfo.vPos.x - 1000 + iScrollX, m_tInfo.vPos.y - 100 , m_tInfo.vPos.x + 4000 + iScrollX, m_tInfo.vPos.y + 50 };
    FillRect(hDC, &i,brush);

    DeleteObject(brush);

    for (int i = 0; i < 30; ++i) {
     
      
         Rectangle(hDC, 100.f* i +  iScrollX, 540.f, 300.f * i + iScrollX, 570.f);
        
 
       
    }

}

void CKMSBox::Release()
{
}

void CKMSBox::Key_Input()
{
}
