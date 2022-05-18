#include "PiggyBank.hpp"
#include "User.hpp"

void PiggyBank::displayInfo()
{
  system("cls");
  std::cout << "          _____________________________________________________________" << std::endl;
  std::cout << "         |            ___  _  __       ___              _              |" << std::endl;
  std::cout << "         |            | _ \\| |/ /      | _ ) __ _  _ _  | |__          |" << std::endl;
  std::cout << "         |            |  _/|   <       | _ \\/ _` || ' \\ | / /          |" << std::endl;
  std::cout << "         |            |_|  |_|\\_\\      |___/\\__/_||_||_||_\\_\\          |" << std::endl;
  std::cout << "         |_____________________________________________________________|" << std::endl
            << std::endl;
  std::cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << User::getMainBallance() << " zl |" << std::endl;
  std::cout << "|   Skarbonka   |" << std::endl;
  std::cout << "-----------------  Twoje pieniadze w Skarbonce: | " << getMainBallance() << " zl | " << std::endl;
  std::cout << std::endl;
}

long double PiggyBank::getMainBallance()
{
  return User::piggyAccount;
}

void PiggyBank::displayMenu()
{
  displayInfo();
  std::cout << "1. Wplata pieniedzy do Skarbonki" << std::endl;
  std::cout << "2. Wyplata pieniedzy ze Skarbonki" << std::endl;
  std::cout << "3. Pomoc" << std::endl;
  std::cout << "4. Powrot" << std::endl
            << std::endl;
  std::cout << "Twoj wybor: ";
  std::cin >> option;
}

void PiggyBank::displayOptions() // Skarbonka
{
  double depositAmmount = 0;
  double withdrawAmmount = 0;

  switch (option)
  {
  case '1': // wplata do Skarbonki
  {
    displayInfo();
    std::cout << "Twoje pieniadze, ktore wyplacisz ze swojego Konta Bankowego, beda istnialy w twojej Skarbonce. " << std::endl;
    std::cout << "Podaj ilosc pieniedzy w celu dodania ich do Skarbonki: ";
    std::cin >> depositAmmount;
    std::cout << std::endl;

    if (depositAmmount <= User::PLN)
    {
      User::deposit(depositAmmount, 6);  // wplata pieniedzy do Skarbonki
      User::withdraw(depositAmmount, 1); // wyplata pieniedzy PLN

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
    displayMenu();
    displayOptions();
    break;
  }
  case '2': // wyplata ze Skarbonki
  {
    displayInfo();
    std::cout << "Twoje pieniadze, ktore wyplacisz ze swojej Skarbonki, beda istnialy na twoim Koncie Bankowym. " << std::endl;
    std::cout << "Podaj ilosc pieniedzy w celu dodania ich do twojego Konta Bankowego: ";
    std::cin >> withdrawAmmount;
    std::cout << std::endl;

    if (withdrawAmmount <= User::piggyAccount)
    {
      User::deposit(withdrawAmmount, 1);  // wplata pieniedzy PLN
      User::withdraw(withdrawAmmount, 6); // wyplata pieniedzy ze Skarbonki
      std::cout << "Wyplaciles " << withdrawAmmount << " zl ze swojej Skarbonki.";
      getch();
    }
    else
    {
      std::cout << "Za malo pieniedzy w twojej Skarbonce, aby wyplacic dana liczbe pieniedzy." << std::endl;
      std::cout << "Kliknij dowolny przycisk aby cofnac do menu.";
      getch();
    }
    displayMenu();
    displayOptions();
    break;
  }
  case '3': // pomoc do programu Skarbonka
  {
    displayMenu();
    std::cout << "Skarbonka to program, ktory umozliwia odlozenie swoich pieniedzy w bezpieczne miejsce. Aby wplacic pieniadze do Skarbonki," << std::endl;
    std::cout << "musisz przelac je ze swojego Konta Bankowego, wybierajac opcje nr 1 w menu Skarbonki. Pieniadze, ktore znajduja sie w Skarbonce, " << std::endl;
    std::cout << "mozesz wyplacic w kazdym momencie, wybierajac opcje nr 2 w menu Skarbonki. Mozesz wyjsc ze Skarbonki, korzystajac z opcji nr 3 w Menu Skarbonki." << std::endl;
    std::cout << std::endl
              << "Aby wyjsc z opcji Pomoc, nacisnij dowolny klawisz.";
    getch();
    displayMenu();
    displayOptions();
    break;
  }
  case '4': // Powrot
  {
    break;
  }
  default: // jesli ktos wpisze zla opcje
  {
    displayMenu();
    std::cout << "Zly wybor opcji, Sprobuj ponownie." << std::endl
              << std::endl;
    getch();
    displayMenu();
    displayOptions();
    break;
  }
  }
}