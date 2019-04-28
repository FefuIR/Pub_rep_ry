#include <iostream>
#include "deck.h"

using namespace std;

int main() {

    Deck D(5);
    D.PushRight(6);
    D.PushRight(8);
    D.PushRight(5);
    D.PushRight(7);
    D.PushRight(4);
    D.Print();
    cout << "---------------------------" << endl;

    for (int i = 0; i < 5; i ++) {D.PopLeft(); }
    D.Print();
    cout << endl << "---------------------------" << endl;

    D.PushRight(5);
    D.PushRight(6);
    D.PushRight(5);
    D.PushRight(2);
    D.PushRight(1);
    D.Print();

    cout << "---------------------------" << endl;
    for (int i = 0; i < 5; i ++) {
        cout << "kol: " << D.Length() << endl ;
        D.PopLeft();
    }
    cout << "kol: " << D.Length() << endl ;
    D.Print();
    cout << endl << "---------------------------" << endl;

    D.PushLeft(5);
    D.PushLeft(5);

    Deck D2(4);
    D2.PushRight(2);
    D2.PushRight(1);
    D2.PushRight(3);
    Deck D3(D);
    D3 = D2;
    D2.Print();
    cout << "-----------" << endl;
    D3.Print();



    return 0;
}