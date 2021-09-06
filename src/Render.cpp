#include "object_manager.h"

///clear screen
void object_manager::Clear_screen() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

//show info about player
void object_manager::show_info() {
	std::cout << std::endl;
	std::cout << "Player's coordinates: " << players[0]->get_pos() << std::endl;
	std::cout << "Health = " << players[0]->get_hp() << std::endl;
	std::cout << "Number of keys collected = " << players[0]->get_sp() << std::endl;
	std::cout << "Number of keys remaining = " << exits_point[0]->get_sp_points() << std::endl;
}

//render map
void object_manager::Render() {
	Clear_screen();
	char temp;
	int temp_id;
	coords temp_coords;
	coords player_pos;
	coords last_saved_position;

	int dist=10; 
	//check if only one player exists
	if ((int)players.size() != 1) {
		std::cout << "Error in player's position read. zero or more player's entities finded." << std::endl;
		exit(1);
	}

	player_pos = coords(players[0]->get_pos().x, players[0]->get_pos().y);

	//check if near corner
	if (player_pos.x - dist >= 0 && player_pos.x + dist < w) {
		last_saved_position.x=player_pos.x;
	}
	else {
		if (player_pos.x - dist < 0) {
			last_saved_position.x = dist;
		}
		if (player_pos.x + dist > w-1) {
			last_saved_position.x = w-dist;
		}
	}
	if (player_pos.y - dist >= 0 && player_pos.y + dist < h) {
		last_saved_position.y = player_pos.y;
	}
	else {
		if (player_pos.y - dist < 0) {
			last_saved_position.y = dist;
		}
		if (player_pos.y + dist > h - 1) {
			last_saved_position.y = h - dist;
		}
	}
	//upper border draw
	for (int i = 0; i<1+ dist * 2; i++) {
		std::cout << '_';
	}

	std::cout << std::endl;
	//render tiles -> entites ->keys
	for (int i = last_saved_position.x - dist; i < last_saved_position.x + dist-1; i++) {
		std::cout << '|';
		for (int j = last_saved_position.y - dist; j < last_saved_position.y + dist-1; j++) {
			temp_coords.x = i;
			temp_coords.y = j;
			temp = get_char_icon(map_tiles[i][j].id);

			temp_id = get_id_by_coord(temp_coords);
			if (temp_id != -1) {
				temp = get_char_icon(temp_id);
			}
			for (int k_j = 0; k_j < (int)keys.size(); k_j++) {
				if (i == keys[k_j].position.x && j == keys[k_j].position.y) {
					temp = get_char_icon(99);
				}
			}
			std::cout << temp;
		}
		std::cout << '|' << std::endl; //
	}
	last_saved_position = player_pos;
	
	for (int i = 0; i < 1 + dist * 2; i++) {
		std::cout << '-';
	}
	show_info();

}