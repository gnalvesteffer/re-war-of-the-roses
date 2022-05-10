#include "pch.h"
#include "Tools.h"
#include "Mod.h"
#include "LuaDumper.h"
#include "LuaReplacer.h"
#include "Mod.h"

void XorberaxMod::Mod::ShowConsole()
{
    AllocConsole();
    freopen_s(reinterpret_cast<FILE**>stdout, "CONOUT$", "w", stdout);
    freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
    freopen_s(reinterpret_cast<FILE**>(stderr), "CONOUT$", "w", stderr);
    SetConsoleTitle(L"WotR Xorberax Mod");
}

void XorberaxMod::Mod::Start()
{
    Tools::seed_random();
    ShowConsole();
    std::cout << "WotR Xorberax Mod Injected!" << std::endl;

#ifdef XORBERAX_LUADUMPER
    this->_luaDumper.Start();
#endif

#ifdef XORBERAX_LUAREPLACER
    this->_luaReplacer.Start();
#endif
}