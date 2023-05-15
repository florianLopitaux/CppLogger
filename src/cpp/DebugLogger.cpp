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

    this->outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    this->errorColors = std::make_pair(LoggerColor::RED, LoggerColor::LIGHT_RED);
    this->warningColors = std::make_pair(LoggerColor::YELLOW, LoggerColor::LIGHT_YELLOW);
    this->infoColors = std::make_pair(LoggerColor::GREEN, LoggerColor::LIGHT_GREEN);

    // display the initialization of the logger
    SetConsoleTextAttribute(this->outHandle, LoggerColor::LIGHT_BLUE);
    std::cout << ">>>>>>>>>  [LOGGER INITIALIZED]  <<<<<<<<<" << std::endl << std::endl;

    SetConsoleTextAttribute(this->outHandle, LoggerColor::WHITE);
}

nsCppLogger::DebugLogger::DebugLogger(const std::string & logFilePath, const unsigned level) {
    this->debugLevel = level;

    // open the log file and print the initialization of the logger
    this->logFile.open(logFilePath);
    this->logFile << ">>>>>>>>>  [LOGGER INITIALIZED]  <<<<<<<<<" << std::endl << std::endl;
}

nsCppLogger::DebugLogger::~DebugLogger() {
    // print the closing of the logger
    if (this->logFile.is_open()) {
        this->logFile << ">>>>>>>>>  [LOGGER CLOSED]  <<<<<<<<<" << std::endl;

        this->logFile.close(); // close the log file

    } else {
        SetConsoleTextAttribute(this->outHandle, LoggerColor::LIGHT_BLUE);
        std::cout << ">>>>>>>>>  [LOGGER CLOSED]  <<<<<<<<<" << std::endl;

        // reset console default color
        SetConsoleTextAttribute(this->outHandle, LoggerColor::WHITE);
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

void nsCppLogger::DebugLogger::setErrorColors(const LoggerColor primaryColor, const LoggerColor secondaryColor) {
    this->errorColors = std::make_pair(primaryColor, secondaryColor);
}
void nsCppLogger::DebugLogger::setWarningColors(const LoggerColor primaryColor, const LoggerColor secondaryColor) {
    this->warningColors = std::make_pair(primaryColor, secondaryColor);
}

void nsCppLogger::DebugLogger::setInformationColors(const LoggerColor primaryColor, const LoggerColor secondaryColor) {
    this->infoColors = std::make_pair(primaryColor, secondaryColor);
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
        SetConsoleTextAttribute(this->outHandle, this->errorColors.first);
        std::cout << "[LOG ERROR] - " << typeError << std::endl;

        // print message trace and set secondary color
        SetConsoleTextAttribute(this->outHandle, this->errorColors.second);
        std::cout << "Stack Trace : " << msg << std::endl << std::endl;

        // reset console default color
        SetConsoleTextAttribute(this->outHandle, LoggerColor::WHITE);
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
        this->logFile << "[LOG WARNING] " << std::endl
                      << "Stack Trace : " << msg << std::endl << std::endl;

    } else {
        // print title and set principal color
        SetConsoleTextAttribute(this->outHandle, this->warningColors.first);
        std::cout << "[LOG WARNING]" << std::endl;

        // print message trace and set secondary color
        SetConsoleTextAttribute(this->outHandle, this->warningColors.second);
        std::cout << "Stack Trace : " << msg << std::endl << std::endl;

        // reset console default color
        SetConsoleTextAttribute(this->outHandle, LoggerColor::WHITE);
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
        SetConsoleTextAttribute(this->outHandle, this->infoColors.first);
        std::cout << "[LOG INFORMATION]" << std::endl;

        // print message trace and set secondary color
        SetConsoleTextAttribute(this->outHandle, this->infoColors.second);
        std::cout << "Stak Trace : " << msg << std::endl << std::endl;

        // reset console default color
        SetConsoleTextAttribute(this->outHandle, LoggerColor::WHITE);
    }
}
