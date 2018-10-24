#include "Rule.h"
#include <iostream>
#include <stdexcept>

using namespace std;


Rule::Rule(int head,vector<int> &body)
    : Head(head),
    Body(body)
{
    RuleLen = 1 + Body.size();
}

Rule::Rule(){

}

Rule::Rule(vector<int> NonTerms,vector<int> Terms, size_t maxlength)
    :Head(NonTerms[rand()%NonTerms.size()])
{
    Body.push_back(Terms[rand()%Terms.size()]);
    for(size_t i=1;i<maxlength;++i){
        if(!(rand()%(maxlength-i))) break;
        Body.push_back(NonTerms[rand()%(NonTerms.size()-1)+1]);
    }
    RuleLen = 1 + Body.size();
}

void Rule::print(){
    cout << Head << " -> " ;
    for(size_t i=0; i<Body.size(); ++i)
        std::cout << Body[i] << ' ';
    cout << "Length : " << RuleLen << endl;
}

int Rule::operator[](size_t offset){
    if(offset>RuleLen)
        throw std::invalid_argument( "index out of bounds for Rule" );
    else{
        if(offset == 0) return Head;
        else return Body[offset-1];
    }
}

Rule::~Rule(){
    //cout << "Decon for rule" << endl;
}


int Rule::getRuleLen(){
    return RuleLen;
}
