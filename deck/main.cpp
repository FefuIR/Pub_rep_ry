#include <iostream>
#include "deck.h"

using namespace std;

int main() {

    Deck D(15);
    Deck D1(6);

    for (int i = 0; i < 7; i++) {
        D.PushRight(i*2);
        D.PushLeft(i*4);
    }
    D.Print();
    cout << "L = " << D.Length() << endl;
    cout << "-------" << endl;

    for (int i = 0; i < 15; i++) {
        D.PopRight();
        D.PopLeft();
    }
    D.Print();
    cout << "L = " << D.Length() << endl;
    cout << "-------" << endl;

    for (int i = 0; i < 10; i++) {
      //  D.PushRight(i*10);
        D.PushLeft(i*4);
    }
    D.Print();
    cout << "L = " << D.Length() << endl;
    cout << "-------" << endl;

    //D1.Print();
    //cout << "L = " << D1.Length() << endl;

    /*for (int i(0); i < 5; i++) {
        D.PopRight();
        D1.PopLeft();
    }
    D.Print();
    cout << "L = " << D.Length() << endl;
    D1.Print();
    cout << "L = " << D1.Length() << endl;


    for (int i(0); i < 7; i++) {
        D.PushLeft(2*i);
        D1.PushRight(i*20);
    }

    D.Print();
    cout << "L = " << D.Length() << endl;
    D1.Print();
    cout << "L = " << D1.Length() << endl;


    D=D1=D;
    D.Print();
    cout << "L = " << D.Length() << endl;
    D1.Print();
    cout << "L = " << D1.Length() << endl;*/

    return 0;
}