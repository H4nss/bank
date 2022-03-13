#include <string>

using namespace std;

class User {
  string name;

private:
  string password;

public:
  void login(string username, string userPassword) {
    name = username;
    password = userPassword;
  }
};