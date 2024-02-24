#include <memory>
#include <cassert>
#include <string>
#include <iostream>

int main(){

    auto str_ptr = new std::string("Hello World!");
    std::unique_ptr<std::string> str_unq_ptr(str_ptr); 

    // std::cout << *str_ptr == *str_unq_ptr << std::endl; 

    return 0;
}