#include "deck.h"
#include <iostream>

using namespace std;

Deck::Deck(int max_l) {
    this->max_l = max_l;
    deck = new int[max_l];
    this->left = max_l/2;
    this->right = max_l/2;
}

Deck::~Deck() {
    delete []deck;
}

void Deck::PushLeft(int x) {
    if (left == right) {
        deck[left] = x;
        left--;
    }
    else if (left >= max_l && right == max_l - 1) {
        cout <<  "Deck is full!" << endl;
    }
    else {
        if (left < right) {
            if (x >= deck[left + 1]) {
                deck[left] = x;
                left--;
            }
            else {
                int i = left + 1;
                while (deck[i] > x && i != right) {i++; }
                if (i == right && right < max_l - 1 && x < deck[i]) {
                    deck[right + 1] = x;
                    right++;
                }
                else if (i == right && right == max_l - 1 && x > deck[i]) {
                    for (int j = left + 1; j < i; j++) {
                        deck[j - 1] = deck[j];
                    }
                    deck[i - 1] = x;
                    left--;
                }
                else if (i == right && right == max_l - 1 && x <= deck[i]) {
                    for (int j = left + 1; j <= i; j++) {
                        deck[j - 1] = deck[j];
                    }
                    deck[i] = x;
                    left--;
                }
                else {
                    if (i - left - 1 <= right - i + 1 || right == max_l - 1 || deck[i] == x) {
                        for (int j = left + 1; j < i; j++) {
                            deck[j - 1] = deck[j];
                        }
                        deck[i - 1] = x;
                        left--;
                    }
                    else {
                        for (int j = right + 1; j > i; j--) {
                            deck[j] = deck[j - 1];
                        }
                        deck[i] = x;
                        right++;
                    }
                }
            }
        }
        else {
            int i = 0;
            while (deck[i] > x && i != right + 1) {i++; }
            if (right + 1 != i) {
                for (int j = right; j >= i; j--) {
                    deck[j + 1] = deck[j];
                }
            }
            deck[i] = x;
            right++;
            left = right + 1;
        }
    }
    if (left < 0) {left = right + 1; }
}

void Deck::PushRight(int x) {
    if (left == right) {
        deck[left] = x;
        left--;
    }
    else if (left >= max_l && right == max_l - 1) {
        cout <<  "Deck is full!" << endl;
    }
    else {
        int left_;
        if (left < right) {left_ = left + 1; }
        else {left_ = 0;}
        while (deck[left_] >= x && left_ != right) { left_++; }
        if (left_ == right && right + 1 < max_l && x <= deck[left_]) {
            deck[left_ + 1] = x;
            right++;
            if (left >= right) {left++; }
        }
        else if (right + 1 == max_l && x < deck[right]) {
            for (int i = left + 1; i <= left_; i++) {
                deck[i - 1] = deck[i];
            }
            left--;
            deck[left_] = x;
        }
        else if (left_ != 0) {
            for (int j = 1; j < left_; j++) {
                deck[j - 1] = deck[j];
            }
            deck[left_ - 1] = x;
            left--;
        }
        else {
            for (int j = right; j >= left_; j--) {
                deck[j + 1] = deck[j];
            }
            deck[left_] = x;
            right++;
            left = right + 1;
        }
    }
    if (left < 0) {left = right + 1; }
}

void Deck::PopLeft() {
    if (left == right) {
        cout << "Nothing to delete;" << endl;
    }
    if (left < right) { left++; }
    else { left = 0; }
}

void Deck::PopRight() {
    if (left == right) {
        cout << "Nothing to delete" << endl;
    }
    else {
        if (left >= right) {left--; }
        if (right - 1 >= 0) {right--; }
    }
}

void Deck::Print() {
    int left_;
    if (left == right) {
        cout << "Deck is empty";
    }
    else {
        if (left < right) {left_ = left + 1; }
        else {left_ = 0;}
        for (int i = left_; i <= right; i++) {
            cout << deck[i] << " - " << i << endl;
        }
    }
}

int Deck::Length() {
    if (left == right) {return 0; }
    else {
        if (left < right) {return right - left; }
        else {return right + 1; }
    }
}

int Deck::Read() {
    if (left == right) {return -1; }
    else if (left < right) {return deck[left + 1]; }
    else {return deck[0]; }
}

Deck::Deck(Deck &d): max_l(d.max_l), left(d.left), right(d.right) {
    deck = new int [max_l];
    int current;
    if (left < right) {current = left; }
    else {current = 0; }
    for (int i = (current + 1); i <= right; i++) {
        deck[i] = d.deck[i];
    };
}

Deck& Deck::operator= (Deck &d) {
    int current;
    int i = 0;
    if (this == &d) {return *this; }
    else {
        if (max_l > d.max_l) {
            current = d.left;
            while (current <= d.right){
                deck[i] = d.deck[current];
                i++;
                current++;
            }
            left = 0;
            right = i - 1;
            return *this;
        }
    }
}