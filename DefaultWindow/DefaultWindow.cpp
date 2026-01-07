// DefaultWindow.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "DefaultWindow.h"
#include "CMainGame.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND g_hWnd;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DEFAULTWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEFAULTWINDOW));

    MSG msg;
    msg.message = WM_NULL;

    CMainGame   MainGame;
    MainGame.Initialize();

    DWORD   dwTime = GetTickCount();

    // 기본 메시지 루프입니다:
    while (true)
    {
        // PM_REMOVE : 메세지 큐로부터 메세지를 가져오면서 실행(메세지 큐에서 기존 메세지는 삭제)
        // PM_NOREMOVE : 메세지가 들어왔는지만 확인하고 있으면 실행, 없으면 대기(Getmessage를 다시 호출 해야 메세지를 가져올 수 있음)

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        else
        {
            if (dwTime + 10 < GetTickCount())
            {
                MainGame.Update();
                MainGame.Late_Update();
                MainGame.Render();
           
                dwTime = GetTickCount();
            }        

            //MainGame.Update();
            //MainGame.Late_Update();
            //MainGame.Render();
        }
        
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    // 자기 자신의 크기를 세팅

    wcex.style          = CS_HREDRAW | CS_VREDRAW;

    wcex.lpfnWndProc    = WndProc;

    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;

    wcex.hInstance      = hInstance;

    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEFAULTWINDOW));

    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);

    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    
    wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_DEFAULTWINDOW);

    wcex.lpszClassName  = szWindowClass;

    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   RECT     rc{ 0, 0, WINCX, WINCY };

   // rc = rc + 기본 창 옵션 + 메뉴 바 크기 고려 여부

   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, // 창 시작 x, y 좌표
      rc.right - rc.left,
      rc.bottom - rc.top, // 창 가로, 세로 사이즈
      nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   g_hWnd = hWnd;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

// 1. KERNEL : 메모리 할당 명령어 라이브러리
// 2. USER : 유저 인터페이스와 관련된 명령어 라이브러리
// 3. GDI : 그리기 명령어 라이브러리

//RECT       rc{ 100, 100, 200, 200 };
//list<RECT>  BulletList;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{


    switch (message)
    {
   // case WM_CREATE:
   //     SetTimer(hWnd, 0, 0, 0);
   //     // 1. 윈도우 핸들 지정
   //     // 2. 타이머의 id 번호
   //     // 3. 타이머의 주기(기본값 1 / 1000 초)
   //     // 4. NULL인 경우, 3번에서 설정한 주기대로 WM_TIMER 메세지를 발생
   //     break;
   //
   // case WM_TIMER:
   //
   //     InvalidateRect(hWnd, 0, TRUE);
   //
   //     // 1. 창 핸들
   //     // 2. 윈도우 안에 갱신할 범위 지정(rect 주소가 들어감), NULL인 경우 윈도우 전체 영역
   //     // 3. TRUE : 그려져 있는 않는 부분도 모두 갱신
   //     //    FALSE : 그리는 부분만 갱신
   //     break;



    case WM_KEYDOWN :

        switch (wParam)
        {
        case VK_ESCAPE:
            DestroyWindow(g_hWnd);
            break;

        //case VK_RIGHT:
        //    rc.left += 10;
        //    rc.right += 10;
        //    break;
        //
        //case VK_LEFT:
        //    rc.left  -= 10;
        //    rc.right -= 10;
        //    break;
        //
        //case VK_UP:
        //    rc.top    -= 10;
        //    rc.bottom -= 10;
        //    break;
        //
        //case VK_DOWN:
        //    rc.top    += 10;
        //    rc.bottom += 10;
        //    break;      
        //
        //case VK_SPACE:
        //    BulletList.push_back(rc);
        //    break;
        }

        break;



    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

    //case WM_PAINT:
    //    {
    //        PAINTSTRUCT ps;
    //        HDC hdc = BeginPaint(hWnd, &ps);
    //      
    //        // MoveToEx : 커서의 위치를 이동
    //        //MoveToEx(hdc, 100, 100, nullptr);
    //        //
    //        //LineTo(hdc, 200, 100);
    //        //LineTo(hdc, 200, 200);
    //        //LineTo(hdc, 100, 200);
    //        //LineTo(hdc, 100, 100);
    //        //LineTo(hdc, 200, 200);
    //        //
    //        //MoveToEx(hdc, 200, 100, nullptr);
    //        //LineTo(hdc, 100, 200);
    //
    //
    //        // 선 그리기
    //        //LineTo(hdc, 200, 200);
    //        //
    //        //LineTo(hdc, 200, 300);
    //
    //      //  Rectangle(hdc, 100, 100, 200, 200);
    //       // Ellipse(hdc, 300, 300, 400, 400);
    //
    //        Rectangle(hdc,rc.left, rc.top, rc.right, rc.bottom);
    //
    //        for (auto& bullet : BulletList)
    //        {
    //            Ellipse(hdc, bullet.left, bullet.top, bullet.right, bullet.bottom);
    //
    //            bullet.top -= 10;
    //            bullet.bottom -= 10;
    //
    //        }
    //
    //
    //        EndPaint(hWnd, &ps);
    //    }
    //    break;


    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
