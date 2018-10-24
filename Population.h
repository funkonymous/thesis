#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED
#include "Database.h"
#include "Genome.h"

class Population{

public :
    Population(geDB::Database &dbT,geDB::Database &dbF,size_t populous,size_t maxGrammarLen=50,size_t maxRuleLen=10,size_t nonTerms = 10);
    ~Population();
    void sortPop();

private :
    vector<Genome> pool;
    geDB::Database data;
    geDB::Database data_not;
    vector<int> Terms;
    vector<int> NonTerms;
};

#endif // POPULATION_H_INCLUDED
