#pragma once
#include "info.h"
#include "menu.h"
#include "sciana.h"
#include "stan.h"
#include "waz.h"
#include "wybor.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define Wyjscie_pod 2


//class menuwyj
//{
//public:
//	sf::Font fonts;
//	sf::RenderWindow *win;
//	sf::Text texts[3];
//	Stangry *stangry;
//	
//
//
//	menuwyj(sf::Font fonts, sf::RenderWindow &win, Stangry &gameState);
//	void odtowrzmenuwyj();
//	void updatemenu();
//	void tworzytekst();
//	~menuwyj();
//};
//class wyj
//{
//public:
//	wyj();
//	Stangry stangry;
//	sf::RenderWindow win;
//	sf::Font fonts;
//	void run();
//	void runwyj();
//	~wyj();
//};
class engine
{
public:
	sf::RenderWindow *win;
	sf::Font fonts;
	sf::Font font;
	sf::RenderWindow *window;
	sf::Text text;
	sf::Text text2;
	sf::Event event;
	Stangry *stangry;
	snake Snake;
	szeregscian map;
	int counter = 0;
	bool pause = false;
	bool containFlag = false;
	engine(sf::Font font, sf::RenderWindow &window, Stangry &gameState);
	void pozaekranem();
	void kolizjazwezem();
	void kolizjazsciana();
	void rysujpunktacje();
	void odtworzgre();
};
class enginebis
{
public:
	sf::RenderWindow *win;
	sf::Font fonts;
	sf::Font font;
	sf::RenderWindow *window;
	sf::Text text;
	sf::Event event;
	Stangry *stangry;
	snake Snake;
	szeregscian map;
	int counter = 0;
	bool pause = false;
	bool containFlag = false;
	enginebis(sf::Font font, sf::RenderWindow &window, Stangry &gameState);
	void pozaekranem();
	void kolizjazwezem();
	void rysujpunktacje();
	void odtworzgre();
};