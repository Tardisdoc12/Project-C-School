//os.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "player.h"
#include "cadre.h"
using namespace std;
using namespace sf;


#ifndef __os_h__
#define __os_h__

class Os{
public:
  Sprite os_sprite;
  Texture os_texture;
  IntRect os_anim;
  bool test=false;
  RectangleShape rect_red;
  bool afficher=false;
  sf::SoundBuffer buffer;
  sf::Sound sound;
  sf::SoundBuffer buffer_os;
  sf::Sound sound_os;
  int sound1=0;
  int sound2=0;
  bool os_lance=false;
  bool os_damage=false;
  Os();
  void position(Vector2f Pos);
  void drawTo(RenderWindow & window,cadre & cadre1);
  void move(Vector2f distance);
  void son_lance();
  void animation_h(Clock & Timer,float vitesse,float direction);
  void animation_v(Clock & Timer,float vitesse,float direction);
  float getY();
  float getX();
  void setScale(Vector2f taille);
  void rotation(float angle);
  virtual void degat(Player & heart,Clock & perte_de_vie,Clock & intervalle_degat,bool isJumping,bool blue,cadre & cadre1,int groundheight)=0;
  ~Os();
};


#endif
