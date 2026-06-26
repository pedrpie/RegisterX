#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <vector>
#include "User.h"

//Declaração das funções auxiliares
bool isValidCPF(const std::string& cpf);
int countUsersRecursive(const std::vector<User>& users, int index);
int findUserById(const std::vector<User>& users, int id);
//Declaração das funções principais de CRUD para os usuários
void createUser(std::vector<User>& users);
void listUser(const std::vector<User>& users);
void sortUsersByName(std::vector<User>& users);
void updateUser(std::vector<User>& users);
void deleteUser(std::vector<User>& users);

#endif