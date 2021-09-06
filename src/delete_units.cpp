#include "object_manager.h"


//delete goblins from vectors
void object_manager::delete_unit(int uniq_id) {
	for (int i = 0; i < (int)enemies.size(); i++) {
		if (enemies[i]->get_global_id() == uniq_id) {
			enemies.erase(enemies.begin() + i);
			break;
		}
	}
	enemies.shrink_to_fit();

	for (int i = 0; i < (int)all_objects.size(); i++) {
		if (all_objects[i]->get_global_id() == uniq_id) {
			delete all_objects[i];
			all_objects.erase(all_objects.begin() + i);
			break;
		}
	}
	all_objects.shrink_to_fit();
	
	
}
//check all goblins hp
void object_manager::check_hp() {

	for (int i = 0; i < (int)enemies.size(); i++) {
		if (enemies[i]->get_hp() <= 0) {
			delete_unit(enemies[i]->get_global_id());
		}
	}
}