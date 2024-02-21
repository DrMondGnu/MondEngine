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

namespace mondengine::file {

    MEcstr read_file(const char *filename);
}


#endif //MONDENGINE_FILE_H
