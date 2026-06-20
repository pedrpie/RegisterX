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
        cout << "\033[36m";
        cout << "===================================================" << endl;
        cout << "  RegisterX - Seu Sistema de Registro de Usuários  " << endl;
        cout << "===================================================";
        cout << "\033[0m" << endl;

        cout << "\nSelecione uma opção\n" << endl;

        cout << "\33[33m";
        cout << "1 - Cadastrar\n2 - Listar\n3 - Atualizar\n4 - Deletar\n0 - Sair\n";
        cout << "\33[0m" << endl;

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

        else if (option == 0) {
            cout << "Saindo..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }

        else{
            cout << "Opção Inválida\n" << endl;
        }
    }
}