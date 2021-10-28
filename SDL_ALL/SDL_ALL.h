#ifndef SDL_ALL
#define SDL_ALL
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#ifdef __linux__
#include <png.h>
#include <zlib.h>
#endif

#ifdef _WIN32
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_mixer.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#undef main
#endif

#endif
