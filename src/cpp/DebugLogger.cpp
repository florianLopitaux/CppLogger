/**
 * @file src.cpp.DebugLogger.cpp
 * @author Florian Lopitaux
 * @version 1.0
 * @brief source file of the DebugLogger class. Implements all class methods.
 * 
 * --------------------------------------------------------------------
 *
 * Copyright (C) 2023 Florian Lopitaux
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


/*
* ---------------------------------------------
* CONSTRUCTORS & DESTRUCTOR
* ---------------------------------------------
*/
nsCppLogger::DebugLogger::DebugLogger(const unsigned level) {
    this->debugLevel = level;

    this->enableConsoleMode();
}

nsCppLogger::DebugLogger::DebugLogger(const std::string & logFilePath, const unsigned level) {
    this->debugLevel = level;

    if (logFilePath.empty()) {
        this->enableConsoleMode();
    } else {
        this->enableLogFileMode(logFilePath);
    }
}

nsCppLogger::DebugLogger::~DebugLogger() {
    // print the closing of the logger
    if (this->logFile.is_open()) {
        this->logFile << ">>>>>>>>>  [LOGGER CLOSED]  <<<<<<<<<" << std::endl;

        // close the log file
        this->logFile.close();

    } else {
        this->setTerminalColor(LoggerColor::BLUE);
        std::cout << ">>>>>>>>>  [LOGGER CLOSED]  <<<<<<<<<" << std::endl;

        // reset console color
        this->setTerminalColor(LoggerColor::WHITE);
    }
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

void nsCppLogger::DebugLogger::setErrorColors(const LoggerColor color) {
    this->errorColor = color;
}
void nsCppLogger::DebugLogger::setWarningColors(const LoggerColor color) {
    this->warningColor = color;
}

void nsCppLogger::DebugLogger::setInformationColors(const LoggerColor color) {
    this->infoColor = color;
}


/*
* ---------------------------------------------
* PUBLIC METHODS
* ---------------------------------------------
*/
void nsCppLogger::DebugLogger::error(const unsigned logLevel,
                                     const std::string & typeError, const std::string & msg) {

    if (logLevel == 0) {
        throw new std::invalid_argument("log level can't be to 0, this level is the release mode");
    }

    // check if we have the right to print the log
    if (this->debugLevel == 0 || this->debugLevel < logLevel) {
        return;
    }

    // check if we write in the log file or in the console
    if (this->logFile.is_open()) {
        // print the error
        this->logFile << "[LOG ERROR] - " << typeError << std::endl
                      << "Stack Trace : " << msg << std::endl << std::endl;

    } else {
        // print title and set principal color
        this->setTerminalColor(this->errorColor);
        std::cout << "[LOG ERROR] - " << typeError << std::endl
                  << "Stack Trace : " << msg << std::endl << std::endl;

        // reset console color
        this->setTerminalColor(LoggerColor::WHITE);
    }
}

void nsCppLogger::DebugLogger::warning(const unsigned logLevel, const std::string & msg) {
    if (logLevel == 0) {
        throw new std::invalid_argument("log level can't be to 0, this level is the release mode");
    }

    // check if we have the right to print the log
    if (this->debugLevel == 0 || this->debugLevel < logLevel) {
        return;
    }

    // check if we write in the log file or in the console
    if (this->logFile.is_open()) {
        // print the warning
        this->logFile << "[LOG WARNING]" << std::endl
                      << "Stack Trace : " << msg << std::endl << std::endl;

    } else {
        // print title and set principal color
        this->setTerminalColor(this->warningColor);
        std::cout << "[LOG WARNING]" << std::endl
                  << "Stack Trace : " << msg << std::endl << std::endl;

        // reset console color
        this->setTerminalColor(LoggerColor::WHITE);
    }
}

void nsCppLogger::DebugLogger::inform(const unsigned logLevel, const std::string & msg) {
    if (logLevel == 0) {
        throw new std::invalid_argument("log level can't be to 0, this level is the release mode");
    }

    // check if we have the right to print the log
    if (this->debugLevel == 0 || this->debugLevel < logLevel) {
        return;
    }

    // check if we write in the log file or in the console
    if (this->logFile.is_open()) {
        // print the information
        this->logFile << "[LOG INFORMATION] " << std::endl
                      << "Stack Trace : " << msg << std::endl << std::endl;

    } else {
        // print title and set principal color
        this->setTerminalColor(this->infoColor);
        std::cout << "[LOG INFORMATION]" << std::endl
                  << "Stack Trace : " << msg << std::endl << std::endl;

        // reset console color
        this->setTerminalColor(LoggerColor::WHITE);
    }
}


/*
* ---------------------------------------------
* PRIVATE METHODS
* ---------------------------------------------
*/
void nsCppLogger::DebugLogger::enableConsoleMode() {
    // initialize default text colors
    this->errorColor = LoggerColor::RED;
    this->warningColor = LoggerColor::YELLOW;
    this->infoColor = LoggerColor::GREEN;

    // display the initialization of the logger
    this->setTerminalColor(LoggerColor::BLUE);
    std::cout << ">>>>>>>>>  [LOGGER INITIALIZED]  <<<<<<<<<" << std::endl << std::endl;

    // reset console color
    this->setTerminalColor(LoggerColor::WHITE);
}

void nsCppLogger::DebugLogger::enableLogFileMode(const std::string & path) {
    // open the log file and print the initialization of the logger
    this->logFile.open(path);
    this->logFile << ">>>>>>>>>  [LOGGER INITIALIZED]  <<<<<<<<<" << std::endl << std::endl;
}


// we are on a windows os
#ifdef _WIN32
#include "windows.h"

void nsCppLogger::DebugLogger::setTerminalColor(const LoggerColor color) const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// we are on a linux or mac os
#else
void nsCppLogger::DebugLogger::setTerminalColor(const LoggerColor color) const {
    std::cout << "\033[" + color + 'm';
}

#endif
