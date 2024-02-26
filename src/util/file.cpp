//
// Created by MondGnu on 2/21/2024.
//

#include "util/file.h"

namespace mondengine::file {

    const char *read_file(const char *filename)
    {
        std::fstream fileReader;
        std::stringstream stringstream;
        fileReader.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            fileReader.open(filename);
            stringstream << fileReader.rdbuf(); // TODO: Change to throw error instead of catching it
            fileReader.close();
        }
        catch(std::ifstream::failure &e)
        {
            MOE_ERROR("Error reading file {}: {}", filename, e.what());
            return nullptr;
        }

        auto str = stringstream.str();
        char* string = new char[str.length()+1];
        strcpy_s(string, str.length()+1, str.c_str());
        return string;
    }
}