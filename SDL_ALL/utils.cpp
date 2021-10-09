#include "utils.h"



//LTexture

LTexture::LTexture(){

}

LTexture::LTexture(std::string path){

}

LTexture::LTexture(std::string path, SDL_Rect* clip){

}

LTexture::LTexture(std::string path, SDL_Rect* clip, SDL_Rect* position){

}

void LTexture::setupTexture(){

}

SDL_Texture* LTexture::getTexture(){

  return NULL;

}

void LTexture::changeClip(SDL_Rect* clip){

}

void LTexture::changePosition(SDL_Rect* position){

}


LTexture::~LTexture(){

}

//SDL_Manager
SDL_MANAGER::SDL_MANAGER(){


}

SDL_MANAGER::~SDL_MANAGER(){


}

bool SDL_MANAGER::init(){

  return true;
}

bool SDL_MANAGER::deinit(){

  return true;
}

void SDL_MANAGER::setDrawMethod(void (*method)(Display*)){

}

void SDL_MANAGER::draw(){

}

Display* SDL_MANAGER::getDisplay(){

  return &display;

}

std::list<LTexture>* SDL_MANAGER::getTextures(){

  return &textures;
}
