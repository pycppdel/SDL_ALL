"""
resets the file to the given filename

Use: SDL_ALL_reset <PATH>

"""
import sys
import os
import pickle

meta_data = None

try:

    meta_data = pickle.load(open("meta_data.pkl", "rb"))

except FileNotFoundError:

    raise ValueError("No such folder")

#folder exists
meta_data["SDL_ALL_PATH"] = sys.argv[1]
print("\n\nchanged SDL_ALL Path to ", sys.argv[1])

pickle.dump(meta_data, open("meta_data.pkl", "wb"))
