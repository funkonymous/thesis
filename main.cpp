#include <iostream>
#include "Rule.h"
#include "Database.h"
#include "Genome.h"
#include "Population.h"
#include "utilities.h"

int exceptionNumber = 0;

using namespace std;
using namespace geDB;


int main()
{
    /*  Comment this line
    // Test Snippet #1.0
    //Just running some tests for gene constructors
    vector<char> B = {'a','b'};
    vector<char> A = {'S','A','C','B'};
    vector<char> A2 = {'a','B','B'};
    string w("aaa");
    Rule r1(A,B,10);
    Rule r2(A,B,10);
    Rule r3('S',A2);
    r1.print();
    r2.print();
    r3.print();
    Genome gene;
    gene += r1;
    gene += r2;
    gene += r3;
    gene.print();
    gene.parse(w);
    cout << gene.getEval() << endl;//*/

    /*  Comment this line
    // Test Snippet #1.1
    //Test the average length of the random rule generator
    vector<char> v1 = {'a','b','c'}; //of no particular significance, just testing
    vector<char> v2 = {'d','e','f'};
    int freq[10] = {0};
    int acc = 0;
    for(size_t i=0;i<1000000;++i){
        Rule r(v1,v2,10);
        acc += r.getRuleLen();
        freq[r.getRuleLen()-1]++;
    }
    cout << "Average percentage of max length for a generated rule : " << (float) acc / 100000.0 << " %" << endl;
    cout << "Histogram : " ;
    for(size_t i = 0;i<10;++i,cout<<endl) for(size_t j = 0;j<(freq[i]/10000);++j) cout << '*';
    for(size_t i = 0;i<10;cout<< freq[i] <<endl,++i);
    //*/


    /*  Comment this line
    // Test Snippet #1.2
    //Big test for parser
    vector<int> w = {1,2,3,2,3,3,5,5,5};
    Genome G1;
    vector<int> v1 = {1,40};
    vector<int> v2 = {2,41,41};
    vector<int> v3 = {3};
    vector<int> v4 = {3,42,42,42};
    vector<int> v5 = {5};
    Rule r1(0,v1);
    Rule r2(40,v2);
    Rule r3(41,v3);
    Rule r4(41,v2);
    Rule r5(42,v5);
    Rule r6(41,v4);

    G1 += r1;
    G1 += r2;
    G1 += r3;
    G1 += r4;
    G1 += r5;
    G1 += r6;

    G1.print();

    cout << G1.getEval() << endl;
    G1.parse(w,PARSE);
    cout << G1.getEval() << endl;
    //*/

    //* Comment this line
    // Test snippet #1.3
    // Test for database
    string f("ShortData");
    string f1("ShortDataNot");
    Database DB(f);
    Database DBf(f1);
    printMemory();
    cout << "Data read\n\nPRESS ENTER TO CONTINUE" << endl;
    getchar();
    Population Pop(DB,DBf,100000,45,5);
    printMemory();
    //DB.print();
    cout << "\nPRESS ENTER TO CONTINUE" <<endl;
    getchar();
    Pop.sortPop();
    printMemory();
    cout << "Exceptions caught : " << exceptionNumber << endl;
    //*/
}
