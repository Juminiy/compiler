#pragma once 
#ifndef _FUNC_HPP
#define _FUNC_HPP

#include <memory>
#include <string>
#include "_const_.hpp"
#include "_ast_.hpp"

#define RED_STR(str) ("\033[1;31m"+str+"\033[0m")

extern int yyparse(std::unique_ptr<BaseAST>&);

static inline void DEBUG_PRINT(const char *s)
{
    std::cerr << s << std::endl;
}

#endif 