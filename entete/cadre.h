//cadre.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using namespace sf;
#ifndef __cadre_h__
#define __cadre_h__
class cadre{
public:
  float tailleX,tailleY;
  Texture textureCadre;
  Sprite spriteCadre;
  IntRect rectcadre;
  cadre();
  void animationFinFight(Clock & Timer);
  void animationDebutFight(Clock & Timer,int & groundheight, std::function<void(float,float)> setPosition);
  void drawTo(RenderWindow & window);
  float getY();
  float getX();
};
#endif
