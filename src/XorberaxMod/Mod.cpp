#include "pch.h"
#include "Tools.h"
#include "Mod.h"
#include "LuaDumper.h"
#include "LuaReplacer.h"

using namespace Xorberax;

static void ShowConsole()
{
    AllocConsole();
    freopen_s(reinterpret_cast<FILE**>stdout, "CONOUT$", "w", stdout);
    freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
    freopen_s(reinterpret_cast<FILE**>(stderr), "CONOUT$", "w", stderr);
    SetConsoleTitle(L"WotR Xorberax Mod");
}

void Xorberax::Mod::Start()
{
    Tools::seed_random();
    ShowConsole();
    std::cout << "WotR Xorberax Mod Injected!" << std::endl;

#ifdef XORBERAX_LUADUMPER
    LuaDumper::Start();
#endif

#ifdef XORBERAX_LUAREPLACER
    LuaReplacer::Start();
#endif
}