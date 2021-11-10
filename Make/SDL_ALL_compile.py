"""
Compiles the file given by the first arguments with arguments -I and -A for add
"""

import sys
import os
import pickle

"""
First: checking for pickle
"""

__FILENAME__ = "meta_data.pkl"

#if meta data was loaded
meta_data_loaded = True

print("\n")

try:

    meta_data =  pickle.load(open(__FILENAME__, "rb"))

except FileNotFoundError:

    print("First use <SDL_ALL_SETUP> with the option -SDL to setup your SDL_ALL System")
    meta_data_loaded = False

filename = (sys.argv[1] if len(sys.argv) > 1 else None)

index = 0
#making lists for arguments
includelist = []
addlist = []

for el in sys.argv:

    if el == "-I":

        includelist.append(sys.argv[index+1])
    elif el == "-A":

        addlist.append(sys.argv[index+1])

    index += 1

#checking all files
for el in includelist+addlist:

    if not os.path.exists(el):
        print("PATH "+el+" DOES NOT EXIST")
        meta_data_loaded = False

if filename is None:
    meta_data_loaded = False

#everything is correct: starting compilation
if meta_data_loaded:

    SDL_ALL_PATH = meta_data["SDL_ALL_PATH"] #got path
    #now ready for compiling

    #creating string
    compilestring = "".join([

    "g++ ",
    "-o ",
    filename[0:filename.find(".cpp")]+" ",
    filename+" ",
    SDL_ALL_PATH+"Includes/utils.cpp ",


    ])

    for el in addlist:

        compilestring += el+" "

    compilestring += "-lSDL2 -lSDL2_image -lSDL2_ttf `sdl2-config --cflags --libs` "
    compilestring += "-I "+SDL_ALL_PATH+"Includes/"

    os.system(compilestring)






print("\n")
