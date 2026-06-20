#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include "User.h"
#include "UserService.h"

void createUser(std::vector<User>& users){
    User newUser;
    std::cout << "\nNome: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, newUser.nome);
    std::cout << "Idade: ";
    std::cin >> newUser.idade;
    users.push_back(newUser);

    std::cout << "\nTotal users: "
     << users.size()
     << std::endl;
}

void readUser(const std::vector<User>& users){

    std::cout << "\n===== USERS =====\n";
    if(users.empty()){
        std::cout << "\nNenhum usuário cadastrado.\n" << std::endl;
        return;
    }
    else {
        for (int i = 0; i < users.size(); i++) {
            std::cout << "\nUsuário " << i + 1 << std::endl;

            std::cout << "Nome: "
                << users[i].nome
                << std::endl;

            std::cout << "Idade: "
                << users[i].idade
                << std::endl;
        }

    }
    std::cout << std::endl;
}

void updateUser(std::vector<User>& users){

}

void deleteUser(std::vector<User>& users){

}