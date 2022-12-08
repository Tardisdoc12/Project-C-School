//slice.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
using namespace std;
using namespace sf;
#ifndef __slice_h__
#define __slice_h__
class slice{
public:
  Texture slice_texture;
  Sprite slice_sprite;
  IntRect slice_anim;
  slice();
  void animation(Clock & slice_jouer);
  void setPosition(Vector2f newPos);
  void drawTo(RenderWindow & window);
};
#endif
