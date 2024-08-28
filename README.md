# Cross stitch pattern maker

This program aims to convert any picture into a cross stitch pattern that uses the DMC threads' colors.

Although there are 500 kind of DMC threads, this program only uses 482 of them, as the remaining 18 are multicolor threads.
I used Raylib for all manipulation and generation of images.

## How to use

The picture must be in a .png format. Place the picture you want to convert in the "pictures" folder. The relative path used in line 77 of the main function must be replaced by the relative path of the new picture, meaning the line becomes :
```Image pic = LoadImage("../pictures/name.png");```
where "name" is the name of the picture (in the code given, a picture named "turtle" is used. It is a screenshot of a video originally posted on Instagram by the account oceanholic_life).

When running the program, a window opens showing the caption that links every symbol to the DMC color code. This window is solely used for developping purpose and is not important to the user. The image displayed might take a small amount of time to load.

Once it is loaded, it means that the program is done. The results will be found in the "results" folder.
These results are :
- "pattern_caption.png" : The caption that links every symbol to the DMC color code. It is the same than the one displayed in the window.
- "pattern_expected.png" : A pixel-art rendition of what the completed pattern should look like once done by the user.
- "pattern_symbols.png" : The actual cross stitch pattern, which used alongside the caption should allow them to recreate the picture of their choices in cross stitch.

The "pattern_expected" file is merely a preview but it is does not hold any significance other than that for the user, so it can be deleted from the program if need be.

**If you intend to print the results** : The pattern grid might be very small as the symbols are only 16x16px. For this reason, printing all the grid on one piece of paper might make it difficult to read (depending on the size of the grid). Because of this it is advised to divide the grid into multiple pictures before printing them. Similarly, is the grid contains few crosses and can be easily printed in its entirety, then it might be worth redimensioning the picture.

## Changing parameters and additional information

Some parameters, such as grid height (in number of crosses), or the (maximum) number of colors used, can be changed in the file "pattern.hpp". It is worth noting that :
- The grid width is automatically adjusted according to the grid height and the image dimensions. The default height is currently of 170 crosses.
- Since this parameter gives the exact height of the result (in number of crosses), a part of the image will likely be cut so as to get to that number. For this reason, **it is strongly advised not to use low-resolution pictures**, as the cropped part might be important. On the contrary, the cropped part of higher resolution pictures will be smaller.
- As of now, there are only 64 symbols existing. This means that only 64 colors can be used at once, at maximum. If you wish to add symbols in order to increase the number of colors you can use in a single pattern, here is what should be known :
    - the symbols are all in a 16x16 .png format.
    - They must be put in the "symbols" folder, and named "x.png" where "x" is the number of the symbol. Current symbols are numbered from 1 to 30, with additional symbols B and w. As such, additional symbols must be named "65.png", "66.png", etc. without skipping any number.
    - The variable ```nbSymbols``` present in the file "pattern.hpp" must be changed to the total number of symbols minus 2 (as it doesn't include B and w, even if they are effectively used).
    - For example, if adding 3 symbols, these must be 16x16 .png files, saved in the "symbols" folder under the names "65.png", "66.png", "67.png", and the ```nbSymbols``` variable of the "pattern.hpp" file must be equal to 67.