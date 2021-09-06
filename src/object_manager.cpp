#include "object_manager.h"

object_manager::object_manager() {
	
}
object_manager::~object_manager() {
	
	all_objects.clear();
	
	enemies.clear();
	
	players.clear();
	
	fires.clear();
	
	exits_point.clear();
	std::vector<exit_point*>().swap(exits_point);
	std::vector<enemy*>().swap(enemies);
	std::vector<std::vector<tile>>().swap(map_tiles);
}
//exit game without errors
void object_manager::exit_game() {
	exit(0);
}

//create fire
void object_manager::create_unit(int id_p,coords coords_p) {
	fire* temp = new fire(id_p, coords_p);
	temp->obj_manager = this;
	all_objects.push_back(temp);
	fires.push_back(temp);
}


///exit_points
void object_manager::create_unit(int id_p,  coords coords_p, int sp_points_p) {
	exit_point* temp = new exit_point(id_p, coords_p, sp_points_p);
	temp->obj_manager = this;
	all_objects.push_back(temp);
	exits_point.push_back(temp);
}

//create goblin
void object_manager::create_unit(int id_p, int hp_p, coords coords_p) {
	enemy* temp = new enemy(id_p, hp_p, coords_p);
	temp->obj_manager = this;
	all_objects.push_back(temp);
	enemies.push_back(temp);
}

//player creation
void object_manager::create_unit(int id_p, int hp_p, coords coords_p, int sp_p) {
	if ((int)players.size() > 0) {
		std::cout << "Error in player creating, maybe save file corrupted. Player already exists. Please check savefile and restart game." << std::endl;
		exit(1);
	}

	player* temp = new player(id_p, hp_p, coords_p, sp_p);
	temp->obj_manager = this;
	
	all_objects.push_back(temp);
	players.push_back(temp);
}
//show player's coordinates
void object_manager::show_list_of_players() {
	for (int i = 0; i < (int)players.size(); i++) {
		std::cout <<"uniqal id "<< players[i]->get_global_id()<<" object id:"<<players[i]->get_id()<<std::endl;
	}
}
//show enemie's coordinates
void object_manager::show_list_of_enemies() {
	for (int i = 0; i < (int)enemies.size(); i++) {
		std::cout << "uniqal id " << enemies[i]->get_global_id() << " object id:" << enemies[i]->get_id() << std::endl;
	}
}
//show object's coordinates
void object_manager::show_list_of_all_objects() {
	for (int i = 0; i < (int)all_objects.size(); i++) {
		std::cout << "uniqal id " << all_objects[i]->get_global_id() << " object id:" << all_objects[i]->get_id() << " coords: "<<all_objects[i]->get_pos()<<std::endl;
		std::cout << all_objects[i]->obj_manager->map_tiles[i][i].id;
	}
}

//get id by position
int object_manager::get_id_by_coord(coords pos_p1) {
	for (int i = 0; i < (int)all_objects.size(); i++) {

		if (((all_objects[i]->get_pos().x) == pos_p1.x) && ((all_objects[i]->get_pos().y) == pos_p1.y)) {
			return all_objects[i]->get_id();
			
		}
		
	}
	return -1;
}