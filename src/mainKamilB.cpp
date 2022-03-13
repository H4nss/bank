#include <iostream>
#include <string>
class Bank
{
public:
    void MainScreen();
    void LoginScreen();
    void Header();
    void ExitScreen();
};
void Bank::Header()
{
    system("cls");
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "     ___  _  __       ___              _" << std::endl;
    std::cout << "    | _ \\| |/ /      | _ ) __ _  _ _  | |__" << std::endl;
    std::cout << "    |  _/|   <       | _ \\/ _` || ' \\ | / /" << std::endl;
    std::cout << "    |_|  |_|\\_\\      |___/\\__/_||_||_||_\\_\\ " << std::endl;
    std::cout << "----------------------------------------------" << std::endl
              << std::endl;
}
void Bank::MainScreen()
{
    Header();
    std::cout << "   Wybierz jedna z opcji:\n";
    std::cout << "1 || Zaloguj sie\n";
    std::cout << "2 || Zarejestruj sie\n";
    std::cout << "3 || Wyjdz z aplikacji\n\n";
    std::cout << "Opcja: ";
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
        system("cls");
        LoginScreen();
        break;
    case 3:
        ExitScreen();
    default:
        std::cout << "blad";
    }
};
void Bank::LoginScreen()
{
    Header();
    std::cout << "\n";
    std::cout << "Login:";
    std::string login, haslo;
    std::cin >> login;
    std::cout << "\nHaslo:";
    std::cin >> haslo;
    MainScreen();
};
void Bank::ExitScreen()
{
    system("cls");
    std::cout
        << "----------------------------------------------" << std::endl;
    std::cout << "\n\nDziekujemy za skorzystanie z naszego banku :>\n\n";
    std::cout << "----------------------------------------------" << std::endl;
    exit(0);
}
int main()
{
    Bank app;
    app.MainScreen();
    return 0;
}