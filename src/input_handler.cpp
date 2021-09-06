#include "object_manager.h"

void object_manager::input_handler() {
	char input_char;
	std::string input_string;
	std::string helper_dummy_string;
	check_game_end();//check if game ended
	std::cin >> input_string;
	//if more than 1 letter input
	while ((int)input_string.size() != 1) {
		
			std::cout << "Error. Please, use one letter comands. For help type 'h'" << std::endl;
			input_char = '!';
			std::cin >> input_string;
	}
	
	input_char = input_string[0];
	
	switch (input_char)
	{
	case 'w':
		players[0]->velocity.x=-1; //move up
		players[0]->velocity.y=0;
		break;
	case 'a':
		players[0]->velocity.x = 0; //move left
		players[0]->velocity.y = -1;
		break;
	case 's':
		players[0]->velocity.x = 1; //move down
		players[0]->velocity.y = 0;
		break;
	case 'd':
		players[0]->velocity.x = 0; //move right
		players[0]->velocity.y = 1;
		break;
	case 'e':
		players[0]->attack(); //attack
		break;
	case 'p':
		save_game(); //save 
		break;
	case 'q':
		exit_game(); //exit
		break;
	case 'h': //help
		std::cout << "Collect all the keys and get out of the burning forest! Beware of goblins!" << std::endl;
		std::cout << "Icons: P - player, G - goblin, # - exit, K - key, F - fire, ~ - water(impassable)" << std::endl;
		std::cout << "Commands: w a s d - movement, q - exit, e - attack, h - help, p - save game" << std::endl;
		std::cin >> helper_dummy_string;

		while ((int)helper_dummy_string.size() != 1) { //wait for input

			std::cout << "Error. Please, use one letter comands. For help type 'h'" << std::endl;
			input_char = '!';
			std::cin >> helper_dummy_string;
		}
		break;
	default:
		break;
	}

	for (int i = 0; i < (int)all_objects.size(); i++) { //update all objects
		all_objects[i]->update();
		
	}
	//std::cout << input_char << std::endl;

}