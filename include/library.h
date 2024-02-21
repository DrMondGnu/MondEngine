#ifndef MONDENGINE_LIBRARY_H
#define MONDENGINE_LIBRARY_H
#include "types.h"

#ifdef MOND_ENGINE_COMPILE
    #define MOND_API __declspec(dllexport)
#elif MOND_ENGINE_IMPORT
    #define MOND_API __declspec(dllimport)
#else
    #define MOND_API
#endif

#endif //MONDENGINE_LIBRARY_H
