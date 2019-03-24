#include <utility>

#include <string>
#include <iostream>
#include "hash.h"

#define fail -1
#define NO_RECORD "Record is not found"
#define DELETE "Nothing to delete!"
#define REPEAT "Enter again!"
#define LIMIT "100 is a limit for hashtable!"


HashEntry::HashEntry(int rate) {
    this->size = static_cast<unsigned int>(rate);
    Rec table;
}

void HashEntry::SetRecords(Rec R) {
    if (this->size <= n) {
        R.fio = "Ivanov";
        for (int i = 0; i < this->size; i++) {
            //cin >> R.number; cin >> R.fio;
            R.number = static_cast<unsigned int>(i); R.fio[0]++;
            if  (Review(R)) {
                cerr << REPEAT << endl;
                cin >> R.number; cin >> R.fio;
                i--;
            }
            else Add(R);
        }
    }
    else cerr << LIMIT << endl;
}

int HashEntry::HashFunction1(int number) {
    return (number%10);
}

bool HashEntry::Review(Rec R) {
    bool error = false;
    for (auto &i : table) {
        if ((R.number == i.number) && (R.fio == i.fio)) { //must be for search
            return !error;
        }
    }
    return error;
}

void HashEntry::Add(Rec R) {
    int key2;
    bool insert = false;
    auto key = static_cast<unsigned int>(HashFunction1(R.number)); //last numeral of passport number
    if (table[key].status == 0) {  //ячейка свободна
        table[key].number = R.number;
        table[key].fio = R.fio;
        table[key].status = 1;
    } else {                                      //коллизия, переходим к хеш 2 (j+1)
        key2 = HashFunction2(key);
        for (int i = key2; i < n; i++) {
            if ((table[key2].status == 0) && !insert){
                table[key2].number = R.number;
                table[key2].fio = R.fio;
                table[key2].status = 1;
                insert = true;
            }
            else key2++;
        }
    }
}

int HashEntry::HashFunction2(int num) {
    return (num + 1);
}

int HashEntry::Search(Rec R) {
    int i = HashFunction1(R.number);
    if ((table[i].number == R.number) && (table[i].fio == R.fio)) return i;
    else {
        while (i < n) {
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
        for (int i = pos; i < n; i++) {
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
    for (int i = 0; i < n; i++) {
        if (table[i].status == 1) {
            cout << i << " " << table[i].number << " " << table[i].fio << endl;
        }
    }
    cout << endl;
}

HashEntry::~HashEntry() {
    delete[] &table;
}