//menustart.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

#ifndef __menustart_h__
#define __menustart_h__
class menustart{
public:
  RectangleShape square2;
  Sprite heart;
  Texture texture;
  Text pauseMessage;
  Text play;
  Font font;
  Text exit;
  menustart();
  void etatmenu(bool & PlayButtonSelected, bool & ExitButtonSelected,bool & PlayButtonPressed,bool & ExitButtonPressed,Event event);
  void selected(RenderWindow & window,bool & PlayButtonPressed, bool & ExitButtonPressed,bool & is_Playing,bool & PlayButtonSelected,bool & ExitButtonSelected);
  void drawTo(RenderWindow & window);
};
#endif
