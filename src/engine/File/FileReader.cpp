//
// Created by MondGnu on 5/1/2024.
//

#include "engine/File/FileReader.h"

namespace mondengine {

    void StreamFileReader::ReadBytes(char *out, std::streamsize size)
    {
        stream.read(out, size);
    }

    std::string StreamFileReader::ReadString(std::streamsize size)
    {
        char* buf = new char[size];
        stream.read(buf, size);
        std::string str{buf, (buf+size)};
        delete[] buf;
        return str;
    }

    std::string StreamFileReader::ReadAll()
    {
        std::stringstream buf;
        buf << stream.rdbuf();
        return buf.str();
    }

    void StreamFileReader::SetPos(std::streamoff pos)
    {
        stream.seekg(pos);
    }

    void StreamFileReader::Open(FileReader::path path)
    {
        stream.open(path);
    }

    StreamFileReader::StreamFileReader(const FileReader::path& path) : stream(path) {}
} // mondengine