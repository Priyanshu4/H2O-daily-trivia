""" Automatically generates backgrounds_data.hpp using background png files in assets folder
"""
import os
import PIL
import PIL.Image
import numpy as np
import glob

BACKGROUNDS_FOLDER_PATH = os.path.join("..", "..", "..", "assets", "backgrounds")
OUTPUT_HEADER_PATH = os.path.join("..", "backgrounds_data.hpp")
SCREEN_HEIGHT = 240
SCREEN_WIDTH = 320

INITIAL_HEADER_FILE_LINES = '#pragma once\n#include "background.hpp"\n#include <pico/platform.h>\nnamespace pico_trivia\n{\n'
TERMINATING_HEADER_FILE_LINES = '\n}'


def to_rgb332(rgba_tuple):
    """ Takes a tuple of rgba values from 0 to 255 and converts to a single 0 to 255 integer representing a RGB332 value
    """
    r = rgba_tuple[0]
    g = rgba_tuple[1]
    b = rgba_tuple[2]
    rgb332 = (r & 0b11100000) | ((g & 0b11100000) >> 3) | ((b & 0b11000000) >> 6)
    return rgb332

if __name__ == "__main__":

    background_pngs = glob.glob(os.path.join(BACKGROUNDS_FOLDER_PATH, '*.png'))
    print("Generating data for the following backgrounds:")

    
    with open(OUTPUT_HEADER_PATH, 'w+') as f:
        f.write(INITIAL_HEADER_FILE_LINES)


        for png_filename in background_pngs:

            background_name = os.path.basename(png_filename)[:-4]

            image = PIL.Image.open(png_filename)
            image = np.asarray(image)
            
            image_height = image.shape[0]
            image_width = image.shape[1]
            data_bytes = int(image_height * image_width)
            
            if image_height != SCREEN_HEIGHT or image_width != SCREEN_WIDTH:
                raise ValueError(f"Background image {png} has incorrect dimensions")


            f.write(f'\n\tconst pimoroni::RGB332 __in_flash() {background_name}_background_rgbdata[{data_bytes}] = ')
            f.write('{')
            for row in image:
                for pixel in row:
                    rgb332 = to_rgb332(pixel)
                    # special correction for bamboo png
                    if background_name == "bamboo" and rgb332 == 255:
                        rgb332 = 254
                    f.write(f'{hex(rgb332)},')
            f.write('};')
            f.write(f"\n\tBackground {background_name}_background({background_name}_background_rgbdata);")


            print(png_filename)

        f.write(TERMINATING_HEADER_FILE_LINES)

    print(f"{OUTPUT_HEADER_PATH} successfully created")





