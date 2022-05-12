#pragma once
#include "pch.h"
#include <luajit.h>

namespace Xorberax::NativeFunctions
{
	typedef int(__cdecl* luaL_loadbuffer)(lua_State* L, const char* buff, size_t sz, const char* name);
}