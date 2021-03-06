#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main() {
    Rec R;
    HashEntry Hash(10);

    R.fio = "Avanov";

    for (int i = 0; i < 10; i++) {
        R.number = i;
        R.fio[0]++;
        Hash.Add(R);
    }
    Hash.PrintTheTable();
    cout<<R.number<<" "<< R.fio<<endl;

    cout<< endl << "-----------------------" << endl;

    R.fio = "Kvanov";
    for (int i = 8; i > 0 ; i-=2) {
        R.number = i - 1;
        R.fio[0]-=2;
        cout<<R.number<<" "<< R.fio<<endl;
        Hash.Delete(R);
    }
    cout<<"---------------"<<endl;

    Hash.PrintTheTable();

    R.fio = "bvanof";

    for (int i = 1; i < 15; i++) {
        R.number = i*5;
        R.fio[0]+= 2;
        Hash.Add(R);
    }

    Hash.PrintTheTable();


    R.fio = "bvanof";

    for (int i = 1; i < 6; i++) {
        R.number = i*5;
        R.fio[0]+= 2;
        cout<<R.number<<" "<< R.fio<<endl;
        Hash.Delete(R);
    }
    cout<<"---------------"<<endl;

    Hash.PrintTheTable();
    return 0;
}