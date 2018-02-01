#ifndef SDL_UTILS_HPP
#define SDL_UTILS_HPP

/**
 * @file sdl_utils.hpp
 * @brief Utility functions that use SDL
 * @author Niklas Andersson
 * @version 0.1
 * @date 2018-01-26
 */

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

/**
 * @brief Get the path to find application resources
 *
 * This function uses SDL functionality that may be slow. Call once and store the result.
 *
 * @param subdirectory Get the path to this subdirectory of project/resoruces
 *
 * @return  The path to application resources
 */
std::string GetResourcePath(const std::string &subdirectory = "");

#endif /* SDL_UTILS_HPP */
