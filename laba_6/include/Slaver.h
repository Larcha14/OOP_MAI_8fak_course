#pragma once
#include "npc.h"

//Убивает друидов

class Slaver: public NPC{
    public:
        Slaver();
        Slaver(const Coord<int> &c);
        Slaver(int x, int y);
        bool fight(NPC &other)override;
        // bool accept(IVisitor &visitor, NPC &attacker)override;
};

// Slaver::Slaver(): NPC(){

// }

// Slaver::Slaver(const Coord<int> &c): NPC(NpcType(1), c){

// }

// Slaver::Slaver(int x, int y): NPC(NpcType(1), x, y){

// }

// bool Slaver::fight(shared_ptr<NPC> &other){
//     if(other->Type==NpcType(0)){
//         throw logic_error("Try to fight with no one");
//     } else if (other->Type==NpcType(2)){
//         return true;
//     } else {
//         return false;
//     }
// }