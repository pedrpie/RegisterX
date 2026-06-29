#include "Menu.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include "UserService.h"

using namespace std;

void menu(vector<User>& users){
    char option;

    while(true){
        cout << "\033[36m";
        cout << "===================================================" << endl;
        cout << "  RegisterX - Seu Sistema de Registro de Usuários  " << endl;
        cout << "===================================================";
        cout << "\033[0m" << endl;

        cout << "\nSelecione uma opção\n" << endl;

        cout << "\33[33m";
        cout << "1 - Cadastrar\n2 - Listar\n3 - Ordenar\n4 - Atualizar\n5 - Deletar\n0 - Sair\n";
        cout << "\33[0m" << endl;

        cin >> option;

        switch(option){
            case '1':
                createUser(users);
                break;

            case '2':
                listUser(users);
                break;

            case '3':
                sortUsersByName(users);
                listUser(users);
                break;

            case '4':
                updateUser(users);
                break;

            case '5':
                deleteUser(users);

            case '0':
                cout << "\x1b[31mSaindo...\x1b[0m" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                break;

            default:
                cout << "\nOpção inválida\n" << endl;
                this_thread::sleep_for(chrono::seconds(1));

        }

    }
}