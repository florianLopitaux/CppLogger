/**
 * @file src.include.DebugLogger.h
 * @author Florian Lopitaux
 * @version 0.1
 * @brief Header file of the DebugLogger class.
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

#ifndef DEBUG_LOGGER_H
#define DEBUG_LOGGER_H

#include <iostream>
#include "windows.h"

#include "LoggerColor.h"


/**
 * @namespace nsCppLogger
 * @brief Namespace that contains all the class, enum, ... of the CppLogger library.
 */
namespace nsCppLogger {
    /**
     * @typedef textColor_t
     * @brief Type representing the two colors needed by a type log. 
     */
    typedef std::pair<LoggerColor, LoggerColor> textColor_t;

    /**
     * @class DebugLogger
     * @brief Class representing the logger object.
     * 
     * This class allows us to write in the output terminal usefull custom trace
     * of the code execution.
     */
    class DebugLogger {
        private:
            // FIELDS
            unsigned debugLevel;
            
            HANDLE outHandle;
            textColor_t errorColors;
            textColor_t warningColors;
            textColor_t infoColors;


        public:
            // CONSTRUCTOR
            /**
             * @brief Constructor of the DebugLogger class.
             * 
             * Instantiate an object of the DebugLogger class,
             * initialize everything to begin to print.
             * 
             * @param level [in] [optional] : The level of debugging
             *                                0 by default
             */
            DebugLogger(const unsigned level = 0);


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
             * @param level [in] : The new debugging level
             */
            void setDebugLevel(const unsigned level);

            /**
             * @brief Setter of the 'errorColors' attribute.
             * 
             * Change the colors used to print the error in the terminal.
             * 
             * @param primaryColor [in] : The color used to the error balise and the error type
             * @param secondaryColor [in] : The color used to the description message
             */
            void setErrorColors(const LoggerColor primaryColor, const LoggerColor secondaryColor);

            /**
             * @brief Setter of the 'warningColors' attribute.
             * 
             * Change the colors used to print the warning in the terminal.
             * 
             * @param primaryColor [in] : The color used to the warning balise
             * @param secondaryColor [in] : The color used to the description message
             */
            void setWarningColors(const LoggerColor primaryColor, const LoggerColor secondaryColor);

            /**
             * @brief Setter of the 'infoColors' attribute.
             * 
             * Change the colors used to print the information in the terminal.
             * 
             * @param primaryColor [in] : The color used to the information balise
             * @param secondaryColor [in] : The color used to the description message
             */
            void setInformationColors(const LoggerColor primaryColor, const LoggerColor secondaryColor);


            // METHODS
            /**
             * @brief Print an error in the terminal.
             * 
             * Print the trace of the error with the custom displaying.
             * 
             * @param logLevel [in] : The level needed to print the log
             * @param typeError [in] : The text resume of the error
             * @param msg [in] : The complete message description of the error
             */
            void error(const unsigned logLevel, const std::string & typeError, const std::string & msg);

            /**
             * @brief Print a warning in the terminal.
             * 
             * Print the trace of the warning with the custom displaying.
             * 
             * @param logLevel [in] : The level needed to print the log
             * @param msg [in] : The message of the warning
             */
            void warning(const unsigned logLevel, const std::string & msg);

            /**
             * @brief Print an information in the terminal.
             * 
             * Print the trace of the information with the custom displaying.
             * 
             * @param logLevel [in] : The level needed to print the log
             * @param msg [in] : The information to print
             */
            void inform(const unsigned logLevel, const std::string & msg);
    };
}

#endif
