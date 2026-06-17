#include <iostream>
#include <limits>
#include "../include/system.h"

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
            cadastrar();
        }

        else if(option == 2){
            listar();
        }

        else if(option == 3){
            atualizar();
        }

        else if(option == 4){
            deletar();
        }

        else{
            cout << "Opção Inválida\n" << endl;
        }
    }
}

void cadastrar(){

}

void listar(){
    
}

void atualizar(){
    
}

void deletar(){
    
}