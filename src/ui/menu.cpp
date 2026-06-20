#include "Menu.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include "UserService.h"

using namespace std;

void menu(vector<User>& users){
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
            createUser(users);
        }

        else if(option == 2){
            readUser(users);
        }

        else if(option == 3){
            updateUser(users);
        }

        else if(option == 4){
            deleteUser(users);
        }

        else if (option == 5) {
            cout << "Saindo..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }

        else{
            cout << "Opção Inválida\n" << endl;
        }
    }
}