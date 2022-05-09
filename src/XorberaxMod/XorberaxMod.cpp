#include "pch.h"
#include "Tools.h"
#include "XorberaxMod.h"
#include "LuaDumper.h"

void ShowConsole()
{
    AllocConsole();
    freopen_s(reinterpret_cast<FILE**>stdout, "CONOUT$", "w", stdout);
    freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
    freopen_s(reinterpret_cast<FILE**>(stderr), "CONOUT$", "w", stderr);
    SetConsoleTitle(L"WotR Xorberax Mod");
}

bool XorberaxMod::Start()
{
    Tools::seed_random();
    ShowConsole();
    std::cout << "WotR Xorberax Mod Injected!" << std::endl;

#ifdef XORBERAX_LUADUMPER
    XorberaxMod::LuaDumper::Initialize();
#endif

#ifdef XORBERAX_INTERACTIVE
    while (TRUE)
    {
        static int option;
        std::cout << "Choose option:" << std::endl;
        std::cout << "1 - Lua Dumper" << std::endl;
        std::cout << std::endl;
        std::cout << "Option: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            _luaDumper.Initialize();
        }

        std::cout << std::endl << "--------------------" << std::endl;
    }
#endif

    return TRUE;
}