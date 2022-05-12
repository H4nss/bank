#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>

#ifndef PIGGYBANK_h
#define PIGGYBANK_h

using namespace std;

class Piggybank
{
public:
    long double balance=0;
    float sumPiggyBank = 0; //suma zl w skarbonce
    char sign;
    double x = 0,t=0;

    void menuPiggyBank(); //Menu Skarbonki
    void piggyBank(); //Skarbonka
    void choice ();
};
#endif