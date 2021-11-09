#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <filesystem>
#include <string>

#define MAX_PATHLENGTH 500
/*
*
*compiles all files given by <FOLDER>
*
*/

char* folder;

char* extract_folder(int, char**);

int main(int argc, char** argv){

  chdir("/home/");

  folder = extract_folder(argc, argv);

  if(folder == NULL){
    exit(1);
  }

  char current_path[MAX_PATHLENGTH];
  strncpy(current_path,get_current_dir_name(),MAX_PATHLENGTH);

  char helper[MAX_PATHLENGTH];
  strncpy(helper, "cd ", 3);
  strncat(helper, folder, strlen(folder));
  try{
}
catch(...){

  std::cout << "Invalid path\n";
  exit(1);

}

  std::string folder_as_string(folder);

  //now in make



  return 0;
}

char* extract_folder(int argc, char** argv){

  if (argc < 2){
    return NULL;
  }

  else{

    return argv[1];

  }

}
