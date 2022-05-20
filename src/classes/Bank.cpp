#include "Bank.hpp"
#include "User.hpp"

void Bank::changePLN(char firstChoice, char secondChoice) // zamiana PLN-->x, liczba z przecinkiem to kurs waluty x-->PLN
{
    std::string firstCurrency, secondCurrency; // wyswietlanie nazw walut w opisach

    if (ammountToChange <= User::PLN)
    {
        if (firstChoice == '1' && secondChoice == '2')
        {
            firstCurrency = " Zl";
            secondCurrency = " Euro";
            converted = ammountToChange / 4.6372;
            User::deposit(converted, 2);        // wplata pieniedzy EUR
            User::withdraw(ammountToChange, 1); // wyplata pieniedzy PLN
        }
        if (firstChoice == '1' && secondChoice == '3')
        {
            firstCurrency = " Zl";
            secondCurrency = " $";
            converted = ammountToChange / 4.3835;
            User::deposit(converted, 3);        // wplata pieniedzy USD
            User::withdraw(ammountToChange, 1); // wyplata pieniedzy PLN
        }
        if (firstChoice == '1' && secondChoice == '4')
        {
            firstCurrency = " Zl";
            secondCurrency = " Fr";
            converted = ammountToChange / 4.5134;
            User::deposit(converted, 4);        // wplata pieniedzy CHF
            User::withdraw(ammountToChange, 1); // wyplata pieniedzy PLN
        }
        if (firstChoice == '1' && secondChoice == '5')
        {
            firstCurrency = " Zl";
            secondCurrency = " L";
            converted = ammountToChange / 5.4708;
            User::deposit(converted, 5);        // wplata pieniedzy GBP
            User::withdraw(ammountToChange, 1); // wyplata pieniedzy PLN
        }
        std::cout << "Zamieniles " << ammountToChange << firstCurrency << " na " << converted << secondCurrency << ".";
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe.";
    }
    getch();
}

void Bank::changeEUR(char firstChoice, char secondChoice) // zamiana EUR-->x, liczba z przecinkiem to kurs waluty x-->EUR
{
    std::string firstCurrency, secondCurrency; // wyswietlanie nazw walut w opisach

    if (ammountToChange <= User::EUR)
    {
        if (firstChoice == '2' && secondChoice == '1')
        {
            firstCurrency = " Euro";
            secondCurrency = " Zl";
            converted = ammountToChange / 0.2156;
            User::deposit(converted, 1);        // wplata pieniedzy PLN
            User::withdraw(ammountToChange, 2); // wyplata pieniedzy EUR
        }
        if (firstChoice == '2' && secondChoice == '3')
        {
            firstCurrency = " Euro";
            secondCurrency = " $";
            converted = ammountToChange / 0.9452;
            User::deposit(converted, 3);        // wplata pieniedzy USD
            User::withdraw(ammountToChange, 2); // wyplata pieniedzy EUR
        }
        if (firstChoice == '2' && secondChoice == '4')
        {
            firstCurrency = " Euro";
            secondCurrency = " Fr";
            converted = ammountToChange / 0.9726;
            User::deposit(converted, 4);        // wplata pieniedzy CHF
            User::withdraw(ammountToChange, 2); // wyplata pieniedzy EUR
        }
        if (firstChoice == '2' && secondChoice == '5')
        {
            firstCurrency = " Euro";
            secondCurrency = " L";
            converted = ammountToChange / 1.1791;
            User::deposit(converted, 5);        // wplata pieniedzy GBP
            User::withdraw(ammountToChange, 2); // wyplata pieniedzy EUR
        }
        std::cout << "Zamieniles " << ammountToChange << firstCurrency << " na " << converted << secondCurrency << ".";
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe.";
    }
    getch();
}

void Bank::changeUSD(char firstChoice, char secondChoice) // zamiana USD-->x, liczba z przecinkiem to kurs waluty x-->USD
{
    std::string firstCurrency, secondCurrency; // wyswietlanie nazw walut w opisach

    if (ammountToChange <= User::USD)
    {
        if (firstChoice == '3' && secondChoice == '1')
        {
            firstCurrency = " $";
            secondCurrency = " Zl";
            converted = ammountToChange / 0.2281;
            User::deposit(converted, 1);        // wplata pieniedzy PLN
            User::withdraw(ammountToChange, 3); // wyplata pieniedzy USD
        }
        if (firstChoice == '3' && secondChoice == '2')
        {
            firstCurrency = " $";
            secondCurrency = " Euro";
            converted = ammountToChange / 1.0579;
            User::deposit(converted, 2);        // wplata pieniedzy EUR
            User::withdraw(ammountToChange, 3); // wyplata pieniedzy USD
        }
        if (firstChoice == '3' && secondChoice == '4')
        {
            firstCurrency = " $";
            secondCurrency = " Fr";
            converted = ammountToChange / 1.0295;
            User::deposit(converted, 4);        // wplata pieniedzy CHF
            User::withdraw(ammountToChange, 3); // wyplata pieniedzy USD
        }
        if (firstChoice == '3' && secondChoice == '5')
        {
            firstCurrency = " $";
            secondCurrency = " L";
            converted = ammountToChange / 1.2473;
            User::deposit(converted, 5);        // wplata pieniedzy GBP
            User::withdraw(ammountToChange, 3); // wyplata pieniedzy USD
        }
        std::cout << "Zamieniles " << ammountToChange << firstCurrency << " na " << converted << secondCurrency << "." << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe.";
    }
    getch();
}

void Bank::changeCHF(char firstChoice, char secondChoice) // zamiana CHF-->x, liczba z przecinkiem to kurs waluty x-->CHF
{
    std::string firstCurrency, secondCurrency; // wyswietlanie nazw walut w opisach

    if (ammountToChange <= User::CHF)
    {
        if (firstChoice == '4' && secondChoice == '1')
        {
            firstCurrency = " Fr";
            secondCurrency = " Zl";
            converted = ammountToChange / 0.2215;
            User::deposit(converted, 1);        // wplata pieniedzy PLN
            User::withdraw(ammountToChange, 4); // wyplata pieniedzy CHF
        }
        if (firstChoice == '4' && secondChoice == '2')
        {
            firstCurrency = " Fr";
            secondCurrency = " Euro";
            converted = ammountToChange / 1.0281;
            User::deposit(converted, 2);        // wplata pieniedzy EUR
            User::withdraw(ammountToChange, 4); // wyplata pieniedzy CHF
        }
        if (firstChoice == '4' && secondChoice == '3')
        {
            firstCurrency = " Fr";
            secondCurrency = " $";
            converted = ammountToChange / 0.9713;
            User::deposit(converted, 3);        // wplata pieniedzy USD
            User::withdraw(ammountToChange, 4); // wyplata pieniedzy CHF
        }
        if (firstChoice == '4' && secondChoice == '5')
        {
            firstCurrency = " Fr";
            secondCurrency = " L";
            converted = ammountToChange / 1.2118;
            User::deposit(converted, 5);        // wplata pieniedzy GBP
            User::withdraw(ammountToChange, 4); // wyplata pieniedzy CHF
        }
        std::cout << "Zamieniles " << ammountToChange << firstCurrency << " na " << converted << secondCurrency << ".";
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe.";
    }
    getch();
}

void Bank::changeGBP(char firstChoice, char secondChoice) // zamiana GBP-->x, liczba z przecinkiem to kurs waluty x-->GBP
{
    std::string firstCurrency, secondCurrency; // wyswietlanie nazw walut w opisach

    if (ammountToChange <= User::GBP)
    {
        if (firstChoice == '5' && secondChoice == '1')
        {
            firstCurrency = " L";
            secondCurrency = " Zl";
            converted = ammountToChange / 0.1827;
            User::deposit(converted, 1);        // wplata pieniedzy PLN
            User::withdraw(ammountToChange, 5); // wyplata pieniedzy GBP
        }
        if (firstChoice == '5' && secondChoice == '2')
        {
            firstCurrency = " L";
            secondCurrency = " Euro";
            converted = ammountToChange / 0.8481;
            User::deposit(converted, 2);        // wplata pieniedzy EUR 
            User::withdraw(ammountToChange, 5); // wyplata pieniedzy GBP
        }
        if (firstChoice == '5' && secondChoice == '3')
        {
            firstCurrency = " L";
            secondCurrency = " $";
            converted = ammountToChange / 0.8017;
            User::deposit(converted, 3);        // wplata pieniedzy USD
            User::withdraw(ammountToChange, 5); // wyplata pieniedzy GBP
        }
        if (firstChoice == '5' && secondChoice == '4')
        {
            firstCurrency = " L";
            secondCurrency = " Fr";
            converted = ammountToChange / 0.8252;
            User::deposit(converted, 4);        // wplata pieniedzy CHF
            User::withdraw(ammountToChange, 5); // wyplata pieniedzy GBP
        }
        std::cout << "Zamieniles " << ammountToChange << firstCurrency << " na " << converted << secondCurrency << "." << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << std::endl
                  << std::endl;
    }
    getch();
}
