import sys
import time
import os
import shutil

def get_valid_name(Root, plt, dr, lg, cnt=0):
    filename = '/'.join([Root, plt, dr+("" if cnt==0 else f"_{cnt}")])
    filename += f'.{lg}'
    if os.path.exists(filename):
        return get_valid_name(Root, plt, dr, lg, cnt+1)
    else :
        return filename

lg = sys.argv[1]
plt = sys.argv[2]
dr = sys.argv[3]

Root = "C:/Users/Amine/Desktop/projects/cp"


filename = get_valid_name(Root, plt, dr, lg)

f = open(Root+"/test.txt", "a")
f.write(filename+'\n')
f.close()

if lg=="cpp":
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    shutil.copyfile(Root+"/template.cpp", filename)