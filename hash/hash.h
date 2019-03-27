#ifndef HASH_HASH_H
#define HASH_HASH_H

#include <string>

using namespace std;

struct Rec {
    string fio;
    unsigned int number = 0;
    unsigned short int status = 0;
};

class HashEntry {
private:
    unsigned int size;
    Rec *table;
    void SetRecords(Rec R);
    int HashFunction1(int number);
    bool Review(Rec R);
    int HashFunction2(int number);

public:
    HashEntry(int n);
    ~HashEntry();
    void Add (Rec R);
    int Search(Rec R);
    void PrintSearch(Rec R);
    void Delete(Rec R);
    void PrintTheTable ();
};

#endif //HASH_HASH_H
