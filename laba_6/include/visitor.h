#pragma once
#include "Orc.h"
#include "Slaver.h"
#include "Druid.h"
#include "observer.h"

class FightVisitor : public IVisitor{
    public:
        bool visit(NPC  &npc, NPC  &attacker) override;
};

