//plateforme.cpp
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "plateforme.h"
#include "cadre.h"
using namespace std;
using namespace sf;


Plateforme::Plateforme(){
  rect_gr.setSize({60,10});
  rect_gr.setOutlineThickness(1);
  rect_gr.setOutlineColor(Color::Green);
  rect_gr.setFillColor(sf::Color(0,0,0));
  rect_gr.setPosition(300.f,550.f);

  rect_wh.setSize({60,10});
  rect_wh.setOutlineThickness(2);
  rect_wh.setOutlineColor(Color::White);
  rect_wh.setFillColor(sf::Color(0,0,0));
  rect_wh.setPosition(300.f,560.f);
}

void Plateforme::setPosition(float x, float y){
  rect_wh.setPosition(x,y);
  rect_gr.setPosition(x,y-7);
}
void Plateforme::drawTo(RenderWindow & window,cadre & cadre1){
  if ((cadre1.spriteCadre.getGlobalBounds().contains(rect_wh.getPosition().x+rect_wh.getGlobalBounds().width,rect_wh.getPosition().y))
  ||(cadre1.spriteCadre.getGlobalBounds().contains(rect_wh.getPosition().x-rect_wh.getGlobalBounds().width,rect_wh.getPosition().y))){
    window.draw(rect_gr);
    window.draw(rect_wh);
  }
}

void Plateforme::move(Player & heart, float speed, Clock & Timer, float direction){
  if (Timer.getElapsedTime().asSeconds()>speed){
    rect_wh.move({direction,0});
    rect_gr.move({direction,0});
    if( (heart.getY()+12.f >= rect_gr.getPosition().y) && (heart.getY()+12.f <= rect_wh.getPosition().y) ){
      if( (heart.getX() >= rect_wh.getPosition().x) && (heart.getX() <= rect_wh.getPosition().x+60) ) {
	heart.move({direction,0});
      }
    }
    Timer.restart();
  }
}

void Plateforme::hitbox(int & groundheight, Player & heart,int copie_ground){
  if( (heart.getY()+12.f >= rect_gr.getPosition().y) && (heart.getY()+12.f <= rect_wh.getPosition().y) ){
    if( (heart.getX() >= rect_wh.getPosition().x) && (heart.getX() <= rect_wh.getPosition().x+60) ) {
      on_plateforme=true;
      groundheight = rect_gr.getPosition().y-20;
    }
    else{
      groundheight = copie_ground;
    }
  }
  else{
    on_plateforme=false;
    groundheight = copie_ground;
  }
}
