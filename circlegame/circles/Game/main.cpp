#include <iostream>
#include "game.h"
#include "MyVector.h"
#include "random.h"
#include <fstream>
using namespace std;

int main()
{
    Random r;
    r.Seed();

    Vector v;
    Game game;
    game.run();
    return 0;
}
