//menuDefaut.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "button.h"
#include "player.h"
using namespace std;
using namespace sf;

#ifndef __menuDefaut_h__
#define __menuDefaut_h__

class DefautMenu{
public:
  vector<Button> buttons;
  DefautMenu(Button Fight,Button Act,Button Items, Button Mercy);
  int selectedButton(int Button, Sprite sprite, Event event,int & presse);
  void EtatDuMenu(const int Button, Player & heart);
  void drawTo(sf::RenderWindow & window, Player & heart);
};

#endif

