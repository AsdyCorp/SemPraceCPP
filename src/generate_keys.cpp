#include "object_manager.h"

//generate keys randomly
void object_manager::generate_keys(int count) {
	int keys_remaining=count; 
	bool free_tile = true;
	srand((unsigned)time(0));
	while (keys_remaining >0) {
		free_tile = true;
		int x =  1+(rand() % (w-3));
		int y =  1+(rand() % (h-3));
		for (int i = 0; i < (int)players[0]->collision_group.size(); i++) {
			if (map_tiles[x][y].id == players[0]->collision_group[i]) {
				free_tile = false;
				break;
			}
		}
		for (int i = 0; i < (int)keys.size(); i++) {
			if (keys[i].position.x == x && keys[i].position.y == y) {
				free_tile = false;
			}
		}
		if (free_tile == true) {
			keys.push_back(key(coords(x, y)));
			keys_remaining--;
		}

	}

}