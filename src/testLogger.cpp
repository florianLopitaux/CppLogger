#include <iostream>

#include "DebugLogger.h"



int main(int argc, char *argv[]) {
    std::string logFileParameter = "";

    // check executable arguments to know if we print in a log file or the console
    if (argc == 2) {
        logFileParameter = argv[1];
    }

    nsCppLogger::DebugLogger logger (logFileParameter);

    // logs doesn't print because we are in release mode (debug level = 0)
    logger.error(1, "HiddenError", "This error doesn't be display !");
    logger.warning(1, "This warning doesn't be display !");
    logger.inform(2, "This information doesn't be display !");

    // activate debug mode
    logger.setDebugLevel(2); // all logging with an level <= 2 will be display

    // printable logs
    logger.error(1, "Test Error", "This error is a test which is displayed on the terminal.");
    logger.warning(2, "This warning is a test which is displayed on the terminal.");
    logger.inform(1, "This information is a test which is displayed on the terminal.");

    // debug level not high enough, doesn't print logs
    logger.error(5, "HiddenError", "This error doesn't be display !");
    logger.warning(4, "This warning doesn't be display !");
    logger.inform(3, "This information doesn't be display !");

    return 0;
}
