#include "./include/visitor.h"

bool FightVisitor::visit(NPC  &npc, NPC  &attacker){
    bool win=attacker.fight(npc);
    attacker.fight_notify(npc, win);
    return win;
}