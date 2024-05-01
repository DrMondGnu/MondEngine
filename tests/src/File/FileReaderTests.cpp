//
// Created by MondGnu on 5/1/2024.
//
#include "doctest.h"
#include "engine/File/FileReader.h"

using namespace mondengine;

TEST_CASE("StreamFileReaderTests") {
    std::filesystem::path path(MOND_ENGINE_TEST_FILE);
    StreamFileReader reader(path);
    SUBCASE("ReadBytesTest") {
        char* buf = new char[11];
        reader.ReadBytes(buf, 11);

        std::string str(buf, buf+11);
        CHECK_EQ(str, "Hello World");
        delete[] buf;
    }

    SUBCASE("ReadStringTest") {
        std::string str = reader.ReadString(11);
        CHECK_EQ(str, "Hello World");
    }

    SUBCASE("ReadAllTest") {
        std::string str = reader.ReadAll();
        CHECK_EQ(str, "Hello World");
    }
}