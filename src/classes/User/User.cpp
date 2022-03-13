#include "User.h"

// deklaracja metody tworzacej klase User
User::User(){};

//deklaracja metody
void User::login(string username, string userPassword) {
  name = username;
  password = userPassword;
};
