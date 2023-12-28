#include "./include/Orc.h"

Orc::Orc(): NPC(){

}

Orc::Orc(const Coord<int> &c): NPC(NpcType(3), c){

}

Orc::Orc(int x, int y): NPC(NpcType(3), x, y){

}

bool Orc::fight(NPC &other){
    if(other.Type==NpcType(0)){
        throw logic_error("Try to fight with no one");
    } else {
        return true;
    }
}

// bool Orc::accept(IVisitor &visitor, NPC &attacker){
//     return visitor.visit(*this, attacker);
// }