# Reverse Engineering War of the Roses
Reverse Engineering notes for the beta `wotr.exe` / War of the Roses Balance Beta.

## BitSquid Engine
- The game is built on the [BitSquid Engine](https://en.wikipedia.org/wiki/Bitsquid).
- A behind the scenes PDF from the developers of the engine was found at https://www.kth.se/social/upload/5289cb3ff276542440dd668c/bitsquid-behind-the-scenes.pdf, which I've archived [here](resources/bitsquid-behind-the-scenes.pdf).

## LuaJit
- The game/engine uses [LuaJit](https://luajit.org) 2.0.0 beta 10.
- [LuaJit on Github](https://github.com/LuaDist/luajit).

## Relevant Addresses
- `0x005DD090` - luaL_loadbuffer
