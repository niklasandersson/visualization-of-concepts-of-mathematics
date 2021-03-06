#include "utils/sdl_utils.hpp"

std::string GetResourcePath(const std::string &subdirectory) {
  static std::string path_store;

  #ifdef _WIN32
    const std::string SEPERATOR = "\\";
  #else
    const std::string SEPERATOR = "/";
  #endif

  if (path_store.empty()) {
    char* base_path = SDL_GetBasePath();

    if (base_path) {
      path_store = base_path;
      SDL_free(base_path);

    } else {
      std::cerr << "Error: Could not get resource path:"
                << SDL_GetError() << std::endl;

    }

    std::size_t pos = path_store.rfind("bin");
    path_store = path_store.substr(0, pos) + "resources" + SEPERATOR;

  }

  if (subdirectory.empty()) {
   return path_store;
  } else {
    return path_store + subdirectory + SEPERATOR;
  }
}
