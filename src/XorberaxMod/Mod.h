#pragma once
#include "LuaDumper.h"
#include "LuaReplacer.h"

namespace XorberaxMod
{
    class Mod
    {
    public:
        void Start();
    private:
        XorberaxMod::LuaReplacer _luaReplacer;
        XorberaxMod::LuaDumper _luaDumper;
        void ShowConsole();
    };
};
