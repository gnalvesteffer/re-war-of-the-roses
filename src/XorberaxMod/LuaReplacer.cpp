#include "pch.h"
#include "NativeFunctions.h"
#include "LuaReplacer.h"
#include "Tools.h"

using namespace Xorberax::NativeFunctions;

static std::string _luaScriptReplacementDirectory;
static luaL_loadbuffer _luaLoadBufferOriginal = reinterpret_cast<luaL_loadbuffer>(GetProcAddress(GetModuleHandle(NULL), "luaL_loadbuffer"));
static luaL_loadbuffer _luaLoadBufferTrampoline;

/*
    BUG: Game crashes when replacing Lua script from file. Need to investigate.
*/
static std::string* GetReplacementLuaScript(
    const char* buff,
    size_t sz,
    const char* name
)
{
    auto luaScriptFilePath = _luaScriptReplacementDirectory + name;
    std::replace(luaScriptFilePath.begin(), luaScriptFilePath.end(), '/', '\\'); // Sanitize file path, replacing forward slashes with backslashes.
    std::cout << "LuaReplacer | Processing script: " << name << ", Replacing with: " << luaScriptFilePath << std::endl;

    // Replace Lua script from script in file system.
    std::ifstream luaScriptFileStream(luaScriptFilePath, std::ios_base::binary);
    std::stringstream luaScriptStringStream;
    luaScriptStringStream << luaScriptFileStream.rdbuf();
    luaScriptFileStream.close();
    return new std::string(luaScriptStringStream.str());
}

static int __cdecl LuaLoadBufferHook(
    lua_State* L,
    const char* buff,
    size_t sz,
    const char* name
)
{
    auto replacementLuaScript = GetReplacementLuaScript(buff, sz, name);
    return _luaLoadBufferTrampoline(L, replacementLuaScript->c_str(), replacementLuaScript->length(), name);
}

void Xorberax::LuaReplacer::Start()
{
    std::cout << "LuaReplacer | Enter replacement script directory (ensure path ends with \"\\\"): ";
    std::getline(std::cin, _luaScriptReplacementDirectory);
    std::cout << std::endl;
    std::cout << "LuaReplacer | Attempting to install hook for luaL_loadbuffer (" << _luaLoadBufferOriginal << ") with " << LuaLoadBufferHook << "." << std::endl;
    _luaLoadBufferTrampoline = (luaL_loadbuffer)Tools::TrampolineHook32((char*)_luaLoadBufferOriginal, (char*)LuaLoadBufferHook, 7);
    std::cout << "LuaReplacer | Hook installation succeeded!" << std::endl;
}