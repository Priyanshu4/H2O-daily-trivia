""" Takes a png file and makes a header file for an RGB332 background (320 by 240 image) with it.
"""
import os
import PIL
import PIL.Image
import argparse
import numpy as np

BACKGROUNDS_FOLDER_PATH = os.path.join("..", "..", "assets", "backgrounds")
OUTPUT_HEADER_FOLDER_PATH = "."
SCREEN_HEIGHT = 240
SCREEN_WIDTH = 320

def to_rgb332(rgba_tuple):
    """ Takes a tuple of rgba values from 0 to 255 and converts to a single 0 to 255 integer representing a RGB332 value
    """
    r = rgba_tuple[0]
    g = rgba_tuple[1]
    b = rgba_tuple[2]
    rgb332 = (r & 0b11100000) | ((g & 0b11100000) >> 3) | ((b & 0b11000000) >> 6)
    return rgb332

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description=(
            f'''Script to generate a header for an RGB332 background from a PNG file
                Transparency data is not preserved.
                '''
        ),
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )

    parser.add_argument("asset_name", type=str, help="name of your background png file")
    args = parser.parse_args()

    ASSET_NAME = args.asset_name
    PNG_FILEPATH = os.path.join(BACKGROUNDS_FOLDER_PATH, ASSET_NAME + '.png')

    image = PIL.Image.open(PNG_FILEPATH)
    image = np.asarray(image)
    
    image_height = image.shape[0]
    image_width = image.shape[1]
    
    assert image_height == SCREEN_HEIGHT
    assert image_width == SCREEN_WIDTH

    header_file = os.path.join(OUTPUT_HEADER_FOLDER_PATH, ASSET_NAME + '.hpp')

    with open(header_file, 'w+') as f:

        f.write('#include "background.hpp"\n\n')
        f.write(f'Background {ASSET_NAME}_background(')
        f.write('{')
        for row in image:
            f.write('{')
            for pixel in row:
                rgb332 = to_rgb332(pixel)
                f.write(f'{hex(rgb332)},')
            f.write('}, ')
        f.write('});')
