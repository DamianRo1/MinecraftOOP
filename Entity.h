#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include <sstream>

using namespace std;

class Entity {
    protected:
        int id;
        int hp;
        string type;
        ;
    public:
        Entity(): id(0), hp(10), type("") {};
        Entity(int eid, int h, string t):
        id(eid), hp(h), type(t) {};

    int get_id() {
        return id;
    }
    int get_hp() {
        return hp;
    }
    string get_type() {
        return type;
  }
    virtual int die() = 0;
    virtual string to_string() = 0;
};
class Player: public Entity {
    private:
        int sword;
    public:

        Player(): Entity(0, 10, "player") {};
        Player(int id, int swd): Entity(id, 10, "player"),
        sword(swd) {};

    int slash() {
        return sword;
    }
    int die();
    string to_string();
};
int Player::die() {
        cout << "Game Over \n";
        return 0;
}
string Player::to_string() {

    stringstream aux;
    aux << "Entity ID: " << id << " Entity type: " << type << " Hitpoints: " << hp << "\n";
    return aux.str();
}
class Sheep: public Entity {
    private:
        string wool;
        bool age;
    public:
        Sheep(): Entity(0, 6, "sheep") {};
        Sheep(int id, string wl, bool bby): Entity(id, 6, "sheep"),
        wool(wl),
        age(bby) {};

    int die();
    string to_string();

};
int Sheep::die() {
        cout << "you got mutton and " << wool << " wool!  :3 \n";
        return 0;
  }
string Sheep::to_string() {

    stringstream aux;
    aux << "Entity ID: " << id << " Entity type: " << type << " Hitpoints: " << hp << "\n";
    return aux.str();
}
class Zombie: public Entity {
    private:
        bool age;
    public:
        Zombie(): Entity(0, 10, "zombie") {};
        Zombie(int id, bool bby): Entity(id, 10, "zombie"),
        age(bby) {};

    int die();
    string to_string();

};
int Zombie::die() {
    cout << "you got rotten flesh. \n";
    return 0;
}
string Zombie::to_string() {

    stringstream aux;
    aux << "Entity ID: " << id << " Entity type: " << type << " Hitpoints: " << hp << "\n";
    return aux.str();
}
#endif // ENTITY_H_
