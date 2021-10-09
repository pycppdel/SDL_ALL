/*

In this file all the utilities and setup structures for development needed are stored
It includes SDL_ALL automatically

*/

#ifndef SDL_UTILS_ALL
#define SDL_UTILS_ALL
#include "SDL_ALL.h"
#include <list>
#include <string>
//needed: General structures for storing data and interacting

class LTexture;
class SDL_MANAGER;
struct Display;

//for storing window, screen as well as the renderer
struct Display{

  SDL_Window* window;
  SDL_Surface* screen;
  SDL_Renderer* renderer;


};

class LTexture{

private:

  SDL_Texture* texture;
  SDL_Rect* clip;
  SDL_Rect* position;

public:

  LTexture();
  LTexture(std::string);
  LTexture(std::string, SDL_Rect*);
  LTexture(std::string, SDL_Rect*, SDL_Rect*);
  ~LTexture();

  void setupTexture();

  SDL_Texture* getTexture();
  void changeClip(SDL_Rect*);
  void changePosition(SDL_Rect*);


};

//class for managing all structures
class SDL_MANAGER{

private:

  Display display;
  void (*drawmethod)(Display*);
  std::list<LTexture> textures;

public:

  SDL_MANAGER();
  ~SDL_MANAGER();

  bool init();
  bool deinit();

  void setDrawMethod(void (*d)(Display*));
  void draw();

  LTexture* addTexture(char*);
  bool removeTexture(LTexture*);

  Display* getDisplay();
  std::list<LTexture>* getTextures();




};



#endif
