#ifndef DEBUG_LOGGER_H
#define DEBUG_LOGGER_H

#include <iostream>


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
            void setErrorColors(const textColor_t & colors);
            void setErrorColors(const char primaryColor, const char secondaryColor);
            void setWarningColors(const textColor_t & colors);
            void setWarningColors(const char primaryColor, const char secondaryColor);


            // METHODS
            void error(const std::string & title, const std::string & msg);
            void warning(const std::string & title, const std::string & msg);

        private:
            // FIELDS
            unsigned debugLevel;

            textColor_t errorColors;
            textColor_t warningColors;


            // METHODS
            bool checkColorCharacter(const char idColor);
    };
}

#endif
