//
// Created by MondGnu on 5/1/2024.
//
#include "doctest.h"
#include <fmt/format.h>
#include "engine/File/FileReader.h"

using namespace Mond;

TEST_CASE("StreamFileReaderTests") {
    std::filesystem::path path(fmt::format("{}/{}", MOND_ENGINE_RESOURCE_DIR, "test.txt"));
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