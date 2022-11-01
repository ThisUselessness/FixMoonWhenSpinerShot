#include <Windows.h>
#include <iostream>
#include <thread>

void Init() {
	DWORD BaseModule = (DWORD)GetModuleHandle(L"gta_sa.exe");
	while (true) { *reinterpret_cast<int*>(*reinterpret_cast<DWORD*>(BaseModule + 0x00AA7E2C) + 0xE4C) = 0; }
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dReason, LPVOID lReserved) {
	if (dReason == DLL_PROCESS_ATTACH) {
		std::thread(Init).detach();
	}
	return TRUE;
}