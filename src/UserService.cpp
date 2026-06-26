#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include "User.h"
#include "UserService.h"
#include "File.h"

//Funções auxiliares
int findUserById(const std::vector<User>& users, int id) // Função para encontrar o índice do usuário pelo ID
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].id == id)
        {
            return i; 
        }
    }

    return -1; 
}

bool isValidCPF(const std::string& cpf) // Função para validar o CPF
{
    if (cpf.size() != 11)
        return false;

    for (int i = 0; i < cpf.size(); i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9')
            return false;
    }

    return true;
}

int countUsersRecursive(const std::vector<User>& users, int index) //função recursiva para contar o número de usuários
{ 
    if (index == users.size())
        return 0;

    return 1 + countUsersRecursive(users, index + 1);
}


// funções principais de CRUD para os usuários

void createUser(std::vector<User>& users){
    User newUser;
    int maxId = 0;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].id > maxId) {
            maxId = users[i].id;
        }
    }
    std::cout << "\n\33[35m===== CRIAR USUÁRIO =====\33[0m\n";
    newUser.id = maxId + 1;
    std::cout << "\nNome: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, newUser.nome);

    std::cout << "Idade: ";
    std::cin >> newUser.idade;

    std::cout << "Email: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, newUser.email);

    std::cout << "CPF: ";
    std::getline(std::cin, newUser.cpf);
    while (!isValidCPF(newUser.cpf)) {
        std::cout << "CPF inválido. Digite novamente: ";
        std::getline(std::cin, newUser.cpf);
    }
    std::cout << "Curso: ";
    std::getline(std::cin, newUser.curso);
    users.push_back(newUser);
    saveUsersToFile(users);
}

void listUser(const std::vector<User>& users){

    std::cout << "\n\33[35m===== LISTAGEM DOS USUÁRIOS =====\33[0m\n";
    if(users.empty()){
        std::cout << "\nNenhum usuário cadastrado.\n" << std::endl;
        return;
    }
    else {
        std::cout << "\nTOTAL: "
        << countUsersRecursive(users, 0)
        << std::endl;
        for (int i = 0; i < users.size(); i++) {
            std::cout << "\nUsuário " << i + 1 << std::endl;

            std::cout << "ID: "
                << users[i].id
                << std::endl;

            std::cout << "Nome: "
                << users[i].nome
                << std::endl;

            std::cout << "Idade: "
                << users[i].idade
                << std::endl;

            std::cout << "Email: "
                << users[i].email
                << std::endl;

            std::cout << "CPF: "
                << users[i].cpf
                << std::endl;

            std::cout << "Curso: "
                << users[i].curso
                << std::endl;
        }

    }
    std::cout << std::endl;
}

void sortUsersByName(std::vector<User>& users) {
    std::cout << "\n\33[35m===== ORDENAÇÃO DOS USUÁRIOS =====\33[0m\n";
    if(users.empty()){
        std::cout << "\nNenhum usuário cadastrado.\n" << std::endl;
        return;
    }

    else {
        for (int i = 0; i < users.size() - 1; i++){
            for (int j = 0; j < users.size() - i - 1; j++){
                if (users[j].nome > users[j + 1].nome){
                    std::swap(users[j], users[j + 1]);
                }
            }
        }
    std::cout << "\n\33[32mUsuários ordenados por nome com sucesso!\33[0m\n" << std::endl;
    }
}

void updateUser(std::vector<User>& users){
    int id;

    std::cout << "\nSelecione o ID para a atualização: ";
    std::cin >> id;

    int index = findUserById(users, id);

    if (index == -1)
    {
        std::cout << "\nUsuário não encontrado!\n" << std::endl;
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n\33[35m===== ATUALIZAR USUÁRIO =====\33[0m\n" << std::endl;

    std::cout << "Nome do usuário a ser atualizado: " << users[index].nome << std::endl;   
    std::cout << "Novo nome: ";
    std::getline(std::cin, users[index].nome);

    std::cout << "idade do usuário a ser atualizado: " << users[index].idade << std::endl;
    std::cout << "Nova idade: ";
    std::cin >> users[index].idade;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "email do usuário a ser atualizado: " << users[index].email << std::endl;
    std::cout << "Novo email: ";
    std::getline(std::cin, users[index].email);

    std::cout << "CPF do usuário a ser atualizado: " << users[index].cpf << std::endl;
    std::cout << "Novo CPF: ";
    std::getline(std::cin, users[index].cpf);
    while (!isValidCPF(users[index].cpf)) {
        std::cout << "CPF inválido. Digite novamente: ";
        std::getline(std::cin, users[index].cpf);
    }

    std::cout << "Curso do usuário a ser atualizado: " << users[index].curso << std::endl;
    std::cout << "Novo curso: ";
    std::getline(std::cin, users[index].curso);

    std::cout << "\nUser updated successfully!\n";
    saveUsersToFile(users);
}

void deleteUser(std::vector<User>& users){
    int id;

    std::cout << "\n\33[35m===== DELETAR USUÁRIO =====\33[0m\n" << std::endl;
    std::cout << "Selecione o ID: ";
    std::cin >> id;

    int index = findUserById(users, id);

    if (index == -1)
    {
        std::cout << "\nUsuário não encontrado!\n";
        return;
    }
    std::cout << "Deletando Usuário " << users[index].nome << " com ID " << users[index].id << std::endl;
    users.erase(users.begin() + index);

    std::cout <<"\33[32mUsuário deletado com sucesso!\33[0m\n" << std::endl;
    saveUsersToFile(users);
}