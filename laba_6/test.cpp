#include <gtest/gtest.h>
#include "./include/factory.h"
#include "./include/observer.h"
#include "./include/visitor.h"
#include <memory>
#include <set>
#include <string>
using namespace std;

TEST(factory_pattern, Create){
    NPC_Factory nc;
    shared_ptr<NPC> slaver = NPC_Factory::create_npc(NpcType(1), Coord<int>(rand() % 100, rand() % 100));
    shared_ptr<NPC> druid = NPC_Factory::create_npc(NpcType(2), Coord<int>(rand() % 100, rand() % 100));
    shared_ptr<NPC> orc = NPC_Factory::create_npc(NpcType(3), Coord<int>(rand() % 100, rand() % 100));

    ASSERT_TRUE(dynamic_cast<Orc*>(orc.get()) != nullptr);
    ASSERT_TRUE(dynamic_cast<Druid*>(druid.get()) != nullptr);
    ASSERT_TRUE(dynamic_cast<Slaver*>(slaver.get()) != nullptr);
}

TEST(visitor_pattern, Orc){

    shared_ptr<NPC> orc = make_shared<Orc>(Coord<int>(1, 1));
    shared_ptr<NPC> orc1 = make_shared<Orc>(Coord<int>(2, 2));
    shared_ptr<NPC> slaver = make_shared<Slaver>(Coord<int>(3, 3));
    shared_ptr<NPC> druid = make_shared<Druid>(Coord<int>(5, 5));

    ASSERT_TRUE(orc->fight(*orc1));
    ASSERT_FALSE(orc->fight(*slaver));
    ASSERT_FALSE(orc->fight(*druid));

}

TEST(visitor_pattern, slaver){
    FightVisitor visitor;

    shared_ptr<NPC> orc = make_shared<Orc>(Coord<int>(1, 1));
    shared_ptr<NPC> slaver = make_shared<Slaver>(Coord<int>(3, 3));
    shared_ptr<NPC> slaver1 = make_shared<Slaver>(Coord<int>(4, 4));
    shared_ptr<NPC> druid = make_shared<Druid>(Coord<int>(5, 5));

    ASSERT_TRUE(slaver->fight(*orc));
    ASSERT_FALSE(slaver->fight(*slaver1));
    ASSERT_FALSE(slaver->fight(*druid));
}

TEST(visitor_pattern, druid){

    FightVisitor visitor;

    shared_ptr<NPC> orc = make_shared<Orc>(Coord<int>(1, 1));
    shared_ptr<NPC> slaver = make_shared<Slaver>(Coord<int>(3, 3));
    shared_ptr<NPC> druid = make_shared<Druid>(Coord<int>(5, 5));
    shared_ptr<NPC> druid1 = make_shared<Druid>(Coord<int>(6, 6));

    ASSERT_TRUE(druid->fight(*orc));
    ASSERT_TRUE(druid->fight(*slaver));
    ASSERT_FALSE(druid->fight(*druid1));
}

TEST(observer_pattern, screen_observer) {
    shared_ptr<NPC> attacker = make_shared<Orc>(Coord<int>(1, 1));
    shared_ptr<NPC> defender = make_shared<Slaver>(Coord<int>(3, 3));
    shared_ptr<IObserver> observer = ScreenObserver::get();
    
    testing::internal::CaptureStdout();
    observer->update(*attacker, *defender, true);
    string output = testing::internal::GetCapturedStdout();
    
    ASSERT_EQ(output, "\nMurder --------\nKiller: orc: (x: 1; y: 1) \nVictim: slaver: (x: 3; y: 3) \n");
}

TEST(observer_pattern, file_observer) {
    shared_ptr<NPC> attacker = make_shared<Orc>(Coord<int>(1, 1));
    shared_ptr<NPC> defender = make_shared<Slaver>(Coord<int>(3, 3));
    string filename = "log.txt";
    shared_ptr<IObserver> observer = FileObserver::get(filename);
    
    observer->update(*attacker, *defender, true);

    ifstream file(filename);
    string content((istreambuf_iterator<char>(file)),
                        istreambuf_iterator<char>());
    file.close();
    ASSERT_TRUE(content.find("Murder --------") != string::npos);
    ASSERT_TRUE(content.find("Killer: orc: (x: 1; y: 1)") != string::npos);
    ASSERT_TRUE(content.find("Victim: slaver: (x: 3; y: 3)") != string::npos);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 