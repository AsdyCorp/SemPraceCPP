#pragma once

#include "non_living_creature.h"
class object_manager;
/// <summary>
/// Exit point object - inheritance from the non_living_creature
/// readed from save file and instatiated by object manager
/// </summary>
class exit_point:public non_living_creature{
public:
	/// <summary>
	/// exit point constructor
	/// </summary>
	/// <param name="id_p">id from save file - 102 for exit</param>
	/// <param name="coords_p">coordinates from save file</param>
	/// <param name="sp_points_p">keys needed - from save file</param>
	/// <returns></returns>
	exit_point(int id_p, coords coords_p,int sp_points_p);
	/// <summary>
	/// change keys needed for exit
	/// </summary>
	void set_sp_points(int sp_points_p);
	/// <summary>
	/// return needed keys number from exit object
	/// </summary>
	int get_sp_points();
	/// <summary>
	/// update state of object
	/// </summary>
	void update() override;
	/// <summary>
	/// returns string-state about object for game saver 
	/// </summary>
	/// <returns>string id coords sp_p</returns>
	std::string save_data() override;
private :
	int sp_points;
	/// <summary>
	/// check if position+velocity coordinate after update collides with something
	/// </summary>
	/// <returns>returns true if collision happenes</returns>
	bool collision_detection() override;
};