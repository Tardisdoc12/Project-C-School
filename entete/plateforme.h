//plateforme.h
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "player.h"
#include "cadre.h"
using namespace std;
using namespace sf;
#ifndef __plateforme__h
#define __plateforme__h

class Plateforme{
public:
  RectangleShape rect_wh;
  RectangleShape rect_gr;
  bool on_plateforme=false;
  Plateforme();
  void setPosition(float x, float y);
  void drawTo(sf::RenderWindow & window,cadre & cadre1);
  void move(Player & heart, float speed, Clock & Timer, float direction);
  void hitbox(int & groundheight, Player & heart,int copie_ground);
};
#endif
