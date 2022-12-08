//menuMercy.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "player.h"
using namespace std;
using namespace sf;

#ifndef __menuMercy_h__
#define __menuMercy_h__

class menuMercy{
public:
  Font font;
  int selected=1;
  int FleeOrMercy=0;
  Text Mercy;
  Text Flee;
  menuMercy();
  void select(Player & heart,Event event, bool & ds_mercy,int & presse);
  void comeback(Event event,bool & ds_mercy,int & presse);
  void drawTo(RenderWindow & window,Player & heart,bool & ds_mercy,int & presse);
};
#endif
