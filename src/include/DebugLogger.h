#ifndef DEBUG_LOGGER_H
#define DEBUG_LOGGER_H

#include <iostream>

#include "LoggerColor.h"


namespace nsCppLogger {
    typedef std::pair<char, char> textColor_t;

    class DebugLogger {
        public:
            // CONSTRUCTOR
            DebugLogger(const unsigned level = 0);


            // GETTERS
            unsigned getDebugLevel();


            // SETTERS
            void setDebugLevel(const unsigned level);
            void setErrorColors(const LoggerColor primaryColor, const LoggerColor secondaryColor);
            void setWarningColors(const LoggerColor primaryColor, const LoggerColor secondaryColor);


            // METHODS
            void error(const std::string & title, const std::string & msg);
            void warning(const std::string & title, const std::string & msg);

        private:
            // FIELDS
            unsigned debugLevel;

            textColor_t errorColors;
            textColor_t warningColors;


            // METHODS
            char convertColorEnumToChar(const LoggerColor color);
    };
}

#endif
