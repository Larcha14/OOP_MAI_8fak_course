#include "./include/Druid.h"

Druid::Druid(): NPC(){

}

Druid::Druid(const Coord<int> &c): NPC(NpcType(2), c){

}

Druid::Druid(int x, int y): NPC(NpcType(2), x, y){

}

bool Druid::fight(NPC &other){
    if(other.Type==NpcType(0)){
        throw logic_error("Try to fight with no one");
    } else {
        return false;
    }
}