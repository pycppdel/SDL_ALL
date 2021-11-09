/*
*Compiles a file from the terminal
*
*Only for *nix systems with g++ installed
*
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

#define MAX_NAMELENGTH 500


void construct_command();
void get_filename(int, char**);


char command[MAX_NAMELENGTH];
char filename[MAX_NAMELENGTH];


int main(int argc, char** argv){

  get_filename(argc, argv);
  construct_command();

  system(command);


  return 0;
}


void construct_command(){

  strncpy(command, "g++ -o ", 7);
  strncat(command, filename, strlen(filename));
  strncat(command, " ", 1);
  strncat(command, filename, strlen(filename));
  strncat(command, ".cpp", 4);
  strncat(command, " -lSDL2 -lSDL2_image -lSDL2_ttf ", strlen(" -lSDL2 -lSDL2_image -lSDL2_ttf "));
  strncat(command, "`sdl2-config --cflags --libs` ", strlen("`sdl2-config --cflags --libs` "));
}

void get_filename(int argc, char** argv){

  if(argc < 2){
    exit(1);
  }

  strncpy(filename, argv[1], strlen(argv[1]));

}
