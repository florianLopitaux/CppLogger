/**
 * @file src.include.LoggerColor.h
 * @author Florian Lopitaux
 * @version 0.1
 * @brief Header file of the LoggerColor enum.
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

#ifndef COLORS_LOGGER_H
#define COLORS_LOGGER_H


/**
 * @namespace nsCppLogger
 * @brief Namespace that contains all the class, enum, ... of the CppLogger library.
 */
namespace nsCppLogger {
    /**
     * @enum LoggerColor
     * @brief The colors available of the log trace.
     */
    enum LoggerColor {
        BLACK,
        BLUE,
        GREEN,
        AQUA,
        RED,
        PURPLE,
        YELLOW,
        WHITE,
        GRAY,
        LIGHT_BLUE,
        LIGHT_GREEN,
        LIGHT_AQUA,
        LIGHT_RED,
        LIGHT_PURPLE,
        LIGHT_YELLOW,
        BRIGHT_WHITE
    };
}

#endif
