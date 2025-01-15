#include "Snake.h"
using namespace std;





//menuwyj::menuwyj(sf::Font fonts, sf::RenderWindow &window, Stangry &gameState)
//{
//	this->fonts = fonts;
//	this->win = &window;
//	this->stangry = &gameState;
//	texts.setFont(this->fonts);
//
//}
//void menuwyj::odtowrzmenuwyj()
//{
//	tworzytekst();
//		sf::Vector2f mouse(sf::Mouse::getPosition(*win));
//		sf::Event event;
//		while (win->pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				stangry->stan = Stangry::EXIT;
//			if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
//			{
//				if (texts[1].getGlobalBounds().contains(mouse))
//				{
//					stangry->stan = Stangry::MENU;
//					win->close();
//				}
//				if (texts[2].getGlobalBounds().contains(mouse))
//				{
//					win->close();
//				}
//				
//			}
//		}
//		updatemenu();
//		win->clear();
//		for (size_t i = 0; i < 3; i++)
//		{
//			win->draw(texts[i]);
//		}
//		win->display();
//	
//}
//void menuwyj::tworzytekst()
//{
//	std::string tekst[] = { "CZY CHCESZ WYJSC Z GRY","TAK","NIE" };
//
//	texts[0].setFont(fonts);
//	texts[0].setString(tekst[0]);
//	texts[0].setCharacterSize(120);
//	texts[0].setPosition(sf::Vector2f(Informacje::szerokosc / 2 - (texts[0].getGlobalBounds().width / 2), Informacje::wysokosc / 4 - texts[0].getGlobalBounds().height / 2));
//	texts[1].setFont(fonts);
//	texts[1].setString(tekst[1]);
//	texts[1].setCharacterSize(80);
//	texts[1].setPosition(sf::Vector2f(200, Informacje::wysokosc / 4 + texts[0].getGlobalBounds().height));
//	texts[2].setFont(fonts);
//	texts[2].setString(tekst[2]);
//	texts[2].setCharacterSize(80);
//	texts[2].setPosition(sf::Vector2f(600, Informacje::wysokosc / 4 + texts[0].getGlobalBounds().height));
//}
//void menuwyj::updatemenu()
//{
//	sf::Vector2f mouse(sf::Mouse::getPosition(*win));
//	for (size_t i = 1; i < 4; i++)
//	{
//		if (texts[i].getGlobalBounds().contains(mouse))
//		{
//			texts[i].setFillColor(sf::Color::Cyan);
//		}
//		else texts[i].setFillColor(sf::Color::White);
//
//	}
//}
//menuwyj::~menuwyj()
//{
//}
//wyj::wyj()
//{
//	win.create(sf::VideoMode(Informacje::szerokosc, Informacje::wysokosc, 32), "Wyj");
//	if (!fonts.loadFromFile("arial.ttf"))
//	{
//	}
//}
//
//void wyj::run()
//{
//	while (win.isOpen())
//	{
//		sf::Event event;
//		while (win.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				win.close();
//		}
//	
//		switch (stangry.stan)
//		{
//		case Stangry::WYJ:
//			runwyj();
//			break;
//		}
//	}
//}
//void wyj::runwyj()
//{
//	menuwyj menuwyj1(fonts, win, stangry);
//	menuwyj1.odtowrzmenuwyj();
//}
//wyj::~wyj()
//{
//}




class Wyjscie
{
public:
	sf:: Font font;
	sf::Text wyjscie[Wyjscie_pod];
	int wybranaopcja = 0;
	Wyjscie(float width, float height);
	~Wyjscie() {};
	void prawo();
	void lewo();
	int getwyjscie() { return wybranaopcja; }
	void draw(sf::RenderWindow &wyj);
	void close(sf::RenderWindow &wyj);
};
Wyjscie::Wyjscie(float width, float height)
{
	if (!font.loadFromFile("Sabo-Regular.otf"))
	{
		return;
	}

	wyjscie[0].setFont(font);
	wyjscie[0].setFillColor(sf::Color::Cyan);
	wyjscie[0].setString("Tak");
	wyjscie[0].setPosition(sf::Vector2f(800 / (Wyjscie_pod + 1) * 1, 600 / 2.5));
	wyjscie[1].setFont(font);
	wyjscie[1].setFillColor(sf::Color::White);
	wyjscie[1].setString("Nie");
	wyjscie[1].setPosition(sf::Vector2f(800 / (Wyjscie_pod + 1) * 2, 600 / 2.5));
}
void Wyjscie::draw(sf::RenderWindow &wyj)
{
	for (int i = 0; i < Wyjscie_pod; i++)
	{
		wyj.draw(wyjscie[i]);
	}
}
void Wyjscie::close(sf::RenderWindow &wyj)
{
	wyj.close();
}
void Wyjscie::prawo()
{
	if (wybranaopcja >= 0 && wybranaopcja < Wyjscie_pod)
	{
		wyjscie[wybranaopcja].setFillColor(sf::Color::White);
		wyjscie[wybranaopcja].setStyle(sf::Text::Regular);
		wybranaopcja--;
		if (wybranaopcja < 0)
			wybranaopcja = Wyjscie_pod - 1;
		wyjscie[wybranaopcja].setFillColor(sf::Color::Cyan);
		wyjscie[wybranaopcja].setStyle(sf::Text::Bold);
	}
}
void Wyjscie::lewo()
{
	if (wybranaopcja >= 0 && wybranaopcja < Wyjscie_pod)
	{
		wyjscie[wybranaopcja].setFillColor(sf::Color::White);
		wyjscie[wybranaopcja].setStyle(sf::Text::Regular);
		wybranaopcja++;
		if (wybranaopcja >= Wyjscie_pod)
			wybranaopcja = 0;
		wyjscie[wybranaopcja].setFillColor(sf::Color::Cyan);
		wyjscie[wybranaopcja].setStyle(sf::Text::Bold);
	}
}




engine::engine(sf::Font font, sf::RenderWindow &window, Stangry &gameState)
{
	this->font = font;
	this->window = &window;
	this->stangry = &gameState;
	text.setFont(this->font);
}

void engine::odtworzgre()
{
	srand(time(NULL));
	bool pierwszyowoc = true;
	sf::Texture punkt;
	punkt.loadFromFile("food.png");
	sf::IntRect ksztaltpunktu(0,0,20,20);
	sf::Sprite japko(punkt, ksztaltpunktu);
	sf::Clock japkoclock;
	string linia;
	int liczby[1200];
	int zdobytepunkty = 0;
	Snake.punkty = &zdobytepunkty;
	sf::Texture tlo;
	tlo.loadFromFile("cztlo.jpg");
	sf::Sprite sprajt;
	sprajt.setTexture(tlo);
	sf::Clock owockolor;
	sf::Clock owockolor2;
	sf::Texture tekstura;
	tekstura.loadFromFile("food.png");
	sf::IntRect ksztalt(0, 0, 20, 20);
	sf::Sprite owoc(tekstura, ksztalt);
	owoc.setPosition(170, 220);
	sf::Texture tekstura2;
	tekstura2.loadFromFile("food2.png");
	sf::IntRect ksztalt2(0, 0, 20, 20);
	sf::Sprite owoc2(tekstura2, ksztalt2);
	owoc.setPosition(170, 220);
	owoc2.setPosition(630, 220);
	sf::Clock appleClock;
	sf::Clock moveClock;
	sf::Clock napisclock;
	sf::Text text2;
	sf::Font font;
	if (!font.loadFromFile("Sabo-Regular.otf"))
	{
	}
	text2.setFont(font);
	text2.setPosition(600, 0);
	text2.setCharacterSize(24);

	map.dodajmape();
	while (stangry->stan == Stangry::PLAY1)
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				stangry->stan = Stangry::EXIT;
			}
			if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::F4)
			{
				fstream plik;
				plik.open("zapis1.txt", ios::in);
				int licznik = 0;
				while (!plik.eof())
				{
					getline(plik, linia);
					liczby[licznik] = atof(linia.c_str());
					licznik++;
				}
				zdobytepunkty = liczby[0];
				if (liczby[1] == 0)
				{
					Snake.szeregwezaczesc[0].direction = czescweza::UP;
				}
				else if (liczby[1] == 1)
				{
					Snake.szeregwezaczesc[0].direction = czescweza::DOWN;
				}
				else if (liczby[1] == 2)
				{
					Snake.szeregwezaczesc[0].direction = czescweza::LEFT;
				}
				else if (liczby[1] == 3)
				{
					Snake.szeregwezaczesc[0].direction = czescweza::RIGHT;
				}
				for (int j = 1; j <= zdobytepunkty; j++)
				{
					Snake.dodajczescweza();
				}
				for (int i = 0; i <= (zdobytepunkty +2); i++)
				{
					Snake.szeregwezaczesc[i].rect.setPosition(liczby[2 + (i * 2)], liczby[3 + (i * 2)]);
				}
				
				plik.close();
				
				
				
			}
	
		}
		if (!pause)
		{

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					Snake.zmienkierunek(1);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					Snake.zmienkierunek(2);
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					Snake.zmienkierunek(4);
				}
				else if (event.key.code == sf::Keyboard::Up)
				{
					Snake.zmienkierunek(3);
				}
				else if (event.key.code == sf::Keyboard::F1)
				{
					sf::RenderWindow pomoc(sf::VideoMode(1400, 200), "pomoc");
					sf::Font font;
					sf::Text tekst;
					sf::Text tekst2;
					sf::Text tekst3;
					if (!font.loadFromFile("Sabo-Regular.otf"))
					{
					}
					tekst.setFont(font);
					tekst.setPosition(0, 0);
					tekst.setString("Gra polega na uzyskaniu jak najwiekszej ilosci punktow sterujac wezem w taki sposob zeby unikac scian.");
					tekst.setCharacterSize(20);
					tekst.setFillColor(sf::Color::White);
					tekst2.setFont(font);
					tekst2.setPosition(0, tekst.getGlobalBounds().height);
					tekst2.setString("Wezem poruszamy za pomoca strzalek zeby wyjsc nalezy wcisnac Escape i potwierdzic wyjscie Entrerem.");
					tekst2.setCharacterSize(20);
					tekst3.setFont(font);
					tekst3.setPosition(0, tekst.getGlobalBounds().height*2);
					tekst3.setString("Zeby zapisac stan gry nacisnij F5. Zeby zamknac okno pomocy nacisnij F2.");
					tekst3.setCharacterSize(20);
					while (pomoc.isOpen())
					{
						pomoc.clear(sf::Color::Black);
						sf::Event e;
						while (pomoc.pollEvent(e))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
							{
								pomoc.close();
							}


						}

						pomoc.clear();
						pomoc.draw(tekst);
						pomoc.draw(tekst2);
						pomoc.draw(tekst3);
						pomoc.display();
					}
				}
			}
			else if (event.key.code == sf::Keyboard::Escape)
			{
			
				sf::RenderWindow wyj(sf::VideoMode(800, 600), "Potwierz wyjscie");
			
				Wyjscie wyjscie(800, 600);
				sf::Font font;
				sf::Text tekst;
				if (!font.loadFromFile("Sabo-Regular.otf"))
				{
				}
				sf::Texture tlo;
				tlo.loadFromFile("cztlo.jpg");
				sf::Sprite sprajt;
				sprajt.setTexture(tlo);
				tekst.setFont(font);
				tekst.setPosition(50, 100);
				tekst.setString("Czy na pewno chcesz wyjsc?");
				tekst.setCharacterSize(40);
				tekst.setFillColor(sf::Color::White);
				while (wyj.isOpen())
				{
					wyj.clear(sf::Color::Black);
					sf::Event e;
					while (wyj.pollEvent(e))
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						{
							wyjscie.prawo();
							Sleep(100);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						{
							wyjscie.lewo();
							Sleep(100);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && wyjscie.getwyjscie() == 0)
						{
							std::fstream plik;
							plik.open("zapis1.txt", ios::out);
							plik << zdobytepunkty << endl;
							plik << Snake.szeregwezaczesc[0].direction << endl;
							for (int i = 0; i <= zdobytepunkty+2; i++)
							{
								plik << Snake.szeregwezaczesc[i].rect.getPosition().x << endl;
								plik << Snake.szeregwezaczesc[i].rect.getPosition().y << endl;
							}
							plik.close();
							stangry->stan = Stangry::MENU;
							wyj.close();


						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && wyjscie.getwyjscie() == 1)
						{
							wyj.close();
						}
					}
					wyj.clear();
					wyj.draw(tekst);
					wyjscie.draw(wyj);
					wyj.display();
				}



			}

			kolizjazsciana();
			kolizjazwezem();
			if (napisclock.getElapsedTime().asSeconds() <= 3)
			{
				text2.setString("Poziom 1");
			}
		    if (napisclock.getElapsedTime().asSeconds() > 3 && napisclock.getElapsedTime().asSeconds() <= 6)
			{
				text2.setString("Pomoc F1");
			}
			if (napisclock.getElapsedTime().asSeconds() > 6 && napisclock.getElapsedTime().asSeconds() <= 9)
			{
				text2.setString("Wczytaj F4");
			}
			if (napisclock.getElapsedTime().asSeconds() > 9)
			{
				napisclock.restart();
			}
			if (japkoclock.getElapsedTime().asMilliseconds() > 300.0f)
			{
				if (ksztaltpunktu.left == 20)
				{
					ksztaltpunktu.left = 0;
				}
				else
				{
					ksztaltpunktu.left += 20;
				}
				japko.setTextureRect(ksztaltpunktu);
				japkoclock.restart();

			}
			if (pierwszyowoc || containFlag)
			{
				containFlag = false;
				japko.setPosition(((rand() % 40) * 20), ((rand() % 30) * 20));;
				for (size_t i = 0; i < map.szeregscianmapa.size(); i++)
				{
					if (map.szeregscianmapa[i].rect.getGlobalBounds().intersects((japko.getGlobalBounds())))
					{
						containFlag = true;
					}
				}
				pierwszyowoc = false;
			}
			if ((Snake.szeregwezaczesc[0].rect.getPosition().x == japko.getPosition().x && Snake.szeregwezaczesc[0].rect.getPosition().y == japko.getPosition().y) || containFlag)
			{
				containFlag = false;
				zdobytepunkty += Informacje::dodawanepunkty;
				Snake.dodajczescweza();
				japko.setPosition(((rand() % 40) * 20), ((rand() % 30) * 20));;
				for (size_t i = 0; i < map.szeregscianmapa.size(); i++)
				{
					if (map.szeregscianmapa[i].rect.getGlobalBounds().intersects((japko.getGlobalBounds())))
					{
						containFlag = true;
					}
				}
			}
			if (moveClock.getElapsedTime() > sf::milliseconds(Informacje::predkosc * 100))
			{
				Snake.ruszajweza();
				moveClock.restart();
			}
			pozaekranem();
			window->clear();
			window->draw(sprajt);
			window->draw(map);
			window->draw(japko);
			window->draw(Snake);
			window->draw(text2);
			rysujpunktacje();
			window->display();
		}
		else
		{
		if (owockolor.getElapsedTime().asMilliseconds() > 300.0f)
		{
			if (ksztalt.left == 20)
			{
				ksztalt.left = 0;
			}
			else
			{
				ksztalt.left += 20;
			}
			owoc.setTextureRect(ksztalt);
			owockolor.restart();

		}
		if (owockolor2.getElapsedTime().asMilliseconds() > 300.0f)
		{
			if (ksztalt2.left == 20)
			{
				ksztalt2.left = 0;
			}
			else
			{
				ksztalt2.left += 20;
			}
			owoc2.setTextureRect(ksztalt);
			owockolor2.restart();

		}
	
		window->clear();
		window->draw(sprajt);
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(60);
		text.setString("Koniec gry!@");
		text.setPosition(sf::Vector2f(Informacje::szerokosc / 2 - (text.getGlobalBounds().width / 2), Informacje::wysokosc / 4 - text.getGlobalBounds().height / 2));
		window->draw(text);
		text.setPosition(sf::Vector2f(text.getPosition().x + (text.getGlobalBounds().width / 2), text.getPosition().y + text.getGlobalBounds().height * 2));
		text.setCharacterSize(30);
		text.setString(std::to_string(*Snake.punkty));
		window->draw(text);
		window->draw(owoc);
		window->draw(owoc2);
		window->display();

			if (event.key.code == sf::Keyboard::Escape)
			{
				window->clear();
				stangry->stan = Stangry::MENU;
			}
        }
	}
}
void engine::pozaekranem()
{
	if (Snake.szeregwezaczesc[0].rect.getPosition().x < 0)
	{
		Snake.szeregwezaczesc[0].rect.setPosition(sf::Vector2f(Informacje::szerokosc - Informacje::szerokoscjednegoklocka, Snake.szeregwezaczesc[0].rect.getPosition().y));
	}
	if (Snake.szeregwezaczesc[0].rect.getPosition().x >= Informacje::szerokosc)
	{
		Snake.szeregwezaczesc[0].rect.setPosition(sf::Vector2f(0, Snake.szeregwezaczesc[0].rect.getPosition().y));
	}
	if (Snake.szeregwezaczesc[0].rect.getPosition().y < 0)
	{
		Snake.szeregwezaczesc[0].rect.setPosition(sf::Vector2f(Snake.szeregwezaczesc[0].rect.getPosition().x, Informacje::wysokosc - Informacje::szerokoscjednegoklocka));
	}
	if (Snake.szeregwezaczesc[0].rect.getPosition().y >= Informacje::wysokosc)
	{
		Snake.szeregwezaczesc[0].rect.setPosition(sf::Vector2f(Snake.szeregwezaczesc[0].rect.getPosition().x, 0));
	}
}

void engine::kolizjazwezem()
{
	for (size_t i = 1; i < Snake.rozmiarweza; i++)
	{
		if (Snake.szeregwezaczesc[0].rect.getGlobalBounds().intersects(Snake.szeregwezaczesc[i].rect.getGlobalBounds()))
		{
			pause = true;
		}
	}
}
void engine::rysujpunktacje()
{
	text.setStyle(sf::Text::Underlined);
	text.setCharacterSize(24);
	text.setPosition(sf::Vector2f(0, 0));
	text.setString("points: ");
	window->draw(text);
	text.setPosition(sf::Vector2f(text.getPosition().x + text.getGlobalBounds().width, text.getPosition().y));
	text.setString(std::to_string(*Snake.punkty));
	window->draw(text);
}

	
void engine::kolizjazsciana()
{
	for (size_t i = 0; i < map.szeregscianmapa.size(); i++)
	{
		if (map.szeregscianmapa[i].rect.getGlobalBounds().intersects(Snake.szeregwezaczesc[0].rect.getGlobalBounds()))
			pause = true;
	}
}

class Wyjsciebis
{
public:
	sf::Font font;
	sf::Text wyjscie[Wyjscie_pod];
	int wybranaopcja = 0;
	Wyjsciebis(float width, float height);
	~Wyjsciebis() {};
	void prawo();
	void lewo();
	int getwyjscie() { return wybranaopcja; }
	void draw(sf::RenderWindow &wyj);
	void close(sf::RenderWindow &wyj);
};
Wyjsciebis::Wyjsciebis(float width, float height)
{
	if (!font.loadFromFile("Sabo-Regular.otf"))
	{
		return;
	}

	wyjscie[0].setFont(font);
	wyjscie[0].setFillColor(sf::Color::Cyan);
	wyjscie[0].setString("Tak");
	wyjscie[0].setPosition(sf::Vector2f(800 / (Wyjscie_pod + 1) * 1, 600 / 2.5));
	wyjscie[1].setFont(font);
	wyjscie[1].setFillColor(sf::Color::White);
	wyjscie[1].setString("Nie");
	wyjscie[1].setPosition(sf::Vector2f(800 / (Wyjscie_pod + 1) * 2, 600 / 2.5));
}
void Wyjsciebis::draw(sf::RenderWindow &wyj)
{
	for (int i = 0; i < Wyjscie_pod; i++)
	{
		wyj.draw(wyjscie[i]);
	}
}
void Wyjsciebis::close(sf::RenderWindow &wyj)
{
	wyj.close();
}
void Wyjsciebis::prawo()
{
	if (wybranaopcja >= 0 && wybranaopcja < Wyjscie_pod)
	{
		wyjscie[wybranaopcja].setFillColor(sf::Color::White);
		wyjscie[wybranaopcja].setStyle(sf::Text::Regular);
		wybranaopcja--;
		if (wybranaopcja < 0)
			wybranaopcja = Wyjscie_pod - 1;
		wyjscie[wybranaopcja].setFillColor(sf::Color::Cyan);
		wyjscie[wybranaopcja].setStyle(sf::Text::Bold);
	}
}
void Wyjsciebis::lewo()
{
	if (wybranaopcja >= 0 && wybranaopcja < Wyjscie_pod)
	{
		wyjscie[wybranaopcja].setFillColor(sf::Color::White);
		wyjscie[wybranaopcja].setStyle(sf::Text::Regular);
		wybranaopcja++;
		if (wybranaopcja >= Wyjscie_pod)
			wybranaopcja = 0;
		wyjscie[wybranaopcja].setFillColor(sf::Color::Cyan);
		wyjscie[wybranaopcja].setStyle(sf::Text::Bold);
	}
}




enginebis::enginebis(sf::Font font, sf::RenderWindow &window, Stangry &gameState)
{
	this->font = font;
	this->window = &window;
	this->stangry = &gameState;
	text.setFont(this->font);
}

void enginebis::odtworzgre()
{
	srand(time(NULL));
	bool pierwszyowoc = true;

	sf::Texture punkt;
	punkt.loadFromFile("food.png");
	sf::IntRect ksztaltpunktu(0, 0, 20, 20);
	sf::Sprite japko(punkt, ksztaltpunktu);
	sf::Clock japkoclock;
	int liczby[1200];
	int zdobytepunkty = 0;
	Snake.punkty = &zdobytepunkty;
	string linia;
	sf::Texture tlo;
	tlo.loadFromFile("cztlo.jpg");
	sf::Sprite sprajt;
	sprajt.setTexture(tlo);
	sf::Clock owockolor;
	sf::Clock owockolor2;
	sf::Texture tekstura;
	tekstura.loadFromFile("food.png");
	sf::IntRect ksztalt(0, 0, 20, 20);
	sf::Sprite owoc(tekstura, ksztalt);
	owoc.setPosition(170, 220);
	sf::Texture tekstura2;
	tekstura2.loadFromFile("food2.png");
	sf::IntRect ksztalt2(0, 0, 20, 20);
	sf::Sprite owoc2(tekstura2, ksztalt2);
	owoc.setPosition(170, 220);
	owoc2.setPosition(630, 220);
	sf::Clock appleClock;
	sf::Clock moveClock;
	sf::Clock napisclock;
	sf::Text text2;
	sf::Font font;
	if (!font.loadFromFile("Sabo-Regular.otf"))
	{
	}
	text2.setFont(font);
	text2.setPosition(600, 0);
	text2.setCharacterSize(24);
	map.dodajmape();
	int kp, xp, yp;
	while (stangry->stan == Stangry::PLAY2)
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				stangry->stan = Stangry::EXIT;
			}

			
			if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::F4)
			{
				fstream plik;
				plik.open("zapis2.txt", ios::in);
				int licznik = 0;
				while (!plik.eof())
				{
					getline(plik, linia);
					liczby[licznik] = atof(linia.c_str());
					licznik++;
				}
				zdobytepunkty = liczby[0];
				if (liczby[1] == 0)
				{
				Snake.szeregwezaczesc[0].direction = czescweza::UP;
				}
				else if (liczby[1] == 1)
				{
				Snake.szeregwezaczesc[0].direction = czescweza::DOWN;
				}
				else if (liczby[1] == 2)
				{
				Snake.szeregwezaczesc[0].direction = czescweza::LEFT;
				}
				else if (liczby[1] == 3)
				{
				Snake.szeregwezaczesc[0].direction = czescweza::RIGHT;
				}
				for (int j = 0; j < zdobytepunkty; j++)
				{
					Snake.dodajczescweza();
				}
				for (int i = 0; i <= (zdobytepunkty +2); i++)
				{
					Snake.szeregwezaczesc[i].rect.setPosition(liczby[2 + (i * 2)], liczby[3 + (i * 2)]);
				}
				plik.close();
				remove("zapis2.txt");
				

			}
		}
		if (!pause)
		{

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					Snake.zmienkierunek(1);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					Snake.zmienkierunek(2);
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					Snake.zmienkierunek(4);
				}
				else if (event.key.code == sf::Keyboard::Up)
				{
					Snake.zmienkierunek(3);
				}
				else if (event.key.code == sf::Keyboard::F1)
				{
					sf::RenderWindow pomoc(sf::VideoMode(1400, 200), "pomoc");
					sf::Font font;
					sf::Text tekst;
					sf::Text tekst2;
					sf::Text tekst3;
					if (!font.loadFromFile("Sabo-Regular.otf"))
					{
					}
					tekst.setFont(font);
					tekst.setPosition(0, 0);
					tekst.setString("Gra polega na uzyskaniu jak najwiekszej ilosci punktow sterujac wezem w taki sposob zeby unikac scian.");
					tekst.setCharacterSize(20);
					tekst.setFillColor(sf::Color::White);
					tekst2.setFont(font);
					tekst2.setPosition(0, tekst.getGlobalBounds().height);
					tekst2.setString("Wezem poruszamy za pomoca strzalek zeby wyjsc nalezy wcisnac Escape i potwierdzic wyjscie Entrerem.");
					tekst2.setCharacterSize(20);
					tekst3.setFont(font);
					tekst3.setPosition(0, tekst2.getGlobalBounds().height*2);
					tekst3.setString("Stan gry zapisze siê wychodz¹c z gry. Zeby zamknac okno pomocy nacisnij F2.");
					tekst3.setCharacterSize(20);
					while (pomoc.isOpen())
					{
						pomoc.clear(sf::Color::Black);
						sf::Event e;
						while (pomoc.pollEvent(e))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
							{
								pomoc.close();
							}
						}
						pomoc.clear();
						pomoc.draw(tekst);
						pomoc.draw(tekst2);
						pomoc.draw(tekst3);
						pomoc.display();
					}
				}
			}
			else if (event.key.code == sf::Keyboard::Escape)
			{
				sf::RenderWindow wyj(sf::VideoMode(800, 600), "Potwierz wyjscie");
				Wyjsciebis wyjsciebis(800, 600);
				sf::Font font;
				sf::Text tekst;
				if (!font.loadFromFile("Sabo-Regular.otf"))
				{
				}
				sf::Texture tlo;
				tlo.loadFromFile("cztlo.jpg");
				sf::Sprite sprajt;
				sprajt.setTexture(tlo);
				tekst.setFont(font);
				tekst.setPosition(50, 100);
				tekst.setString("Czy na pewno chcesz wyjsc?");
				tekst.setCharacterSize(40);
				tekst.setFillColor(sf::Color::White);
				while (wyj.isOpen())
				{
					wyj.clear(sf::Color::Black);
					sf::Event e;
					while (wyj.pollEvent(e))
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						{
							wyjsciebis.prawo();
							Sleep(100);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						{
							wyjsciebis.lewo();
							Sleep(100);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && wyjsciebis.getwyjscie() == 0)
						{
							std::fstream plik;
							plik.open("zapis2.txt", ios::out);
							plik << Snake.punkty << endl;
							plik << Snake.szeregwezaczesc[0].direction << endl;
							plik << Snake.szeregwezaczesc[0].rect.getPosition().x << endl;
							plik << Snake.szeregwezaczesc[0].rect.getPosition().y << endl;
							plik.close();
							stangry->stan = Stangry::MENU;
							wyj.close();


						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && wyjsciebis.getwyjscie() == 1)
						{
							wyj.close();
						}
					}
					wyj.clear();
					wyjsciebis.draw(wyj);
					wyj.draw(tekst);
					wyj.display();
				}
			}
			kolizjazwezem();
			if (napisclock.getElapsedTime().asSeconds() <= 3)
			{
				text2.setString("Poziom 2");
			}
			if (napisclock.getElapsedTime().asSeconds() > 3 && napisclock.getElapsedTime().asSeconds() <= 6)
			{
				text2.setString("Pomoc F1");
			}
			if (napisclock.getElapsedTime().asSeconds() > 6 && napisclock.getElapsedTime().asSeconds() <= 9)
			{
				text2.setString("Wczytaj F4");
			}
			if (napisclock.getElapsedTime().asSeconds() > 9)
			{
				napisclock.restart();
			}
			if (japkoclock.getElapsedTime().asMilliseconds() > 300.0f)
			{
				if (ksztaltpunktu.left == 20)
				{
					ksztaltpunktu.left = 0;
				}
				else
				{
					ksztaltpunktu.left += 20;
				}
				japko.setTextureRect(ksztaltpunktu);
				japkoclock.restart();
			}
			if (pierwszyowoc)
			{
				japko.setPosition(((rand() % 40) * Informacje::szerokoscjednegoklocka), ((rand() % 30) * Informacje::szerokoscjednegoklocka));
				pierwszyowoc = false;
			}
			if ((Snake.szeregwezaczesc[0].rect.getPosition().x == japko.getPosition().x && Snake.szeregwezaczesc[0].rect.getPosition().y == japko.getPosition().y) || containFlag || pierwszyowoc)
			{
				zdobytepunkty += Informacje::dodawanepunkty;
				Snake.dodajczescweza();
				japko.setPosition(((rand() % 40) * Informacje::szerokoscjednegoklocka), ((rand() % 30) * Informacje::szerokoscjednegoklocka));
				containFlag = false;
			}
			if (moveClock.getElapsedTime() > sf::milliseconds(Informacje::predkosc * 100))
			{
				Snake.ruszajweza();
				moveClock.restart();
			}
			pozaekranem();
			window->clear();
			window->draw(sprajt);
			window->draw(japko);
			window->draw(Snake);
			window->draw(text2);
			rysujpunktacje();
			window->display();
		}
		else
		{
			if (owockolor.getElapsedTime().asMilliseconds() > 300.0f)
			{
				if (ksztalt.left == 20)
				{
					ksztalt.left = 0;
				}
				else
				{
					ksztalt.left += 20;
				}
				owoc.setTextureRect(ksztalt);
				owockolor.restart();
			}
			if (owockolor2.getElapsedTime().asMilliseconds() > 300.0f)
			{
				if (ksztalt2.left == 20)
				{
					ksztalt2.left = 0;
				}
				else
				{
					ksztalt2.left += 20;
				}
				owoc2.setTextureRect(ksztalt);
				owockolor2.restart();
			}
			window->clear();
			window->draw(sprajt);
			text.setStyle(sf::Text::Bold);
			text.setCharacterSize(60);
			text.setString("Koniec gry!@");
			text.setPosition(sf::Vector2f(Informacje::szerokosc / 2 - (text.getGlobalBounds().width / 2), Informacje::wysokosc / 4 - text.getGlobalBounds().height / 2));
			window->draw(text);
			text.setPosition(sf::Vector2f(text.getPosition().x + (text.getGlobalBounds().width / 2), text.getPosition().y + text.getGlobalBounds().height * 2));
			text.setCharacterSize(30);
			text.setString(std::to_string(*Snake.punkty));
			window->draw(text);
			window->draw(owoc);
			window->draw(owoc2);
			window->display();
			if (event.key.code == sf::Keyboard::Escape)
			{
				window->clear();
				stangry->stan = Stangry::MENU;
			}
		}
	}	
}
void enginebis::pozaekranem()
{
	if (Snake.szeregwezaczesc[0].rect.getPosition().x < 0)
	{
		Snake.szeregwezaczesc[0].rect.setPosition(sf::Vector2f(Informacje::szerokosc - Informacje::szerokoscjednegoklocka, Snake.szeregwezaczesc[0].rect.getPosition().y));
	}
	if (Snake.szeregwezaczesc[0].rect.getPosition().x >= Informacje::szerokosc)
	{
		Snake.szeregwezaczesc[0].rect.setPosition(sf::Vector2f(0, Snake.szeregwezaczesc[0].rect.getPosition().y));
	}
	if (Snake.szeregwezaczesc[0].rect.getPosition().y < 0)
	{
		Snake.szeregwezaczesc[0].rect.setPosition(sf::Vector2f(Snake.szeregwezaczesc[0].rect.getPosition().x, Informacje::wysokosc - Informacje::szerokoscjednegoklocka));
	}
	if (Snake.szeregwezaczesc[0].rect.getPosition().y >= Informacje::wysokosc)
	{
		Snake.szeregwezaczesc[0].rect.setPosition(sf::Vector2f(Snake.szeregwezaczesc[0].rect.getPosition().x, 0));
	}
}
void enginebis::kolizjazwezem()
{
	for (size_t i = 1; i < Snake.rozmiarweza; i++)
	{
		if (Snake.szeregwezaczesc[0].rect.getGlobalBounds().intersects(Snake.szeregwezaczesc[i].rect.getGlobalBounds()))
		{
			pause = true;
		}
	}
}
void enginebis::rysujpunktacje()
{
	text.setStyle(sf::Text::Underlined);
	text.setCharacterSize(24);
	text.setPosition(sf::Vector2f(0, 0));
	text.setString("points: ");
	window->draw(text);
	text.setPosition(sf::Vector2f(text.getPosition().x + text.getGlobalBounds().width, text.getPosition().y));
	text.setString(std::to_string(*Snake.punkty));
	window->draw(text);
}
