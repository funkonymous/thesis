#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <string>
#include <vector>

using namespace std;
namespace geDB
{
class Database{

public :
    Database(string &file);
    ~Database();
    void appendDBF(Database &DBT,size_t depth = 3,size_t maxEntries = 1000);
    vector<vector<int>> getData();
    vector<int> getTerms();
    void print();

private :
    vector<vector<int>> Data;
    vector<char> TerminalSymbols;
    vector<int> Terms;
};
}
#endif // DATABASE_H_INCLUDED
