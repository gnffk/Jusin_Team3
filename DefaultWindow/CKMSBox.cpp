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
    m_Obj = nullptr;
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

    for (int i = 0; i < 40; ++i)
    {
        int r = 160 + i*10 ;
        int g = 210 + i*10;
        int b = 255;

        HBRUSH brush = CreateSolidBrush(RGB(r, g, b));

        RECT rc;
        rc.left = 100 * i + iScrollX;
        rc.top = 540;
        rc.right = 300 * i + iScrollX;
        rc.bottom = 570;

        FillRect(hDC, &rc, brush);
        DeleteObject(brush);
    }

    if (m_Obj) {
        HFONT hFont = CreateFont(
            100,             
            0,                 
            0, 0,              
            FW_BOLD,           
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_SWISS,
            L"Arial"
        );
        HFONT oldFont = (HFONT)SelectObject(hDC, hFont);
        wchar_t buf[64];
        swprintf_s(buf, L"%.1fM", m_Obj->Get_Info().vPos.x -400.f);

        SetTextColor(hDC, RGB(0, 0, 0));
        SetBkMode(hDC, OPAQUE);
   
        TextOut(hDC, 10, 10, buf, lstrlen(buf));

 
        SelectObject(hDC, oldFont);
        DeleteObject(hFont);



        //----------
          HFONT hFont1 = CreateFont(
            100,             
            0,                 
            0, 0,              
            FW_BOLD,           
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_SWISS,
            L"Arial"
        );
        HFONT oldFont1 = (HFONT)SelectObject(hDC, hFont1);
        wchar_t buf1[64];
        swprintf_s(buf1, L"2100M");

        SetTextColor(hDC, RGB(255, 0, 0));
        SetBkMode(hDC, OPAQUE);
      
        TextOut(hDC, 500, 10, buf1, lstrlen(buf1));

        // 폰트 원복 (중요)
        SelectObject(hDC, oldFont1);
        DeleteObject(hFont1);
     
    }

}

void CKMSBox::Release()
{
 
}

void CKMSBox::Key_Input()
{
}
