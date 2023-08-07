# convert an image passed in as a command line arg into code that can be included!

import sys
from PIL import Image, ImageFilter

# print(f"Name of the script      : {sys.argv[0]=}")
print(f"// Filenames used in the script : {sys.argv[1:]=}")

if len(sys.argv) < 2:
    print("Missing filename!")
    print("Expected usage: convert.py <filename>")
    exit(1);

filenames = sys.argv[1:]

'''
Converts color to the RPi supported color format. 
May need to write a particular function to handle conversion
based on the color settings you want to use for your game.
'''
def colorToARGB32(color):
    red = color[0]
    green = color[1]
    blue = color[2]
    # pack into 32 bit int
    result = 0
    result |= 0xFF << (8 * 3)
    result |=  red << (8 * 2)
    result |= green << (8 * 1)
    result |= blue
    return result

# sanity check
assert(colorToARGB32((255,255,255)) == 0xFFFFFFFF)

# use for later
output_images = []

def printAsArray(colorData):
    height = len(colorData)
    width = len(colorData[0])

    array_as_hex = ""
    for row in range(height):
        for col in range(width):
            array_as_hex += hex(colorData[row][col])
            array_as_hex += ", "


    data_str = "static struct Image myImage = {" + str(width) + "," + str(height) + ", {" + array_as_hex + "} };"
    print(data_str)
    return data_str    


def generate_image_arrays(imagedata):
    # output of of the form :
    # unsigned int imgData0[] = {0, 1, 2, 3, 4, 6};
    # unsigned int imgData1[] = {0, 1, 2, 3, 4, 6};
    # ...
    output = ""
    for i in range(len(imagedata)):
        array_as_hex = "" # hex string of literal pixels
        for row in range(height):
            for col in range(width):
                array_as_hex += hex(imagedata[i][row][col])
                array_as_hex += ", "
        output += "unsigned int imgData" + str(i) + "[] = { " + array_as_hex +  "};\n"
    return output

def generate_image_decls(imagedata):
    # of the form: struct Image image1 = {32, 32, &imgData0[0]};
    # will be used in list intializer, so we only need: {32, 32, &imgData0[0]},
    output = ""
    for i in range(len(imagedata)):
        output += "{" + str(len(imagedata[i][0])) + ","  + str(len(imagedata[i])) + ", &imgData" + str(i) + "[0]},"
    return output

def generate_tilemap(imagedata):
    # generate list of images with a count associated to them
    output = "struct Tilemap tilemap = {" + str(len(imagedata)) + ", { " + generate_image_decls(imagedata) + "}};"
    return output;

def generate_image_file(imagedata):
    img_arrays = generate_image_arrays(imagedata)
    tilemap_decl = generate_tilemap(imagedata)

    print('#include "image.h"')
    print(img_arrays)
    print(tilemap_decl)

for filename in filenames:
    # process each image, adding it to the output array
    with Image.open(filename) as im:
        height = im.height
        width = im.width
        image = []
        for row in range(height):
            image_row = []
            for col in range(width):
                color = im.getpixel((col,row))
                image_row.append(colorToARGB32(color))
            image.append(image_row)
        output_images.append(image)

# the colors are already 8 bit, just need to mask them together
generate_image_file(output_images)