#ifndef Interface_hpp
#define Interface_hpp

#include <iostream> // obsługa wejścia wyjścia
#include <string>   // dodaje zmienną string
#include <stdlib.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <iomanip>

#include "Authorization.hpp"
#include "Balanceuser.hpp"

class Interface
{
public:
    void header();                               // Wyswietla Logo
    void welcomeScreen();                        // Ekran startowy z logowanie, rejestracją i wyjściem z programu
    void loginScreen();                          // Ekran Logowania
    void exitScreen();                           // Komunikat o zakończeniu programu
    void mainBankScreen(const std::string name); // Ekran dostępny po zalogowaniu pokazuję stan konta, nazwe oraz menu z transferem środków itp
    void depositScreen();                        // Nie dziala trzeba zrobić zapis do pliku dat

private:
    std::string login, password; // Zmienne przechowujące login i hasło login jako nazwa pliku np kamil.dat ale bez końcówki oraz hasło zapisane w 1 linijce pliku
    bool isAuthorized;           // Zmienna przechowująca czy użytkownik jest poprawnie zalogowany
    long double balance;         // Zmienna przechowująca salto konta
};

#endif