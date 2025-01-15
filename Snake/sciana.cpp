#include "sciana.h"

Sciana::Sciana()
{
	rect.setSize(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::Blue);
}

Sciana::~Sciana()
{}
szeregscian::szeregscian()
{
}

void szeregscian::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (size_t i = 0; i < szeregscianmapa.size(); i++)
	{
		target.draw(szeregscianmapa[i].rect);
	}
}
void szeregscian::dodajmape()
{
	for (size_t i = 1; i <= 2; i++)
	{
		for (size_t j = 1; j <= 3; j++)
		{
			sciana.rect.setPosition(sf::Vector2f((Informacje::szerokosc / 4)*j - sciana.rect.getGlobalBounds().width, (Informacje::wysokosc / 3)*i - sciana.rect.getGlobalBounds().height));
			szeregscianmapa.push_back(sciana);
		}
	}
}
szeregscian::~szeregscian()
{}