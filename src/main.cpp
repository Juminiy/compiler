#include <cstdio>
#include <cassert>
#include <string>
#include <memory>
#include <iostream>
#include "_const_.hpp"
#include "_func_.hpp"
#include "_ast_.hpp"

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
    assert(argc < MAX_ARGC);
    // argv[0] = compiler
    auto mode UNUSED = argv[1];
    // argv[2] = -DDEBUG
    auto input UNUSED = argv[3];
    // argv[4] = -o 
    auto output UNUSED = argv[5];
    

    assert(yyin = fopen(input, "r"));

    std::unique_ptr<BaseAST> ast;
    assert(!yyparse(ast));
    
    ast->Print();
    fprintf(stdout, "\n");

    // mention to {must} callback(after register)
    fclose(yyin);

    return 0;
}