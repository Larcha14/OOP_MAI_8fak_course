#pragma once
#include "npc.h"

//Друид никого не трогает

class Druid: public NPC{
    public:
        Druid();
        Druid(const Coord<int> &c);
        Druid(int x, int y);
        bool fight(NPC &other) override;
        // bool accept(IVisitor &visitor, NPC &attacker)override;
};

// Druid::Druid(): NPC(){

// }

// Druid::Druid(const Coord<int> &c): NPC(NpcType(2), c){

// }

// Druid::Druid(int x, int y): NPC(NpcType(2), x, y){

// }

// bool Druid::fight(shared_ptr<NPC> &other){
//     if(other->Type==NpcType(0)){
//         throw logic_error("Try to fight with no one");
//     } else {
//         return false;
//     }
// }