%option noyywrap
%option nounput
%option noinput

%{

#include <cstdlib>
#include <string>
#include "_ast_.hpp"
#include "sysy.tab.hpp"


using namespace std;

%}

/* 空白符和注释 */
WhiteSpace    [ \t\n\r]*
LineComment   "//".*
BlockComment  "/**/".*

/* 标识符 */
Identifier    [a-zA-Z_][a-zA-Z0-9_]*

/* 整数字面量 */
Binary        [0][bB][01]+
Tenary        [0][tT][012]+
Octal         0[oO]?[0-7]*
Decimal       (0[dD])?[1-9][0-9]*
Hexadecimal   0[xX][0-9a-fA-F]+

%%

{WhiteSpace}    { /* 忽略, 不做任何操作 */ }
{LineComment}   { /* 忽略, 不做任何操作 */ }
{BlockComment}  { /* 忽略, 不做任何操作 */ }

"int"           { return INT; }
"return"        { return RETURN; }

{Identifier}    { yylval.str_val = new string(yytext); return IDENT; }

{Binary}        { yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }
{Tenary}        { yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }
{Octal}         { yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }
{Decimal}       { yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }
{Hexadecimal}   { yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }

.               { return yytext[0]; }

%%