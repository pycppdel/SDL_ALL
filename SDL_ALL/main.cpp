#include "../../SDL_ALL/SDL_ALL/utils.h"
#include <ctime>
#include <iostream>
#define width 800
#define height 800

class Timer;
class Stickman;

void draw(struct Display*);

class Timer{

private:

  double interval;

public:

  bool is_set;
  clock_t start, current;

  Timer();
  Timer(double interval);
  bool time_impulse();
  ~Timer();

};

class Stickman{

private:

  SDL_Renderer* r;
  SDL_Texture *stehend, *gehend;
  Timer timer;
  bool steht;

public:


  Stickman();
  ~Stickman();

  void setRender(SDL_Renderer*);
  void modify();
  void draw();


};

Stickman man;

int main(){

  SDL_Rect window = {100, 100, width, height};
  SDL_MANAGER manager(&window);
  manager.init("window");
  manager.setDrawMethod(draw);

  bool quit = false;
  SDL_Event e;
  Timer t(2.0);
  std::cout.setf(std::ios_base::unitbuf);
  man.setRender(manager.getDisplay()->renderer);

  while(!quit){

    SDL_PollEvent(&e);

    switch(e.type){
      case SDL_QUIT:
                    quit = true;
                    break;
    }
    man.modify();

    manager.draw();

  }

  manager.deinit();
  std::cout.unsetf(std::ios_base::unitbuf);

  return 0;
}

void draw(struct Display* display){

  SDL_Renderer* r = display->renderer;
  SDL_RenderClear(r);
  SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
  ::man.draw();
  SDL_RenderPresent(r);
}

Timer::Timer(){

}

Timer::Timer(double val){
  interval = val;
  is_set = false;
  start = clock()/CLOCKS_PER_SEC;
  current = start;
}

Timer::~Timer(){

}

bool Timer::time_impulse(){

  current = clock()/CLOCKS_PER_SEC;

  if((current - start) >= interval){
    start = current;
    is_set = true;

  }

  else{
    is_set = false;
  }
  return is_set;

}


Stickman::~Stickman(){
  SDL_DestroyTexture(stehend);
  SDL_DestroyTexture(gehend);
}

Stickman::Stickman(){
  r = NULL;
  steht = true;


  timer = Timer(1);

}

void Stickman::setRender(SDL_Renderer* render){
  r = render;
  SDL_Surface* s = IMG_Load("Unbenannt.png");
  stehend = SDL_CreateTextureFromSurface(r, s);
  s = IMG_Load("unbenannt2.png");
  gehend = SDL_CreateTextureFromSurface(r, s);
  SDL_FreeSurface(s);
}

void Stickman::draw(){

if(steht){
  SDL_RenderCopy(r, stehend, NULL, NULL);
}
else{
  SDL_RenderCopy(r, gehend, NULL, NULL);
}

}

void Stickman::modify(){

  if (timer.time_impulse()){

    steht = !steht;

  }


}
