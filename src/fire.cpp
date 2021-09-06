
#include "fire.h"
#include "object_manager.h"

//collsion detection
bool fire::collision_detection() {
	//map size detection check
	if (position.x + velocity.x < 0 ||
		position.x + velocity.x >= (obj_manager->w) ||
		position.y + velocity.y < 0 ||
		position.y + velocity.y >= (obj_manager->h)) {
		return true;
	}
	//other fires
	for (int i = 0; i < (int)obj_manager->fires.size(); i++) {
		if (position.x + velocity.x == obj_manager->fires[i]->get_pos().x && position.y + velocity.y == obj_manager->fires[i]->get_pos().y) {
			return true;
		}
	}
	//tiles
	for (int i = 0; i < (int)collision_group.size(); i++) {
		if (obj_manager->map_tiles[position.x + velocity.x][position.y + velocity.y].id == collision_group[i]) {
			return true;
		}
	}
	return false;
}
//make damage to goblin and player by position
void fire::make_damage() {
	for (int i = 0; i < (int)obj_manager->enemies.size(); i++) {
		if (obj_manager->enemies[i]->get_pos().x == position.x && obj_manager->enemies[i]->get_pos().y == position.y) {
			obj_manager->enemies[i]->damage(1);
		}
	}
	for (int i = 0; i < (int)obj_manager->players.size(); i++) {
		if (obj_manager->players[i]->get_pos().x == position.x && obj_manager->players[i]->get_pos().y == position.y) {
			obj_manager->players[i]->damage(1);
		}
	}
}

fire::fire(int id_p, coords coords_p) :non_living_creature(id_p, coords_p) {

}
//update
void fire::update() {
	int x = 0 + (rand() % 20);
	if (x == 2) {
		make_fire();
	}
	make_damage();
}
//save data
std::string fire::save_data() {
	std::string save_data_frame;
	save_data_frame.append(std::to_string(id));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(position.x));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(position.y));
	return save_data_frame;
}
//instantiate fire
void fire::make_fire_instance(coords pos_p){
	obj_manager->create_unit(103, pos_p);
}
//check if possible to instantiate fire
void fire::make_fire() {
	velocity = coords(-1, 0);
	if (collision_detection() == false)
	make_fire_instance(coords(position.x + velocity.x, position.y + velocity.y));
	velocity = coords(0, -1);
	if (collision_detection() == false)
	make_fire_instance(coords(position.x + velocity.x, position.y + velocity.y));
	velocity = coords(0, 1);
	if (collision_detection() == false)
	make_fire_instance(coords(position.x + velocity.x, position.y + velocity.y));
	velocity = coords(1, 0);
	if (collision_detection() == false)
	make_fire_instance(coords(position.x + velocity.x, position.y + velocity.y));
}