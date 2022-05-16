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
        depositeScreen();
        break;
    case 3:
        withdrawScreen();
        break;
    case 4:
        system("cls");
        menuForeignCurrency();
        anotherChoice();
        foreignCurrency();
        break;
    case 5:
        system("cls");
        menuPiggyBank();
        choice();
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

void Bank::depositeScreen()
{
    header();
    long double money = 0;
    int option=1;

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
    int option=1;

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
    short currency=1, check;
    long double money;
    std::cout << "         Podaj id uzytkownika do ktorego chcesz wykonac przelew: ";
    std::cin >> username;
    if (username == User.name)
    {
        std::cout << "         Nie mozesz sam do siebie wyslac przelew";
        getch();
        mainBankScreen();
    }
    //std::cout << "         1 PLN        2 EUR        3 USD        4 CHF        5 GBP\n\n";
    //std::cout << "         Wybierz Walute: ";
    //std::cin >> currency;
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

//Skarbonka---------------------------------------------------------------------------------------------------------------------------------
    void Bank::choice()
    {
        std::cout << "Twoj wybor: ";
        std::cin >> sign;
    }

    void Bank::menuPiggyBank()
    {
        header();
        std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Skarbonka   |" << std::endl;
        std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << User.SKARBONKA << " zl | " << std::endl;
        std::cout << std::endl << "1. Wplata pieniedzy do Skarbonki" <<std:: endl;
        std::cout << "2. Wyplata pieniedzy ze Skarbonki" << std::endl;
        std::cout << "3. Pomoc" << std::endl;
        std::cout << "4. Powrot" <<std:: endl <<std:: endl;
    }

    void Bank::piggyBank()
    {
        double x = 0,t=0;

        switch (sign)
        {
        case '1':
        {
            system("cls");
            header();
            std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
            std::cout << "|   Skarbonka   |" << std::endl;
            std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << User.SKARBONKA << " zl | " << std::endl;
            std::cout << std::endl << "Twoje pieniadze, ktore wyplacisz ze swojego Konta Bankowego, beda istnialy w twojej Skarbonce. " << std::endl;
            std::cout << "Podaj ilosc pieniedzy w celu dodania ich do Skarbonki: ";
            std::cin >> x;
            
            system("cls");
            if (x <= User.PLN)
            {   
                User.deposit(x, 6);
                User.withdraw(x, 1);
                t = x;
                
                menuPiggyBank();
                std::cout << "Wplaciles " << x << " zl do twojej Skarbonki." <<std:: endl << std::endl;
            }
            else
            {
                system("cls");
                menuPiggyBank();
                std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << std::endl << std::endl;
            }
            choice();
            piggyBank();
            break;
        }
        case '2':
        {
            system("cls");
            header();
            std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
            std::cout << "|   Skarbonka   |" << std::endl;
            std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << User.SKARBONKA << " zl | " << std::endl;
            std::cout << std::endl << "Twoje pieniadze, ktore przewalutujesz ze swojej Skarbonki, beda istnialy na twoim Koncie Bankowym. " << std::endl;
            std::cout << "Podaj ilosc pieniedzy w celu dodania ich do twojego Konta Bankowego: ";
            std::cin >> x;
            system("cls");
            if (x <= User.SKARBONKA)
            {
                User.deposit(x, 1);
                User.withdraw(x, 6);
                t = x;
                menuPiggyBank();
                std::cout << "Wyplaciles " << x << " zl ze swojej Skarbonki." << std::endl << std::endl;
            }
            else
            {
                system("cls");
                menuPiggyBank();
                std::cout << "Za malo pieniedzy w twojej Skarbonce, aby wyplacic dana liczbe pieniedzy." <<std:: endl << std::endl;
            }
            choice();
            piggyBank();
            break;
        }
        case '3':
        {
            system("cls");
            header();
            std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
            std::cout << "|   Skarbonka   |" << std::endl;
            std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << User.SKARBONKA << " zl | " << std::endl;
            std::cout<<std::endl<<"Skarbonka to program, ktory umozliwia odlozenie swoich pieniedzy w bezpieczne miejsce. Aby wplacic pieniadze do Skarbonki,"<<std::endl;
            std::cout<<"musisz przelac je ze swojego Konta Bankowego, wybierajac opcje nr 1 w menu Skarbonki. Pieniadze, ktore znajduja sie w Skarbonce, "<<std::endl;
            std::cout<<"mozesz wyplacic w kazdym momencie, wybierajac opcje nr 2 w menu Skarbonki. Mozesz wyjsc ze Skarbonki, korzystajac z opcji nr 3 w Menu Skarbonki."<<std::endl;
            std::cout<<std::endl<<"Aby wyjsc z opcji Pomoc, nacisnij dowolny klawisz.";
            getch();
            system("cls");
            menuPiggyBank();
            choice();
            piggyBank();
            break;
        }
        case '4':
        {
            system("cls");
            mainBankScreen();
            break;
        }
        default:
        {
            system("cls");
            menuPiggyBank();
            std::cout << "Zly wybor opcji, Podaj twoj wybor ponownie." << std::endl << std::endl;
            choice();
            piggyBank();
            break;
        }
        }

    }

//Konto Walutowe.....................................................................................................................


void Bank::anotherChoice()
    {
        std::cout << "Twoj wybor: ";
        std::cin >> firstSign;
    }
void Bank::changePLN() //zamiana PLN-->a
{
    if (a <= User.PLNkontowalutowe)
    {
        if (firstChoice == '1' && secondChoice == '2')
        {
            firstCurrency = " Zl";
            secondCurrency = " Euro";
            b = a / 4.72;
            User.deposit(b, 3);
            User.withdraw(a, 2);
        }
        if (firstChoice == '1' && secondChoice == '3')
        {
            firstCurrency = " Zl";
            secondCurrency = " $";
            b = a / 4.27;
            User.deposit(b, 4);
            User.withdraw(a, 2);
        }
        if (firstChoice == '1' && secondChoice == '4')
        {
            firstCurrency = " Zl";
            secondCurrency = " Fr";
            b = a / 4.57;
            User.deposit(b, 5);
            User.withdraw(a, 2);
        }
        menuForeignCurrency();
        std::cout << "Zamieniles " << a << firstCurrency << " na " << b << secondCurrency << "." << std::endl;
        std::cout << "Jednoczesnie wplaciles " << b << secondCurrency << " do twojego Konta Walutowego." << std::endl << std::endl;
        anotherChoice();
    }
    else
    {
        system("cls");
        menuForeignCurrency();
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << std::endl << std::endl;
        anotherChoice();
    }
}

void Bank::changeEUR() //zamiana EUR-->a
{
    if (a <= User.EUR)
    {
        if (firstChoice == '2' && secondChoice == '1')
        {
            firstCurrency = " Euro";
            secondCurrency = " Zl";
            b = a / 0.21;
            User.deposit(b, 2);
            User.withdraw(a, 3);
        }
        if (firstChoice == '2' && secondChoice == '3')
        {
            firstCurrency = " Euro";
            secondCurrency = " $";
            b = a / 0.90;
            User.deposit(b, 4);
            User.withdraw(a, 3);
        }
        if (firstChoice == '2' && secondChoice == '4')
        {
            firstCurrency = " Euro";
            secondCurrency = " Fr";
            b = a / 0.97;
            User.deposit(b, 5);
            User.withdraw(a, 3);
        }
        menuForeignCurrency();
        std::cout << "Zamieniles " << a << firstCurrency << " na " << b << secondCurrency << "." <<std:: endl;
        std::cout << "Jednoczesnie wplaciles " << b << secondCurrency << " do twojego Konta Walutowego." << std::endl <<std:: endl;
        anotherChoice();
    }
    else
    {
        system("cls");
        menuForeignCurrency();
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << std::endl << std::endl;
        anotherChoice();
    }
}

void Bank::changeUSD() //zamiana USD-->a
{
    if (a <= User.USD)
    {
        if (firstChoice == '3' && secondChoice == '1')
        {
            firstCurrency = " $";
            secondCurrency = " Zl";
            b = a / 0.23;
            User.deposit(b, 2);
            User.withdraw(a, 4);
        }
        if (firstChoice == '3' && secondChoice == '2')
        {
            firstCurrency = " $";
            secondCurrency = " Euro";
            b = a / 1.11;
            User.deposit(b, 3);
            User.withdraw(a, 4);
        }
        if (firstChoice == '3' && secondChoice == '4')
        {
            firstCurrency = " $";
            secondCurrency = " Fr";
            b = a / 1.07;
            User.deposit(b, 5);
            User.withdraw(a, 4);
        }
        menuForeignCurrency();
        std::cout << "Zamieniles " << a << firstCurrency << " na " << b << secondCurrency << "." << std::endl;
        std::cout << "Jednoczesnie wplaciles " << b << secondCurrency << " do twojego Konta Walutowego." << std::endl <<std:: endl;
        anotherChoice();
    }
    else
    {
        system("cls");
        menuForeignCurrency();
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << std::endl << std::endl;
        anotherChoice();
    }
}

void Bank::changeCHF() //zamiana CHF-->a
{
    if (a <= User.CHF)
    {
        if (firstChoice == '4' && secondChoice == '1')
        {
            firstCurrency = " Fr";
            secondCurrency = " Zl";
            b = a / 0.22;
            User.deposit(b, 2);
            User.withdraw(a, 5);
        }
        if (firstChoice == '4' && secondChoice == '2')
        {
            firstCurrency = " Fr";
            secondCurrency = " Euro";
            b = a / 1.03;
            User.deposit(b, 3);
            User.withdraw(a, 5);
        }
        if (firstChoice == '4' && secondChoice == '3')
        {
            firstCurrency = " Fr";
            secondCurrency = " $";
            b = a / 0.93;
            User.deposit(b, 4);
            User.withdraw(a, 5);
        }
        menuForeignCurrency();
        std::cout << "Zamieniles " << a << firstCurrency << " na " << b << secondCurrency << "." << std::endl;
        std::cout << "Jednoczesnie wplaciles " << b << secondCurrency << " do twojego Konta Walutowego." << std::endl << std::endl;
        anotherChoice();
    }
    else
    {
        system("cls");
        menuForeignCurrency();
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << std::endl << std::endl;
        anotherChoice();
    }
}

void Bank::menuForeignCurrency()
{
    header();
    std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" <<std:: endl;
    std::cout << "|   Konto Walutowe   |" << std::endl;
    std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << User.PLNkontowalutowe << " Zl | EUR: " << User.EUR << " Euro | USD: " << User.USD << " $ | CHF: " << User.CHF << " Fr |" << std::endl;
    std::cout << std::endl << "1. Wplata pieniedzy do Konta Walutowego" <<std:: endl;
    std::cout << "2. Wyplata pieniedzy z Konta Walutowego" << std::endl;
    std::cout << "3. Zamiana walut" <<std:: endl;
    std::cout << "4. Pomoc" << std::endl;
    std::cout << "5. Powrot" << std::endl << std::endl;
}

void Bank::foreignCurrency()
{
    switch (firstSign)
    {
    case '1':
    {
        system("cls");
        header();
        std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Konto Walutowe   |" << std::endl;
        std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << User.PLNkontowalutowe << " Zl | EUR: " << User.EUR << " Euro | USD: " << User.USD << " $ | CHF: " << User.CHF << " Fr |" <<std:: endl;
        std::cout << std::endl << "Twoje pieniadze, ktore wyplacisz ze swojego Konta Bankowego, beda istnialy na twoim Koncie Walutowym. " << std::endl;
        std::cout << "Podaj ilosc pieniedzy w zl: ";
        std::cin >> a;
        system("cls");
        if (a <= User.PLN)
        {
            b = a;
            User.deposit(a, 2);
            User.withdraw(a, 1);
            menuForeignCurrency();
            std::cout << "Wplaciles " << a << " zl do twojego Konta Walutowego." <<std:: endl << std::endl;
            anotherChoice();
        }
        else
        {
            system("cls");
            menuForeignCurrency();
            std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << std::endl << std::endl;
            anotherChoice();
        }
        foreignCurrency();
        break;
    }
    case '2':
    {
        system("cls");
        header();
        std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Konto Walutowe   |" << std::endl;
        std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << User.PLNkontowalutowe << " Zl | EUR: " << User.EUR << " Euro | USD: " << User.USD << " $ | CHF: " << User.CHF << " Fr |" <<std:: endl;
        std::cout << std::endl << "Twoje pieniadze, ktore wyplacisz ze swojego Konta Walutowego, beda istnialy na twoim Koncie Bankowym. " << std::endl;
        std::cout << "Podaj ilosc pieniedzy w zl: ";
        std::cin >> a;
        system("cls");
        if (a <= User.PLNkontowalutowe)
        {
            b = a;
            User.deposit(a, 1);
            User.withdraw(a, 2);
            menuForeignCurrency();
            std::cout << "Wyplaciles " << b << " zl ze swojego Konta Walutowego." << std::endl << std::endl;
            anotherChoice();
        }
        else
        {
            system("cls");
            menuForeignCurrency();
            std::cout << "Za malo pieniedzy na twoim Koncie Walutowym, aby wyplacic dana liczbe pieniedzy." << std::endl << std::endl;
            anotherChoice();
        }
        foreignCurrency();
        break;
    }

    case '3':
    {
        system("cls");
        header();
        std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Konto Walutowe   |" <<std:: endl;
        std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << User.PLNkontowalutowe << " Zl | EUR: " << User.EUR << " Euro | USD: " << User.USD << " $ | CHF: " << User.CHF << " Fr |" << std::endl;
        std::cout << std::endl << "1. PLN" << std::endl;
        std::cout << "2. EUR" << std::endl;
        std::cout << "3. USD" << std::endl;
        std::cout << "4. CHF" <<std:: endl <<std:: endl;
        std::cout << "Podaj z jakiej waluty chcesz przelac pieniadze (1-4): ";
        std::cin >> firstChoice;
        std::cout << "Podaj na jaka walute chcesz przelac pieniadze (1-4): ";
        std::cin >> secondChoice;
        std::cout <<std:: endl << "Podaj ilosc pieniedzy: ";
        std::cin >> a;

        system("cls");

        if ((firstChoice == '1' && secondChoice == '2') || (firstChoice == '1' && secondChoice == '3') || (firstChoice == '1' && secondChoice == '4'))
        {
            changePLN();
        }

        else if ((firstChoice == '2' && secondChoice == '1') || (firstChoice == '2' && secondChoice == '3') || (firstChoice == '2' && secondChoice == '4'))
        {
            changeEUR();
        }

        else if ((firstChoice == '3' && secondChoice == '1') || (firstChoice == '3' && secondChoice == '2') || (firstChoice == '3' && secondChoice == '4'))
        {
            changeUSD();
        }

        else if ((firstChoice == '4' && secondChoice == '1') || (firstChoice == '4' && secondChoice == '2') || (firstChoice == '4' && secondChoice == '3'))
        {
            changeCHF();
        }

        else
        {
            system("cls");
            menuForeignCurrency();
            std::cout << "Zly wybor opcji, Podaj twoj wybor ponownie." << std::endl << std::endl;
            anotherChoice();
            foreignCurrency();
        }

        foreignCurrency();
        break;
    }
    case '4':
    {
        system("cls");
        header();
        std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << User.PLN << " zl |" << std::endl;
        std::cout << "|   Konto Walutowe   |" << std::endl;
        std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << User.PLNkontowalutowe << " Zl | EUR: " << User.EUR << " Euro | USD: " << User.USD << " $ | CHF: " << User.CHF << " Fr |" << std::endl;
        std::cout << std::endl << "Konto Walutowe to program, ktory umozliwia zamiane roznych walut i przechowywanie ich na swoim Koncie Walutowym." << std::endl;
        std::cout << "Aby wplacic pieniadze do Konta Walutowego, musisz przelac je ze swojego Konta Bankowego, wybierajac opcje nr 1 w menu Konta Walutowego." << std::endl;
        std::cout << "Pieniadze, ktore znajduja sie na Koncie Walutowym mozesz wyplacic w kazdym momencie, wybierajac opcje nr 2 w menu Konta Walutowego." << std::endl;
        std::cout << "Aby przelew pomiedzy Kontem Bankowym, a Kontem Walutowym doszedl do skutku, musisz korzystac z waluty PLN. Korzystajac z" << std::endl;
        std::cout << "opcji nr 3 w menu Konta Bankowego, mozesz przewalutowac swoje pieniadze. Musisz tylko podac walute, z ktorej chcesz przewalutowac swoje pieniadze, " << std::endl;
        std::cout << "walute docelowa oraz ilosc pieniedzy do przewalutowania. Mozesz wyjsc z Konta Walutowego, korzystajac z opcji nr 5 w Menu Konta Wallutowego." << std::endl;
        std::cout << std::endl << "Aby wyjsc z opcji Pomoc, nacisnij dowolny klawisz.";
        getch();
        system("cls");
        menuForeignCurrency();
        anotherChoice();
        foreignCurrency();
        break;
    }
    case '5':
    {
        system("cls");
        mainBankScreen();
        break;
    }
    default:
    {
        system("cls");
        menuForeignCurrency();
        std::cout << "Zly wybor opcji, Podaj twoj wybor ponownie." << std::endl << std::endl;
        anotherChoice();
        foreignCurrency();
        break;
    }
    }
}