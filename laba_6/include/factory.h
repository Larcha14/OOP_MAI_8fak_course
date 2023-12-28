#pragma once
#include "Orc.h"
#include "Slaver.h"
#include "Druid.h"

class NPC_Factory{
    public:
        static shared_ptr<NPC> create_npc(NpcType type,const  Coord<int> &c);
        static shared_ptr<NPC> create_npc(NpcType type, int x, int y);
};
