#include <windows.h>
#include <string>
#include <sstream> // �����ַ���������

// ����ȫ�ֱ���
HWND hwndEditLength, hwndEditWidth, hwndEditHeight; // �������
HWND hwndResult; // �����ʾ��ǩ���

// ��Ϣ������
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE: // ���ڴ�����Ϣ
        // ���������ͱ�ǩ
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

        // ������ť
        CreateWindowEx(0, L"BUTTON", L"Calculate", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            10, 230, 100, 20, hwnd, (HMENU)1, NULL, NULL);
        CreateWindowEx(0, L"BUTTON", L"Exit", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            120, 230, 100, 20, hwnd, (HMENU)2, NULL, NULL);
        break;

    case WM_COMMAND: // ������Ϣ
        switch (LOWORD(wParam)) { // ���������ʶ��ִ�в�ͬ�Ĳ���
        case 1: // Calculate button
        {
            // ��ȡ����ֵ
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

            // ������
            double cubeSurfaceArea = 6 * length * length;
            double cubeVolume = length * length * length;
            double rectSurfaceArea = 2 * (length * width + width * height + height * length);
            double rectVolume = length * width * height;

            // ��ʾ���
            std::wstringstream result;
            result << L"Cube Surface Area: " << cubeSurfaceArea << L"\n"
                << L"Cube Volume: " << cubeVolume << L"\n"
                << L"Rectangular Prism Surface Area: " << rectSurfaceArea << L"\n"
                << L"Rectangular Prism Volume: " << rectVolume;
            SetWindowText(hwndResult, result.str().c_str());
        }
        break;

        case 2: // Exit button
            PostQuitMessage(0); // �����˳���Ϣ
            break;
        }
        break;

    case WM_DESTROY: // ����������Ϣ
        PostQuitMessage(0); // �����˳���Ϣ
        return 0; // ����0��ʾ��Ϣ�Ѵ���
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam); // ����Ĭ�ϴ��ڹ��̴���������Ϣ
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Sample Window Class"; // ���崰������

    WNDCLASS wc = {}; // ��ʼ��������ṹ��
    wc.lpfnWndProc = WindowProc; // ���ô��ڹ��̺���
    wc.hInstance = hInstance; // ����ʵ�����
    wc.lpszClassName = CLASS_NAME; // ���ô�������

    RegisterClass(&wc); // ע�ᴰ����

    HWND hwnd = CreateWindowEx(
        0,                              // ��ѡ������ʽ
        CLASS_NAME,                     // ��������
        L"Geometry Calculator",         // ���ڱ���
        WS_OVERLAPPEDWINDOW,            // ������ʽ

        // ���ڴ�С��λ��
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,

        NULL,       // �����ھ��    
        NULL,       // �˵����
        hInstance,  // ʵ�����
        NULL        // ����Ӧ�ó�������
    );

    if (hwnd == NULL) {
        return 0; // ������ڴ���ʧ�ܣ�����0
    }

    ShowWindow(hwnd, nCmdShow); // ��ʾ����

    MSG msg = {}; // ��ʼ����Ϣ�ṹ��
    while (GetMessage(&msg, NULL, 0, 0)) { // ѭ����ȡ��Ϣ
        TranslateMessage(&msg); // ���������Ϣ
        DispatchMessage(&msg); // �ַ���Ϣ�����ڹ���
    }

    return 0; // ����0��ʾ������������
}


