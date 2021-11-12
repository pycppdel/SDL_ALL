
"""
Python script for adding files of translated executables to path.

scripts will first be compiled, then all will be added to the PATH
"""

#for determining the system
import platform
import sys
import os
import pickle
#filename for pickle

__FILENAME__ = "meta_data.pkl"


#where the actual compiled folders will go
actual_compiled_home_folders = []

#files to compile in make

make_compile_names = [ endfile for root, dirs, file in os.walk(".", topdown=False) for endfile in file if endfile.endswith(".cpp")]

print(" \n".join(["compiling...\n", *make_compile_names]))

#saving current path
current_path = os.getcwd()

#setting system name to check for operating system
system_name = ("windows" if platform.platform().startswith("windows") else "linux")

#parsing home path
home_names = []

#Path for the files to be translated to .exe or .elf
SDL_ALL_PATH = None

index = 0


for command in sys.argv:
    if command == "-H":

        home_names.append(sys.argv[index+1])

        if not os.path.exists(sys.argv[sys.argv.index(command)+1]):

            raise ValueError("Folder doesn't exist")

    index += 1

if "-SDL" in sys.argv:

    SDL_ALL_PATH = sys.argv[sys.argv.index("-SDL")+1]
else:

    raise ValueError("No SDL path specified")

if not os.path.exists(SDL_ALL_PATH):

    raise ValueError("SDL path not valid")

if not home_names:

    raise ValueError("No home folders given")

#loading file
try:
    meta_data = pickle.load(open(__FILENAME__, "rb"))

except FileNotFoundError:
    meta_data = {"SDL_ALL_PATH": SDL_ALL_PATH, "FILE_EXPORT": {}}



if system_name == "linux":

    #linux system:
    #need to edit the .bashrc file in home folder
    #home folder has to be parsed


    #starting by setting the path to the SDL folder
    os.environ["PATH"] += ":"+SDL_ALL_PATH
    os.environ["PATH"] += ":"+SDL_ALL_PATH+"/Make/"

    #variable set, now moving on to setting the variable in .bashrc file


    for el in home_names:

        if meta_data and el in meta_data["FILE_EXPORT"].keys() and meta_data["FILE_EXPORT"][el] == SDL_ALL_PATH:

            #was exported, skipping
            continue


        os.chdir(el)
        #editing .bashrc
        bashtext = ""
        with open(".bashrc", "r") as f:
            bashtext = f.read()

        #exporting
        with open(".bashrc", "w") as f:


            f.write(bashtext+\
                    "export PATH="+SDL_ALL_PATH+":$PATH\n"+\
                    "export PATH="+SDL_ALL_PATH+"/Make/"+":$PATH\n"\
            )
        actual_compiled_home_folders.append(el)

    #all files written.
    #now the compilation step

    try:

        os.system("g++ --help > del.txt")
        os.system("rm del.txt")

    except Exception:

        raise InvalidOperationError("Try installing g++ first")

    os.chdir(SDL_ALL_PATH+"/Make/")

    for el in make_compile_names:

        os.system("g++ -w -o "+el[0:el.find(".cpp")]+" "+el)




elif system_name == "windows":
    pass


#last step: pickling the path data
#structure:
#
#meta_data = [
#             SDL_ALL_PATH: str
#             PATH_WAS_SET: dict{[str, str]: bool}
#
#
#            ]



meta_data_extended = {

#setting all made paths
el1: SDL_ALL_PATH for el1 in actual_compiled_home_folders

}

meta_data["FILE_EXPORT"].update(meta_data_extended)

pickle.dump(meta_data, open(__FILENAME__, "wb"))

os.chdir(current_path)
