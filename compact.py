import numpy as np
import re
import glob
import os

params = {}
# glob file in FHE_PARAM
for filename in glob.glob("FHE_PARAM/*.bin"):
    name, shape = filename[10:-4] .split("___GPUFHE___")
    shape = list(map(int, re.findall(r'\d+', shape)))
    array = np.fromfile(filename, dtype=np.uint64).reshape(shape)
    params[name] = array
    print(name, shape)

# save to npz
np.savez_compressed("FHE_PARAM.npz", **params)
