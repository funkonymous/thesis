#ifndef RULE_H_INCLUDED
#define RULE_H_INCLUDED

#include <vector>

using namespace std;


class Rule{

public :
    Rule(int head,vector<int> &body);
    Rule();
    Rule(vector<int> NonTerms,vector<int> Terms, size_t maxlength = 2);
    ~Rule();
    int getRuleLen();
    void print();
    int operator[](size_t offset);

private :
    int Head;
    vector<int> Body;
    unsigned int RuleLen;
};

#endif
