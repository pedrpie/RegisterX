#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <vector>
#include "User.h"

void createUser(std::vector<User>& users);
void readUser(const std::vector<User>& users);
int findUserById(const std::vector<User>& users, int id);
void updateUser(std::vector<User>& users);
void deleteUser(std::vector<User>& users);

#endif