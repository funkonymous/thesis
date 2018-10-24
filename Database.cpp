#include "Database.h"
#include "Genome.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>

using namespace std;
using namespace geDB;

Database::Database(string &file){
    clock_t begin1 = clock();
    cout << "Parsing Database : " << file << endl;
    size_t i;
    string word;
    ifstream readFile(file);
    while(getline(readFile,word)){ // find every different char in the database
        for(i=0;i<word.length();++i){
            if( !(find(TerminalSymbols.begin(),TerminalSymbols.end(),word[i]) != TerminalSymbols.end()) )
                TerminalSymbols.push_back(word[i]);
        }
    }
    sort(TerminalSymbols.begin(),TerminalSymbols.end());
    size_t pos;
    vector<int> data;
    readFile.clear();
    readFile.seekg(0,ios::beg);
    while(getline(readFile,word)){ // replace every char with int
        for(i=0;i<word.length();++i){
            pos = find(TerminalSymbols.begin(),TerminalSymbols.end(),word[i]) - TerminalSymbols.begin();
            data.push_back(pos+1);
        }
        Data.push_back(data);
        data.clear();
    }
    for(size_t i = 1; i<= TerminalSymbols.size();++i){ // make terminal symbols list
        Terms.push_back(i);
    }
    cout << "Terminal symbols read : " << TerminalSymbols.size() << endl;
    cout << "Lines read : " << Data.size() << endl;
    clock_t end1 = clock();
    cout << "Time elapsed : " << double(end1 - begin1) / CLOCKS_PER_SEC << endl;
}

Database::~Database(){
    cout << "Deconstructor for DB" << endl;
}

void Database::print(){
    cout << "Terminals list :\n" << "Gen" << "\t" << "Phen" << endl;
    for(size_t i=0;i<Terms.size();++i){
        cout << Terms[i] << "\t" << TerminalSymbols[i] << endl;
    }
    cout << endl;
    for(size_t i = 0;i<Data.size();++i){
        for(size_t j = 0;j<(Data[i]).size();++j){
            cout << Data[i][j] << " " ;
        }
        cout << endl;
    }
}
void appendW(vector<int> &dat,vector<int> &w,size_t currentDepth,size_t maxDepth,size_t currentEntries,size_t maxEntries);

void Database::appendDBF(Database &DBT,size_t depth,size_t maxEntries){
    vector<vector<int>> dat = DBT.getData();
    vector<int> w;
}

void appendW(vector<int> &dat,vector<int> &w,size_t currentDepth,size_t maxDepth,size_t currentEntries,size_t maxEntries){

}

vector<vector<int>> Database::getData(){
    return Data;
}

vector<int> Database::getTerms(){
    return Terms;
}
