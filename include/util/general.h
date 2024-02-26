//
// Created by MondGnu on 2/27/2024.
//

#ifndef NINDO_GENERAL_H
#define NINDO_GENERAL_H

#define STRING_TO_C_STR(p_char, string) p_char = (char*)malloc(string.length()+1); \
                                        strcpy_s(p_char, string.length()+1, string.c_str())

#endif //NINDO_GENERAL_H
