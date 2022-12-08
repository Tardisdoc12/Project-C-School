//life.h
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
using namespace sf;
#ifndef __life__h
#define __life__h

class life{
public:
  Font font;
  Text counter;
  int lp;
  int karma=0;
  int lp_purple;
  Text name;
  Font font2;
  int difference;
  RectangleShape lifepoint;
  RectangleShape purple;
  RectangleShape background;
  life();
  void setMaxLife(int hp_max);
  void setPosition(sf::Vector2f newPos);
  void drawTo(sf::RenderWindow & window);
  void takedamage(Clock & perte_vie);
  void Karma(Clock & karma1);
  void gainLife(int lifepoint);
};
#endif
