#include "waz.h"
czescweza::czescweza()
{
	rect.setSize(sf::Vector2f(20, 20));
	rect.setPosition(sf::Vector2f(100, 0));
	direction = RIGHT;
}
czescweza::~czescweza()
{

}

snake::snake()
{
	rozmiarweza = 1;
	czesc.rect.setFillColor(sf::Color::Green);
	szeregwezaczesc.push_back(czesc);
	dodajczescweza();
	dodajczescweza();

}
void snake::dodajczescweza()
{
	szeregwezaczesc.push_back(czesc);
	rozmiarweza++;
	switch (szeregwezaczesc[rozmiarweza - 2].direction)
	{
	case czescweza::LEFT:
		szeregwezaczesc[rozmiarweza - 1].direction = szeregwezaczesc[rozmiarweza - 2].direction;
		szeregwezaczesc[rozmiarweza - 1].rect.setPosition(szeregwezaczesc[rozmiarweza - 2].rect.getPosition().x + Informacje::szerokoscjednegoklocka, szeregwezaczesc[rozmiarweza - 2].rect.getPosition().y);
		break;
	case czescweza::RIGHT:
		szeregwezaczesc[rozmiarweza - 1].direction = szeregwezaczesc[rozmiarweza - 2].direction;
		szeregwezaczesc[rozmiarweza - 1].rect.setPosition(szeregwezaczesc[rozmiarweza - 2].rect.getPosition().x - Informacje::szerokoscjednegoklocka, szeregwezaczesc[rozmiarweza - 2].rect.getPosition().y);
		break;
	case czescweza::UP:
		szeregwezaczesc[rozmiarweza - 1].direction = szeregwezaczesc[rozmiarweza - 2].direction;
		szeregwezaczesc[rozmiarweza - 1].rect.setPosition(szeregwezaczesc[rozmiarweza - 2].rect.getPosition().x, szeregwezaczesc[rozmiarweza - 2].rect.getPosition().y + Informacje::szerokoscjednegoklocka);

		break;
	case czescweza::DOWN:
		szeregwezaczesc[rozmiarweza - 1].direction = szeregwezaczesc[rozmiarweza - 2].direction;
		szeregwezaczesc[rozmiarweza - 1].rect.setPosition(szeregwezaczesc[rozmiarweza - 2].rect.getPosition().x, szeregwezaczesc[rozmiarweza - 2].rect.getPosition().y - Informacje::szerokoscjednegoklocka);
		break;
	}
}

void snake::draw(sf::RenderTarget &tag, sf::RenderStates states) const
{
	for (size_t i = 0; i < rozmiarweza; i++)
	{
		tag.draw(szeregwezaczesc[i].rect);
	}
}
void snake::zmienkierunek(int a)
{
	switch (a)
	{
	case 1:
		if (szeregwezaczesc[1].direction != czescweza::RIGHT)
		{
			szeregwezaczesc[0].direction = czescweza::LEFT;
		}
		break;
	case 2:
		if (szeregwezaczesc[1].direction != czescweza::LEFT)
		{
			szeregwezaczesc[0].direction = czescweza::RIGHT;
		}
		break;
	case 3:
		if (szeregwezaczesc[1].direction != czescweza::DOWN)
		{
			szeregwezaczesc[0].direction = czescweza::UP;
		}
		break;
	case 4:
		if (szeregwezaczesc[1].direction != czescweza::UP)
		{
			szeregwezaczesc[0].direction = czescweza::DOWN;
		}
		break;
	}
}
void snake::ruszajweza()
{
	szeregwezaczesc[rozmiarweza - 1] = szeregwezaczesc[0];
	szeregwezaczesc.push_front(szeregwezaczesc[rozmiarweza - 1]);
	szeregwezaczesc.pop_back();
	switch (szeregwezaczesc[1].direction)
	{
	case czescweza::LEFT:
		szeregwezaczesc[0].rect.move(-Informacje::szerokoscjednegoklocka, 0);
		break;
	case czescweza::RIGHT:
		szeregwezaczesc[0].rect.move(Informacje::szerokoscjednegoklocka, 0);
		break;
	case czescweza::UP:
		szeregwezaczesc[0].rect.move(0, -Informacje::szerokoscjednegoklocka);
		break;
	case czescweza::DOWN:
		szeregwezaczesc[0].rect.move(0, Informacje::szerokoscjednegoklocka);
		break;
	}
}
snake::~snake()
{
}
