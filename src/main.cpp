#include <iostream>
#include "classes/User.h"

using namespace std;

int main() {
  User user1;

  user1.login("nazwa", "haslo");
  cout << user1.name << endl;

  cout << "Hello world!" << endl;
  return 0;
};