#include "exit_point.h"
#include "object_manager.h"

exit_point::exit_point(int id_p, coords coords_p, int sp_points_p) :non_living_creature(id_p,coords_p),sp_points(sp_points_p) {

}
// set keys number
void exit_point::set_sp_points(int sp_points_p) {
	sp_points = sp_points_p;
}
//get keys number
int exit_point::get_sp_points() {
	return sp_points;
}
//collision detection
bool exit_point::collision_detection() {
	return false;
}
void exit_point::update() {

}
//save data
std::string exit_point::save_data() {
	std::string save_data_frame;
	save_data_frame.append(std::to_string(id));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(position.x));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(position.y));
	save_data_frame.append(" ");
	save_data_frame.append(std::to_string(sp_points));
	return save_data_frame;
}