#include <iostream>
#include <limits>
#include "UserService.h"
using namespace std;

void menu(){
    int option;

    while(1){
        cout << "RegisterX - Seu sistema de cadastro\n" << endl;
        cout << "O que deseja?\n" << endl;
        cout << "1 - Cadastrar \n2 - Listar\n3 - Atualizar\n4 - Deletar\n5 - Sair\n" << endl;

        if(!(cin >> option)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        if(option == 1){
            createUser();
        }

        else if(option == 2){
            readUser();
        }

        else if(option == 3){
            updateUser();
        }

        else if(option == 4){
            deleteUser();
        }

        else{
            cout << "Opção Inválida\n" << endl;
        }
    }
}