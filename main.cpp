#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "gl_includes.hpp"

#include "raylib.h"

#include "pattern.hpp"

std::map<std::string, glm::vec3> loadColors() {

    //Import color database
    std::fstream colorFile;
    colorFile.open("../colors.txt", std::fstream::in);

    std::map<std::string, glm::vec3> colors;

    if(colorFile) {
        
        //Get first line
        std::string colorTest;
        colorFile.seekg (0, colorFile.beg);
        
        while(std::getline(colorFile, colorTest)) {

            //Get color id and rgb as string
            std::string id;
            std::string colorString;
            glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f);
            id = colorTest.substr(0, colorTest.find(' '));
            colorString = colorTest.substr(colorTest.find(' ')+1, colorTest.length());

            float red = std::stof(colorString.substr(0, colorString.find(',')));
            std::string greenBlueStr = colorString.substr(colorString.find(',')+1, colorString.length());
            float green = std::stof(greenBlueStr.substr(0, greenBlueStr.find(',')));
            float blue = std::stof(greenBlueStr.substr(greenBlueStr.find(',')+1, greenBlueStr.length()));
            
            //put rgb in a variable

            color = glm::vec3(red, green, blue);

            //Add to color map
            colors.insert(std::pair<std::string, glm::vec3>(id, color));
        }

        std::cout << "Database successfully imported" <<std::endl;
        
        
    }
    else {std::cout << "Could not open color database" << std::endl;}

    colorFile.close();

    return colors;
}

int main(int argc, char **argv) {

    std::cout << "Loading colors from colors.txt..." << std::endl;
    std::map<std::string, glm::vec3> colors = loadColors();

    // Initialization
    const int screenWidth = 1800;
    const int screenHeight = 960;
    const char *windowTitle = "Cross stitch pattern maker";
 
    InitWindow(screenWidth, screenHeight, windowTitle);

    Pattern pattern;

    //Create grid from picture
    Image pic = LoadImage("../pictures/turtle.png");
    Color white =  WHITE;

    Image* grid = pattern.makeGrid(pic);

    std::pair<Image*, std::map<std::string, glm::vec3> > dmcGridColors = pattern.makeDMCGrid(*grid, colors);
    Image* dmcGrid  = dmcGridColors.first;
    std::map<std::string, glm::vec3> usedColors = dmcGridColors.second;

    std::cout << "reducing number of colors" << std::endl;
    usedColors = pattern.reduceColors(usedColors);
    std::cout<<"Updating grid" << std::endl;
    dmcGrid = pattern.makeDMCGrid(*grid, usedColors).first;
    
    std::cout<<"Converting to symbols"<<std::endl;
    std::pair< Image*, std::map<std::string, Image> > symbolGridandMap = pattern.makeSymbolGrid(*dmcGrid, usedColors);
    Image* symbolGrid = symbolGridandMap.first;
    std::map<std::string, Image> symbolMap = symbolGridandMap.second;

    //Create caption
    std::cout<<"Generating caption..."<<std::endl;
    Image* caption = pattern.makeCaption(symbolMap);
    
    //Exporting image
    std::cout<<"Exporting results..."<<std::endl;
    ExportImage(*dmcGrid, "../results/pattern_expected.png");
    ExportImage(*symbolGrid, "../results/pattern_symbols.png");
    ExportImage(*caption, "../results/pattern_caption.png");

    //resize image so it fits in window
    float ratioy = static_cast<float>(dmcGrid->height)/static_cast<float>(screenHeight);    
    float ratiox = static_cast<float>(dmcGrid->width)/static_cast<float>(screenWidth);

    //if(ratiox>ratioy) {
        //ImageResize(grid, 100, 100);
    ImageResize(dmcGrid, screenWidth*1/2, dmcGrid->height*(1/ratiox)*1/2);
    /*}
    else{
        //ImageResize(grid, screenWidth, 100);
        ImageResize(dmcGrid, dmcGrid->width*1/ratioy, screenHeight);
    }*/

    //Texture2D dmcGridTex = LoadTextureFromImage(*dmcGrid);
    Texture2D captionTex = LoadTextureFromImage(*caption);

    SetTargetFPS(60);
 
    std::cout << usedColors.size() << std::endl;

    // Main loop
    while(!WindowShouldClose()) {
 
        // Update the display
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(captionTex, 0, 0, white);
        EndDrawing();
    }
 
    // Cleanup
    CloseWindow();

    return 0;
}

