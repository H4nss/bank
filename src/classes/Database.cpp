#include "Database.hpp"

std::string Database::getLineFromFile(const std::string username, short n)
{
    using namespace std;
    string fileName = username + ".dat";
    string path = "data\\" + fileName;
    fstream plik(path, ios::in); // zakładamy, że plik istnieje
    string lineInFile;
    for (int i = 0; i < n; i++)         // Przejscie do n lini pliku dat
        std::getline(plik, lineInFile); // Przejscie do n lini pliku dat
    std::getline(plik, lineInFile);     // Przejscie do n lini pliku dat
    plik.close();
    return lineInFile;
}