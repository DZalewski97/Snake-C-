#include "gra.h"

gra::gra()
{
	window.create(sf::VideoMode(Informacje::szerokosc, Informacje::wysokosc, 32), "Snake"/*,::Style::Fullscreen*/);
	if (!font.loadFromFile("Sabo-Regular.otf"))
	{
	}
}
void gra::run()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		switch (stangry.stan)
		{

		case Stangry::PLAY1:
			runEngine1();
			break;
		case Stangry::PLAY2:
			runEngine2();
			break;
		case Stangry::POZIOM:
			runwybor();
			break;
		case Stangry::MENU:
			runMenu();
			break;
		case Stangry::EXIT:
			window.close();
			break;
		}
	}
}
void gra::runMenu()
{
	menu menu1(font, window, stangry);
	menu1.odtowrzmenu();
}
void gra::runwybor()
{
	wybor wybor1(font, window, stangry);
	wybor1.odtowrzwybor();
}
void gra::runEngine1()
{
	engine engine1(font, window, stangry);
	engine1.odtworzgre();
}
void gra::runEngine2()
{
	enginebis enginebis1(font, window, stangry);
	enginebis1.odtworzgre();
}
gra::~gra()
{
}
int main()
{
	gra Game;
	Game.run();
	return EXIT_SUCCESS;
}