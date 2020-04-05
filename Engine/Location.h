#pragma once

class Location
{
public:
	void Add( const Location& val )
	{
		x += val.x;
		y += val.y;
	}
	bool operator==( const Location& rhs ) const //the LHS of the comparison is the object on which the function has been called, and the RHS is the parameter passed in
	{
		return x == rhs.x && y == rhs.y;
	}
	int x;
	int y;
};