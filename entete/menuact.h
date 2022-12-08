//menuact.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "player.h"
using namespace std;
using namespace sf;

#ifndef __menuact_h__
#define __menuact_h__

class menuact{
public:
  Font font;
  int selected=2;
  Text Act;
  menuact();
  void select(Player & heart,Event event,bool & ds_act,int & presse);
  void comeback(Event event,bool & ds_act,int & presse);
  void drawTo(RenderWindow & window,Player & heart,bool & ds_act,int & presse);
};

#endif
