#include "Interface.hpp"
#include "Bank.cpp"
#include "PiggyBank.cpp"
#include "User.cpp"

void Interface::displayHeader()
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

void Interface::displayWelcomeScreen()
{
  displayHeader();
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
    displayExitScreen();
    break;
  default:
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    displayWelcomeScreen();
  }
};

void Interface::displayMainScreen()
{
  displayHeader();
  std::string Bspaces,
      Nspaces, balancetxt = std::to_string(User::PLN);
  for (int i = 0; i < (24 - balancetxt.length()); i++) // Instrukcja obliczająca ilośc spacji żeby się zmieścić w butonie balance
  {
    Bspaces += " ";
  };
  for (int i = 0; i < (22 - User::name.length()); i++) // Instrukcja obliczająca ilośc spacji żeby się zmieścić w butonie name
  {
    Nspaces += " ";
  };
  std::cout << "          Nazwa konta                           Saldo\n";
  std::cout << "          ________________________             ________________________ " << std::endl
            << "         |                        |           |                        |\n"
            << "         | " << User::name << Nspaces << " |           | " << std::fixed << std::setprecision(2) << User::PLN << "PLN" << Bspaces << "|" << std::endl;
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
    changeCurrencyScreen();
    break;
  case 5:
    displayHeader();
    PiggyBank::displayMenu();
    PiggyBank::displayOptions();
    if (PiggyBank::option == '4')
    {
      displayMainScreen();
    }
    break;
  case 6:
    transferListScreen();
    break;
  case 7:
    displayExitScreen();
    break;
  default:
    std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
    std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
    displayMainScreen();
  }
}

void Interface::displayExitScreen()
{
  displayHeader();
  std::cout << "         Dziekujemy za skorzystanie z naszego banku \n\n\n\n\n";
  exit(0);
}

void Interface::loginScreen()
{
  displayHeader();
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
  if (User::doesUserExist(login, password))
  {
    displayMainScreen();
  }
  else
  {
    loginScreen();
  }
};

void Interface::registerScreen()
{
  displayHeader();
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
  if (User::RegisterUser(login, password))
  {
    std::cout << "\n\n         Uzytkownik stworzony pomyslnie\n         kliknij dowolny klawisz: ";
    getch();
    displayWelcomeScreen();
  }
  else
  {
    std::cout << "\n\n         Osoba o takim loginie juz istnieje\n         kliknij dowolny klawisz: ";
    getch();
    displayWelcomeScreen();
  }
}

void Interface::depositScreen()
{
  displayHeader();
  long double money = 0;
  int option = 1;

  switch (option)
  {
  case 1:
    std::cout << "\n         Podaj liczbe ktora chcesz wplacic: ";
    std::cin >> money;
    User::deposit(money, 1);
    successDepositOrWithdrawScreen(money, "PLN", 0);
    displayMainScreen();
    break;
  default:
    std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
    std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
    depositScreen();
  }
}

void Interface::withdrawScreen()
{
  displayHeader();
  long double money = 0;
  int option = 1;

  switch (option)
  {
  case 1:
    system("cls");
    displayHeader();
    std::cout << "         Podaj liczbe ktora chcesz wyplacic: ";
    std::cin >> money;
    if (User::withdraw(money, 1))
      successDepositOrWithdrawScreen(money, "PLN", 1);
    else
      std::cout << "         Nie masz wystarczajacy srodkow na koncie by wyplacic\n\n";
    std::cout << "         Wcisnij dowolny klawisz aby wrocic do menu glownego. ";
    getch();
    break;

  default:
    std::cin.clear();            // Obsługa błedu wejścia np 1231 abr4523
    std::cin.ignore(1000, '\n'); // Obsługa błedu wejścia np 1231 abr4523
    withdrawScreen();
  }
}

void Interface::transferScreen()
{
  displayHeader();
  std::string username;
  short currency = 1, check;
  long double money;
  std::cout << "         Podaj nazwe uzytkownika do ktorego chcesz wykonac przelew: ";
  std::cin >> username;
  if (username == User::name)
  {
    std::cout << "         Nie mozesz sam do siebie wyslac przelewu";
    getch();
    displayMainScreen();
  }
  std::cout << "         Podaj kwote: ";
  std::cin >> money;
  std::string CurrencyTab[] = {"PLN", "EUR", "USD", "CHF", "GBP"};
  check = User::Transfer(money, currency, username);
  if (check == 1)
    std::cout << "         Udalo sie wykonac przelew do " << username << " na kwote " << money << CurrencyTab[currency - 1];
  else if (check == 2)
    std::cout << "\n         Niewystarczajace srodki na koncie\n";
  else if (check == 3)
    std::cout << "\n         Uzytkownik nie istnieje\n";
  else
    std::cout << "\n         Nie znany blad\n";
  getch();
  displayMainScreen();
}

void Interface::transferListScreen()
{
  displayHeader();
  std::cout << "          Lista tranzakcji: \n";
  User::raportTransferRead();
  getch();
  displayMainScreen();
}

void Interface::successDepositOrWithdrawScreen(long double money, std::string currency, short n)
{
  displayHeader();
  if (n == 1)
    std::cout << "         Wyplaciles: " << money << currency << std::endl
              << std::endl;
  else
    std::cout << "         Wplaciles: " << money << currency << std::endl
              << std::endl;

  std::cout << "         Wcisnij dowolny klawisz aby wrocic do menu glownego. ";
  getch();
  displayMainScreen();
}

void Interface::changeCurrencyScreen() // Konto Walutowe
{
  char menuOption, firstChoice, secondChoice;

  displayHeader();
  std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | PLN: " << User::PLN << " zl |" << std::endl;
  std::cout << "|   Konto Walutowe   |" << std::endl;
  std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | EUR: " << User::EUR << " Euro | USD: " << User::USD << " $ | CHF: " << User::CHF << " Fr | GBP: " << User::GBP << " L |" << std::endl
            << std::endl;
  std::cout << "1. Zamiana walut" << std::endl;
  std::cout << "2. Pomoc" << std::endl;
  std::cout << "3. Powrot" << std::endl
            << std::endl;
  std::cout << "Twoj wybor: ";
  std::cin >> menuOption;

  switch (menuOption)
  {
  case '1': // Zamiana walut
  {
    displayHeader();
    std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | PLN: " << User::PLN << " zl |" << std::endl;
    std::cout << "|   Konto Walutowe   |" << std::endl;
    std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | EUR: " << User::EUR << " Euro | USD: " << User::USD << " $ | CHF: " << User::CHF << " Fr | GBP: " << User::GBP << " L |" << std::endl
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
    std::cin >> Bank::ammountToChange;
    std::cout << std::endl;

    // obsluga zamiany walut

    if ((firstChoice == '1' && secondChoice == '2') || (firstChoice == '1' && secondChoice == '3') || (firstChoice == '1' && secondChoice == '4') || (firstChoice == '1' && secondChoice == '5'))
    {
      Bank::changePLN(firstChoice, secondChoice);
    }

    else if ((firstChoice == '2' && secondChoice == '1') || (firstChoice == '2' && secondChoice == '3') || (firstChoice == '2' && secondChoice == '4') || (firstChoice == '2' && secondChoice == '5'))
    {
      Bank::changeEUR(firstChoice, secondChoice);
    }

    else if ((firstChoice == '3' && secondChoice == '1') || (firstChoice == '3' && secondChoice == '2') || (firstChoice == '3' && secondChoice == '4') || (firstChoice == '3' && secondChoice == '5'))
    {
      Bank::changeUSD(firstChoice, secondChoice);
    }

    else if ((firstChoice == '4' && secondChoice == '1') || (firstChoice == '4' && secondChoice == '2') || (firstChoice == '4' && secondChoice == '3') || (firstChoice == '4' && secondChoice == '5'))
    {
      Bank::changeCHF(firstChoice, secondChoice);
    }

    else if ((firstChoice == '5' && secondChoice == '1') || (firstChoice == '5' && secondChoice == '2') || (firstChoice == '5' && secondChoice == '3') || (firstChoice == '5' && secondChoice == '4'))
    {
      Bank::changeGBP(firstChoice, secondChoice);
    }

    else
    {
      std::cout << "Wybrano zla opcje." << std::endl
                << std::endl;
      getch();
    }

    changeCurrencyScreen();
    break;
  }
  case '2': // pomoc Konta Walutowego
  {
    displayHeader();
    std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | PLN: " << User::PLN << " zl |" << std::endl;
    std::cout << "|   Konto Walutowe   |" << std::endl;
    std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | EUR: " << User::EUR << " Euro | USD: " << User::USD << " $ | CHF: " << User::CHF << " Fr | GBP: " << User::GBP << " L |" << std::endl
              << std::endl;
    std::cout << "Konto Walutowe to program, ktory umozliwia zamiane roznych walut i przechowywanie ich na swoim Koncie Walutowym." << std::endl;
    std::cout << "Korzystajac z opcji nr 3 w menu Konta Bankowego, mozesz przewalutowac swoje pieniadze. Musisz tylko podac walute, z ktorej chcesz" << std::endl;
    std::cout << "przewalutowac swoje pieniadze, walute docelowa oraz ilosc pieniedzy do przewalutowania. Mozesz wyjsc z Konta Walutowego, " << std::endl;
    std::cout << "korzystajac z opcji nr 5 w Menu Konta Wallutowego." << std::endl
              << std::endl;
    std::cout << "Aby wyjsc z opcji Pomoc, nacisnij dowolny klawisz." << std::endl;
    getch();
    changeCurrencyScreen();
    break;
  }
  case '3': // Powrot
  {
    displayMainScreen();
    break;
  }
  default: // Zly wybor opcji
  {
    displayHeader();
    std::cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | PLN: " << User::PLN << " zl |" << std::endl;
    std::cout << "|   Konto Walutowe   |" << std::endl;
    std::cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | EUR: " << User::EUR << " Euro | USD: " << User::USD << " $ | CHF: " << User::CHF << " Fr | GBP: " << User::GBP << " L |" << std::endl
              << std::endl;
    std::cout << "Zly wybor opcji, Sprobuj ponownie.";
    getch();
    changeCurrencyScreen();
    break;
  }
  }
}