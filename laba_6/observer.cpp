#include "./include/observer.h"


FileObserver::FileObserver(string flname) {
    this->filename_ = flname;
    this->fd = ofstream(flname);
    if (!(fd.is_open())) {
        cout << "Observer's file opening error!" << endl;
    }
}

FileObserver::~FileObserver() {
    this->fd.close();
}

shared_ptr<IObserver> FileObserver::get(string filename) {
    static FileObserver instance(filename);
    return shared_ptr<IObserver>(&instance, [](IObserver *) {});
}
    
void FileObserver::update(NPC& attacker, NPC& defender, bool win){
    if (win){
        if(fd.is_open()){
            fd << endl
                << "Murder --------" << endl;
            fd << "Killer: ";
            attacker.print(fd);
            // fd << attacker;
            fd << "Victim: ";
            // fd << defender;
            defender.print(fd);
        }
        else{
            cerr << "Observer's file opening error!" << endl;
        }
    }
        
}



shared_ptr<IObserver> ScreenObserver::get(){
    static ScreenObserver instance;
    return shared_ptr<IObserver>(&instance, [](IObserver *) {});
}

void ScreenObserver::update(NPC& attacker, NPC& defender, bool win) {
    if (win){
        cout << endl
                << "Murder --------" << endl;
        cout << "Killer: ";
        attacker.print();
        cout << "Victim: ";
        defender.print();
    }
}