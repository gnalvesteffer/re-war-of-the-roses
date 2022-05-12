#pragma once
namespace Xorberax::LuaReplacer
{
    /// <summary>
    /// Hooks luaL_loadbuffer to replace lua scripts from ones on the file system as they are loaded.
    /// </summary>
    void Start();
}