#include <iostream>
#include "UserService.h"
#include "./ui/menu.h"
using namespace std;

int main(){

    // CONFIGURAÇÃO DO TERMINAL PARA UTF-8 (ACENTUAÇÃO)
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif

    menu();

    return 0;
}