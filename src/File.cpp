#include "File.h"
#include <fstream>
#include <sstream>
#include <iostream>

void saveUsersToFile(const std::vector<User>& users) {

    
    try 
    {
        std::ofstream file("src/database/Users.txt");
        
        if (!file.is_open()) {
            throw std::runtime_error("\x1b[31mNão foi possível abrir o arquivo para escrita.\x1b[0m");
        }

        for (const User& user : users) {
            file << user.id << ","
                    << user.nome << ","
                    << user.idade << ","
                    << user.email << ","
                    << user.cpf << ","
                    << user.curso << "\n";
        }
        file.close();
    }
    catch (const std::exception& e) {
        std::cout << "\x1b[31mErro ao salvar usuários: \x1b[0m" << e.what() << std::endl;
    }
}
void loadUsersFromFile(std::vector<User>& users) {
    std::ifstream file("src/database/Users.txt");

    if (!file.is_open()) {
        std::cout << "\x1b[31mNão foi possível abrir o arquivo para leitura.\x1b[0m" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        try 
        {
            User user;
            std::stringstream ss(line);

            std::string id;
            std::string idade;

            std::getline(ss, id, ',');
            std::getline(ss, user.nome, ',');
            std::getline(ss, idade, ',');
            std::getline(ss, user.email, ',');
            std::getline(ss, user.cpf, ',');
            std::getline(ss, user.curso, ',');

            user.id = std::stoi(id);
            user.idade = std::stoi(idade);

            users.push_back(user);
        }
        catch (const std::exception& e) {
            std::cout << "\x1b[31mErro ao carregar usuário: \x1b[0m" << e.what() << std::endl;
        }
    }
    file.close();
}