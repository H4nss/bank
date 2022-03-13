#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

// inicjalizacja klasy z jej metodami i polami
class User {
public:
  string name;

private:
  string password;

public:
  User();
  void login(string username, string userPassword);
};

#endif