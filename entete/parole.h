//parole.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "sanstete.h"
using namespace std;
using namespace sf;

#ifndef __parole_h__
#define __parole_h__
class parole{
public:
  Font font;
  string parole1;
  Sprite bulle;
  Texture text_b;
  Text texte;
  int nbr_lettre=0;
  bool fini_parle=false;
  bool fin_de_tour=false;
  bool retour_normal=false;
  parole();
  void setPosition(SansTete st);
  void setText(string say,Clock & appear,float speed);
  void effacement(Event event);
  void drawTo(RenderWindow & window);
  void setPosition(Vector2f newPos);
  void setPosition(float x,float y);
  int getX();
  int getY();
};
#endif
