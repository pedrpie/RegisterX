#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <vector>
#include "User.h"

void saveUsersToFile(const std::vector<User>& users);
void loadUsersFromFile(std::vector<User>& users);

#endif