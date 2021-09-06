#pragma once
#include "creature.h"

/// <summary>
/// exit and fire parent class - inheritance after creature
/// </summary>
class non_living_creature:public creature {
public:
	/// <summary>
	/// update inner state
	/// </summary>
	virtual void update() = 0;
	/// <summary>
	/// create save-state for game saving
	/// </summary>
	virtual std::string save_data() = 0;
protected:
	non_living_creature(int id_p, coords coords_p);
	/// <summary>
	/// collsion detection
	/// </summary>
	/// <returns>true if collision happened</returns>
	virtual bool collision_detection() = 0;
};
