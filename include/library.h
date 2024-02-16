#ifndef MOND_ENGINE_LIBRARY_H
#define MOND_ENGINE_LIBRARY_H

#ifdef MOND_ENGINE_COMPILE
    #define MOND_API __declspec(dllexport)
#elif MOND_ENGINE_IMPORT
    #define MOND_API __declspec(dllimport)
#else
    #define MOND_API
#endif

#endif //MOND_ENGINE_LIBRARY_H
