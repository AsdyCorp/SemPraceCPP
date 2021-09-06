#pragma once


#include "living_creature.h"
class object_manager;
/// <summary>
/// player object
/// </summary>
class player:public living_creature {

public: 
	/// <summary>
	/// change player's keys in inventory
	/// </summary>
	void set_sp(int sp_p);
	/// <summary>
	/// get player's keys in inventory
	/// </summary>
	/// <returns></returns>
	int get_sp();
	
	player(int id_p, int hp_p, coords coords_p, int sp_p);
	/// <summary>
	/// update state
	/// </summary>
	void update() override;
	/// <summary>
	/// attack goblins near
	/// </summary>
	void attack() override;
	/// <summary>
	/// create save-state for game saving
	/// </summary>
	std::string save_data() override;
private:
	int sp;
	/// <summary>
	/// checks if player founded key
	/// </summary>
	void find_key();

	/// <summary>
	/// collision detection
	/// </summary>
	/// <returns>true if collsion happened</returns>
	bool collision_detection() override;
};