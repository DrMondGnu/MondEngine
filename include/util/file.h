//
// Created by MondGnu on 2/21/2024.
//

#ifndef MONDENGINE_FILE_H
#define MONDENGINE_FILE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "engine/log.h"
#include "types.h"
#include "general.h"


namespace Mond::file {

    MEcstr read_file(const char *filename);
    MOND_API const char* get_file_name(const char *filepath);
}


#endif //MONDENGINE_FILE_H
