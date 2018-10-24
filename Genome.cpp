#include "Genome.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "utilities.h"


Genome::Genome(){
    numberOfRules = 0;
    numberOfSymbols = 0;
    evaluation = 0;
    cout << "Constructor for genome" << endl;
}

bool comp(Rule &a, Rule &b){
    return a[0] < b[0];
}

Genome::Genome(vector<Rule> &rv)
    : rules(rv), numberOfRules(rv.size()),numberOfSymbols(0), evaluation(0)
{
    sort(rules.begin(),rules.end(),comp);
    for(size_t i;i<rules.size();++i) numberOfSymbols += rules[i].getRuleLen();
}


Genome::~Genome(){
    //cout << "Deconstructor for genome" << endl;
}

void Genome::print(){
    for(int i = 0;i<numberOfRules;++i){
        (rules[i]).print();
    }
}
bool parser(vector<int> &w,vector<Rule> &r,int head = 0);

bool parser(vector<int> &w,vector<Rule> &r,vector<int> &stackOfHeads){
    if(w.size()==0||stackOfHeads.size()==0||stackOfHeads.size()>w.size()) return false;
    if(stackOfHeads.size()==1) return parser(w,r,stackOfHeads[0]);
    for(size_t i = 1;i<w.size();++i){
        vector<int> *w1 = new vector<int>(w.begin(),w.begin() + i);
        vector<int> *w2 = new vector<int>(w.begin()+i,w.end());
        vector<int> *SH = new vector<int>(stackOfHeads.begin()+1,stackOfHeads.end());
        if(SH->size()==0 && w2->size()>0) return false;
        if( parser( *w1,r,stackOfHeads[0] ) && parser( *w2,r,*SH )){
            return true;
        }
        delete SH;
        delete w2;
        delete w1;
    }
    return false;
}

bool parser(vector<int> &w,vector<Rule> &r,int head){
    if(w.size()==0||r.size()==0) return false;
    if(w.size()==1){    // Check if word is a letter
        for(size_t i = 0;i < r.size() ; ++i){
            if( (r[i])[0]==head && (r[i])[1] == w[0] && r[i].getRuleLen() == 2) return true;
        }
        return false;
    }
    vector<int>::const_iterator first = w.begin() + 1;
    vector<int>::const_iterator last = w.end();
    vector<int> *w1 = new vector<int>(first,last);
    for(size_t i = 0;i<r.size();++i){
        if((r[i])[0]==head && (r[i])[1] == w[0] && r[i].getRuleLen() > 2){
            vector<Rule> *CandidateRules = new vector<Rule>;
            CandidateRules->reserve(r.size());
            *CandidateRules = r;
            for(int j = 0;j<CandidateRules->size();++j){
                if( (*CandidateRules)[j].getRuleLen()-1 > w1->size() ) CandidateRules->erase((*CandidateRules).begin()+j);
            }
            vector<int> *StackH = new vector<int>;
            StackH->reserve(r.size());
            for(int k = 2;k<r[i].getRuleLen();++k) StackH->push_back(r[i][k]);
            if(parser(*w1,*CandidateRules,*StackH)) return true;
            delete StackH;
            delete CandidateRules;
        }
    }
    delete w1;
    return false;
}

void Genome::parse(vector<int> &w, int ParseType){
    try{
        if(ParseType) parser(w,rules)?(++evaluation):(--evaluation);
        else parser(w,rules)?(--evaluation):(++evaluation);
    }
    catch(exception &e){
        exceptionNumber++;
        (*this).print();
        for(size_t i =0;i<w.size();++i) cout << w[i] << " ";
        cout << endl;
    };
}

const Genome &Genome::operator+=(Rule &r){
    if(r[0]==0) rules.insert(rules.begin(),r);
    else{
        rules.push_back(r);
        for(size_t i = 0;i<rules.size();++i){
            if(((rules[rules.size()-i-1])[0]<(rules[rules.size()-i-2])[0])&&((rules[rules.size()-i-2])[0]!=0)){
                iter_swap(rules.end()-i-1,rules.end()-i-2);
            }
            else break;
        }
    }
    numberOfRules++;
    numberOfSymbols += r.getRuleLen();
    return *this;
}


int Genome::getEval(){
    return evaluation;
}

bool Genome::valid(){
    return (rules[0][0] == 0)?true:false;
}
