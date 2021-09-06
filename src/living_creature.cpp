#include "living_creature.h"

//damage creature
void living_creature::damage(int damage_p) {
	hp -= damage_p;
}
//get hp
int living_creature::get_hp() {
	return hp;
}

living_creature::living_creature(int id_p, int hp_p, coords coords_p) :creature(id_p,  coords_p),hp(hp_p) {

}

