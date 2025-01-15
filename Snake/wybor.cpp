#include "wybor.h"

wybor::wybor(sf::Font font, sf::RenderWindow &window, Stangry &gameState)
{
	this->font = font;
	this->window = &window;
	this->stangry = &gameState;
}
void wybor::odtowrzwybor()
{
	sf::Texture tlo;
	tlo.loadFromFile("tlo.jpg");
	sf::Sprite sprajt;
	sprajt.setTexture(tlo);
	tworztekst();

	while (stangry->stan == Stangry::POZIOM)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(*window));
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				stangry->stan = Stangry::EXIT;
			if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				if (text[1].getGlobalBounds().contains(mouse))
				{
					stangry->stan = Stangry::PLAY1;
				}
				if (text[2].getGlobalBounds().contains(mouse))
				{
					stangry->stan = Stangry::PLAY2;
				}

			}
		}
		updatewybor();
		window->clear();
		window->draw(sprajt);
		for (size_t i = 0; i < 3; i++)
		{
			window->draw(text[i]);
		}
		window->display();
	}
}
void wybor::tworztekst()
{
	std::string tekst[] = { "WYBIERZ POZIOM GRY","POZIOM 1","POZIOM 2" };

	text[0].setFont(font);
	text[0].setString(tekst[0]);
	text[0].setCharacterSize(60);
	text[0].setPosition(sf::Vector2f(Informacje::szerokosc / 2 - (text[0].getGlobalBounds().width / 2), Informacje::wysokosc / 4 - text[0].getGlobalBounds().height / 2));
	text[1].setFont(font);
	text[1].setString(tekst[1]);
	text[1].setCharacterSize(60);
	text[1].setPosition(sf::Vector2f(Informacje::szerokosc / 4 + (text[0].getGlobalBounds().width / 4) - 100, Informacje::wysokosc / 4 + text[0].getGlobalBounds().height * 3));
	text[2].setFont(font);
	text[2].setString(tekst[2]);
	text[2].setCharacterSize(60);
	text[2].setPosition(sf::Vector2f(Informacje::szerokosc / 4 + (text[0].getGlobalBounds().width / 4) - 100, Informacje::wysokosc / 4 + text[0].getGlobalBounds().height * 6));

}
void wybor::updatewybor()
{
	sf::Vector2f mouse(sf::Mouse::getPosition(*window));
	for (size_t i = 1; i < 4; i++)
	{
		if (text[i].getGlobalBounds().contains(mouse))
		{
			text[i].setFillColor(sf::Color::Cyan);
		}
		else text[i].setFillColor(sf::Color::White);

	}
}
wybor::~wybor()
{
}