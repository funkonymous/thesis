#ifndef GENOME_H_INCLUDED
#define GENOME_H_INCLUDED

#define PARSE 1
#define NOTPARSE 0

#include "Rule.h"
#include <vector>

extern int exceptionNumber;

using namespace std;

class Genome{

public :
    Genome();
    Genome(vector<Rule> &rv);
    ~Genome();
    const Genome &operator+=(Rule &r);
    void print();
    void parse(vector<int> &w,int ParseType);
    int getEval();
    bool valid();

private :
    vector<Rule> rules;
    int numberOfRules;
    int numberOfSymbols;
    int evaluation;
};

#endif // GENOME_H_INCLUDED
