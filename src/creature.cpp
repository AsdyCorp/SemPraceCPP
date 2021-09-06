#include "creature.h"
#include "object_manager.h"
#include <iomanip>
int creature::next_id = 0;


coords creature::find_path(coords finish_point) {
	//8 directions around given point
	std::vector<coords > all_ways;
	//8 directions around given point
	std::vector<coords > player_round;
	coords next_return_step;
	coords current_return_step;
	int d = 0;//weght
	bool next_cell_exists=false;
	bool path_finded=false;
	map.clear();//clear weight map

	map.resize(obj_manager->w);
	for (int i = 0; i < obj_manager->w; i++)
		map[i].resize(obj_manager->h);

	///create wave 
	for (int i = 0; i < obj_manager->w; i++) {
		for (int j = 0; j < obj_manager->h; j++) {
			for (int g = 0; g < (int)obj_manager->all_objects.size(); g++) {
				map[i][j] = -1;
				if (obj_manager->all_objects[g]->get_pos().x == i && obj_manager->all_objects[g]->get_pos().y == j) {
					map[i][j] = -2;
					break;
				}
			}
			for (int g = 0; g < (int)collision_group.size(); g++) {
				if (obj_manager->map_tiles[i][j].id == collision_group[g]) {
					map[i][j] = -3;
					break;

				}
			}
		}
	}

	map[position.x][position.y] = 0;
	//write all 8 directions around point
	current_return_step = finish_point;
	player_round.clear();
	if (current_return_step.x > 0) { player_round.push_back(coords(current_return_step.x - 1, current_return_step.y)); } //up
	if (current_return_step.y > 0) { player_round.push_back(coords(current_return_step.x, current_return_step.y - 1)); } //left

	if (current_return_step.y < obj_manager->h - 1) { player_round.push_back(coords(current_return_step.x, current_return_step.y + 1)); } //right
	if (current_return_step.x < obj_manager->w - 1) { player_round.push_back(coords(current_return_step.x + 1, current_return_step.y)); } //down 

	if (current_return_step.x > 0 && current_return_step.y > 0) { player_round.push_back(coords(current_return_step.x - 1, current_return_step.y - 1)); } //left corner up
	if (current_return_step.x > 0 && current_return_step.y < obj_manager->h - 1) { player_round.push_back(coords(current_return_step.x - 1, current_return_step.y + 1)); } //right corner up

	if (current_return_step.x < obj_manager->w - 1 && current_return_step.y > 0) { player_round.push_back(coords(current_return_step.x + 1, current_return_step.y - 1)); }//left corner down
	if (current_return_step.x < obj_manager->w - 1 && current_return_step.y < obj_manager->h - 1) { player_round.push_back(coords(current_return_step.x + 1, current_return_step.y + 1)); }  //right corner down

	
	///create wave 
	while (true) {
		for (int i = 0; i <(int) player_round.size(); i++) {
			if (map[player_round[i].x][player_round[i].y] > 0) {
				path_finded = true;
			}
		}
		if (path_finded == true) {
			break;
		}
		next_cell_exists = false;
		for (int i = 0; i < obj_manager->w; i++) {
			for (int j = 0; j < obj_manager->h; j++) {
				if (map[i][j] == d) {
					current_return_step = coords(i,j);
					all_ways.clear();
					if (current_return_step.x > 0) { all_ways.push_back(coords(current_return_step.x - 1, current_return_step.y)); } //up
					if (current_return_step.y > 0) { all_ways.push_back(coords(current_return_step.x, current_return_step.y - 1)); } //left

					if (current_return_step.y < obj_manager->h - 1) { all_ways.push_back(coords(current_return_step.x, current_return_step.y + 1)); } //right
					if (current_return_step.x < obj_manager->w - 1) { all_ways.push_back(coords(current_return_step.x + 1, current_return_step.y)); } //down 

					if (current_return_step.x > 0 && current_return_step.y > 0) { all_ways.push_back(coords(current_return_step.x - 1, current_return_step.y - 1)); } //left corner up
					if (current_return_step.x > 0 && current_return_step.y < obj_manager->h - 1) { all_ways.push_back(coords(current_return_step.x - 1, current_return_step.y + 1)); } //right corner up

					if (current_return_step.x < obj_manager->w - 1 && current_return_step.y > 0) { all_ways.push_back(coords(current_return_step.x + 1, current_return_step.y - 1)); }//left corner down
					if (current_return_step.x < obj_manager->w - 1 && current_return_step.y < obj_manager->h - 1) { all_ways.push_back(coords(current_return_step.x + 1, current_return_step.y + 1)); }  //right corner down

					for (int u = 0; u < (int)all_ways.size(); u++) {
						if (map[all_ways[u].x][all_ways[u].y] == -1) {
							map[all_ways[u].x][all_ways[u].y] = d + 1;
							next_cell_exists = true;
						}
					}
				}
			}
		}
		if (next_cell_exists == false) {
			break;
		}
		else {
			d++;
		}

	}
	if (path_finded == true) {
		map[finish_point.x][finish_point.y] = d + 1;
		d++;
	}
	else {
		return position;
	}
	//restore backward path
	current_return_step = finish_point;
	for (int i = 0; i < map[finish_point.x][finish_point.y]-1; i++) {
		
		all_ways.clear();
		if (current_return_step.x > 0) { all_ways.push_back(coords(current_return_step.x - 1, current_return_step.y)); } //up
		if (current_return_step.y > 0) { all_ways.push_back(coords(current_return_step.x, current_return_step.y - 1)); } //left

		if (current_return_step.y < obj_manager->h - 1) { all_ways.push_back(coords(current_return_step.x, current_return_step.y + 1)); } //right
		if (current_return_step.x < obj_manager->w - 1) { all_ways.push_back(coords(current_return_step.x + 1, current_return_step.y)); } //down 

		if (current_return_step.x > 0 && current_return_step.y > 0) { all_ways.push_back(coords(current_return_step.x - 1, current_return_step.y - 1)); } //left corner up
		if (current_return_step.x > 0 && current_return_step.y < obj_manager->h - 1) { all_ways.push_back(coords(current_return_step.x - 1, current_return_step.y + 1)); } //right corner up

		if (current_return_step.x < obj_manager->w - 1 && current_return_step.y > 0) { all_ways.push_back(coords(current_return_step.x + 1, current_return_step.y - 1)); }//left corner down
		if (current_return_step.x < obj_manager->w - 1 && current_return_step.y < obj_manager->h - 1) { all_ways.push_back(coords(current_return_step.x + 1, current_return_step.y + 1)); }  //right corner down


		for (int j = 0; j < (int)all_ways.size(); j++) {
			if (map[all_ways[j].x][all_ways[j].y] == d - 1) {
				next_return_step = all_ways[j];
				break;
			}
		}
		d--;
		current_return_step = next_return_step;
	}
	return current_return_step;
}
creature::creature() {
	
}
//get postion
coords creature::get_pos() {
	return position;
}
//set new position
void creature::set_pos(coords pos_to_set) {
	position=coords(pos_to_set.x, pos_to_set.y);
}
//get id
int creature::get_id() {
	return id;
}
//get global id
int creature::get_global_id() {
	return uniq_id;
}
//create uniqal static id of object
creature::creature(int id_p,  coords coords_p) :id(id_p),  position(coords_p) {
	uniq_id = ++next_id;
}

creature::~creature() {
	std::vector<std::vector<int>>().swap(map);

}