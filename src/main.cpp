#include <iostream>
#include <vector>
#include "User.h"   
#include "Menu.h"
#include "File.h"
using namespace std;

int main(){

    // CONFIGURAÇÃO DO TERMINAL PARA UTF-8 (ACENTUAÇÃO)
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    //
    
    std::vector<User> users;
    loadUsersFromFile(users);
    menu(users);

    return 0;
}