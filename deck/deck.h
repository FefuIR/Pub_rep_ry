#ifndef DECK_DECK_H
#define DECK_DECK_H

class Deck {
private:
    int *deck;
    int max_l, left, right;

public:
    Deck(int max_l);
    ~Deck();
    void PushLeft(int x);
    void PushRight(int x);
    void PopLeft();
    void PopRight();
    void Print();
    int Length();
    int Read();
    Deck(Deck &d);
    Deck& operator= (Deck& deck2);

};

#endif //DECK_DECK_H
