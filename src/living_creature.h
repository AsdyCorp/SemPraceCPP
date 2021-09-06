#pragma once

#include "creature.h"
/// <summary>
/// living creature - inhritance after creature - can be killed
/// </summary>
class living_creature:public creature {
public:
	/// <summary>
	/// get hp of living creature
	/// </summary>
	/// <returns>number of hp in int</returns>
	int get_hp();
	/// <summary>
	/// make damage to this creature
	/// </summary>
	/// <param name="damage_p">strength of damage</param>
	void damage(int damage_p);
	/// <summary>
	/// create string-state for save file function
	/// </summary>
	/// <returns>string of data</returns>
	virtual std::string save_data() = 0;
	living_creature();
	/// <summary>
	/// constructor -object instantiated by object manager(from file)
	/// </summary>
	/// <param name="id_p">id of creature </param>
	/// <param name="hp_p">hp of creatur</param>
	/// <param name="coords_p">coordinates</param>
	/// <returns></returns>
	living_creature(int id_p, int hp_p, coords coords_p);
	/// <summary>
	/// update state of creature
	/// </summary>
	virtual void update() = 0;
	/// <summary>
	/// attack nearest creture - player by goblin or goblin by player
	/// </summary>
	virtual void attack() = 0;
protected:
	int hp;
	/// <summary>
	/// collision detection
	/// </summary>
	/// <returns>true if collision happened</returns>
	virtual bool collision_detection() = 0;
};