#include "Snake.h"
#include <assert.h>

Snake::Snake( const Location& loc ) //snake constructor
{
	constexpr int nBodyColors = 4;
	constexpr Color bodyColors[nBodyColors] = {		
		{ 10,100,32 },
		{ 10,130,48 },
		{ 18,160,48 },
		{ 10,130,48 }
	};
		
	for( int i = 0; i < nSegmentsMax; ++i )
	{
		segments[i].InitBody( bodyColors[i % nBodyColors] ); //remainder when 'i' is devidied by nBodyColors
	}

	segments[0].InitHead( loc ); //create the head at the location passed to the constructor
}

void Snake::MoveBy( const Location& delta_loc )
{
	for( int i = nSegments - 1; i > 0; --i )
	{
		segments[i].Follow( segments[i - 1] );
	}
	segments[0].MoveBy( delta_loc );
}

Location Snake::GetNextHeadLocation( const Location& delta_loc ) const
{
	Location l( segments[0].GetLocation() );
	l.Add( delta_loc );
	return l;
}

void Snake::GrowAndMoveBy( const Location& delta_loc )
{
	if( nSegments < nSegmentsMax )
	{
		++nSegments;
	}
	MoveBy( delta_loc );
}

void Snake::Draw( Board & brd ) const
{
	for( int i = 0; i < nSegments; ++i )
	{
		segments[i].Draw( brd );
	}
}

bool Snake::IsInTileExceptEnd( const Location& target ) const
{
	for( int i = 0; i < nSegments - 1; ++i )
	{
		if( segments[i].GetLocation() == target )
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile( const Location& target ) const
{
	for( int i = 0; i < nSegments; ++i )
	{
		if( segments[i].GetLocation() == target )
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead( const Location& in_loc )
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody( Color c_in )
{
	c = c_in;
}

void Snake::Segment::Follow( const Segment& next )
{
	loc = next.loc;
}

void Snake::Segment::MoveBy( const Location& delta_loc )
{
	assert( abs( delta_loc.x ) + abs( delta_loc.y ) == 1 );
	loc.Add( delta_loc );
}

void Snake::Segment::Draw( Board& brd ) const //modifies board but does not change snake
{
	brd.DrawCell( loc,c );
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
