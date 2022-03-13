#include "User.h"

// inicjalizacja metody tworzacej klase User
User::User(){};

//inicjalizacja metody
void User::login(string username, string userPassword) {
  name = username;
  password = userPassword;
};
