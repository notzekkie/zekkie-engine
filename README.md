![header](https://github.com/user-attachments/assets/9b5236b7-a3ff-433b-ad26-b5eb591aa500)

![GitHub repo size](https://img.shields.io/github/repo-size/zekticezy/zekkie-engine) ![Website](https://img.shields.io/website?url=https%3A%2F%2Fengine.zekkie.dev) ![GitHub Issues or Pull Requests](https://img.shields.io/github/issues/zekticezy/zekkie-engine) ![GitHub commit activity](https://img.shields.io/github/commit-activity/w/zekticezy/zekkie-engine) ![GitHub top language](https://img.shields.io/github/languages/top/zekticezy/zekkie-engine) ![GitHub License](https://img.shields.io/github/license/zekticezy/zekkie-engine)






# Libraries
zkE is compiled using **gcc**. You can install gcc through [the MinGW MSY2](https://www.msys2.org/) by running
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```
Restarting your machine after installation may be necessary.

zkE uses the following libraries:
- SDL2
- SDL2 Image
- SDL2 TTF

# Compiling
## Windows
This guide supports all Windows versions that the libraries mentioned above support. It's still, however, recommended to use either 10/11.

First, make sure to use **MSYS MINGW64** (the blue icon).

![image](https://github.com/user-attachments/assets/2dd38a82-c858-4f75-9fdf-d0e59361a13b)

Next, head to your project directory. I use GitHub Desktop, so it'll be in `Documents/GitHub/zekkie-engine`. To head there, run:
```
cd /c/Users/<yourname>/Documents/GitHub/zekkie-engine
```
Replace `<yourname>` with your Windows user directory name.

Then, to compile zekkie Engine, run:
```bash
gcc -o program program.c $(pkg-config --cflags sdl2) $(pkg-config --libs sdl2) $(pkg-config --cflags sdl2_image) $(pkg-config --libs sdl2_image) $(pkg-config --cflags sdl2_ttf) $(pkg-config --libs sdl2_ttf) -Wl,-subsystem,console
```

Then, run the following:
```
./program
```
