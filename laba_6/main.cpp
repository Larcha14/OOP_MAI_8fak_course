
#include "./include/factory.h"
#include "./include/observer.h"
#include "./include/visitor.h"
#include <memory>
#include <set>
#include <string>

using namespace std;
// #include "./include/factory.h"
using set_t = set<shared_ptr<NPC>>;

ostream &operator<<(ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}

void save(const set_t &array, const string &filename)
{
    ofstream fs(filename);
    fs << array.size() << endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const string &filename)
{
    string filepath = filename;
    set_t result;
    ifstream is(filepath);
    if (!is.is_open()){
        cerr << "Error: " << endl;
    }
    NPC_Factory NF;
    int count, x, y;
    int type;
    is >> count;

    for (int i = 0; i < count; ++i){
        is >> type >> x >> y;
        result.insert(NF.create_npc(NpcType(type), x, y));
        // result.insert(NPCFactory::factory(static_cast<NpcType>(type), Point(x, y)));
    }
        
    is.close();
    
    return result;
}

set_t fight(const set_t& array, size_t distance) {
    set_t dead_list;

    // FightVisitor visitor;

    for (const auto& attacker : array) {
        for (const auto& defender : array) {
            if ((attacker != defender) && (attacker->is_close(defender, distance))) {
                bool success{false};
                success = defender->fight(*attacker);
                if (success) {
                    dead_list.insert(defender);
                }
            }
        }
    }

    return dead_list;
}


// int main(){
//     int a=11;
//     int b=11;
//     shared_ptr<NPC> npc2; 
//     NPC_Factory NF;
//     const Coord<int> c(a, b);
//     npc2= NF.create_npc(NpcType(2), a, b);

// //     shared_ptr<NPC> npc2; 
// //     shared_ptr<NPC> orc;

// //     Coord c2=c;

// //     orc=make_shared<Orc>(c);

//     // NPC npc1(NpcType(3), c2);
//     // npc2=make_shared<Slaver>(a,b);
//     cout<<"hi ="<<*npc2;
// }

int main(){
    set_t npcs;
    NPC_Factory np;
    for (size_t i = 0; i < 30; ++i){
        const Coord<int> tmp(rand() % 200, rand() % 200);
        npcs.insert(np.create_npc(NpcType(1+rand() % 3), tmp));
    }
    cout << "Saving ..." << endl;
    save(npcs, "npc.txt");

    cout << "Loading ..." << endl;
    npcs = load("npc.txt");

    cout << "Fighting ..."  << endl 
            << "_________NPCS_________"
                        << endl
                        << npcs
            << "______________________" 
            << endl << endl;
    for (size_t distance = 20; (distance <= 200) && !npcs.empty(); distance += 20)
    {
        std::cout << "_________NEW ROUND_________"  << std::endl;
        auto dead_list = fight(npcs, distance);
        for (auto &d : dead_list)
            npcs.erase(d);
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl;

    }
}