#include "_ast_.hpp"
#include <iostream>

void CompUnitAST::Print() const{
    std::cout << "CompUnit { ";
    func_def->Print();
    std::cout << " }" ;
}

void FuncDefAST::Print() const{
    std::cout << "FuncDef { " ;
    func_type->Print();
    std::cout << ", "   
            << ident   
            << ", " ;
    block->Print();
    std::cout << " }" ;
}

void FuncTypeAST::Print() const{
    std::cout << "FuncType { "   
            << type  
            << " }" ;;
}   

void BlockAST::Print() const{
    std::cout << "Block { " ;
    stmt->Print();
    std::cout << " }" ;
}   

void StmtAST::Print() const{
    std::cout << "Stmt { " ;
    number->Print();
    std::cout << " }" ;
}   

void NumberAST::Print() const{
    std::cout << "Number { "  
                << int_const  
                << " }" ;
}   

