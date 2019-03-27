#include <string>
#include <iostream>
#include "hash.h"

#define fail -1
#define NO_RECORD "Record is not found"
#define DELETE "Nothing to delete!"
#define REPEAT "This record is already used!"
#define END "Hashtable finished!"


HashEntry::HashEntry(int n) {
    size = n;
    table = new Rec[size];
}

HashEntry::~HashEntry() {
    delete []table;
}

int HashEntry::HashFunction1(int number) {
    return (number%10);
}

int HashEntry::HashFunction2(int number) {
    return (number + 1);
}

bool HashEntry::Review(Rec R) {
    bool error = false;
    for (int i = 0; i < size; i++) {
        if ((R.number == table[i].number) && (1 == table[i].status)) {
            return !error;
        }
    }
    return error;
}

void HashEntry::Add(Rec R) {
    bool insert = false;
    int key = HashFunction1(R.number);
    if  (Review(R)) {
        cerr << REPEAT << endl;
        //cin >> R.number; cin >> R.fio;
    }
    else {
        if (table[key].status == 0) {  //ячейка свободна
            table[key].number = R.number;
            table[key].fio = R.fio;
            table[key].status = 1;
        } else {                                      //коллизия, переходим к хеш 2 (j+1)
            int key2 = HashFunction2(key);
            for (int i = key2; i < size; i++) {
                if ((table[key2].status == 0) && !insert){
                    table[key2].number = R.number;
                    table[key2].fio = R.fio;
                    table[key2].status = 1;
                    insert = true;
                }
                else key2++;
            }
            if (!insert) {
                cerr << END << endl;
            }
        }
    }
}

int HashEntry::Search(Rec R) {
    int i = HashFunction1(R.number);
    if ((table[i].number == R.number) && (table[i].fio == R.fio)) return i;
    else {
        while (i < size) {
            i = HashFunction2(i);
            if ((table[i].number == R.number) && (table[i].fio == R.fio)) return i;
        }
    }
    return fail;
}

void HashEntry::PrintSearch(Rec R) {
    if (Search(R) == fail) cerr <<  NO_RECORD << endl;
    else if (Search(R) != -1) {
        cout << table[Search(R)].number << " " << table[Search(R)].fio;
    }
    cout << endl;
}

void HashEntry::Delete(Rec R) {
    int pos = Search(std::move(R));
    if (pos != fail) {
        table[pos].status = 0;
        pos++;
        for (int i = pos; i < size; i++) {
            if (table[i].status == 1) {
                int key = HashFunction1(table[i].number);
                if (i != key) {
                    if (table[key].status == 0) {
                        table[key].number = table[i].number;
                        table[key].fio = table[i].fio;
                        table[key].status = 1;
                        table[i].status = 0;
                    } else {
                        key = HashFunction2(key);
                        bool found = false;
                        while (!found) {
                            if (table[key].status == 0) {
                                table[key].number = table[i].number;
                                table[key].fio = table[i].fio;
                                table[key].status = 1;
                                table[i].status = 0;
                                found = true;
                            } else key++;
                        }
                    }
                }
            }
        }
    }
    else cerr << DELETE << endl;
}

void HashEntry::PrintTheTable() {
    for (int i = 0; i < size; i++) {
        if (table[i].status == 1) {
            cout << i << " " << table[i].number << " " << table[i].fio << endl;
        }
    }
    cout << endl;
}
