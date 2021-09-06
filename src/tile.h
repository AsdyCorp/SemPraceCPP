#pragma once
#include "coords.h"
/// <summary>
/// tile object
/// </summary>
class tile {
public:
	/// <summary>
	/// id of tile - from save file
	/// </summary>
	int id;
	/// <summary>
	/// get coordinates of tile on map
	/// </summary>
	coords get_pos();
	/// <summary>
	/// change coordinates of tile on map
	/// </summary>
	void set_pos(coords pos_p);
	tile(int id_p,coords pos_p);
	tile();

protected:
	coords position;
};