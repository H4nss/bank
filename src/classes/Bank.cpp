#include "Bank.hpp"
#include "User.hpp"

void Bank::header()
{
    system("cls");
    std::cout << "          _____________________________________________________________" << std::endl;
    std::cout << "         |            ___  _  __       ___              _              |" << std::endl;
    std::cout << "         |            | _ \\| |/ /      | _ ) __ _  _ _  | |__          |" << std::endl;
    std::cout << "         |            |  _/|   <       | _ \\/ _` || ' \\ | / /          |" << std::endl;
    std::cout << "         |            |_|  |_|\\_\\      |___/\\__/_||_||_||_\\_\\          |" << std::endl;
    std::cout << "         |_____________________________________________________________|" << std::endl
              << std::endl;
};
void Bank::welcomeScreen()
{
    header();
    std::cout << "         1.    Zaloguj sie                                         \n";
    std::cout << "         2.    Zarejestruj sie                                     \n";
    std::cout << "         3.    Wyjdz z aplikacji                                   \n\n";
    std::cout << "         Wybierz Opcje wpisujac liczbe: ";
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
        loginScreen();
        break;
    case 2:
        registerScreen();
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
void Bank::loginScreen()
{
    header();
    char character;
    std::string password, login;
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
    if (User.doesUserExist(login, password))
    {
        mainBankScreen();
    }
    else
    {
        loginScreen();
    }
};
void Bank::mainBankScreen()
{
    header();
    std::string Bspaces,
        Nspaces, balancetxt = std::to_string(User.PLN);
    for (int i = 0; i < (24 - balancetxt.length()); i++) // Instrukcja obliczająca ilośc spacji żeby się zmieścić w butonie balance
    {
        Bspaces += " ";
    };
    for (int i = 0; i < (22 - User.name.length()); i++) // Instrukcja obliczająca ilośc spacji żeby się zmieścić w butonie name
    {
        Nspaces += " ";
    };
    std::cout << "          Nazwa konta                           Saldo\n";
    std::cout << "          ________________________             ________________________ " << std::endl
              << "         |                        |           |                        |\n"
              << "         | " << User.name << Nspaces << " |           | " << std::fixed << std::setprecision(2) << User.PLN << "PLN" << Bspaces << "|" << std::endl;
    std::cout
        << "         |________________________|           |________________________| " << std::endl
        << std::endl;

    std::cout << "         1.    Wykonaj Transfer \n";
    std::cout << "         2.    Dodaj srodki     \n";
    std::cout << "         3.    Wyplac srodki    \n";
    std::cout << "         4.    Konto Walutowe   \n";
    std::cout << "         5.    Skarbonka        \n";
    std::cout << "         6.    Lista transakcji           \n";
    std::cout << "         7.    Wyloguj sie      \n\n";

    int option;
    std::cout << "         Wybierz Opcje wpisujac liczbe: ";
    std::cin >> option;

    switch (option)
    {
    case 1:
        system("cls");
        transferScreen();
        break;
    case 2:
        depositScreen();
        break;
    case 3:
        withdrawScreen();
        break;
    case 4:
        system("cls");
        menuForeignCurrency();
        foreignCurrency();
        break;
    case 5:
        system("cls");
        menuPiggyBank();
        piggyBank();
        break;
    case 6:
        TransferListScreen();
        break;
    case 7:
        exitScreen();
        break;
    default:
        std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
        std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
        mainBankScreen();
    }
}
void Bank::exitScreen()
{
    header();
    std::cout << "         Dziekujemy za skorzystanie z naszego banku \n\n\n\n\n";
    exit(0);
}

void Bank::depositScreen()
{
    header();
    long double money = 0;
    int option = 1;

    switch (option)
    {
    case 1:
        std::cout << "\n         Podaj liczbe ktora chcesz wplacic: ";
        std::cin >> money;
        User.deposit(money, 1);
        successWithdrawDeposit(money, "PLN", 0);
        mainBankScreen();
        break;
    default:
        std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
        std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
        depositScreen();
    }
}
void Bank::registerScreen()
{
    header();
    char character;
    std::string password, login;
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
    if (User.RegisterUser(login, password))
    {
        std::cout << "\n\n         Uzytkownik stworzony pomyslnie\n         kliknij dowolny klawisz: ";
        getch();
        welcomeScreen();
    }
    else
    {
        std::cout << "\n\n         Osoba o takim loginie juz istnieje\n         kliknij dowolny klawisz: ";
        getch();
        welcomeScreen();
    }
}
void Bank::withdrawScreen()
{
    header();
    long double money = 0;
    int option = 1;

    switch (option)
    {
    case 1:
        system("cls");
        header();
        std::cout << "         Podaj liczbe ktora chcesz wyplacic: ";
        std::cin >> money;
        if (User.withdraw(money, 1))
            successWithdrawDeposit(money, "PLN", 1);
        else
            failWithdraw();
        break;

    default:
        std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
        std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
        withdrawScreen();
    }
}
void Bank::successWithdrawDeposit(long double money, std::string currency, short n)
{
    header();
    if (n == 1)
        std::cout << "         Wyplaciles: " << money << currency << std::endl
                  << std::endl;
    else
        std::cout << "         Wplaciles: " << money << currency << std::endl
                  << std::endl;

    std::cout << "         Wcisnij dowolny klawisz aby wrocic do menu glownego: ";
    getch();
    mainBankScreen();
}
void Bank::failWithdraw()
{
    header();
    std::cout << "         Nie masz wystarczajacy srodkow na koncie by wyplacic\n\n";
    std::cout << "         Wcisnij dowolny klawisz aby wrocic do menu glownego: ";
    getch();
    mainBankScreen();
}

void Bank::transferScreen()
{
    header();
    std::string username;
    short currency = 1, check;
    long double money;
    std::cout << "         Podaj id uzytkownika do ktorego chcesz wykonac przelew: ";
    std::cin >> username;
    if (username == User.name)
    {
        std::cout << "         Nie mozesz sam do siebie wyslac przelewu";
        getch();
        mainBankScreen();
    }
    std::cout << "         Podaj kwote: ";
    std::cin >> money;
    std::string CurrencyTab[] = {"PLN", "EUR", "USD", "CHF", "GBP"};
    check = User.Transfer(money, currency, username);
    if (check == 1)
        std::cout << "         Udalo sie wykonac przelew do " << username << " na kwote " << money << CurrencyTab[currency - 1];
    else if (check == 2)
        std::cout << "\n         Niewystarczajace srodki na koncie\n";
    else if (check == 3)
        std::cout << "\n         Uzytkownik nie istnieje\n";
    else
        std::cout << "\n         Nie znany blad\n";
    getch();
    mainBankScreen();
}
void Bank::TransferListScreen()
{
    header();
    std::cout << "          Lista tranzakcji: \n";
    User.raportTransferRead();
    getch();
    mainBankScreen();
}

// Skarbonka---------------------------------------------------------------------------------------------------------------------------------

void Bank::menuPiggyBank() // menu wyboru opcji Skarbonki
{
    header();
    std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
    std::cout << "|   Skarbonka   |" << std::endl;
    std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << User.piggyAccount << " zl | " << std::endl;
    std::cout << std::endl
              << "1. Wplata pieniedzy do Skarbonki" << std::endl;
    std::cout << "2. Wyplata pieniedzy ze Skarbonki" << std::endl;
    std::cout << "3. Pomoc" << std::endl;
    std::cout << "4. Powrot" << std::endl
              << std::endl;
    std::cout << "Twoj wybor: ";
    std::cin >> menuOption;
}

void Bank::piggyBank() // Skarbonka
{
    double depositAmmount = 0;
    double withdrawAmmount = 0;

    switch (menuOption)
    {
    case '1': // wplata do Skarbonki
    {
        system("cls");
        header();
        std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Skarbonka   |" << std::endl;
        std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << User.piggyAccount << " zl | " << std::endl;
        std::cout << std::endl
                  << "Twoje pieniadze, ktore wyplacisz ze swojego Konta Bankowego, beda istnialy w twojej Skarbonce. " << std::endl;
        std::cout << "Podaj ilosc pieniedzy w celu dodania ich do Skarbonki: ";
        std::cin >> depositAmmount;
        std::cout << std::endl;

        if (depositAmmount <= User.PLN)
        {
            User.deposit(depositAmmount, 6);  // wplata pieniedzy do Skarbonki
            User.withdraw(depositAmmount, 1); // wyplata pieniedzy PLN

            std::cout << "Wplaciles " << depositAmmount << " zl do twojej Skarbonki." << std::endl;
            std::cout << "Kliknij dowolny przycisk aby kontynuowac.";
            getch();
        }
        else
        {
            std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << std::endl;
            std::cout << "Kliknij dowolny przycisk aby cofnąć do menu.";
            getch();
        }
        menuPiggyBank();
        piggyBank();
        break;
    }
    case '2': // wyplata ze Skarbonki
    {
        system("cls");
        header();
        std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Skarbonka   |" << std::endl;
        std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << User.piggyAccount << " zl | " << std::endl;
        std::cout << std::endl
                  << "Twoje pieniadze, ktore wyplacisz ze swojej Skarbonki, beda istnialy na twoim Koncie Bankowym. " << std::endl;
        std::cout << "Podaj ilosc pieniedzy w celu dodania ich do twojego Konta Bankowego: ";
        std::cin >> withdrawAmmount;
        std::cout << std::endl;

        if (withdrawAmmount <= User.piggyAccount)
        {
            User.deposit(withdrawAmmount, 1);  // wplata pieniedzy PLN
            User.withdraw(withdrawAmmount, 6); // wyplata pieniedzy ze Skarbonki
            std::cout << "Wyplaciles " << withdrawAmmount << " zl ze swojej Skarbonki.";
            getch();
        }
        else
        {
            std::cout << "Za malo pieniedzy w twojej Skarbonce, aby wyplacic dana liczbe pieniedzy." << std::endl;
            std::cout << "Kliknij dowolny przycisk aby cofnac do menu.";
            getch();
        }
        menuPiggyBank();
        piggyBank();
        break;
    }
    case '3': // pomoc do programu Skarbonka
    {
        header();
        std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Skarbonka   |" << std::endl;
        std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << User.piggyAccount << " zl | " << std::endl;
        std::cout << std::endl
                  << "Skarbonka to program, ktory umozliwia odlozenie swoich pieniedzy w bezpieczne miejsce. Aby wplacic pieniadze do Skarbonki," << std::endl;
        std::cout << "musisz przelac je ze swojego Konta Bankowego, wybierajac opcje nr 1 w menu Skarbonki. Pieniadze, ktore znajduja sie w Skarbonce, " << std::endl;
        std::cout << "mozesz wyplacic w kazdym momencie, wybierajac opcje nr 2 w menu Skarbonki. Mozesz wyjsc ze Skarbonki, korzystajac z opcji nr 3 w Menu Skarbonki." << std::endl;
        std::cout << std::endl
                  << "Aby wyjsc z opcji Pomoc, nacisnij dowolny klawisz.";
        getch();
        menuPiggyBank();
        piggyBank();
        break;
    }
    case '4': // Powrot
    {
        mainBankScreen();
        break;
    }
    default: // jesli ktos wpisze zla opcje
    {
        header();
        std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Skarbonka   |" << std::endl;
        std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << User.piggyAccount << " zl | " << std::endl
                  << std::endl;
        std::cout << "Zly wybor opcji, Sprobuj ponownie." << std::endl
                  << std::endl;
        getch();
        menuPiggyBank();
        piggyBank();
        break;
    }
    }
}

// Konto Walutowe.....................................................................................................................

void Bank::changePLN() // zamiana PLN-->x, liczba z przecinkiem to kurs waluty x-->PLN
{
    if (option2 <= User.PLN)
    {
        if (firstChoice == '1' && secondChoice == '2')
        {
            firstCurrency = " Zl";
            secondCurrency = " Euro";
            option3 = option2 / 4.65;
            User.deposit(option3, 2);  // wplata pieniedzy EUR
            User.withdraw(option2, 1); // wyplata pieniedzy PLN
        }
        if (firstChoice == '1' && secondChoice == '3')
        {
            firstCurrency = " Zl";
            secondCurrency = " $";
            option3 = option2 / 4.42;
            User.deposit(option3, 3);  // wplata pieniedzy USD
            User.withdraw(option2, 1); // wyplata pieniedzy PLN
        }
        if (firstChoice == '1' && secondChoice == '4')
        {
            firstCurrency = " Zl";
            secondCurrency = " Fr";
            option3 = option2 / 4.44;
            User.deposit(option3, 4);  // wplata pieniedzy CHF
            User.withdraw(option2, 1); // wyplata pieniedzy PLN
        }
        if (firstChoice == '1' && secondChoice == '5')
        {
            firstCurrency = " Zl";
            secondCurrency = " L";
            option3 = option2 / 5.52;
            User.deposit(option3, 5);  // wplata pieniedzy GBP
            User.withdraw(option2, 1); // wyplata pieniedzy PLN
        }
        std::cout << "Zamieniles " << option2 << firstCurrency << " na " << option3 << secondCurrency << ".";
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe.";
    }
    getch();
}

void Bank::changeEUR() // zamiana EUR-->x, liczba z przecinkiem to kurs waluty x-->EUR
{
    if (option2 <= User.EUR)
    {
        if (firstChoice == '2' && secondChoice == '1')
        {
            firstCurrency = " Euro";
            secondCurrency = " Zl";
            option3 = option2 / 0.21;
            User.deposit(option3, 1);  // wplata pieniedzy PLN
            User.withdraw(option2, 2); // wyplata pieniedzy EUR
        }
        if (firstChoice == '2' && secondChoice == '3')
        {
            firstCurrency = " Euro";
            secondCurrency = " $";
            option3 = option2 / 0.95;
            User.deposit(option3, 3);  // wplata pieniedzy USD
            User.withdraw(option2, 2); // wyplata pieniedzy EUR
        }
        if (firstChoice == '2' && secondChoice == '4')
        {
            firstCurrency = " Euro";
            secondCurrency = " Fr";
            option3 = option2 / 0.95;
            User.deposit(option3, 4);  // wplata pieniedzy CHF
            User.withdraw(option2, 2); // wyplata pieniedzy EUR
        }
        if (firstChoice == '2' && secondChoice == '5')
        {
            firstCurrency = " Euro";
            secondCurrency = " L";
            option3 = option2 / 1.18;
            User.deposit(option3, 5);  // wplata pieniedzy GBP
            User.withdraw(option2, 2); // wyplata pieniedzy EUR
        }
        std::cout << "Zamieniles " << option2 << firstCurrency << " na " << option3 << secondCurrency << ".";
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe.";
    }
    getch();
}

void Bank::changeUSD() // zamiana USD-->x, liczba z przecinkiem to kurs waluty x-->USD
{
    if (option2 <= User.USD)
    {
        if (firstChoice == '3' && secondChoice == '1')
        {
            firstCurrency = " $";
            secondCurrency = " Zl";
            option3 = option2 / 0.23;
            User.deposit(option3, 1);  // wplata pieniedzy PLN
            User.withdraw(option2, 3); // wyplata pieniedzy USD
        }
        if (firstChoice == '3' && secondChoice == '2')
        {
            firstCurrency = " $";
            secondCurrency = " Euro";
            option3 = option2 / 1.05;
            User.deposit(option3, 2);  // wplata pieniedzy EUR
            User.withdraw(option2, 3); // wyplata pieniedzy USD
        }
        if (firstChoice == '3' && secondChoice == '4')
        {
            firstCurrency = " $";
            secondCurrency = " Fr";
            option3 = option2 / 1.01;
            User.deposit(option3, 4);  // wplata pieniedzy CHF
            User.withdraw(option2, 3); // wyplata pieniedzy USD
        }
        if (firstChoice == '3' && secondChoice == '5')
        {
            firstCurrency = " $";
            secondCurrency = " L";
            option3 = option2 / 1.25;
            User.deposit(option3, 5);  // wplata pieniedzy GBP
            User.withdraw(option2, 3); // wyplata pieniedzy USD
        }
        std::cout << "Zamieniles " << option2 << firstCurrency << " na " << option3 << secondCurrency << "." << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe.";
    }
    getch();
}

void Bank::changeCHF() // zamiana CHF-->x, liczba z przecinkiem to kurs waluty x-->CHF
{
    if (option2 <= User.CHF)
    {
        if (firstChoice == '4' && secondChoice == '1')
        {
            firstCurrency = " Fr";
            secondCurrency = " Zl";
            option3 = option2 / 0.23;
            User.deposit(option3, 1);  // wplata pieniedzy PLN
            User.withdraw(option2, 4); // wyplata pieniedzy CHF
        }
        if (firstChoice == '4' && secondChoice == '2')
        {
            firstCurrency = " Fr";
            secondCurrency = " Euro";
            option3 = option2 / 1.05;
            User.deposit(option3, 2);  // wplata pieniedzy EUR
            User.withdraw(option2, 4); // wyplata pieniedzy CHF
        }
        if (firstChoice == '4' && secondChoice == '3')
        {
            firstCurrency = " Fr";
            secondCurrency = " $";
            option3 = option2 / 0.99;
            User.deposit(option3, 3);  // wplata pieniedzy USD
            User.withdraw(option2, 4); // wyplata pieniedzy CHF
        }
        if (firstChoice == '4' && secondChoice == '5')
        {
            firstCurrency = " Fr";
            secondCurrency = " L";
            option3 = option2 / 1.24;
            User.deposit(option3, 5);  // wplata pieniedzy GBP
            User.withdraw(option2, 4); // wyplata pieniedzy CHF
        }
        std::cout << "Zamieniles " << option2 << firstCurrency << " na " << option3 << secondCurrency << ".";
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe.";
    }
    getch();
}

void Bank::changeGBP() // zamiana GBP-->x, liczba z przecinkiem to kurs waluty x-->GBP
{
    if (option2 <= User.GBP)
    {
        if (firstChoice == '5' && secondChoice == '1')
        {
            firstCurrency = " L";
            secondCurrency = " Zl";
            option3 = option2 / 0.18;
            User.deposit(option3, 1);  // wplata pieniedzy PLN
            User.withdraw(option2, 5); // wyplata pieniedzy GBP
        }
        if (firstChoice == '5' && secondChoice == '2')
        {
            firstCurrency = " L";
            secondCurrency = " Euro";
            option3 = option2 / 0.84;
            User.deposit(option3, 2);  // wplata pieniedzy EUR
            User.withdraw(option2, 5); // wyplata pieniedzy GBP
        }
        if (firstChoice == '5' && secondChoice == '3')
        {
            firstCurrency = " L";
            secondCurrency = " $";
            option3 = option2 / 0.80;
            User.deposit(option3, 3);  // wplata pieniedzy USD
            User.withdraw(option2, 5); // wyplata pieniedzy GBP
        }
        if (firstChoice == '5' && secondChoice == '4')
        {
            firstCurrency = " L";
            secondCurrency = " Fr";
            option3 = option2 / 0.81;
            User.deposit(option3, 4);  // wplata pieniedzy CHF
            User.withdraw(option2, 5); // wyplata pieniedzy GBP
        }
        std::cout << "Zamieniles " << option2 << firstCurrency << " na " << option3 << secondCurrency << "." << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << std::endl
                  << std::endl;
    }
    getch();
}

void Bank::menuForeignCurrency() // menu wyboru opcji Konta Walutowego
{
    header();
    std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | PLN: " << User.PLN << " zl |" << std::endl;
    std::cout << "|   Konto Walutowe   |" << std::endl;
    std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | EUR: " << User.EUR << " Euro | USD: " << User.USD << " $ | CHF: " << User.CHF << " Fr | GBP: " << User.GBP << " L |" << std::endl
              << std::endl;
    std::cout << "1. Zamiana walut" << std::endl;
    std::cout << "2. Pomoc" << std::endl;
    std::cout << "3. Powrot" << std::endl
              << std::endl;
    std::cout << "Twoj wybor: ";
    std::cin >> menuOption;
}

void Bank::foreignCurrency() // Konto Walutowe
{
    switch (menuOption)
    {
    case '1': // Zamiana walut
    {
        header();
        std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | PLN: " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Konto Walutowe   |" << std::endl;
        std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | EUR: " << User.EUR << " Euro | USD: " << User.USD << " $ | CHF: " << User.CHF << " Fr | GBP: " << User.GBP << " L |" << std::endl
                  << std::endl;
        std::cout << "1. PLN" << std::endl;
        std::cout << "2. EUR" << std::endl;
        std::cout << "3. USD" << std::endl;
        std::cout << "4. CHF" << std::endl;
        std::cout << "5. GBP" << std::endl
                  << std::endl;
        std::cout << "Podaj z jakiej waluty chcesz przelac pieniadze (1-5): ";
        std::cin >> firstChoice;
        std::cout << "Podaj na jaka walute chcesz przelac pieniadze (1-5): ";
        std::cin >> secondChoice;
        std::cout << std::endl
                  << "Podaj ilosc pieniedzy: ";
        std::cin >> option2;
        std::cout << std::endl;

        // obsluga zamiany walut

        if ((firstChoice == '1' && secondChoice == '2') || (firstChoice == '1' && secondChoice == '3') || (firstChoice == '1' && secondChoice == '4') || (firstChoice == '1' && secondChoice == '5'))
        {
            changePLN();
        }

        else if ((firstChoice == '2' && secondChoice == '1') || (firstChoice == '2' && secondChoice == '3') || (firstChoice == '2' && secondChoice == '4') || (firstChoice == '2' && secondChoice == '5'))
        {
            changeEUR();
        }

        else if ((firstChoice == '3' && secondChoice == '1') || (firstChoice == '3' && secondChoice == '2') || (firstChoice == '3' && secondChoice == '4') || (firstChoice == '3' && secondChoice == '5'))
        {
            changeUSD();
        }

        else if ((firstChoice == '4' && secondChoice == '1') || (firstChoice == '4' && secondChoice == '2') || (firstChoice == '4' && secondChoice == '3') || (firstChoice == '4' && secondChoice == '5'))
        {
            changeCHF();
        }

        else if ((firstChoice == '5' && secondChoice == '1') || (firstChoice == '5' && secondChoice == '2') || (firstChoice == '5' && secondChoice == '3') || (firstChoice == '5' && secondChoice == '4'))
        {
            changeGBP();
        }

        else
        {
            std::cout << "Wybrano zla opcje." << std::endl
                      << std::endl;
            getch();
        }

        menuForeignCurrency();
        foreignCurrency();
        break;
    }
    case '2': // pomoc Konta Walutowego
    {
        header();
        std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | PLN: " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Konto Walutowe   |" << std::endl;
        std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | EUR: " << User.EUR << " Euro | USD: " << User.USD << " $ | CHF: " << User.CHF << " Fr | GBP: " << User.GBP << " L |" << std::endl
                  << std::endl;
        std::cout << "Konto Walutowe to program, ktory umozliwia zamiane roznych walut i przechowywanie ich na swoim Koncie Walutowym." << std::endl;
        std::cout << "Korzystajac z opcji nr 3 w menu Konta Bankowego, mozesz przewalutowac swoje pieniadze. Musisz tylko podac walute, z ktorej chcesz" << std::endl;
        std::cout << "przewalutowac swoje pieniadze, walute docelowa oraz ilosc pieniedzy do przewalutowania. Mozesz wyjsc z Konta Walutowego, " << std::endl;
        std::cout << "korzystajac z opcji nr 5 w Menu Konta Wallutowego." << std::endl
                  << std::endl;
        std::cout << "Aby wyjsc z opcji Pomoc, nacisnij dowolny klawisz." << std::endl;
        getch();
        menuForeignCurrency();
        foreignCurrency();
        break;
    }
    case '3': // Powrot
    {
        mainBankScreen();
        break;
    }
    default: // Zly wybor opcji
    {
        header();
        std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | PLN: " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Konto Walutowe   |" << std::endl;
        std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | EUR: " << User.EUR << " Euro | USD: " << User.USD << " $ | CHF: " << User.CHF << " Fr | GBP: " << User.GBP << " L |" << std::endl
                  << std::endl;
        std::cout << "Zly wybor opcji, Sprobuj ponownie.";
        getch();
        menuForeignCurrency();
        foreignCurrency();
        break;
    }
    }
}