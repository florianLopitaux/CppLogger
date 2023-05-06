#include "DebugLogger.h"

#include <algorithm>
#include <sstream>
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

void nsCppLogger::DebugLogger::setErrorColors(const LoggerColor primaryColor, const LoggerColor secondaryColor) {
    // convert LoggerColor parameteres to characters id
    char firstColor = this->convertColorEnumToChar(primaryColor);
    char secondColor = this->convertColorEnumToChar(secondaryColor);

    this->errorColors = std::make_pair(firstColor, secondColor);
}
void nsCppLogger::DebugLogger::setWarningColors(const LoggerColor primaryColor, const LoggerColor secondaryColor) {
    // convert LoggerColor parameteres to characters id
    char firstColor = this->convertColorEnumToChar(primaryColor);
    char secondColor = this->convertColorEnumToChar(secondaryColor);

    this->warningColors = std::make_pair(firstColor, secondColor);
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
char nsCppLogger::DebugLogger::convertColorEnumToChar(const LoggerColor color) {
    std::ostringstream stringStream;
    stringStream << std::hex << color;

    return stringStream.str()[0];
}
