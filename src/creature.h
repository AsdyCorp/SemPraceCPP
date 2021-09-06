#pragma once
#include "coords.h"
#include <vector>
#include <string>


class object_manager;
/// <summary>
/// Base parent class creature
/// </summary>
class creature
{
public:
	/// <summary>
	/// velocity of moving creature - direction for next step
	/// </summary>
	coords velocity;
	/// <summary>
	/// global uniq id for object manager manipulation 
	/// </summary>
	static int next_id;
	
	/// <summary>
	/// object manager pointer for in game navigation and interactino
	/// </summary>
	object_manager* obj_manager;
	/// <summary>
	/// collision group vector - universal blocks of non impassable tiles - uses in collision_detecton()
	/// </summary>
	std::vector<int> collision_group = { 0 };

	/// <summary>
	/// get position of object
	/// </summary>
	/// <returns>coordinate coords</returns>
	coords get_pos();
	/// <summary>
	/// set new position
	/// </summary>
	void set_pos(coords pos_to_set);
	/// <summary>
	/// update state of object 
	/// </summary>
	virtual void update() = 0;
	/// <summary>
	/// returns id of object(save file id)
	/// </summary>

	int get_id();
	/// <summary>
	/// returns uniq id of object(object manager id)
	/// </summary>
	int get_global_id();
	/// <summary>
	/// create save-state for game saving
	/// </summary>
	virtual std::string save_data()=0;
	
	creature(int id_p,  coords coords_p);
	creature();
	~creature();
private:

protected:
	int id;
	/// <summary>
	/// check if position+velocity coordinate after update collides with something
	/// </summary>
	/// <returns>returns true if collision happenes</returns>
	virtual bool collision_detection() = 0;
	
	int uniq_id; 
	/// <summary>
	/// position of object
	/// </summary>
	coords position;
	/// <summary>
	/// map for collsiion detection
	/// </summary>
	std::vector<std::vector<int>> map;
	/// <summary>
	/// navigation alghoritm - uses Lee alghoritm
	/// </summary>
	/// <param name="finish_point">finish point in path finding</param>
	/// <returns>direction for next step on path to founded object</returns>
	coords find_path(coords finish_point);
};
