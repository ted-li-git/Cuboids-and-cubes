#include <windows.h>
#include <string>
#include <sstream> // 用于字符串流操作

// 定义全局变量
HWND hwndEditLength, hwndEditWidth, hwndEditHeight; // 输入框句柄
HWND hwndResult; // 结果显示标签句柄

// 消息处理函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE: // 窗口创建消息
        // 创建输入框和标签
        hwndEditLength = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
            10, 10, 100, 20, hwnd, NULL, NULL, NULL);
        hwndEditWidth = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
            120, 10, 100, 20, hwnd, NULL, NULL, NULL);
        hwndEditHeight = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
            230, 10, 100, 20, hwnd, NULL, NULL, NULL);

        CreateWindowEx(0, L"STATIC", L"Length:", WS_CHILD | WS_VISIBLE,
            10, 40, 100, 20, hwnd, NULL, NULL, NULL);
        CreateWindowEx(0, L"STATIC", L"Width:", WS_CHILD | WS_VISIBLE,
            120, 40, 100, 20, hwnd, NULL, NULL, NULL);
        CreateWindowEx(0, L"STATIC", L"Height:", WS_CHILD | WS_VISIBLE,
            230, 40, 100, 20, hwnd, NULL, NULL, NULL);

        hwndResult = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE,
            10, 70, 320, 150, hwnd, NULL, NULL, NULL);

        // 创建按钮
        CreateWindowEx(0, L"BUTTON", L"Calculate", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            10, 230, 100, 20, hwnd, (HMENU)1, NULL, NULL);
        CreateWindowEx(0, L"BUTTON", L"Exit", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            120, 230, 100, 20, hwnd, (HMENU)2, NULL, NULL);
        break;

    case WM_COMMAND: // 命令消息
        switch (LOWORD(wParam)) { // 根据命令标识符执行不同的操作
        case 1: // Calculate button
        {
            // 获取输入值
            wchar_t lengthStr[10], widthStr[10], heightStr[10];
            GetWindowText(hwndEditLength, lengthStr, 10);
            GetWindowText(hwndEditWidth, widthStr, 10);
            GetWindowText(hwndEditHeight, heightStr, 10);

            double length = _wtof(lengthStr);
            double width = _wtof(widthStr);
            double height = _wtof(heightStr);

            if (length <= 0 || width <= 0 || height <= 0) {
                SetWindowText(hwndResult, L"Invalid input. Please enter positive values.");
                break;
            }

            // 计算结果
            double cubeSurfaceArea = 6 * length * length;
            double cubeVolume = length * length * length;
            double rectSurfaceArea = 2 * (length * width + width * height + height * length);
            double rectVolume = length * width * height;

            // 显示结果
            std::wstringstream result;
            result << L"Cube Surface Area: " << cubeSurfaceArea << L"\n"
                << L"Cube Volume: " << cubeVolume << L"\n"
                << L"Rectangular Prism Surface Area: " << rectSurfaceArea << L"\n"
                << L"Rectangular Prism Volume: " << rectVolume;
            SetWindowText(hwndResult, result.str().c_str());
        }
        break;

        case 2: // Exit button
            PostQuitMessage(0); // 发送退出消息
            break;
        }
        break;

    case WM_DESTROY: // 窗口销毁消息
        PostQuitMessage(0); // 发送退出消息
        return 0; // 返回0表示消息已处理
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam); // 调用默认窗口过程处理其他消息
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Sample Window Class"; // 定义窗口类名

    WNDCLASS wc = {}; // 初始化窗口类结构体
    wc.lpfnWndProc = WindowProc; // 设置窗口过程函数
    wc.hInstance = hInstance; // 设置实例句柄
    wc.lpszClassName = CLASS_NAME; // 设置窗口类名

    RegisterClass(&wc); // 注册窗口类

    HWND hwnd = CreateWindowEx(
        0,                              // 可选窗口样式
        CLASS_NAME,                     // 窗口类名
        L"Geometry Calculator",         // 窗口标题
        WS_OVERLAPPEDWINDOW,            // 窗口样式

        // 窗口大小和位置
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,

        NULL,       // 父窗口句柄    
        NULL,       // 菜单句柄
        hInstance,  // 实例句柄
        NULL        // 附加应用程序数据
    );

    if (hwnd == NULL) {
        return 0; // 如果窗口创建失败，返回0
    }

    ShowWindow(hwnd, nCmdShow); // 显示窗口

    MSG msg = {}; // 初始化消息结构体
    while (GetMessage(&msg, NULL, 0, 0)) { // 循环获取消息
        TranslateMessage(&msg); // 翻译键盘消息
        DispatchMessage(&msg); // 分发消息到窗口过程
    }

    return 0; // 返回0表示程序正常结束
}


