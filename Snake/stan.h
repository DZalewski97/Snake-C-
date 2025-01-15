#pragma once
#include "info.h"
class Stangry
{
public:
	enum gra_stany { MENU, PLAY1, PLAY2, POZIOM, GAME_OVER, EXIT, WYJ };
	gra_stany stan;
	Stangry();
};
