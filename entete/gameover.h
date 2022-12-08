//gameover.h
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

#ifndef __Gameover_h__
#define __Gameover_h__

class Gameover{
public:
  Texture texture;
  Text Gameover_text;
  Text tmort;
  Font font;
  Font font2;
  Gameover();
  void drawTo(RenderWindow & window, int & next, bool & isPlaying, bool & ds_gameover,Player & heart);
  void changetext(Event event, int & next);
};

#endif
