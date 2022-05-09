#include "pch.h"
#include "NativeFunctions.h"
#include "LuaDumper.h"
#include "Tools.h"

static luaL_loadbuffer _luaLoadBufferOriginal = reinterpret_cast<luaL_loadbuffer>(GetProcAddress(GetModuleHandle(NULL), "luaL_loadbuffer"));
static luaL_loadbuffer _luaLoadBufferTrampoline;

int __cdecl LuaLoadBufferHook(
    lua_State* L,
    const char* buff,
    size_t sz,
    const char* name
)
{
    std::cout << "LuaLoadBufferHook: Processing script \"" << name << "\"" << std::endl;
    // TODO: dump script contents to files
    return _luaLoadBufferTrampoline(L, buff, sz, name);
}

void XorberaxMod::LuaDumper::Initialize()
{
    std::cout << "LuaDumper attempting to install hook for luaL_loadbuffer (" << _luaLoadBufferOriginal << ") with " << LuaLoadBufferHook << "." << std::endl;
    _luaLoadBufferTrampoline = (luaL_loadbuffer)Tools::TrampolineHook32((char*)_luaLoadBufferOriginal, (char*)LuaLoadBufferHook, 7);
    std::cout << "LuaDumper hook installation succeeded!" << std::endl;
}