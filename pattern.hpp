#ifndef PATTERN_H
#define PATTERN_H

#include "raylib.h"
#include <map>
#include <string>
#include "gl_includes.hpp"
#include <memory>

class Pattern {

public:
    int gridHeight = 170;
    int gridWidth;
    int square_size;
    int nbUsedColors = 64;
    int nbSymbols = 62; // This does not include the symbols B and W, which is why the actual number of symbols is equal to nbSymbols+2
    int symbolSize = 16;
    int captionWidth = 1000;


    //Creates a grid of simplified squares of colors approaching the picture
    Image* makeGrid(Image image);
    //Creates the grid using DMC threads colors and the map of used colors
    std::pair< Image*, std::map<std::string, glm::vec3> > makeDMCGrid(Image image, std::map<std::string, glm::vec3> colors);
    //Creates the grid with the black and white symbols
    std::pair< Image*,std::map<std::string, Image> > makeSymbolGrid(Image image, std::map<std::string, glm::vec3> colors);
    //Creates the caption
    Image* makeCaption(std::map<std::string, Image> symbolMap);

    //Returns closest thread color id
    std::string closestColor(Color color, std::map<std::string, glm::vec3> colors);

    //Reduces number of used colors
    std::map<std::string, glm::vec3> reduceColors(std::map<std::string, glm::vec3> usedColors);

    //Load all symbols into a map
    std::map<std::string, Image > makeSymbolMap(std::map<std::string, glm::vec3> colors);

    #endif //PATTERN

};