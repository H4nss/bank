#include <iostream>
#include "../classes/User.h";

using namespace std;

int main() {
  User user = new User();

  user.login('nazwa', 'haslo')

  cout << "Hello world!" << endl;
  return 0;
};