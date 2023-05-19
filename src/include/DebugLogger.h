/**
 * @file src.include.DebugLogger.h
 * @author Florian Lopitaux
 * @version 1.0
 * @brief Header file of the DebugLogger class.
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

#ifndef DEBUG_LOGGER_H
#define DEBUG_LOGGER_H

#include <iostream>
#include <fstream>

#include "LoggerColor.h"


/**
 * @namespace nsCppLogger
 * @brief Namespace that contains all the class, enum, ... of the CppLogger library.
*/
namespace nsCppLogger {
    /**
     * @class DebugLogger
     * @brief Class representing the logger object.
     * 
     * This class allows us to write in the output terminal or a log file
     * usefull custom trace of the code execution.
    */
    class DebugLogger {
        private:
            // FIELDS
            unsigned debugLevel;

            std::ofstream logFile;

            LoggerColor errorColor;
            LoggerColor warningColor;
            LoggerColor infoColor;


            // PRIVATE METHODS
            /**
             * @brief Initialize everything to print in the console.
            */
            void enableConsoleMode();

            /**
             * @brief Initialize everything to print in a log file.
             * 
             * @param path [in] The path of the log file
            */
            void enableLogFileMode(const std::string & path);

            /**
             * @brief Set the text color of the terminal output.
             * 
             * @param color [in] The color to applied on the text
            */
            void setTerminalColor(const LoggerColor color) const;


        public:
            // CONSTRUCTORS & DESTRUCTOR
            /**
             * @brief Constructor of the DebugLogger class.
             * 
             * Instantiate an object of the DebugLogger class,
             * initialize everything to begin to print in the console.
             * 
             * @param level [in] [optional] The level of debugging, 0 by default
            */
            DebugLogger(const unsigned level = 0);

            /**
             * @brief Constructor of the DebugLogger class.
             * 
             * Instantiate an object of the DebugLogger class,
             * initialize everything to begin to print in a log file.
             * 
             * If the path parameter is an empty string, we activate the console print mode.
             * 
             * @param logFilePath [in] The path of the file to print the logs.
             * @param level [in] [optional] The level of debugging, 0 by default
            */
            DebugLogger(const std::string & logFilePath, const unsigned level = 0);

            /**
             * @brief Destructor of the DebugLogger class.
             * 
             * Close the log file if there was one used.
            */
            ~DebugLogger();


            // GETTERS
            /**
             * @brief Getter of the 'level' attribute.
             * 
             * Get the current debugging level of the logger.
             * 
             * @return The level of debugging
            */
            unsigned getDebugLevel();


            // SETTERS
            /**
             * @brief Setter of the 'level' attribute.
             * 
             * Change the current debugging level of the logger.
             * 
             * @param level [in] The new debugging level
            */
            void setDebugLevel(const unsigned level);

            /**
             * @brief Setter of the 'errorColors' attribute.
             * 
             * Change the color used to print the error in the terminal.
             * 
             * @param color [in] The color used to the error logs
            */
            void setErrorColors(const LoggerColor color);

            /**
             * @brief Setter of the 'warningColors' attribute.
             * 
             * Change the color used to print the warning in the terminal.
             * 
             * @param color [in] The color used to the warning logs
            */
            void setWarningColors(const LoggerColor color);

            /**
             * @brief Setter of the 'infoColors' attribute.
             * 
             * Change the color used to print the information in the terminal.
             * 
             * @param color [in] The color used to the information logs
            */
            void setInformationColors(const LoggerColor color);


            // PUBLIC METHODS
            /**
             * @brief Print an error in the terminal.
             * 
             * Print the trace of the error with the custom displaying.
             * 
             * @param logLevel [in] The level needed to print the log
             * @param typeError [in] The text resume of the error
             * @param msg [in] The complete message description of the error
            */
            void error(const unsigned logLevel, const std::string & typeError, const std::string & msg);

            /**
             * @brief Print a warning in the terminal.
             * 
             * Print the trace of the warning with the custom displaying.
             * 
             * @param logLevel [in] The level needed to print the log
             * @param msg [in] The message of the warning
            */
            void warning(const unsigned logLevel, const std::string & msg);

            /**
             * @brief Print an information in the terminal.
             * 
             * Print the trace of the information with the custom displaying.
             * 
             * @param logLevel [in] The level needed to print the log
             * @param msg [in] The information to print
            */
            void inform(const unsigned logLevel, const std::string & msg);
    };
}

#endif
