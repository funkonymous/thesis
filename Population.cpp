#include "Population.h"
#include "Genome.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace geDB;
using namespace std;

Population::Population(geDB::Database &dbT,geDB::Database &dbF,size_t populous,size_t maxGrammarLen,size_t maxRuleLen,size_t nonTerms)
    : data(dbT) , data_not(dbF)
{
    clock_t begin1 = clock();
    cout << "Constructor for Population for " << populous << " grammars" << endl;

    vector<int> t1 = data.getTerms();
    vector<int> t2 = data_not.getTerms();

    Terms.reserve(t1.size()+t2.size());
    Terms.insert(Terms.end(),t1.begin(),t1.end());
    Terms.insert(Terms.end(),t2.begin(),t2.end());

    sort(Terms.begin(),Terms.end());
    vector<int>::iterator i1;
    i1 = unique(Terms.begin(),Terms.end());

    Terms.resize( distance(Terms.begin(),i1) );

    NonTerms.reserve(nonTerms+1);
    NonTerms.push_back(0);
    for(size_t i = 1; i <= nonTerms; ++i){
        NonTerms.push_back( Terms.back() + i );
    }
    vector<Genome> *G = new vector<Genome>;
    for(size_t j=0;j<populous;++j){
        vector<Rule> *r1 = new vector<Rule>;

        for(size_t i = 0;i<maxGrammarLen;++i){
            Rule r2(NonTerms,Terms,maxRuleLen);
            r1->push_back(r2);
            if(!(rand()%maxGrammarLen)) break;
        }
        if( (*r1)[0][0]==0 ){
            Genome *G1 = new Genome(*r1);
            G->push_back(*G1);
            delete G1;
        }
        else --j;
        delete r1;
    }
    pool = *G;
    delete G;
    clock_t end1 = clock();
    cout << "Time elapsed : " << double(end1 - begin1) / CLOCKS_PER_SEC << endl;
}

Population::~Population(){
    cout << "Deconstructor for Population" << endl;
}

bool criterion(Genome &a, Genome &b){
    return a.getEval() > b.getEval();
}

void Population::sortPop(){
    clock_t begin1 = clock();
    cout << "Parsing and sorting population based on Data : \nParsing..." << endl;
    vector<vector<int>> dat = data.getData();
    vector<vector<int>> dat2 = data_not.getData();
    for(size_t j = 0;j < pool.size();++j){
        for(size_t i = 0; i<dat.size();++i){
            (pool[j]).parse(dat[i],PARSE);
        };
        for(size_t i = 0; i<dat2.size();++i){
            (pool[j]).parse(dat2[i],NOTPARSE);
        };
        cout << j+1 << " / " << pool.size() << "\r" << flush;
    };
    //*
    cout << endl;
    dat.clear();
    dat2.clear();
    cout << "Sorting..." << endl;
    sort(pool.begin(),pool.end(),criterion);
    clock_t end1 = clock();
    cout << "Time elapsed : " << double(end1 - begin1) / CLOCKS_PER_SEC << endl;
    /*
    for(size_t i =0;i<pool.size();++i){
        cout << "Eval : " << (pool[i]).getEval() ;
        getchar();
    }//*/
    cout << "Best fit : " << pool[0].getEval() << "\n\nPRESS ENTER TO CONTINUE" << endl;
    getchar();
    //pool[0].print();
}
