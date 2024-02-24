#pragma once 
#ifndef _AST_HPP
#define _AST_HPP

#include <memory>
#include <string>

class BaseAST 
{
public: 
    virtual ~BaseAST() = default;
    virtual void Print() const = 0;
};

class CompUnitAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_def;
    void Print() const override;
};

class FuncDefAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_type;
    std::string ident;
    std::unique_ptr<BaseAST> block;

    void Print() const override;
};

class FuncTypeAST : public BaseAST 
{
public :
   std::string type;

   void Print() const override;
};

class BlockAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> stmt;

    void Print() const override;
};

class StmtAST : public BaseAST
{
public: 
    std::unique_ptr<BaseAST> number;

    void Print() const override;
};

class NumberAST : public BaseAST 
{
public:
    int int_const;
    NumberAST(int _int_const){
        int_const = _int_const;
    }

    void Print() const override;
};


#endif 