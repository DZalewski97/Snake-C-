#pragma once
#include "info.h"
class czescweza
{
public:
	sf::RectangleShape rect;
	enum propablyDirection { UP, DOWN, LEFT, RIGHT };
	propablyDirection direction;
	czescweza();
	~czescweza();
	
};
class snake :
	public sf::Drawable, sf::Transformable
{
public:
	snake();
	std::deque<czescweza> szeregwezaczesc;
	std::deque<czescweza>::const_iterator czescwezaIterator;
	czescweza czesc;
	int *punkty;
	int rozmiarweza;
	void dodajczescweza();
	void ruszajweza();
	void zmienkierunek(int a);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	~snake();
};