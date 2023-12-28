#include <iostream>
#include "./include/npc.h"

char* NpcType_naming[]={
    "Unknown", "Slaver", "Druid", "Orc"
};


// NPC::NPC(){
//     Type=NpcType(0);
//     Coord<int> c(0, 0);
//     coord=c;
// }

// NPC::NPC(NpcType type, int x, int y){
//     Type=type;
//     Coord<int> new_c(x, y);
//     coord= new_c;
// }

// NPC::NPC(NpcType type, const Coord<int> &c){
//     Type=type;
//     coord=c;
// }

NPC::NPC(){
    Type=NpcType(0);
    Coord<int> c(0, 0);
    coord=c;
}

NPC::NPC(NpcType type, int x, int y){
    Type=type;
    Coord<int> new_c(x, y);
    coord= new_c;
}

NPC::NPC(NpcType type, const Coord<int> &c){
    Type=type;
    coord=c;
}


NPC& NPC::operator=(NPC& other){
    this->coord=other.coord;
    this->Type=other.Type;
    //vector<shared_ptr<IObserver>> observers;
    this->observers.resize(other.observers.size());
    for(int i=0; i<this->observers.size();++i){
        this->observers[i]=other.observers[i];
    }
    return *this;
}

NPC& NPC::operator=(NPC&& other){
    this->coord=other.coord;
    this->Type=other.Type;
    //vector<shared_ptr<IObserver>> observers;
    this->observers=other.observers;
    other.observers=vector<shared_ptr<IObserver>>(0);
    other.Type=NpcType(0);
    return *this;

}

bool NPC::is_eq_type(NpcType other_t){
    if(Type==other_t){
        return true;
    }
    return false;
}

void NPC::save(ostream &os){
    os<<coord.x<<endl;
    os<<coord.y<<endl;
}

ostream &operator<<(ostream &os, NPC &npc){
    os<<"Type is "<<NpcType_naming[npc.Type]<<endl;
    os<<"X="<<npc.coord.x<<" || Y="<<npc.coord.y<<endl;
    return os;

}

void NPC::print(){
    cout<<*this;
}

void NPC::print(ostream &os){
    os<<*this;
}

void NPC::print_type(){
    cout<<NpcType_naming[Type];
}

NPC::~NPC(){
    
    observers=vector<shared_ptr<IObserver>>(0);

}

void NPC::subscribe(shared_ptr<IObserver> observer){
    observers.push_back(observer);
}

bool NPC::is_close(const shared_ptr<NPC> &other, int distance) {
    if(coord.distance(other->coord)<=distance){
        return true;
    }
    return false;
}

void NPC::fight_notify(NPC&defender, bool win){
    for(auto &obs : observers ){
        obs->update(*this, defender, win);
    }
}

// bool NPC::accept(IVisitor& visitor, shared_ptr<NPC>& attacker) {
//     shared_ptr<NPC> ptr= make_shared<NPC>(*this);
//     return visitor.visit(ptr, attacker);
// }