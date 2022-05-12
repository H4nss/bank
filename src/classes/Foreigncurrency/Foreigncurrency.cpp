#include "Foreigncurrency.h"

void Foreigncurrency::choice()
    {
        cout << "Twoj wybor: ";
        cin >> firstSign;
    }
void Foreigncurrency::changePLN() //zamiana PLN-->a
{
    if (a <= sumPLN)
    {
        if (firstChoice == '1' && secondChoice == '2')
        {
            firstCurrency = " Zl";
            secondCurrency = " Euro";
            sumPLN = sumPLN - a;
            b = a / 4.72;
            sumEUR = sumEUR + b;
        }
        if (firstChoice == '1' && secondChoice == '3')
        {
            firstCurrency = " Zl";
            secondCurrency = " $";
            sumPLN = sumPLN - b;
            b = a / 4.27;
            sumUSD = sumUSD + b;
        }
        if (firstChoice == '1' && secondChoice == '4')
        {
            firstCurrency = " Zl";
            secondCurrency = " Fr";
            sumPLN = sumPLN - a;
            b = a / 4.57;
            sumCHF = sumCHF + b;
        }
        menuForeignCurrency();
        cout << "Zamieniles " << a << firstCurrency << " na " << b << secondCurrency << "." << endl;
        cout << "Jednoczesnie wplaciles " << b << secondCurrency << " do twojego Konta Walutowego." << endl << endl;
        choice();
    }
    else
    {
        system("cls");
        menuForeignCurrency();
        cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << endl << endl;
        choice();
    }
}

void Foreigncurrency::changeEUR() //zamiana EUR-->a
{
    if (a <= sumEUR)
    {
        if (firstChoice == '2' && secondChoice == '1')
        {
            firstCurrency = " Euro";
            secondCurrency = " Zl";
            sumEUR = sumEUR - a;
            b = a / 0.21;
            sumPLN = sumPLN + b;
        }
        if (firstChoice == '2' && secondChoice == '3')
        {
            firstCurrency = " Euro";
            secondCurrency = " $";
            sumEUR = sumEUR - a;
            b = a / 0.90;
            sumUSD = sumUSD + b;
        }
        if (firstChoice == '2' && secondChoice == '4')
        {
            firstCurrency = " Euro";
            secondCurrency = " Fr";
            sumEUR = sumEUR - a;
            b = a / 0.97;
            sumCHF = sumCHF + b;
        }
        menuForeignCurrency();
        cout << "Zamieniles " << a << firstCurrency << " na " << b << secondCurrency << "." << endl;
        cout << "Jednoczesnie wplaciles " << b << secondCurrency << " do twojego Konta Walutowego." << endl << endl;
        choice();
    }
    else
    {
        system("cls");
        menuForeignCurrency();
        cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << endl << endl;
        choice();
    }
}

void Foreigncurrency::changeUSD() //zamiana USD-->a
{
    if (a <= sumUSD)
    {
        if (firstChoice == '3' && secondChoice == '1')
        {
            firstCurrency = " $";
            secondCurrency = " Zl";
            sumUSD = sumUSD - a;
            b = a / 0.23;
            sumPLN = sumPLN + b;
        }
        if (firstChoice == '3' && secondChoice == '2')
        {
            firstCurrency = " $";
            secondCurrency = " Euro";
            sumUSD = sumUSD - a;
            b = a / 1.11;
            sumEUR = sumEUR + b;
        }
        if (firstChoice == '3' && secondChoice == '4')
        {
            firstCurrency = " $";
            secondCurrency = " Fr";
            sumUSD = sumUSD - a;
            b = a / 1.07;
            sumCHF = sumCHF + b;
        }
        menuForeignCurrency();
        cout << "Zamieniles " << a << firstCurrency << " na " << b << secondCurrency << "." << endl;
        cout << "Jednoczesnie wplaciles " << b << secondCurrency << " do twojego Konta Walutowego." << endl << endl;
        choice();
    }
    else
    {
        system("cls");
        menuForeignCurrency();
        cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << endl << endl;
        choice();
    }
}

void Foreigncurrency::changeCHF() //zamiana CHF-->a
{
    if (a <= sumCHF)
    {
        if (firstChoice == '4' && secondChoice == '1')
        {
            firstCurrency = " Fr";
            secondCurrency = " Zl";
            sumCHF = sumCHF - a;
            b = a / 0.22;
            sumPLN = sumPLN + b;
        }
        if (firstChoice == '4' && secondChoice == '2')
        {
            firstCurrency = " Fr";
            secondCurrency = " Euro";
            sumCHF = sumCHF - a;
            b = a / 1.03;
            sumEUR = sumEUR + b;
        }
        if (firstChoice == '4' && secondChoice == '3')
        {
            firstCurrency = " Fr";
            secondCurrency = " $";
            sumCHF = sumCHF - a;
            b = a / 0.93;
            sumUSD = sumUSD + b;
        }
        menuForeignCurrency();
        cout << "Zamieniles " << a << firstCurrency << " na " << b << secondCurrency << "." << endl;
        cout << "Jednoczesnie wplaciles " << b << secondCurrency << " do twojego Konta Walutowego." << endl << endl;
        choice();
    }
    else
    {
        system("cls");
        menuForeignCurrency();
        cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << endl << endl;
        choice();
    }
}

void Foreigncurrency::menuForeignCurrency()
{
    cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << balance << " zl |" << endl;
    cout << "|   Konto Walutowe   |" << endl;
    cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << sumPLN << " Zl | EUR: " << sumEUR << " Euro | USD: " << sumUSD << " $ | CHF: " << sumCHF << " Fr |" << endl;
    cout << endl << "1. Wplata pieniedzy do Konta Walutowego" << endl;
    cout << "2. Wyplata pieniedzy z Konta Walutowego" << endl;
    cout << "3. Zamiana walut" << endl;
    cout << "4. Pomoc" << endl;
    cout << "5. Powrot" << endl << endl;
}

void Foreigncurrency::foreignCurrency()
{
    switch (firstSign)
    {
    case '1':
    {
        system("cls");
        cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << balance << " zl |" << endl;
        cout << "|   Konto Walutowe   |" << endl;
        cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << sumPLN << " Zl | EUR: " << sumEUR << " Euro | USD: " << sumUSD << " $ | CHF: " << sumCHF << " Fr |" << endl;
        cout << endl << "Twoje pieniadze, ktore wyplacisz ze swojego Konta Bankowego, beda istnialy na twoim Koncie Walutowym. " << endl;
        cout << "Podaj ilosc pieniedzy w zl: ";
        cin >> a;
        system("cls");
        if (a <= balance)
        {
            balance = balance - a;
            b = a;
            sumPLN = sumPLN + b;
            menuForeignCurrency();
            cout << "Wplaciles " << a << " zl do twojego Konta Walutowego." << endl << endl;
            choice();
        }
        else
        {
            system("cls");
            menuForeignCurrency();
            cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << endl << endl;
            choice();
        }
        foreignCurrency();
        break;
    }
    case '2':
    {
        system("cls");
        cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << balance << " zl |" << endl;
        cout << "|   Konto Walutowe   |" << endl;
        cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << sumPLN << " Zl | EUR: " << sumEUR << " Euro | USD: " << sumUSD << " $ | CHF: " << sumCHF << " Fr |" << endl;
        cout << endl << "Twoje pieniadze, ktore wyplacisz ze swojego Konta Walutowego, beda istnialy na twoim Koncie Bankowym. " << endl;
        cout << "Podaj ilosc pieniedzy w zl: ";
        cin >> a;
        system("cls");
        if (a <= sumPLN)
        {
            b = a;
            balance = balance + b;
            sumPLN = sumPLN - a;
            menuForeignCurrency();
            cout << "Wyplaciles " << b << " zl ze swojego Konta Walutowego." << endl << endl;
            choice();
        }
        else
        {
            system("cls");
            menuForeignCurrency();
            cout << "Za malo pieniedzy na twoim Koncie Walutowym, aby wyplacic dana liczbe pieniedzy." << endl << endl;
            choice();
        }
        foreignCurrency();
        break;
    }

    case '3':
    {
        system("cls");
        cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << balance << " zl |" << endl;
        cout << "|   Konto Walutowe   |" << endl;
        cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << sumPLN << " Zl | EUR: " << sumEUR << " Euro | USD: " << sumUSD << " $ | CHF: " << sumCHF << " Fr |" << endl;
        cout << endl << "1. PLN" << endl;
        cout << "2. EUR" << endl;
        cout << "3. USD" << endl;
        cout << "4. CHF" << endl << endl;
        cout << "Podaj z jakiej waluty chcesz przelac pieniadze (1-4): ";
        cin >> firstChoice;
        cout << "Podaj na jaka walute chcesz przelac pieniadze (1-4): ";
        cin >> secondChoice;
        cout << endl << "Podaj ilosc pieniedzy: ";
        cin >> a;

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
            cout << "Zly choice opcji, Podaj twoj choice ponownie." << endl << endl;
            choice();
            foreignCurrency();
        }

        foreignCurrency();
        break;
    }
    case '4':
    {
        system("cls");
        cout << "----------------------  Twoje pieniadze na Koncie Bankowym: | " << balance << " zl |" << endl;
        cout << "|   Konto Walutowe   |" << endl;
        cout << "----------------------  Twoje pieniadze na Koncie Walutowym: | PLN: " << sumPLN << " Zl | EUR: " << sumEUR << " Euro | USD: " << sumUSD << " $ | CHF: " << sumCHF << " Fr |" << endl;
        cout << endl << "Konto Walutowe to program, ktory umozliwia zamiane roznych walut i przechowywanie ich na swoim Koncie Walutowym." << endl;
        cout << "Aby wplacic pieniadze do Konta Walutowego, musisz przelac je ze swojego Konta Bankowego, wybierajac opcje nr 1 w menu Konta Walutowego." << endl;
        cout << "Pieniadze, ktore znajduja sie na Koncie Walutowym mozesz wyplacic w kazdym momencie, wybierajac opcje nr 2 w menu Konta Walutowego." << endl;
        cout << "Aby przelew pomiedzy Kontem Bankowym, a Kontem Walutowym doszedl do skutku, musisz korzystac z waluty PLN. Korzystajac z" << endl;
        cout << "opcji nr 3 w menu Konta Bankowego, mozesz przewalutowac swoje pieniadze. Musisz tylko podac walute, z ktorej chcesz przewalutowac swoje pieniadze, " << endl;
        cout << "walute docelowa oraz ilosc pieniedzy do przewalutowania. Mozesz wyjsc z Konta Walutowego, korzystajac z opcji nr 5 w Menu Konta Wallutowego." << endl;
        cout << endl << "Aby wyjsc z opcji Pomoc, nacisnij dowolny klawisz.";
        getch();
        system("cls");
        menuForeignCurrency();
        choice();
        foreignCurrency();
        break;
    }
    case '5':
    {
        system("cls");
        break;
    }
    default:
    {
        system("cls");
        menuForeignCurrency();
        cout << "Zly choice opcji, Podaj twoj choice ponownie." << endl << endl;
        choice();
        foreignCurrency();
        break;
    }
    }
}