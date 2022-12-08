//player.ccp
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

Player::Player (int lifepoint1, int attack1, int defense1, float speed1, std::string texture_path) :
  lifepoint(lifepoint1), attack(attack1), defense(defense1), speed(speed1)
{
  gravityspeed=3;
  block=false;
  lp_P.setMaxLife(lifepoint);
  if (!texture.loadFromFile(texture_path))
    throw std::runtime_error("Loading of the texture failed !");
  this->sprite.setTexture(texture);
  sprite.setOrigin({2.f,2.f});
}

void Player::move(sf::Vector2f distance){
  sprite.move(distance);
}
void Player::setPosition(sf::Vector2f newPos){
  sprite.setPosition(newPos);
}

void Player::drawTo(sf::RenderWindow & window){
  window.draw(sprite);
}
int Player::getY(){
  return sprite.getPosition().y;
}
int Player::getX(){
  return sprite.getPosition().x;
}

void Player::released(Event event,bool & isJumping, int groundheight){
  switch(event.type){
  case sf::Event::KeyReleased:
    isJumping=false;
    if(this->getY()<groundheight){
      block=true;
    }
  }
}


void Player::gravity(int groundheight,bool & plafond, bool & isJumping, bool & blue){
  if((this->getY()< groundheight+6) && (isJumping==false) && (blue) ||(plafond)||((blue)&&(block)&&((this->getY()<groundheight)))){
    this->move({0, gravityspeed});
  }
  if(this->getY()>=groundheight-2){
    plafond=false;
    block=false;
  }
}





void Player::movement(bool blue,bool & isJumping, bool & plafond, int groundheight, cadre & cadre1,bool & on_plateforme){
  if(blue){
    if(this->getY()>=groundheight){
      block=false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->getY() >=cadre1.getY()-0.2*cadre1.tailleY && plafond==false && (!block) ){
      this->move({0, -speed});
      isJumping=true;
    }
    if((this->getY()<=cadre1.getY()-0.2*cadre1.tailleY) && (!on_plateforme)){
      plafond=true;
    }
    if (on_plateforme){
      if (this->getY()<=groundheight-0.5*cadre1.spriteCadre.getGlobalBounds().height){
        plafond=true;
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getX() < cadre1.getX()+0.11*cadre1.tailleX+2){
      this->move({speed,0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& this->getX() > cadre1.getX()-0.135*cadre1.tailleX){
      this->move({-speed,0});
    }
  }
  if(!blue){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&  this->getY() >=cadre1.getY()-0.5*cadre1.tailleY+12){
      this->move({0, -speed});
      isJumping=true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->getY()<groundheight+6){
      this->move({0,speed});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getX() < cadre1.getX()+0.11*cadre1.tailleX+3){
      this->move({speed,0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& this->getX() >  cadre1.getX()-0.135*cadre1.tailleX){
      this->move({-speed,0});
    }
  }
}

void Player::couleur(bool blue){
  if (blue){
    if(!texture.loadFromFile("../Sprite/heart/spr_heartblue_0.png")){
      cout<<"EXIT_FAILURE"<<endl;
    }
    sprite.setTexture(texture);
  }
  else{
    if(!texture.loadFromFile("../Sprite/heart/spr_heart_0.png")){
      cout<<"EXIT_FAILURE"<<endl;
    }
    sprite.setTexture(texture);
  }
}
