#include "Interface.hpp"

void Interface::header()
{
    system("cls");
    std::cout << "         ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "         ┃            ___  _  __       ___              _              ┃" << std::endl;
    std::cout << "         ┃            | _ \\| |/ /      | _ ) __ _  _ _  | |__          ┃" << std::endl;
    std::cout << "         ┃            |  _/|   <       | _ \\/ _` || ' \\ | / /          ┃" << std::endl;
    std::cout << "         ┃            |_|  |_|\\_\\      |___/\\__/_||_||_||_\\_\\          ┃" << std::endl;
    std::cout << "         ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl
              << std::endl;
};

void Interface::mainBankScreen(const std::string name)
{
    header();
    Balanceuser Balanceuser;
    balance = Balanceuser.getBalance(name, isAuthorized);
    std::string Bspaces, Nspaces, balancetxt = std::to_string(balance);

    for (int i = 0; i < (26 - balancetxt.length()); i++) // Instrukcja obliczająca ilośc spacji żeby się zmieścić w butonie balance
    {
        Bspaces += " ";
    };
    for (int i = 0; i < (22 - name.length()); i++) // Instrukcja obliczająca ilośc spacji żeby się zmieścić w butonie name
    {
        Nspaces += " ";
    };
    std::cout << "          Nazwa konta                           Saldo\n";
    std::cout << "         ┏━━━━━━━━━━━━━━━━━━━━━━━┓             ┏━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "         ┃ " << name << Nspaces << "┃             ┃ " << std::fixed << std::setprecision(2) << balance << Bspaces << "┃" << std::endl;
    std::cout
        << "         ┗━━━━━━━━━━━━━━━━━━━━━━━┛             ┗━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
    std::cout << std::endl
              << "         1.    Wykonaj Transfer                                         " << std::endl;
    std::cout << "         2.    Dodaj srodki                                     " << std::endl;
    std::cout << "         3.    Historia Przelewow                                     " << std::endl;
    std::cout << "         4.    Wyloguj sie                                   " << std::endl
              << std::endl;

    int option;
    std::cout << "         Wybierz Opcje wpisujac liczbe: ";
    std::cin >> option;

    switch (option)
    {
    case 1:
        system("cls");
        exitScreen();
        break;
    case 2:
        depositScreen();
        break;
    case 4:
        exitScreen();
        break;
    default:
        std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
        std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
        mainBankScreen(login);
    }
};
void Interface::welcomeScreen()
{
    header();
    std::cout << "         1.    Zaloguj sie                                         " << std::endl;
    std::cout << "         2.    Zarejestruj sie                                     " << std::endl;
    std::cout << "         3.    Wyjdz z aplikacji                                   " << std::endl
              << std::endl;
    std::cout << "         Wybierz Opcje wpisujac liczbe: ";
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
        loginScreen();
        break;
    case 2:
        exitScreen();
        break;
    case 3:
        exitScreen();
        break;
    default:
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        welcomeScreen();
    }
};
void Interface::loginScreen()
{
    header();
    char character;
    std::cout << "         Login: ";

    std::cin >> login;

    std::cout << "\n         Haslo: ";

    character = getch();
    password = "";
    while (character != 13)
    {
        if (character == 8 && password.size())
        {
            std::cout << "\b \b";
            password.pop_back();
        }
        else if (character != 8)
        {
            std::cout.put('*');
            password += character;
        }
        character = getch();
    }
    Authorization Authorization;
    if (Authorization.doesUserExist(login, password))
    {
        isAuthorized = true;
        std::cout
            << "\n\n         Wprowadzone dane sa poprawne za chwile nastapi zalogowanie do banku";
        this_thread::sleep_for(chrono::seconds(2));
        mainBankScreen(login);
    }
    else
    {
        isAuthorized = false;
        std::cout
            << "\n\n         Podano nieprawidlowy login lub haslo";
        this_thread::sleep_for(chrono::seconds(2));
        welcomeScreen();
    }
};
void Interface::exitScreen()
{
    header();
    std::cout << "         Dziekujemy za skorzystanie z naszego banku \n\n\n\n\n";
    exit(0);
}
void Interface::depositScreen() // Nie dziala trzeba zrobić zapis do pliku dat
{
    header();
    long double dodaj = 0;
    std::cout << "Dodaj srodki: ";
    std::cin >> dodaj;
    balance = balance + dodaj;
    mainBankScreen(login);
}