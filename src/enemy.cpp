#include "enemy.h"
#include "object_manager.h"
enemy::enemy(int id_p, int hp_p, coords coords_p) :living_creature(id_p, hp_p, coords_p){

}
//attack player
void enemy::attack() {
	obj_manager->players[0]->damage(1);
}



void enemy::update() {
	int dist; //distance to player
	dist = sqrt(
		(obj_manager->players[0]->get_pos().x - position.x) * (obj_manager->players[0]->get_pos().x - position.x) +
		(obj_manager->players[0]->get_pos().y - position.y) * (obj_manager->players[0]->get_pos().y - position.y)
	);
	if (abs(dist>1) && abs(dist)<8) {
		coords temp = find_path(obj_manager->players[0]->get_pos());
		velocity.x = temp.x - position.x;
		velocity.y = temp.y - position.y;
	}
	//move goblin
	if (collision_detection() == false) {
		position = coords(position.x + velocity.x, position.y + velocity.y);
	}
	//attack
	if (abs(dist) <= 2) {
		attack();
	}

}

bool enemy::collision_detection() {
	//map size detection check
	if (position.x + velocity.x < 0 ||
		position.x + velocity.x >= (obj_manager->w) ||
		position.y + velocity.y < 0 ||
		position.y + velocity.y >= (obj_manager->h)) {
		return true;
	}
	//tile detection check
	for (int i = 0; i < (int)collision_group.size(); i++) {
		if (obj_manager->map_tiles[position.x + velocity.x][position.y + velocity.y].id == collision_group[i]) {
			return true;
		}
	}
	//player detection check
	for (int i = 0; i < (int)obj_manager->players.size(); i++) {
		if (position.x + velocity.x == obj_manager->players[i]->get_pos().x &&
			position.y + velocity.y == obj_manager->players[i]->get_pos().y) {
			return true;
		}
	}
	//other goblin detection check
	for (int i = 0; i < (int)obj_manager->enemies.size(); i++) {
		if (position.x + velocity.x == obj_manager->enemies[i]->get_pos().x &&
			position.y + velocity.y == obj_manager->enemies[i]->get_pos().y) {
			return true;
		}
	}

	return false;
}
//save data
std::string enemy::save_data() {
	std::string save_data_frame;
	save_data_frame.append(std::to_string(id));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(hp));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(position.x));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(position.y));
	return save_data_frame;
}