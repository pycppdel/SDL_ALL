"""
resets the file to the given filename

Use: SDL_ALL_reset <PATH>

"""
import sys
import os
import pickle
import platform

meta_data = None

try:

    meta_data = pickle.load(open("meta_data.pkl", "rb"))

except FileNotFoundError:

    raise ValueError("No such folder")

#folder exists
meta_data["SDL_ALL_PATH"] = sys.argv[1]
print("\n\nchanged SDL_ALL Path to ", sys.argv[1])

home_folders = [el for el in meta_data["FILE_EXPORT"]]

if platform.platform().startswith("windows"):
    pass
else:

    current_path = os.getcwd()
    for el in meta_data["FILE_EXPORT"]:
        os.chdir(el)

        text = []
        with open(".bashrc", "r") as f:
            text = f.readlines()

        text = [el for el in text if "SDL_ALL" not in el]
        with open(".bashrc", "w") as f:
            f.write("".join(text))

    meta_data = []

    pickle.dump(meta_data, open("meta_data.pkl", "wb"))
    os.chdir(sys.argv[1]+"Make/")
    os.system("python3 SDL_ALL_SETUP.py -SDL "+sys.argv[1]+" "+\

    " ".join(["-H "+el for el in home_folders])

    )
    os.chdir(current_path)
