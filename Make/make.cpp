/*
* Creates a file with a setup skeleton used for SDL_ALL
*
* Usage: make <FILENAME> (OPTIONAL)-D <DIRECTORY>
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <cerrno>
#include <cstdlib>
#include <sys/stat.h>
#include <string>
#include <vector>

#define MAX_DIRNAME_LENGTH 500


bool directory_is_given(int, char**);
bool directory_is_valid(char*);
char* directory_name(char**);
int directory_namelength(char**);

bool filename_is_valid(int, char**, char*);
char* file_name(char**);
int file_namelength(char**);

void add_sentences(std::vector<std::string>*);


char* dirname;
char* filename;
bool directory_name_was_given;

std::vector<std::string> plaintext;


int main(int argc, char** argv){


/*
*
* starting main activity
*
*/

dirname = new char[MAX_DIRNAME_LENGTH];

if(directory_is_given(argc, argv)){

  /*
  *
  * Now it should be determined which directory you chose
  *
  */

if(!directory_is_valid(argv[3])){

  //directory is invalid

  std::cout << "\n\nDirectory " << directory_name(argv) << " does not exist" << std::endl;
  std::cout.flush();
  exit(1);

}



//directory is valid
//assigning directory name
directory_name_was_given = true;

//making directory variable
strncpy(dirname, directory_name(argv), directory_namelength(argv));

std::cout << "\nregistering directory (" << dirname << ")...\n";


}
else{
  directory_name_was_given = false;
  strncpy(dirname, "", strlen(dirname));
}


/*
*Testing filename
*/
if(!filename_is_valid(argc, argv, dirname)){

std::cout << "\n\n" << "Filename is invalid" << std::endl;
delete [] dirname;


exit(1);

}

//test passed

filename = new char[MAX_DIRNAME_LENGTH];

if(directory_name_was_given){
  strncpy(filename, dirname, strlen(dirname));
}
strncat(filename, file_name(argv), file_namelength(argv));
strncat(filename, ".cpp", 4);

//filename is constructed

//opening and writing text

std::ofstream stream;

stream.open(filename, std::ios::out);

/*
*constructing text
*/

/*
*
* adding sentences
*
*/

add_sentences(&plaintext);

for(int i=0;i<plaintext.size();i++){

  stream.write(plaintext[i].c_str(), strlen(plaintext[i].c_str()));

}


stream.close();


delete [] dirname;
delete [] filename;


}





bool directory_is_given(int argc, char** argv){

  //checks whether the optional -D directive was used
  if(argc < 3){
    return false;
  }
  int compared;
  if(argc > 2){
    char dname[3] = "-D";
    compared = strncmp(argv[2], "-D", 3);
  }
  return ((argc == 4) && (compared==0));

}

bool directory_is_valid(char* dirname){

  //checks if the directory exists
  struct stat s;

  return (stat(dirname, &s)==0 && (s.st_mode & S_IFDIR));


}

char* directory_name(char** argv){

  return argv[3];

}

int directory_namelength(char** argv){
  return strlen(argv[3]);
}


bool filename_is_valid(int argc, char** argv, char* prefix){

  //checks if filename is valid by checking if file exists

  //checking if argv is enough

  if(argc < 2){
    return false;
  }



  return true;

  }



char* file_name(char** argv){

  return argv[1];
}

int file_namelength(char** argv){

  return strlen(argv[1]);
}

void add_sentences(std::vector<std::string>* vec){

vec->push_back("#include <iostream>\n");
vec->push_back("#include \"utils.h\"\n");
vec->push_back("\n");
vec->push_back("#define width 800\n");
vec->push_back("#define height 800\n");
vec->push_back("#define X 100\n");
vec->push_back("#define Y 100\n");
vec->push_back("#define APP_NAME \"__\"\n");
vec->push_back("\n\n");
vec->push_back("void draw(struct Display*);\n");
vec->push_back("\n\n");
vec->push_back("int main(int argc, char** argv){\n");
vec->push_back("\n");
vec->push_back("SDL_Rect rect = {X, Y, width, height};\n");
vec->push_back("\n");
vec->push_back("SDL_MANAGER manager(&rect);\n");
vec->push_back("manager.init(APP_NAME);\n");
vec->push_back("manager.setDrawMethod(draw);\n");
vec->push_back("\n");
vec->push_back("bool quit = false;\n");
vec->push_back("SDL_Event evt;\n");
vec->push_back("\n");
vec->push_back("while(!quit){\n");
vec->push_back("\n");
vec->push_back("SDL_PollEvent(&evt);\n");
vec->push_back("\n");
vec->push_back("switch(evt.type){\n");
vec->push_back("\n");
vec->push_back("case SDL_QUIT:\n");
vec->push_back("              //do something\n");
vec->push_back("              quit = true;\n");
vec->push_back("              break;\n");
vec->push_back("}\n");
vec->push_back("\n");
vec->push_back("manager.draw();\n");
vec->push_back("\n");
vec->push_back("}\n");
vec->push_back("\n");
vec->push_back("manager.deinit();\n");
vec->push_back("\n");
vec->push_back("return 0;\n");
vec->push_back("\n");
vec->push_back("}\n");
vec->push_back("\n");
vec->push_back("\n");
vec->push_back("void draw(struct Display* display){\n");
vec->push_back("\n");
vec->push_back("SDL_Renderer* r = display->renderer;\n");
vec->push_back("\n");
vec->push_back("SDL_RenderClear(r);\n");
vec->push_back("SDL_SetRenderDrawColor(r, 0x0, 0x0, 0x0, 0x0);\n");
vec->push_back("SDL_RenderPresent(r);\n");
vec->push_back("\n");
vec->push_back("}\n");




}
