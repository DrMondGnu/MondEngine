//
// Created by MondGnu on 2/26/2024.
//
#include "gtest/gtest.h"
#include "util/file.h"

TEST(GetFileName, CanFindNames)
{
    ASSERT_STREQ(mondengine::file::get_file_name("C:\\test\\new.txt"), "new.txt");
}
