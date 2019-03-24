#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main() {
    HashEntry Hash(10);
    Rec R = Rec();
    Hash.SetRecords(R);
    Hash.PrintTheTable();

    R.number = 7;
    R.fio = "Qvanov";

    Hash.Search(R);
    Hash.PrintSearch(R);
    Hash.Delete(R);
    Hash.PrintTheTable();
    return 0;
}