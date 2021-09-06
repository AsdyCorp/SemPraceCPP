#pragma once

#include "living_creature.h"
class object_manager;
/// <summary>
/// enemy object - goblin - inheritance after living creature
/// </summary>
class enemy :public living_creature {
public:
	/// <summary>
	/// goblin constructor - from object manager
	/// </summary>
	enemy(int id_p, int hp_p, coords coords_p);
	/// <summary>
	/// update state
	/// </summary>
	void update() override;
	/// <summary>
	/// attack player on next tile
	/// </summary>
	void attack() override;
	/// <summary>
	/// create save-state for game saving
	/// </summary>
	std::string save_data() override;
private:
	/// <summary>
	/// collision detection
	/// </summary>
	/// <returns>true if collision happend</returns>
	bool collision_detection() override;
};