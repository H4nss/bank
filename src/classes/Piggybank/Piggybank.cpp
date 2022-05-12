#include "Piggybank.h"

    void Piggybank::choice()
    {
        cout << "Twoj wybor: ";
        cin >> sign;
    }

    void  Piggybank::menuPiggyBank()
    {
        cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << balance << " zl |" << endl;
        cout << "|   Skarbonka   |" << endl;
        cout << "-----------------  Twoje pieniadze w Skarbonce: | " << sumPiggyBank << " zl | " << endl;
        cout << endl << "1. Wplata pieniedzy do Skarbonki" << endl;
        cout << "2. Wyplata pieniedzy ze Skarbonki" << endl;
        cout << "3. Pomoc" << endl;
        cout << "4. Powrot" << endl << endl;
    }

    void Piggybank::piggyBank()
    {
        switch (sign)
        {
        case '1':
        {
            system("cls");
            cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << balance << " zl |" << endl;
            cout << "|   Skarbonka   |" << endl;
            cout << "-----------------  Twoje pieniadze w Skarbonce: | " << sumPiggyBank << " zl | " << endl;
            cout << endl << "Twoje pieniadze, ktore wyplacisz ze swojego Konta Bankowego, beda istnialy w twojej Skarbonce. " << endl;
            cout << "Podaj ilosc pieniedzy w celu dodania ich do Skarbonki: ";
            cin >> x;
            system("cls");
            if (x <= balance)
            {
                balance = balance - x;
                t = x;
                sumPiggyBank = sumPiggyBank + t;
                menuPiggyBank();
                cout << "Wplaciles " << x << " zl do twojej Skarbonki." << endl << endl;
                choice();
            }
            else
            {
                system("cls");
                menuPiggyBank();
                cout << "Za malo pieniedzy na twoim Koncie Bankowym, aby wyplacic dana liczbe." << endl << endl;
                choice();
            }
            piggyBank();
            break;
        }
        case '2':
        {
            system("cls");
            cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << balance << " zl |" << endl;
            cout << "|   Skarbonka   |" << endl;
            cout << "-----------------  Twoje pieniadze w Skarbonce: | " << sumPiggyBank << " zl | " << endl;
            cout << endl << "Twoje pieniadze, ktore przewalutujesz ze swojej Skarbonki, beda istnialy na twoim Koncie Bankowym. " << endl;
            cout << "Podaj ilosc pieniedzy w celu dodania ich do twojego Konta Bankowego: ";
            cin >> x;
            system("cls");
            if (x <= sumPiggyBank)
            {
                t = x;
                balance = balance + t;
                sumPiggyBank = sumPiggyBank - x;
                menuPiggyBank();
                cout << "Wyplaciles " << x << " zl ze swojej Skarbonki." << endl << endl;
                choice();
            }
            else
            {
                system("cls");
                menuPiggyBank();
                cout << "Za malo pieniedzy w twojej Skarbonce, aby wyplacic dana liczbe pieniedzy." << endl << endl;
                choice();
            }
            piggyBank();
            break;
        }
        case '3':
        {
            system("cls");
            cout << "-----------------  Twoje pieniadze na Koncie Bankowym: | " << balance << " zl |" << endl;
            cout << "|   Skarbonka   |" << endl;
            cout << "-----------------  Twoje pieniadze w Skarbonce: | " << sumPiggyBank << " zl | " << endl;
            cout<<endl<<"Piggybank to program, ktory umozliwia odlozenie swoich pieniedzy w bezpieczne miejsce. Aby wplacic pieniadze do Skarbonki,"<<endl;
            cout<<"musisz przelac je ze swojego Konta Bankowego, wybierajac opcje nr 1 w menu Skarbonki. Pieniadze, ktore znajduja sie w Skarbonce, "<<endl;
            cout<<"mozesz wyplacic w kazdym momencie, wybierajac opcje nr 2 w menu Skarbonki. Mozesz wyjsc ze Skarbonki, korzystajac z opcji nr 3 w Menu Skarbonki."<<endl;
            cout<<endl<<"Aby wyjsc z opcji Pomoc, nacisnij dowolny klawisz.";
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
            break;
        }
        default:
        {
            system("cls");
            menuPiggyBank();
            cout << "Zly wybor opcji, Podaj twoj wybor ponownie." << endl << endl;
            choice();
            piggyBank();
            break;
        }
        }

    }