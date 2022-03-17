#ifndef Database_hpp
#define Database_hpp

#include <fstream>
#include <string>

class Database
{
public:
    std::string getLineFromFile(const std::string username, short n);
};

#endif