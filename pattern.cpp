#include "pattern.hpp"
#include "iostream"

Image *Pattern::makeGrid(Image image)
{
    gridWidth = image.width * gridHeight / image.height;
    square_size = image.height / gridHeight;

    Image *grid = new Image(GenImageColor(gridWidth * square_size, gridHeight * square_size, WHITE));

    // For each square
    for (int i = 0; i < gridWidth; i++)
    {
        for (int j = 0; j < gridHeight; j++)
        {

            int meanRed = 0;
            int meanGreen = 0;
            int meanBlue = 0;
            int meanAlpha = 0;

            // Compute the mean color of the corresponding area of the picture
            for (int pixelX = i * square_size; pixelX < (i + 1) * square_size; pixelX++)
            {
                for (int pixelY = j * square_size; pixelY < (j + 1) * square_size; pixelY++)
                {
                    meanRed += GetImageColor(image, pixelX, pixelY).r;
                    meanGreen += GetImageColor(image, pixelX, pixelY).g;
                    meanBlue += GetImageColor(image, pixelX, pixelY).b;
                    meanAlpha += GetImageColor(image, pixelX, pixelY).a;
                }
            }

            meanRed /= square_size * square_size;
            meanGreen /= square_size * square_size;
            meanBlue /= square_size * square_size;
            meanAlpha /= square_size * square_size;

            Color meanColor = Color{meanRed, meanGreen, meanBlue, meanAlpha};

            // Draw square with meanColor
            ImageDrawRectangle(grid, i * square_size, j * square_size, square_size, square_size, meanColor);
        }
    }

    return grid;
}

std::string Pattern::closestColor(Color color, std::map<std::string, glm::vec3> colors)
{

    int minSquareDiff = 3 * pow(255, 2);
    std::string minId = colors.begin()->first;

    for (auto const &it : colors)
    {
        std::string id = it.first;
        glm::vec3 col = it.second;

        int diff = pow(col.x - color.r, 2) + pow(col.y - color.g, 2) + pow(col.z - color.b, 2);

        if (diff < minSquareDiff)
        {
            minSquareDiff = diff;
            minId = id;
        }
    }
    return minId;
}

std::pair<Image *, std::map<std::string, glm::vec3>> Pattern::makeDMCGrid(Image image, std::map<std::string, glm::vec3> colors)
{

    std::map<std::string, glm::vec3> usedColorsMap;

    gridWidth = image.width * gridHeight / image.height;
    square_size = image.height / gridHeight;
    Image *DMCgrid = new Image(GenImageColor(gridWidth * square_size, gridHeight * square_size, WHITE));
    // For each square
    for (int i = 0; i < gridWidth; i++)
    {
        for (int j = 0; j < gridHeight; j++)
        {
            Color squareColor = GetImageColor(image, i * square_size, j * square_size);

            std::string DMCId = closestColor(squareColor, colors);
            Color dmcColor = Color{colors.at(DMCId).r, colors.at(DMCId).g, colors.at(DMCId).b, 255};

            usedColorsMap.insert(std::pair<std::string, glm::vec3>(DMCId, colors.at(DMCId)));
            ImageDrawRectangle(DMCgrid, i * square_size, j * square_size, square_size, square_size, dmcColor);
        }
    }

    return std::pair<Image *, std::map<std::string, glm::vec3>>(DMCgrid, usedColorsMap);
}

std::map<std::string, glm::vec3> Pattern::reduceColors(std::map<std::string, glm::vec3> usedColors)
{
    int nbColors = usedColors.size();

    while (nbColors > nbUsedColors)
    {
        // Compare every used color to find the two closest ones
        std::string closest1 = usedColors.begin()->first;

        std::string closest2 = usedColors.begin()->first;

        int minSquareDiff = 3 * pow(255, 2);

        for (auto const &it : usedColors)
        {
            for (auto const &it2 : usedColors)
            {
                if (it != it2)
                {
                    glm::vec3 col1 = it.second;
                    glm::vec3 col2 = it2.second;
                    int squareDiff = pow(col1.x - col2.x, 2) + pow(col1.y - col2.y, 2) + pow(col1.z - col2.z, 2);

                    if (squareDiff < minSquareDiff)
                    {
                        minSquareDiff = squareDiff;
                        closest1 = it.first;
                        closest2 = it2.first;
                    }
                }
            }
        }

        usedColors.erase(closest2);
        nbColors = usedColors.size();
    }
    return usedColors;
}

std::map<std::string, Image > Pattern::makeSymbolMap(std::map<std::string, glm::vec3> colors){
    
    std::map<std::string, Image > symbolMap;
    symbolMap.clear();
    int count=1;

    for (auto const &it : colors)
    {
        if(count<=nbSymbols){

            char symbolFilename[100];

            strcpy(symbolFilename, "../symbols/");
            char* name;
            name = std::to_string(count).data();
            strcat(symbolFilename, name);
            strcat(symbolFilename, ".png");
            
            Image symbol = LoadImage(symbolFilename);

            std::string key = it.first;
            symbolMap.insert(std::pair<std::string, Image >(key, symbol));

        }
        else if(count==nbSymbols+1){
            Image symbol;
            symbol = LoadImage("../symbols/w.png");
            symbolMap.insert(std::pair<std::string, Image >(it.first, symbol));

        }
        else{
            Image symbol;
            symbol = LoadImage("../symbols/B.png");
            symbolMap.insert(std::pair<std::string, Image >(it.first, symbol));

        }
        count++;
    }

    return symbolMap;
}


std::pair< Image*, std::map<std::string, Image> > Pattern::makeSymbolGrid(Image image, std::map<std::string, glm::vec3> colors)
{
    Image *symbolGrid = new Image(GenImageColor(gridWidth*(symbolSize+1)+1 , gridHeight * (symbolSize+1)+1, WHITE));

    //Create symbol map
    std::map<std::string, Image> symbolMap = makeSymbolMap(colors);

    //Draw the image
    // For each square
    for (int i = 0; i < gridWidth; i++)
    {
        for (int j = 0; j < gridHeight; j++)
        {
            Color squareColor = GetImageColor(image, i * square_size, j * square_size);

            //Find symbol within symbol file
            Image symbolSquare;

            for(auto const &it : colors){
                if(it.second==glm::vec3(squareColor.r, squareColor.g, squareColor.b)){
                    symbolSquare = symbolMap.at(it.first);
                }
            }

            //Draw the symbol at the right place
            Rectangle rectDest{i*(symbolSize+1)+1, j*(symbolSize+1)+1, symbolSize, symbolSize};
            Rectangle rectSrc{0,0,symbolSize, symbolSize};
            ImageDraw(symbolGrid, symbolSquare, rectSrc, rectDest, WHITE);
        }
    }

    // ----- Background grid -----

    //lines
    for(int j=0; j<gridHeight; j++){
        ImageDrawLine(symbolGrid, 0, j*(symbolSize+1), gridWidth*(symbolSize+1)+1, j*(symbolSize+1), BLACK);
    }
    //columns
    for(int i=0; i<gridWidth; i++){
        ImageDrawLine(symbolGrid, i*(symbolSize+1), 0, i*(symbolSize+1), gridHeight*(symbolSize+1)+1, BLACK);
    }

    //Thiccer grid every ten symbols
    for(int j=0; j<gridHeight; j++){
        if(j%10==0){
            ImageDrawLine(symbolGrid, 0, j*(symbolSize+1)-1, gridWidth*(symbolSize+1)+1, j*(symbolSize+1)-1, BLACK);
            ImageDrawLine(symbolGrid, 0, j*(symbolSize+1)+1, gridWidth*(symbolSize+1)+1, j*(symbolSize+1)+1, BLACK);
        } 
    }
    for(int i=0; i<gridWidth; i++){
        if(i%10==0){
            ImageDrawLine(symbolGrid, i*(symbolSize+1)-1, 0, i*(symbolSize+1)-1, gridHeight*(symbolSize+1)+1, BLACK);
            ImageDrawLine(symbolGrid, i*(symbolSize+1)+1, 0, i*(symbolSize+1)+1, gridHeight*(symbolSize+1)+1, BLACK);
        }
    }
    
    return std::pair< Image*, std::map<std::string, Image> >(symbolGrid, symbolMap);
}

Image* Pattern::makeCaption(std::map<std::string, Image> symbolMap) {

    int step = 45;

    Image* caption = new Image(GenImageColor(captionWidth , symbolMap.size()*22 + 45, WHITE));

    const char* title = "LEGENDE";

    ImageDrawText(caption, title, 5, 5, 20, BLACK);

    int nbSymbolPerLine = captionWidth/(5*step/2);

    std::cout<< nbSymbolPerLine << std::endl;

    int count = 1;
    int xCursor = 5;
    int yCursor = 35;
    for(auto const &it : symbolMap) {

        const char* colorNumber = it.first.c_str();
        Image symbol = it.second;

        ImageDrawText(caption, colorNumber, xCursor, yCursor, 15, BLACK);

        xCursor+=step;

        Rectangle rectDest{xCursor, yCursor, symbolSize, symbolSize};
        Rectangle rectSrc{0,0,symbolSize, symbolSize};

        ImageDraw(caption, symbol, rectSrc, rectDest, WHITE);

        if(count != nbSymbolPerLine){
            xCursor +=3*step/2;
            count++;
        }
        else {
            xCursor = 5;
            yCursor += 20;
            count = 1;
        }
        
    }

    return caption;

}