#pragma once
namespace XorberaxMod
{
    class LuaReplacer
    {
    public:
        /// <summary>
        /// Hooks luaL_loadbuffer to replace lua scripts from ones on the file system as they are loaded.
        /// </summary>
        static void Start();
    private:
        static std::string* GetReplacementLuaScript(const char* buff, size_t sz, const char* name);
        static int __cdecl LuaLoadBufferHook(lua_State* L, const char* buff, size_t sz, const char* name);
    };
}