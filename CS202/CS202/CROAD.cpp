#include "CROAD.h"

CROAD::CROAD(float x, float y)
{
	mX = x;
	mY = y;
	NumRoad += 1;
	playing = false;
}

CROAD::CROAD()
{
	NumRoad += 1;
	playing = false;
}


CROAD::~CROAD()
{
	--NumRoad;
}


bool CROAD::checkoutwindow(sf::RenderWindow& window)
{
	return out.getPosition().y >= Constants::Height_screen;

}

void CROAD::draw(sf::RenderWindow& window)
{
	window.draw(out);
}

void CROAD::shiftObject(char shift)
{
	if (shift == 'U' || shift == 'u')
	{
		out.move(0, Constants::ShiftVelocity);
	}
	else if (shift == 'd' || shift == 'D')
	{
		out.move(0, -Constants::ShiftVelocity);
	}

	mX = out.getPosition().x;
	mY = out.getPosition().y;
	shiftObj(shift);
	//out.setPosition(mX, mY);
}

void CROAD::setplaying()
{
	playing = !playing;
}

int CROAD::getNumRoads()
{
	return NumRoad;
}

sf::Vector2f CROAD::getPos()
{
	return sf::Vector2f(mX, mY);
}