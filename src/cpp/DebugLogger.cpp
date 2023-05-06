/**
 * @file src.cpp.DebugLogger.cpp
 * @author Florian Lopitaux
 * @version 0.1
 * @brief source file of the DebugLogger class. Implements all methods.
 * 
 * --------------------------------------------------------------------
 *
 * Copyright (C) 2023  Florian Lopitaux
 *
 * Use of this software is governed by the GNU Public License, version 3.
 *
 * CppLogger is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * CppLogger is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with CppLogger. If not, see <http://www.gnu.org/licenses/>.
 * 
 * This banner notice must not be removed.
 * 
 * --------------------------------------------------------------------
 */

#include "DebugLogger.h"

#include <algorithm>
#include <sstream>
#include "windows.h"


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
void nsCppLogger::DebugLogger::error(const unsigned logLevel,
                                     const std::string & title, const std::string & msg) {

    // check if we have the right to print the log
    if (this->debugLevel < logLevel) {
        return;
    }

    // print title and set principal color
    system("Color 0" + this->errorColors.first);
    std::cout << "[LOG ERROR] - " << title << std::endl;

    // print message trace and set secondary color
    system("Color 0" + this->errorColors.second);
    std::cout << "Trace : " << msg << std::endl;

    // reset terminal default color
    system("Color 07");
}

void nsCppLogger::DebugLogger::warning(const unsigned logLevel,
                                       const std::string & title, const std::string & msg) {
    
    // check if we have the right to print the log
    if (this->debugLevel < logLevel) {
        return;
    }

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
