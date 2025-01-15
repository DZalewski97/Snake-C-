#pragma once
#include "info.h"

class Sciana
{
public:
	sf::RectangleShape rect;
	Sciana();
	~Sciana();
};
class szeregscian :
	public sf::Drawable, sf::Transformable
{
public:
	szeregscian();
	std::vector<Sciana> szeregscianmapa;
	Sciana sciana;
	void dodajmape();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	~szeregscian();
};