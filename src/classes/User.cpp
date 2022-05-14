#include "User.hpp"

bool User::doesUserExist(std::string username, std::string password)
{
    std::string passwordinfile = getLineFromFile(username, 0);

    if (password == passwordinfile)
    {
        name = username;
        PLN = stold(getLineFromFile(username, 1));
        EUR = stold(getLineFromFile(username, 2));
        USD = stold(getLineFromFile(username, 3));
        CHF = stold(getLineFromFile(username, 4));
        GBP = stold(getLineFromFile(username, 5));
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

    for (int i = 0; i < 6; i++)
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
    EUR = stold(getLineFromFile(name, 2));
    USD = stold(getLineFromFile(name, 3));
    CHF = stold(getLineFromFile(name, 4));
    GBP = stold(getLineFromFile(name, 5));

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

    for (int i = 0; i < 6; i++)
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
    EUR = stold(getLineFromFile(name, 2));
    USD = stold(getLineFromFile(name, 3));
    CHF = stold(getLineFromFile(name, 4));
    GBP = stold(getLineFromFile(name, 5));
    return 1;
}
long double User::moneyChanger(long double n, short currencyO, short currencyS)
{
    // 1 PLN        2 EUR        3 USD        4 CHF        5 GBP
    if (currencyO == 1 && currencyS == 1 && PLN >= n) // PLN to EUR
    {
        deposit(n * 0.21, 2);
        withdraw(n, 1);
        return n * 0.21;
    }

    else if (currencyO == 1 && currencyS == 2 && PLN >= n) // PLN to USD
    {
        deposit(n * 0.22, 3);
        withdraw(n, 1);
        return n * 0.22;
    }
    else if (currencyO == 1 && currencyS == 3 && PLN >= n) // PLN to CHF
    {
        deposit(n * 0.22, 4);
        withdraw(n, 1);
        return n * 0.22;
    }
    else if (currencyO == 1 && currencyS == 4 && PLN >= n) // PLN to GBP
    {
        deposit(n * 0.18, 5);
        withdraw(n, 1);
        return n * 0.18;
    }
    /////////////////////////////////////////////////////////////////////////

    else if (currencyO == 2 && currencyS == 1 && EUR >= n) // EUR to PLN
    {
        deposit(n * 4.68, 1);
        withdraw(n, 2);
        return n * 4.68;
    }

    else if (currencyO == 2 && currencyS == 2 && EUR >= n) // EUR to USD
    {
        deposit(n * 1.04, 3);
        withdraw(n, 2);
        return n * 1.04;
    }
    else if (currencyO == 2 && currencyS == 3 && EUR >= n) // EUR to CHF
    {
        deposit(n * 1.04, 4);
        withdraw(n, 2);
        return n * 1.04;
    }
    else if (currencyO == 2 && currencyS == 4 && EUR >= n) // EUR to GBP
    {
        deposit(n * 0.85, 5);
        withdraw(n, 2);
        return n * 0.85;
    }
    ///////////////////////////////////////////////////////////////////////////

    else if (currencyO == 3 && currencyS == 1 && USD >= n) // USD to PLN
    {
        deposit(n * 4.5, 1);
        withdraw(n, 3);
        return n * 4.5;
    }
    else if (currencyO == 3 && currencyS == 2 && USD >= n) // USD to EUR
    {
        deposit(n * 0.96, 2);
        withdraw(n, 3);
        return n * 0.96;
    }
    else if (currencyO == 3 && currencyS == 4 && USD >= n) // USD to CHF
    {
        deposit(n * 1.0, 5);
        withdraw(n, 3);
        return n * 1.0;
    }
    else if (currencyO == 3 && currencyS == 5 && USD >= n) // USD to GBP
    {
        deposit(n * 0.82, 5);
        withdraw(n, 3);
        return n * 0.82;
    }
    //////////////////////////////////////////////////////////////
    else if (currencyO == 4 && currencyS == 1 && CHF >= n) // CHF to PLN
    {
        deposit(n * 4.49, 1);
        withdraw(n, 4);
        return n * 4.49;
    }
    else if (currencyO == 4 && currencyS == 2 && CHF >= n) // CHF to EUR
    {
        deposit(n * 0.962, 2);
        withdraw(n, 4);
        return n * 0.96;
    }
    else if (currencyO == 4 && currencyS == 3 && CHF >= n) // CHF to USD
    {
        deposit(n * 1.0, 3);
        withdraw(n, 4);
        return n * 1.0;
    }
    else if (currencyO == 4 && currencyS == 4 && CHF >= n) // CHF to GBP
    {
        deposit(n * 0.81, 5);
        withdraw(n, 4);
        return n * 0.81;
    }
    //////////////////////////////////////////////////////////
    else if (currencyO == 5 && currencyS == 1 && GBP >= n) // GBP to PLN
    {
        deposit(n * 5.52, 1);
        withdraw(n, 5);
        return n * 5.52;
    }
    else if (currencyO == 5 && currencyS == 2 && GBP >= n) // GBP to EUR
    {
        deposit(n * 1.18, 2);
        withdraw(n, 5);
        return n * 1.18;
    }
    else if (currencyO == 5 && currencyS == 3 && GBP >= n) // GBP to USD
    {
        deposit(n * 1.23, 3);
        withdraw(n, 5);
        return n * 1.23;
    }
    else if (currencyO == 5 && currencyS == 4 && GBP >= n) // GBP to CHF
    {
        deposit(n * 1.23, 4);
        withdraw(n, 5);
        return n * 1.23;
    }

    else
        return 0;
}
