#pragma once

#include <iostream>
#include <vector>
#include "coord.h"
// #include "coord_int.h"
#include <memory>
using namespace std;

class NPC;
class Orc;

enum NpcType{
    Unknown = 0,
    Slaver_type = 1,
    Druid_type = 2,
    Orc_type = 3
};

class IVisitor{
    public:
        virtual bool visit(NPC  &npc, NPC  &attacker)=0;
};

class IObserver { // Обзервер виртуальный
public:
    // virtual void update(shared_ptr<NPC> &attacker, shared_ptr<NPC> &defender, bool win) = 0;
    virtual void update(NPC  &attacker, NPC &defender, bool win) = 0;
};

class NPC{

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    public:
        NpcType Type;
        Coord<int> coord;
        // Coord coord;
        vector<shared_ptr<IObserver>> observers;
        NPC();
        // NPC(NpcType type, const Coord<int> &c);
        NPC(NpcType type, const Coord<int> &c);
        NPC(NpcType type, int x, int y);

        NPC& operator = (NPC& other);
        NPC& operator = (NPC&& other);

        bool is_eq_type(NpcType other_type);
        virtual bool fight(NPC &other)=0;
        // virtual bool accept(IVisitor &visitor, NPC &attacker)=0;


        void subscribe(shared_ptr<IObserver> observer );
        // void fight_notify(const shared_ptr<NPC> &defender,bool win);
        void fight_notify(NPC &defender,bool win);
        virtual bool is_close(const shared_ptr<NPC> &other, int distance);

        // Need for writing to the file
        void print();
        void print_type();
        void print(ostream &os);
        void save(ostream &os);
        ~NPC();
};


