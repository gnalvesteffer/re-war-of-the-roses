#include "pch.h"
#include "NativeFunctions.h"
#include "LuaDumper.h"
#include "Tools.h"

static std::string _luaScriptReplacementDirectory;
static luaL_loadbuffer _luaLoadBufferOriginal = reinterpret_cast<luaL_loadbuffer>(GetProcAddress(GetModuleHandle(NULL), "luaL_loadbuffer"));
static luaL_loadbuffer _luaLoadBufferTrampoline;

void XorberaxMod::LuaDumper::DumpLuaScript(
    const char* buff,
    size_t sz,
    const char* name
)
{
    auto luaScriptFilePath = _luaScriptReplacementDirectory + name;
    std::replace(luaScriptFilePath.begin(), luaScriptFilePath.end(), '/', '\\'); // Sanitize file path, replacing forward slashes with backslashes.
    std::cout << "LuaDumper | Processing script: " << name << ", Output: " << luaScriptFilePath << std::endl;

    // Dump Lua script to file.
    auto luaScriptDirectory = luaScriptFilePath.substr(0, luaScriptFilePath.find_last_of('\\'));
    std::filesystem::create_directories(luaScriptDirectory);
    std::ofstream luaScriptFileStream(luaScriptFilePath);
    for (size_t characterIndex = 0; characterIndex < sz; ++characterIndex)
    {
        luaScriptFileStream << buff[characterIndex];
    }
    luaScriptFileStream.close();
}

int __cdecl XorberaxMod::LuaDumper::LuaLoadBufferHook(
    lua_State* L,
    const char* buff,
    size_t sz,
    const char* name
)
{
    XorberaxMod::LuaDumper::DumpLuaScript(buff, sz, name);
    return _luaLoadBufferTrampoline(L, buff, sz, name);
}

void XorberaxMod::LuaDumper::Start()
{
    std::cout << "LuaDumper | Enter output directory (ensure path ends with \"\\\"): ";
    std::getline(std::cin, _luaScriptReplacementDirectory);
    std::cout << std::endl;
    std::cout << "LuaDumper | Attempting to install hook for luaL_loadbuffer (" << _luaLoadBufferOriginal << ") with " << XorberaxMod::LuaDumper::LuaLoadBufferHook << "." << std::endl;
    _luaLoadBufferTrampoline = (luaL_loadbuffer)Tools::TrampolineHook32((char*)_luaLoadBufferOriginal, (char*)XorberaxMod::LuaDumper::LuaLoadBufferHook, 7);
    std::cout << "LuaDumper | Hook installation succeeded!" << std::endl;
}