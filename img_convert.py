from PIL import Image
import matplotlib.pyplot as plt
import numpy as np

jpg_image_path = "./data/2007_008407.jpg"
bin_image_path = "./data/2007_008407.bin"

with Image.open(jpg_image_path) as img:
    img_300 = img.resize((300, 300))
    img_np = np.array(img_300, dtype = np.uint8)
    
    with open(bin_image_path, "wb") as bin_file:
        bin_file.write(img_np)