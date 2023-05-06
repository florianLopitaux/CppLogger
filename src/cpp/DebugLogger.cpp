#include "DebugLogger.h"

#include <algorithm>
#include "windows.h"


const char VALID_COLOR_CHARACTERS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                       'A', 'B', 'C', 'D', 'E', 'F'};


/*
* ---------------------------------------------
* CONSTRUCTOR
* ---------------------------------------------
*/
nsCppLogger::DebugLogger::DebugLogger(const unsigned level = 0) {
    this->debugLevel = level;

    this->errorColors = std::make_pair('4', 'C');
    this->warningColors = std::make_pair('6', 'E');
}


/*
* ---------------------------------------------
* GETTERS
* ---------------------------------------------
*/
unsigned nsCppLogger::DebugLogger::getDebugLevel() {
    return this->debugLevel;
}


/*
* ---------------------------------------------
* SETTERS
* ---------------------------------------------
*/
void nsCppLogger::DebugLogger::setDebugLevel(const unsigned level) {
    this->debugLevel = level;
}

void nsCppLogger::DebugLogger::setErrorColors(const char primaryColor, const char secondaryColor) {
    // check if color characters are valid
    if (this->checkColorCharacter(primaryColor) || this->checkColorCharacter(secondaryColor)) {
        throw new std::invalid_argument("One color character passed as parameter are wrong !"
            " See the class documentation to see all possible values.");
    }

    this->errorColors = std::make_pair(primaryColor, secondaryColor);
}

void nsCppLogger::DebugLogger::setErrorColors(const textColor_t & colors) {
    this->setErrorColors(colors.first, colors.second);
}

void nsCppLogger::DebugLogger::setWarningColors(const char primaryColor, const char secondaryColor) {
    // check if color characters are valid
    if (this->checkColorCharacter(primaryColor) || this->checkColorCharacter(secondaryColor)) {
        throw new std::invalid_argument("One color character passed as parameter are wrong !"
            " See the class documentation to see all possible values.");
    }

    this->warningColors = std::make_pair(primaryColor, secondaryColor);
}

void nsCppLogger::DebugLogger::setWarningColors(const textColor_t & colors) {
    this->setWarningColors(colors.first, colors.second);
}


/*
* ---------------------------------------------
* PUBLIC METHODS
* ---------------------------------------------
*/
void nsCppLogger::DebugLogger::error(const std::string & title, const std::string & msg) {
    // print title and set principal color
    system("Color 0" + this->errorColors.first);
    std::cout << "[LOG ERROR] - " << title << std::endl;

    // print message trace and set secondary color
    system("Color 0" + this->errorColors.second);
    std::cout << "Trace : " << msg << std::endl;

    // reset terminal default color
    system("Color 07");
}

void nsCppLogger::DebugLogger::warning(const std::string & title, const std::string & msg) {
    // print title and set principal color
    system("Color 0" + this->warningColors.first);
    std::cout << "[LOG WARNING] - " << title << std::endl;

    // print message trace and set secondary color
    system("Color 0" + this->warningColors.second);
    std::cout << "Trace : " << msg << std::endl;

    // reset terminal default color
    system("Color 07");
}


/*
* ---------------------------------------------
* PRIVATE METHODS
* ---------------------------------------------
*/
bool nsCppLogger::DebugLogger::checkColorCharacter(const char idColor) {
    return std::find(VALID_COLOR_CHARACTERS, std::end(VALID_COLOR_CHARACTERS), idColor)
                != std::end(VALID_COLOR_CHARACTERS);
}
