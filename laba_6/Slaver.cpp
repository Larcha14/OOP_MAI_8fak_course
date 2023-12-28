#include "./include/Slaver.h"
 
Slaver::Slaver(): NPC(){

}

Slaver::Slaver(const Coord<int> &c): NPC(NpcType(1), c){

}

Slaver::Slaver(int x, int y): NPC(NpcType(1), x, y){

}

bool Slaver::fight(NPC &other){
    if(other.Type==NpcType(0)){
        throw logic_error("Try to fight with no one");
    } else if (other.Type==NpcType(2)){
        return true;
    } else {
        return false;
    }
}