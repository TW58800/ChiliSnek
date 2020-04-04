#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board( Graphics& gfx );
	void DrawCell( const Location& loc,Color c ); //pass location by const reference (&) does not alter the reference
	int GetGridWidth() const; //const = function can only read not change
	int GetGridHeight() const;
	bool IsInsideBoard( const Location& loc ) const;
	void DrawBorder();
private:
	static constexpr Color borderColor = Colors::Blue;
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int width = 32;
	static constexpr int height = 24;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 70;
	static constexpr int y = 50;
	Graphics& gfx; //cache (store a local copy) a reference to the graphics object for convenicence (also for performance, but not in this case)
};