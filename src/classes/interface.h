/* Dodaje interfejs
Przykład użycia w main.cpp

#include "classes/interface.h"

int main()
{
    interface interface;
    interface.WelcomeScreen();
    return 0;
}
*/
#ifndef interface_hpp
#define interface_hpp

#include <iostream> // obsługa wejścia wyjścia
#include <string>   // dodaje zmienną string
#include <stdlib.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <iomanip> //for std::setprecision

#include "authorization.h"
#include "balanceuser.h"

class interface
{
public:
    void Header();                               // Wyswietla Logo
    void WelcomeScreen();                        // Ekran startowy z logowanie, rejestracją i wyjściem z programu
    void LoginScreen();                          // Ekran Logowania
    void ExitScreen();                           // Komunikat o zakończeniu programu
    void MainBankScreen(const std::string name); // Ekran dostępny po zalogowaniu pokazuję stan konta, nazwe oraz menu z transferem środków itp
    void DepositScreen();                        // Nie dziala trzeba zrobić zapis do pliku dat

private:
    std::string login, password; // Zmienne przechowujące login i hasło login jako nazwa pliku np kamil.dat ale bez końcówki oraz hasło zapisane w 1 linijce pliku
    bool auth;                   // Zmienna przechowująca czy użytkownik jest poprawnie zalogowany
    long double balance;         // Zmienna przechowująca salto konta
};
void interface::Header()
{
    system("cls");
    std::cout << "         ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "         ┃            ___  _  __       ___              _              ┃" << std::endl;
    std::cout << "         ┃            | _ \\| |/ /      | _ ) __ _  _ _  | |__          ┃" << std::endl;
    std::cout << "         ┃            |  _/|   <       | _ \\/ _` || ' \\ | / /          ┃" << std::endl;
    std::cout << "         ┃            |_|  |_|\\_\\      |___/\\__/_||_||_||_\\_\\          ┃" << std::endl;
    std::cout << "         ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl
              << std::endl;
    ;
}
void interface::MainBankScreen(const std::string name)
{
    Header();
    balanceuser balanceuser;
    balance = balanceuser.Balance(name, auth);
    std::string Bspaces, Nspaces, balancetxt = std::to_string(balance);

    for (int i = 0; i < (26 - balancetxt.length()); i++) // Instrukcja obliczająca ilośc spacji żeby się zmieścić w butonie balance
    {
        Bspaces += " ";
    };
    for (int i = 0; i < (22 - name.length()); i++) // Instrukcja obliczająca ilośc spacji żeby się zmieścić w butonie name
    {
        Nspaces += " ";
    };
    std::cout << "          Nazwa konta                           Salto\n";
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
        ExitScreen();
        break;
    case 2:
        DepositScreen();
        break;
    case 4:
        ExitScreen();
        break;
    default:
        std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
        std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
        MainBankScreen(login);
    }
};
void interface::WelcomeScreen()
{
    Header();
    int option;
    std::cout << "         1.    Zaloguj sie                                         " << std::endl;
    std::cout << "         2.    Zarejestruj sie                                     " << std::endl;
    std::cout << "         3.    Wyjdz z aplikacji                                   " << std::endl
              << std::endl;
    std::cout << "         Wybierz Opcje wpisujac liczbe: ";
    std::cin >> option;
    switch (option)
    {
    case 1:
        LoginScreen();
        break;
    case 2:
        ExitScreen();
        break;
    case 3:
        ExitScreen();
        break;
    default:
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        WelcomeScreen();
    }
};
void interface::LoginScreen()
{
    Header();
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
    authorization authorization;
    if (authorization.IsUserExist(login, password))
    {
        auth = true;
        std::cout
            << "\n         Poprawne dane";
        this_thread::sleep_for(chrono::seconds(2));
        MainBankScreen(login);
    }
    else
    {
        auth = false;
        system("cls");
        Header();
        std::cout
            << "\n         Nieporawne haslo albo login" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        WelcomeScreen();
    }

    // WelcomeScreen();
};
void interface::ExitScreen()
{
    Header();
    std::cout << "         Dziekujemy za skorzystanie z naszego banku \n\n\n\n\n";
    exit(0);
}
void interface::DepositScreen() // Nie dziala trzeba zrobić zapis do pliku dat
{
    Header();
    long double dodaj = 0;
    std::cout << "Dodaj srodki: ";
    std::cin >> dodaj;
    balance = balance + dodaj;
    MainBankScreen(login);
}
#endif