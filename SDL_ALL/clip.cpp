#include "utils.h"
#include "SDL_ttf.h"
#include <iostream>

#pragma comment(lib, "SDL2_ttf.lib")
#define width 800
#define height 800

void draw(struct Display*);
SDL_Texture* u;
short angle=0;

int main(){

  SDL_Rect rect ={100, 100, width, height};
  SDL_MANAGER manager(&rect);

  manager.init("EE");
  manager.setDrawMethod(draw);

  bool quit = false;
  SDL_Event e;
  SDL_Surface* g = IMG_Load("Unbenannt.png");
  u = SDL_CreateTextureFromSurface(manager.getDisplay()->renderer, g);
  SDL_FreeSurface(g);

  while (!quit){

    SDL_PollEvent(&e);

  switch(e.type){
    case SDL_QUIT:
    quit = true;
    break;
  }
  angle--;

  std::cout << angle << "\n";
  std::cout.flush();

  manager.draw();


  }
  SDL_DestroyTexture(u);
  manager.deinit();


  return 0;
}

void draw(struct Display* display){

  SDL_Renderer* r = display->renderer;
  SDL_RenderClear(r);
  SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderCopyEx(r, u, NULL, NULL, angle, NULL, SDL_FLIP_NONE);
  SDL_RenderPresent(r);
}
