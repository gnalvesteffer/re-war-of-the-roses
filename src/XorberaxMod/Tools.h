#pragma once
namespace Tools
{
    void memcpy_s(PVOID address, char* val, int bytes);
    bool Detour32(void* src, void* dst, int len);
    char* TrampolineHook32(char* src, char* dst, const intptr_t len);
    void seed_random();
};

