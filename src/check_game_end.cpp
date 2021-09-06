#include "object_manager.h"



void object_manager::check_game_end() {
	char dummy;
	//if player died
	if (players[0]->get_hp() <= 0) {
		Clear_screen();
		std::cout << "YOU DIED!" << std::endl;
		std::cout << "number of keys collected: " << players[0]->get_sp() << std::endl;
		std::cout << "press q to exit." << std::endl;
		std::cin >> dummy;
		exit(0);
	}
	
	//if there are no exit on map
	if (exits_point.size()<1) {
		std::cout << "error occured. game session has no valid exit point. check save file" << std::endl;
		exit(1);
	}
	/// <summary>
	/// if player wins
	/// </summary>
	for(int i=0; i<(int)exits_point.size(); i++){
		if (exits_point[i]->get_pos().x == players[0]->get_pos().x && exits_point[i]->get_pos().y == players[0]->get_pos().y) {
			if (exits_point[i]->get_sp_points() <= players[0]->get_sp()) {
				Clear_screen();
				std::cout << "YOU WIN!" << std::endl;
				std::cout << "number of keys collected: " << players[0]->get_sp() << std::endl;
				std::cout << "press q to exit." << std::endl;
				std::cin >> dummy;
				save_game();
				exit(0);
			}
		}
	}
	
	
}