#include <string>
#include <iostream>
#include <fstream>
#include <iomanip> //for std::setprecision

#ifndef balanceuser_hpp
#define balanceuser_hpp

class balanceuser
{
public:
    long double Balance(const std::string username, bool auth);
};

long double balanceuser::Balance(const std::string username, bool auth)
{
    if (auth)
    {
        std::string fileName = username + ".dat";
        std::string path = "data\\" + fileName;
        std::fstream plik(path, std::ios::in); // zakładamy, że plik istnieje
        std::string balancestring;
        for (int i = 0; i < 1; i++)            // Przejscie do 2 lini pliku dat
            std::getline(plik, balancestring); // Przejscie do 2 lini pliku dat
        std::getline(plik, balancestring);     // Przejscie do 2 lini pliku dat
        plik.close();

        long double b = std::stold(balancestring);
        return b;
    }
    else
        return 0;
}

#endif