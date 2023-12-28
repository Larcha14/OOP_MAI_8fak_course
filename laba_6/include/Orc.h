#pragma once
#include "npc.h"

//Убивает всех

class Orc: public NPC{
    public:
        Orc();
        Orc(const Coord<int> &c);
        Orc(int x, int y);
        bool fight(NPC &other) override;
        // bool accept(IVisitor &visitor, NPC &attacker) override;
};

// Orc::Orc(): NPC(){

// }

// Orc::Orc(const Coord<int> &c): NPC(NpcType(3), c){

// }

// Orc::Orc(int x, int y): NPC(NpcType(3), x, y){

// }

// bool Orc::fight(shared_ptr<NPC> &other){
//     if(other->Type==NpcType(0)){
//         throw logic_error("Try to fight with no one");
//     } else {
//         return true;
//     }
// }