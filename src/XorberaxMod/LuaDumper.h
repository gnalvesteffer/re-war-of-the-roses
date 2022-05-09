#pragma once
namespace XorberaxMod::LuaDumper
{
    /// <summary>
    /// Hooks luaL_loadbuffer to dump lua scripts as they are loaded.
    /// </summary>
    void Initialize();
}