//menuItem.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include<vector>
#include "cadre.h"
#include "life.h"
#include "player.h"
using namespace std;
using namespace sf;
#ifndef __menuItem_h__
#define __menuItem_h__

class menuItem{
 public:
  Font font;
  Text Item;
  int selectH=0;
  int selectV=0;
  int presse=8;
  int item_pris=8;
  vector<Text> items;
  menuItem();
  void selected(Player & heart,Event event);
  void takeItem(Event event,Player & heart,life & p_life,bool & ds_item,int & whereMenu);
  void drawTo(RenderWindow & window, Player & heart,bool & ds_item,int & whereMenu);
  void comeBack(Event event,bool & ds_item,int & whereMenu);
};
#endif
