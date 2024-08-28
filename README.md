![header](https://github.com/user-attachments/assets/9b5236b7-a3ff-433b-ad26-b5eb591aa500)

used libraries:
- SDL2
- SDL_Image
- SDL2_TTF

## Compilation Command
Make sure to use **MSYS MINGW64**. You can get MSYS2 [here](https://www.msys2.org/).
´´´
gcc -o program program.c $(pkg-config --cflags sdl2) $(pkg-config --libs sdl2) $(pkg-config --cflags sdl2_image) $(pkg-config --libs sdl2_image) $(pkg-config --cflags sdl2_ttf) $(pkg-config --libs sdl2_ttf) -Wl,-subsystem,console
´´´