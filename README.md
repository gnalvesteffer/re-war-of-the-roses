# War of the Roses
A reverse-engineering effort to revive the abandonware live-service game "War of the Roses", which was shutdown many years ago and unable to be played.

Built for the War of the Roses Balance Beta (available on Steam if you own WotR).
This reverse engineering effort is focused on the Balance Beta specifically because it is the only branch of the game that I can get to run. 
The main branch crashes at startup, so I figured the Balance Beta would be a suitable starting point, as it displays splash videos, and attempts to load the game (but fails to connect to the official backend services).

## Prerequisites
- Must already own `War of the Roses` on Steam.
    - NOTE: You can no longer purchase the game, as it has been delisted.

## Installation
- Install `War of the Roses`
- Install the `War of the Roses Balance Beta`
- Copy the `wotr.exe` from `War of the Roses Balance Beta` to the `War of the Roses` folder (you can rename it to `wotr-beta.exe` avoid replacing the original `wotr.exe`).
- Create a shortcut to the beta `wotr.exe` and add the following command line argument: `-bundle-dir bundle`
- Use a DLL Injector (such as [Xenos Injector](https://github.com/DarthTon/Xenos/releases)) to inject XorberaxMod.dll into the game on startup.
    - NOTE: It is important that the DLL is injected as soon as the game is launched.
- If successful, a console should appear with the message `WotR Xorberax Mod Injected!`.