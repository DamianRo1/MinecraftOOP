#include <iostream>

#include "Entity.h"

#include "World.h"

using namespace std;

int main() {

    World world;
    world.generate_world();
    cout << "\n\n base generated entities:" << endl;
    world.show_ent();
    cout << endl;
    world.show_ent("sheep");
    world.spawn_sheep("red", false);
    world.spawn_zombie(4, false);
    cout << "\n\n total entities:" << endl;
    world.show_ent();
    string b;
    b = world.SheepDies();
    cout << "A sheep spontaneously combusts." << b << endl;
    b = world.PDies();
    cout << "You also spontaneously combust! " << b << endl;
}
