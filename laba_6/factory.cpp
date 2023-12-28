#include "./include/factory.h"
#include "./include/observer.h"

// shared_ptr<NPC> NPC_Factory::create_npc(NpcType type, Coord<int> &c){
// 	shared_ptr<NPC> new_npc;
// 	new_npc = make_shared<NPC>(type, c);
// 	return new_npc;
// }

// shared_ptr<NPC> NPC_Factory::create_npc(NpcType type, int x, int y){
// 	shared_ptr<NPC> new_npc;
// 	new_npc = make_shared<NPC>(type, x, y);
// 	return new_npc;
// }

shared_ptr<NPC> NPC_Factory::create_npc(NpcType type, const Coord<int> &c){
	shared_ptr<NPC> new_npc;
	switch(type){
		case 1:
			new_npc=make_shared<Slaver>(c);
			break;
		case 2:
			new_npc=make_shared<Druid>(c);	
			break;
		case 3:
			new_npc=make_shared<Orc>(c);
			break;
		default:
			throw logic_error("uncorrect type");
			break;
	}
	if(new_npc){
        new_npc->subscribe(ScreenObserver::get());
        new_npc->subscribe(FileObserver::get("log.txt"));
    }
	return new_npc;
}

shared_ptr<NPC> NPC_Factory::create_npc(NpcType type, int x, int y){
	shared_ptr<NPC> new_npc;
	switch(type){
		case 1:
			new_npc=make_shared<Slaver>(x, y);
			break;
		case 2:
			new_npc=make_shared<Druid>(x, y);	
			break;
		case 3:
			new_npc=make_shared<Orc>(x, y);
			break;
		default:
			throw logic_error("uncorrect type");
			break;
	}
	if(new_npc){
        new_npc->subscribe(ScreenObserver::get());
        new_npc->subscribe(FileObserver::get("log.txt"));
    }
	return new_npc;
}

