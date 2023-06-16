
#ifndef WORLD_H_
#define WORLD_H_

#include <string>

#include <iostream>

#include <sstream>

#include "Entity.h"

using namespace std;
const int NE = 1000;
class World {
    private:
        Entity * Ent[NE];
    int ct;
    public:
        World():ct(0){};
    void generate_world();
    void show_ent();
    void show_ent(string type);
    void spawn_sheep(string Wool, bool age);
    void spawn_zombie(int Armor, bool age);
    int SheepDies();
    int PDies();
};
void World :: generate_world(){
    Ent[ct] = new Player(ct,1);
    ct++;
    Ent[ct] = new Sheep(ct, "pink", 1);
    ct++;
    Ent[ct] = new Sheep(ct, "white", 1);
    ct++;
    Ent[ct] = new Sheep(ct, "white", 0);
    ct++;
    Ent[ct] = new Sheep(ct, "pink", 0);
    ct++;
    Ent[ct] = new Zombie(ct, 0);
    ct++;
    Ent[ct] = new Zombie(ct, 0);
    ct++;
    Ent[ct] = new Zombie(ct, 1);
    ct++;
    Ent[ct] = new Zombie(ct, 1);
    ct++;
}
void World :: show_ent(){
    for (int i = 0; i < ct; i++)
            cout << Ent[i] -> to_string();
}
void World :: show_ent(string type){
    for (int i = 0; i < ct; i++) {
        if (Ent[i] -> get_type() == type)
            cout << Ent[i] -> to_string();
    }
}
int World :: SheepDies() {
    for (int i = 0; i < ct; i++) {
        if (Ent[i] -> get_type() == "sheep")
            cout << Ent[i]-> die();
            break;
    }
}
int World :: PDies() {
    for (int i = 0; i < ct; i++) {
        if (Ent[i] -> get_type() == "player")
            cout << Ent[i] -> die();
    }
}
void World :: spawn_sheep(string Wool, bool age){
    Ent[ct] = new Sheep(ct, "cyan", 0);
    ct++;
}
void World :: spawn_zombie(int Armor, bool age){
    Ent[ct] = new Zombie(ct, 0);
    ct++;
}
#endif // WORLD_H_
