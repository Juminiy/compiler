#include <cstdio>
#include <cassert>
#include <string>
#include <memory>
#include <iostream>
#include "_const_.hpp"
#include "_func_.hpp"

// 
// "//".*
/**/
// "/**/".* 

// 1. 
/**/

// 2. 
/*
*/

// 3. 
/**
 *
 *
**/

int main(int argc, 
            const char *argv[], 
            const char *envp[])
{

    // compiler mode input -o output
    assert(argc == MAX_ARGC);
    // argv[0] = compiler
    auto mode UNUSED = argv[1];
    auto input UNUSED = argv[2];
    // argv[3] = -o 
    auto output UNUSED = argv[4];


    assert(yyin = fopen(input, "r"));

    std::unique_ptr<std::string> ast;
    assert(!yyparse(ast));

    std::cout << RED_STR(*ast) << std::endl;

    return 0;
}