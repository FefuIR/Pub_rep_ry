#include <iostream>

using namespace std;

enum Color {Red, Green, Yellow};

class Plants;
class Tree;

class Oxygen {
private:
    int Oxy;
public:
    Oxygen(int oxygen){
        this->Oxy = oxygen;
    }
};

class Plants {
public:
    Oxygen* oxygen1;
    bool oxygen = true;
    bool IsAlive(Tree tree);

    Plants(Oxygen oxygen1){
        this->oxygen1 = new Oxygen(oxygen1);
    };

    class Flower{
        Plants *plant;
    private:
        int numOfPetals;
    public:
        Flower(int petal){
            numOfPetals = petal;
        }
    };
};

class Tree {
public:
    Color c = Yellow;
    bool alive = true;

    bool IsAPlant(Plants plant);
};

bool Plants::IsAlive(Tree tree){
    if (tree.c == 1) {
        tree.alive = true;
    }
    return tree.alive;
}

bool Tree::IsAPlant(Plants plant) {
    if (plant.oxygen == true) {
        return plant.oxygen;
    }
    else return !plant.oxygen;
}


int main() {
    Plants p(100);
    Plants :: Flower f(20);
    Tree t;
    cout << t.IsAPlant(p);

    return 0;
}