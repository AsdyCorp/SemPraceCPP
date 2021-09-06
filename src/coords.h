#pragma once
#include <iostream>
#include <cmath>

/// <summary>
/// structure for coordinate manipulation - saves x and y int 
/// </summary>
struct  coords
{
	int x;
	int y; 
	/// <summary>
	/// coordinate constructor - in: x y
	/// </summary>
	coords(int x_p, int y_p) :x(x_p), y(y_p) {
	}
    /// <summary>
    /// default constructor
    /// </summary>
    coords() {
        x = 0;
        y = 0;
    }
    /// <summary>
    /// redefinition of assignment
    /// </summary>
    coords& operator= (const coords& coord_copy)
    {
        x = coord_copy.x;
        y = coord_copy.y;
        return *this;
    }
    /// <summary>
    /// stream handler
    /// </summary>
    friend std::ostream& operator<< (std::ostream& out, const coords& point);

};
inline
std::ostream& operator<< (std::ostream& out, const coords& point)
{
    out << point.x << " " << point.y << " ";
    return out;
}