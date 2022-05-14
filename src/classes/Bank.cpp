#include "Bank.hpp"

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
    std::cout << "         2.    Konto walutowe   \n";
    std::cout << "         3.    Dodaj srodki     \n";
    std::cout << "         4.    Wyplac srodki    \n";
    std::cout << "         5.    Kantor           \n";
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
        piggyBankScreen();
        break;
    case 3:
        depositeScreen();
        break;
    case 4:
        withdrawScreen();
        break;
    case 5:
        moneyChangerScreen();
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
void Bank::piggyBankScreen()
{
    header();
    std::cout << "         Na twoim koncie Waluntowym aktualnie znajduję się: \n\n";
    std::cout << "          " << User.PLN << " PLN " << std::endl;
    std::cout << "          " << User.EUR << " EUR " << std::endl;
    std::cout << "          " << User.USD << " USD " << std::endl;
    std::cout << "          " << User.CHF << " CHF " << std::endl;
    std::cout << "          " << User.GBP << " GBP " << std::endl
              << std::endl;
    std::cout << "         Wcisnij dowolny klawisz aby wrocic do menu glownego: ";
    getch();
    mainBankScreen();
}
void Bank::depositeScreen()
{
    header();
    long double money = 0;
    std::cout << "         1 PLN        2 EUR        3 USD        4 CHF        5 GBP\n\n";
    std::cout << "         Wybierz Walute: ";
    int option;
    std::cin >> option;

    switch (option)
    {
    case 1:
        std::cout << "\n         Podaj liczbe ktora chcesz wplacic: ";
        std::cin >> money;
        User.deposit(money, 1);
        successWithdrawDeposit(money, "PLN", 0);
        mainBankScreen();
        break;
    case 2:
        std::cout << "\n         Podaj liczbe ktora chcesz wplacic: ";
        std::cin >> money;
        User.deposit(money, 2);
        successWithdrawDeposit(money, "EUR", 0);
        mainBankScreen();
        break;
    case 3:
        std::cout << "\n         Podaj liczbe ktora chcesz wplacic: ";
        std::cin >> money;
        User.deposit(money, 3);
        successWithdrawDeposit(money, "USD", 0);
        mainBankScreen();
        break;
    case 4:
        std::cout << "\n         Podaj liczbe ktora chcesz wplacic: ";
        std::cin >> money;
        User.deposit(money, 4);
        successWithdrawDeposit(money, "CHF", 0);
        mainBankScreen();
        break;
    case 5:
        std::cout << "\n         Podaj liczbe ktora chcesz wplacic: ";
        std::cin >> money;
        User.deposit(money, 5);
        successWithdrawDeposit(money, "GBP", 0);
        mainBankScreen();

        break;
    default:
        std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
        std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
        depositeScreen();
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
    std::cout << "         Wybierz Walute do wypłacenia: \n";
    std::cout << "         1.PLN: " << std::endl;
    std::cout << "         2.EUR: " << std::endl;
    std::cout << "         3.USD: " << std::endl;
    std::cout << "         4.CHF: " << std::endl;
    std::cout << "         5.GBP: " << std::endl;
    int option;
    std::cout << "         Wybierz Opcje wpisujac liczbe: ";
    std::cin >> option;

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
    case 2:
        system("cls");
        header();
        std::cout << "         Podaj liczbe ktora chcesz wyplacic: ";
        std::cin >> money;
        if (User.withdraw(money, 2))
            successWithdrawDeposit(money, "EUR", 1);
        else
            failWithdraw();
        break;
    case 3:
        system("cls");
        header();
        std::cout << "         Podaj liczbe ktora chcesz wyplacic: ";
        std::cin >> money;
        if (User.withdraw(money, 3))
            successWithdrawDeposit(money, "USD", 1);
        else
            failWithdraw();
        break;
    case 4:
        system("cls");
        header();
        std::cout << "         Podaj liczbe ktora chcesz wyplacic: ";
        std::cin >> money;
        if (User.withdraw(money, 4))
            successWithdrawDeposit(money, "CHF", 1);
        else
            failWithdraw();
        break;
    case 5:
        system("cls");
        header();
        std::cout << "         Podaj liczbe ktora chcesz wyplacic: ";
        std::cin >> money;
        if (User.withdraw(money, 5))
            successWithdrawDeposit(money, "GBP", 1);
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
void Bank::moneyChangerScreen()
{
    header();
    long double money;
    long double change;

    std::cout << "         Wybierz walute do przewalutowania\n";
    std::cout << "         1 PLN        2 EUR        3 USD        4 CHF        5 GBP\n\n";
    std::cout << "         Wybierz walute: ";
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
        header();
        std::cout << "         Wybierz walute na ktora chcesz przewalotowac walute\n";
        std::cout << "         1 EUR        2 USD        3 CHF        4 GBP\n\n";
        std::cout << "         Wybierz walute: ";
        std::cin >> option;
        std::cout << "\n         Wpisz ilosc pieniedzy do przewalotowania: ";
        std::cin >> money;
        change = User.moneyChanger(money, 1, option);
        if (change)
        {
            std::string CurrencyTab[] = {"EUR", "USD", "CHF", "GBP"};
            std::cout << "\n         Przewalotowales " << money << "PLN na " << change << CurrencyTab[option - 1];
        }
        else
            std::cout << "\n         Za malo srodkow na koncie";
        break;
    case 2:
        header();
        std::cout << "         Wybierz walute do przewalutowania\n";
        std::cout << "         1 PLN        2 USD        3 CHF        4 GBP\n\n";
        std::cout << "         Wybierz walute: ";
        std::cin >> option;
        std::cout << "\n         Wpisz ilosc pieniedzy do przewalotowania: ";
        std::cin >> money;
        change = User.moneyChanger(money, 2, option);
        if (change)
        {
            std::string CurrencyTab[] = {"PLN", "USD", "CHF", "GBP"};
            std::cout << "\n         Przewalotowales " << money << "EUR na " << change << CurrencyTab[option - 1];
        }
        else
            std::cout << "\n         Za malo srodkow na koncie";
        break;
    case 3:
        header();
        std::cout << "         Wybierz walute do przewalutowania\n";
        std::cout << "         1 PLN        2 EUR        3 CHF        4 GBP\n\n";
        std::cout << "         Wybierz walute: ";
        std::cin >> option;
        std::cout << "\n         Wpisz ilosc pieniedzy do przewalotowania: ";
        std::cin >> money;
        change = User.moneyChanger(money, 3, option);
        if (change)
        {
            std::string CurrencyTab[] = {"PLN", "EUR", "CHF", "GBP"};
            std::cout << "\n         Przewalotowales " << money << "USD na " << change << CurrencyTab[option - 1];
        }
        else
            std::cout << "\n         Za malo srodkow na koncie";
        break;
    case 4:
        header();
        std::cout << "         Wybierz walute do przewalutowania\n";
        std::cout << "         1 PLN        2 EUR        3 USD        4 GBP\n\n";
        std::cout << "         Wybierz walute: ";
        std::cin >> option;
        std::cout << "\n         Wpisz ilosc pieniedzy do przewalotowania: ";
        std::cin >> money;
        change = User.moneyChanger(money, 4, option);
        if (change)
        {
            std::string CurrencyTab[] = {"PLN", "EUR", "USD", "GBP"};
            std::cout << "\n         Przewalotowales " << money << "CHF na " << change << CurrencyTab[option - 1];
        }
        else
            std::cout << "\n         Za malo srodkow na koncie";
        break;
    case 5:
        header();
        std::cout << "         Wybierz walute do przewalutowania\n";
        std::cout << "         1 PLN        2 EUR        3 USD        4 CHF\n\n";
        std::cout << "         Wybierz walute: ";
        std::cin >> option;
        std::cout << "\n         Wpisz ilosc pieniedzy do przewalotowania: ";
        std::cin >> money;
        change = User.moneyChanger(money, 5, option);
        if (change)
        {
            std::string CurrencyTab[] = {"PLN", "EUR", "USD", "CHF"};
            std::cout << "\n         Przewalotowales " << money << "GBP na " << change << CurrencyTab[option - 1];
        }
        else
            std::cout << "\n         Za malo srodkow na koncie";
        break;
    default:
        std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
        std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
        moneyChangerScreen();
    }
    getch();
    mainBankScreen();
}
void Bank::transferScreen()
{
    header();
    std::string username;
    short currency, check;
    long double money;
    std::cout << "         Podaj id uzytkownika do ktorego chcesz wykonac przelew: ";
    std::cin >> username;
    if (username == User.name)
    {
        std::cout << "         Nie mozesz sam do siebie wyslac przelew";
        getch();
        mainBankScreen();
    }
    std::cout << "         1 PLN        2 EUR        3 USD        4 CHF        5 GBP\n\n";
    std::cout << "         Wybierz Walute: ";
    std::cin >> currency;
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