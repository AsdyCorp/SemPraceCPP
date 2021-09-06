#include "player.h"

#include "object_manager.h"

player::player(int id_p, int hp_p, coords coords_p, int sp_p): living_creature(id_p,hp_p,coords_p),sp(sp_p) {

}

//attack goblins
void player::attack() {
	int dist; //distance to enemy
	for (int i = 0; i < (int)obj_manager->enemies.size(); i++) {
		dist = sqrt(
			(obj_manager->enemies[i]->get_pos().x - position.x) * (obj_manager->enemies[i]->get_pos().x - position.x) +
			(obj_manager->enemies[i]->get_pos().y - position.y) * (obj_manager->enemies[i]->get_pos().y - position.y)
		);
		if (dist <= 2) {
			obj_manager->enemies[0]->damage(3);
		}
	}
}
//add key to inventory
void player::find_key() {
	for (int i = 0; i < (int)obj_manager->keys.size(); i++) {
		if (position.x==obj_manager->keys[i].position.x && position.y == obj_manager->keys[i].position.y){
			obj_manager->keys.erase(obj_manager->keys.begin() + i);
			set_sp(get_sp()+1);
			std::cout << "You finded key." << std::endl;
		}
	}
}


//collison check
bool player::collision_detection() {
	//map size check
	if (position.x + velocity.x < 0 ||
		position.x + velocity.x >= (obj_manager->w) ||
		position.y + velocity.y<0 ||
		position.y + velocity.y>=(obj_manager->h)) {
		return true;
	}
	//tile detection check
	for (int i = 0; i < (int)collision_group.size(); i++) {
		if (obj_manager->map_tiles[position.x + velocity.x][position.y + velocity.y].id == collision_group[i]) {
			return true;
		}
	}
	//enemies detection check
	for (int i = 0; i < (int)obj_manager->enemies.size(); i++) {
		if (position.x + velocity.x == obj_manager->enemies[i]->get_pos().x &&
			position.y + velocity.y == obj_manager->enemies[i]->get_pos().y) {
			return true;
		}
	}
	return false;

}
//set key count
void player::set_sp(int sp_p) {
	sp = sp_p;
}
//get key count
int player::get_sp() {
	return sp;
}
//update state
void player::update() {
	find_key();
	if (collision_detection() == false) {
		position = coords(position.x + velocity.x, position.y + velocity.y);
	}
	velocity.x = 0;
	velocity.y = 0;
	
}
//create save frame
std::string player::save_data() {
	std::string save_data_frame;
	save_data_frame.append(std::to_string(id));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(hp));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(position.x));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(position.y));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(sp));
	return save_data_frame;
}