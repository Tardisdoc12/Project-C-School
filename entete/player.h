//Player.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "cadre.h"
#include "life.h"
using namespace std;
using namespace sf;

#ifndef __player_h__
#define __player_h__
class Player{
private:
  int lifepoint;
  int attack;
  int defense;
public:
  life lp_P;
  bool block;
  float gravityspeed;
  float speed;
  sf::Texture texture;
  sf::Sprite sprite;
  Player(int lifepoint1,int attack1,int defense1,float speed1,std::string path);
  void move(sf::Vector2f distance);
  void setPosition(sf::Vector2f newPos);
  void drawTo(sf::RenderWindow & window);
  int getY();
  int getX();
  void movement(bool blue,bool & isJumping, bool & plafond, int groundheight, cadre & cadre1,bool & on_plateforme);
  void gravity(int groundheight,bool & plafond, bool & isJumping, bool & blue);
  void released(Event event, bool & isJumping, int groundheight);
  void couleur(bool blue);
};
#endif
