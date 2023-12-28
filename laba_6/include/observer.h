#pragma once
#include "npc.h"
#include <string>
#include <fstream>
// class IObserver



class FileObserver : public IObserver {
private:
    string filename_;
    ofstream fd;

    FileObserver(string flname);
    ~FileObserver();
    
public:
    static shared_ptr<IObserver> get(string filename);
    
    void update(NPC& attacker, NPC& defender, bool win) override; 
};

class ScreenObserver : public IObserver {
private:
    ScreenObserver(){};

public:
    static shared_ptr<IObserver> get();
    void update(NPC& attacker, NPC& defender, bool win) override;
};
