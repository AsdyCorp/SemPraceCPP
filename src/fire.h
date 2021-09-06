#pragma once
#include "non_living_creature.h"
class object_manager;


/// <summary>
/// Fire object - inheritance after non_living_creature
/// </summary>
class fire :public non_living_creature {

public:
	/// <summary>
	/// Contructor of fire object. Fire object creates by object_manager from save file or from already instatiated fire 
	/// </summary>
	fire(int id_p, coords coords_p);
	/// <summary>
	/// update fire state. Fire uses random for check if new fire neaded to create.
	/// </summary>
	void update() override;
	/// <summary>
	/// function saving fire instance to save file
	/// </summary>
	/// <returns>string for game saver - id coords</returns>
	std::string save_data() override;
private:
	/// <summary>
	/// Make damage to player or goblin
	/// </summary>
	void make_damage();
	/// <summary>
	/// check every coordinate - up right down left - if it's possible to create fire on new tile
	/// </summary>
	void make_fire();
	/// <summary>
	/// check collision with another fires
	/// </summary>
	/// <returns>true if collision happenes</returns>
	bool collision_detection()override;
	/// <summary>
	/// instantiate fire through object manager
	/// </summary>
	/// <param name="pos_p">coordinate for new fire</param>
	void make_fire_instance(coords pos_p);
};