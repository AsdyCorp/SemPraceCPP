#pragma once
#include <vector>
#include "player.h"
#include "exit_point.h"
#include <string>
#include <fstream>
#include <iostream>
#include "tile.h"
#include "enemy.h"
#include "fire.h"
#include <ctime>
#include "char_decoder.h"

class creature;

/// <summary>
/// struct for key object - contains position of key on map
/// </summary>
struct key {
	coords position;
	key(coords pos_p) :position(pos_p) {}
};

/// <summary>
/// main game loop manager - contains, creates, deletes all entities. Save and load game
/// </summary>
class  object_manager{
public:

	/// <summary>
	/// all keys on map
	/// </summary>
	std::vector<key> keys;
	/// <summary>
	/// map tiles - loaded from file
	/// </summary>
	std::vector<std::vector<tile>> map_tiles;
	int w;//width of map
	int h;//height of map
	std::string map_name;//map name
	/// <summary>
	/// all creatures container
	/// </summary>
	std::vector<creature*> all_objects;
	/// <summary>
	/// all players container
	/// </summary>
	std::vector<player*>  players;
	/// <summary>
	/// all goblins container
	/// </summary>
	std::vector<enemy*>  enemies;
	/// <summary>
	/// all fires container
	/// </summary>
	std::vector<fire*> fires;
	/// <summary>
	/// all exit points container
	/// </summary>
	std::vector<exit_point*> exits_point;

	/// <summary>
	/// instantiate fire
	/// </summary>
	void create_unit(int id_p, coords coords_p);//fire
	/// <summary>
	/// instantiate goblin
	/// </summary>
	void create_unit(int id_p, int hp_p, coords coords_p);//enemy
	/// <summary>
	/// instantiate exit
	/// </summary>
	void create_unit(int id_p, coords coords_p, int sp_points);//exit points
	/// <summary>
	/// instantiate player
	/// </summary>
	void create_unit(int id_p, int hp_p, coords coords_p, int sp_p);//player

	 
	object_manager();
	~object_manager();

	/// <summary>
	/// laod map by name
	/// </summary>
	void load_map(std::string name);
	/// <summary>
	/// save game as save_file+epochtime
	/// </summary>
	void save_game();
	/// <summary>
	/// show map and creatures on map
	/// </summary>
	void Render();
	/// <summary>
	/// show info about player
	/// </summary>
	void show_info();
	/// <summary>
	/// get id of object on given coordinate
	/// </summary>
	int get_id_by_coord(coords pos_p);
	/// <summary>
	/// input handler function, check and parse input of player 
	/// </summary>
	void input_handler();
	/// <summary>
	/// clean screen function - called after every input
	/// </summary>
	void Clear_screen();

	/// <summary>
	/// delete goblin if it was killed
	/// </summary>
	void delete_unit(int uniq_id);
	/// <summary>
	/// check if hp of goblin <=0 and called delete_unit()
	/// </summary>
	void check_hp();
	/// <summary>
	/// generate keys on free spaces on map
	/// </summary>
	void generate_keys(int count);

	/// <summary>
	/// debug function - shows all player's coordinates on map
	/// </summary>
	void show_list_of_players();
	/// <summary>
	/// debug function - shows all goblin's coordinates on map
	/// </summary>
	void show_list_of_enemies();
	/// <summary>
	/// debug function - shows all object's coordinates on map
	/// </summary>
	void show_list_of_all_objects();
private:
	/// <summary>
	/// checks if player was killed or enter the gate and exit_game
	/// </summary>
	void check_game_end();
	/// <summary>
	/// exit game function
	/// </summary>
	void exit_game();
	
};




