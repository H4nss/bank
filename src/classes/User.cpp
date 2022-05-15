#include "User.hpp"

bool User::doesUserExist(std::string username, std::string password)
{
    std::string passwordinfile = getLineFromFile(username, 0);

    if (password == passwordinfile)
    {
        name = username;
        PLN = stold(getLineFromFile(username, 1));
        PLNkontowalutowe = stold(getLineFromFile(name, 2));
        EUR = stold(getLineFromFile(username, 3));
        USD = stold(getLineFromFile(username, 4));
        CHF = stold(getLineFromFile(username, 5));
        SKARBONKA = stold(getLineFromFile(username, 6));

        return 1;
    }
    return 0;
}
std::string User::getLineFromFile(const std::string username, short n)
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
bool User::deposit(long double n, short currency)
{
    using namespace std;
    string fileName = name + ".dat";
    string path = "data\\" + fileName;
    string buffer;

    ifstream currentFile(path);
    string bufferName = "data\\buffer.dat";
    ofstream bufferFile(bufferName);

    for (int i = 0; i < 7; i++)
    {
        if (i == currency)
        {
            long double money;
            getline(currentFile, buffer);
            money = stold(buffer);
            bufferFile << n + money;
            bufferFile << '\n';
        }
        else
        {
            getline(currentFile, buffer);
            bufferFile << buffer + '\n';
        }
    }
    currentFile.close();
    bufferFile.close();
    remove(path.c_str());
    rename("data\\buffer.dat", path.c_str());
    PLN = stold(getLineFromFile(name, 1));
    PLNkontowalutowe = stold(getLineFromFile(name, 2));
    EUR = stold(getLineFromFile(name, 3));
    USD = stold(getLineFromFile(name, 4));
    CHF = stold(getLineFromFile(name, 5));
    SKARBONKA = stold(getLineFromFile(name, 6));
    
    return 0;
}
bool User::RegisterUser(std::string username, std::string password)
{
    std::string fileName = username + ".dat";
    std::string pathName = "data\\" + fileName;

    if (!std::ifstream(pathName)) // If file does not exist, create
    {
        std::ofstream file(pathName, std::ios::out);
        file << password << std::endl;
        file << 0 << std::endl;
        file << 0 << std::endl;
        file << 0 << std::endl;
        file << 0 << std::endl;
        file << 0 << std::endl;
        file << 0 << std::endl;

        file.close();
        return true; // SUCCESS.
    }
    else
    {
        return false; // username already exists. Thus do not create.
    }
}
bool User::withdraw(long double n, short currency)
{
    using namespace std;

    string fileName = name + ".dat";
    string path = "data\\" + fileName;
    string buffer;

    ifstream currentFile(path);
    string bufferName = "data\\buffer.dat";
    ofstream bufferFile(bufferName);

    for (int i = 0; i < 7; i++)
    {
        if (i == currency)
        {
            long double money;
            getline(currentFile, buffer);
            money = stold(buffer);
            if (money < n)
                return 0;
            else
            {
                bufferFile << money - n;
                bufferFile << '\n';
            }
        }
        else
        {
            getline(currentFile, buffer);
            bufferFile << buffer + '\n';
        }
    }
    currentFile.close();
    bufferFile.close();
    remove(path.c_str());
    rename("data\\buffer.dat", path.c_str());
    PLN = stold(getLineFromFile(name, 1));
    PLNkontowalutowe = stold(getLineFromFile(name, 2));
    EUR = stold(getLineFromFile(name, 3));
    USD = stold(getLineFromFile(name, 4));
    CHF = stold(getLineFromFile(name, 5));
    SKARBONKA = stold(getLineFromFile(name, 6));

    return 1;
}

