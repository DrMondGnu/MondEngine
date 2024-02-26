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
        catch (std::ifstream::failure &e)
        {
            MOE_ERROR("Error reading file {}: {}", filename, e.what());
            return nullptr;
        }

        auto str = stringstream.str();
        char *string = new char[str.length() + 1];
        strcpy_s(string, str.length() + 1, str.c_str());
        return string;
    }

    const char *get_file_name(const char *filepath)
    {
        if (filepath[0] == '\0') {
            return ""; // Return empty string on empty filepath
        }

        // Allocate space for a single filename (using std::string for memory management)
        std::string filename;

        // Loop through the filepath string
        for (size_t i = 0; filepath[i] != '\0'; ++i) {
            if (filepath[i] == '\\') {
                // Reset filename when encountering a backslash
                filename.clear();
            } else {
                // Append character to the filename
                filename += filepath[i];
            }
        }
        char* fName;
        STRING_TO_C_STR(fName, filename);
        return fName;
    }
}