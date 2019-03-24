

#ifndef HASH_HASH_H
#define HASH_HASH_H

#include <string>

using namespace std;

const int n = 20;

struct Rec {
    string fio;
    unsigned int number = 0;
    unsigned short int status = 0;
};

class HashEntry {
    Rec table[n];
    unsigned int size;
public:
    explicit HashEntry(int rate);
    ~HashEntry();
    void SetRecords(Rec R);
    int HashFunction1(int number);
    bool Review(Rec R);
    void Add (Rec R);
    int HashFunction2(int num);
    int Search(Rec R);
    void PrintSearch(Rec R);
    void Delete(Rec R);
    void PrintTheTable ();
};

#endif //HASH_HASH_H
