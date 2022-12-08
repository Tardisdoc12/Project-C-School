//sinus.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <functional>
#include "os.h"
#include "os_wh.h"
#include "cadre.h"
using namespace std;
using namespace sf;
#ifndef __sinus_h__
#define __sinus_h__
class Sinus{
public:
  vector<Os_wh> sin2;
  Os_wh os1;
  RectangleShape cache_misere;
  vector<Os_wh> sin;
  sf::SoundBuffer lance;
  sf::Sound vu;
  int no=0;
  Sinus();
  void degat(Player & heart,Clock & intervalle_degat,Clock & perte_de_vie,bool isJumping,bool blue,cadre & cadre1,int groundheight);
  void move(Vector2f Frame,Clock & movement);
  void son_lance();
  void drawTo(RenderWindow & window,cadre & cadre1);
  void setPosition(cadre & cadre1, Vector2f Pos);
};

 #endif
