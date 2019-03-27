#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main() {
    Rec R;
    HashEntry Hash(20);

    R.fio = "Avanov";

    for (int i = 1; i < 21; i++) {
        R.number = i;
        R.fio[0]++;
        //cin >> R.number; cin >> R.fio;
        Hash.Add(R);
    }

    Hash.PrintTheTable();

    cout<< endl << "-----------------------" << endl;
    R.fio = "Avanov";

    for (int i = 1; i < 16; i++) {
        R.number = 2*i;
        R.fio[0]+= 2;
        Hash.Delete(R);
    }

    Hash.PrintTheTable();

    cout<< endl << "-----------------------" << endl;
    R.fio = "Avanof";

    for (int i = 1; i < 11; i++) {
        R.number = 2*i;
        R.fio[0]+= 2;
        Hash.Add(R);
    }

    Hash.PrintTheTable();
    return 0;
}