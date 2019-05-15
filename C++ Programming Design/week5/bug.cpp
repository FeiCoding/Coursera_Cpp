#include <iostream>
#include <string>
using namespace std;

class Skill{
    int i;
    public:
        Skill(int i_):i(i_){}
};

class Bug{
    int nLegs, nColor;
    public:
        int nType;
        Bug(int leg, int color):nLegs(leg), nColor(color){}
        void PrintBug(){
            cout << "Legs: " << nLegs << " Color: " << nColor << " Type: " << nType;
        };
};

class FlyBug: public Bug{
    int nWings;
    Skill s1, s2;
    public:
        FlyBug(int leg, int color, int wing, int s1_, int s2_):Bug(leg, color), s1(s1_), s2(s2_){
            nWings = wing;
        }
};

int main(){
    FlyBug fb(4, 2, 4, 2, 1);
    fb.nType = 3;
    fb.PrintBug();
}