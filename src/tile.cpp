#include "tile.h"

//get position
coords tile::get_pos() {
	return position;
}
//set new position
void tile::set_pos(coords pos_p) {
	position = pos_p;
}

tile::tile(int id_p, coords pos_p):id(id_p),position(pos_p) {

}
//default constructor
tile::tile() {
	position = coords(0, 0);
	id = 0;
}