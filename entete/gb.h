//gb.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "player.h"
using namespace std;
using namespace sf;


#ifndef __gb_h__
#define __gb_h__

class GB:public sf::Transformable{
public:
  Sprite sprite;
  Texture texture;
  IntRect gasterblaster;
  float rayon=0;
  Sprite rayon_du_gaster;
  Texture tir;
  IntRect cadretir;
  bool gb_block=false;
  sf::SoundBuffer tirtest;
  sf::Sound tir1;
  int no=0;
  sf::SoundBuffer damage;
  sf::Sound damage2;
  int no2=0;
  GB();
  void position(Vector2f Pos);
  void drawTo(RenderWindow & window);
  void move(Vector2f distance);
  void animation(Clock & Timer,int direction);
  float getY();
  float getX();
  void play_attaque();
  void setScale(Vector2f taille);
  void rotation(float angle);
  void degat(Player & heart,Clock & oerte_de_vie,Clock & intervalle_degat);
  void reinitialisation(Vector2f newPos);
};


#endif
