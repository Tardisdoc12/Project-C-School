//life.cpp
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "life.h"
using namespace std;
using namespace sf;


life::life(){
  if(!font2.loadFromFile("../Font/DTM-Mono.otf")){
    cout<<"load failed"<<endl;
  }
  name.setFont(font2);
  name.setString("Chara  LV 19       Kr   /92 ");
  name.setCharacterSize(30);
  name.setFillColor(Color::White);
  name.setPosition(60.f,550.f);

  if(!font.loadFromFile("../Font/DTM-Mono.otf")){
    cout<<"Loading failed!"<<endl;
  }
  counter.setFont(font);
  counter.setCharacterSize(30);
  counter.setFillColor(Color::White);
  counter.setPosition(450.f,550.f);
}

void life::setMaxLife(int hp_max){
  lifepoint.setSize({float(hp_max),20});
  lifepoint.setOutlineThickness(1);
  lifepoint.setOutlineColor(Color::Yellow);
  lifepoint.setFillColor(Color::Yellow);
  lifepoint.setPosition(300.f,560.f);
  background.setSize({float(hp_max),20});
  background.setOutlineThickness(1);
  background.setOutlineColor(Color::Red);
  background.setFillColor(Color::Red);
  background.setPosition(300.f,560.f);
  purple.setSize({float(hp_max),20});
  purple.setOutlineThickness(1);
  purple.setOutlineColor(Color::Magenta);
  purple.setFillColor(Color::Magenta);
  purple.setPosition(300.f,560.f);
  lp=hp_max;
  lp_purple=hp_max;
  counter.setString(to_string(lp_purple));
}

void life::setPosition(sf::Vector2f newPos){
  name.setPosition(newPos);
  lifepoint.setPosition(newPos);
}
void life::drawTo(RenderWindow & window){
  window.draw(name);
  window.draw(counter);
  window.draw(background);
  window.draw(purple);
  window.draw(lifepoint);
}
void life::takedamage(Clock & perte_vie){
  if(perte_vie.getElapsedTime().asSeconds()>0.05f){
    if(lp_purple-karma>1){
      if(lp>1){
        lp-=2;
        lifepoint.setSize(Vector2f(lifepoint.getSize().x-2.f,lifepoint.getSize().y));
      }
      if(lp<=1){
        lp=1;
        lifepoint.setSize(Vector2f(1.f,lifepoint.getSize().y));
      }
      lp_purple-=1;
      if(lp_purple-karma>1){
        karma+=1;
      }
      counter.setString(to_string(lp_purple));
      purple.setSize(Vector2f(float(lp_purple),purple.getSize().y));
      perte_vie.restart();
    }
    else if((lp_purple==1)&&(karma==0)&&(lp>0)){
      lp-=1;
      lp_purple-=1;
      lifepoint.setSize(Vector2f(lifepoint.getSize().x-1.f,lifepoint.getSize().y));
      purple.setSize(Vector2f(purple.getSize().x-1.f,purple.getSize().y));
      counter.setString(to_string(lp_purple));
      perte_vie.restart();
    }
    else if((lp_purple-karma==1)&&(karma>0)){
      karma-=1;
      lp_purple-=1;
      purple.setSize(Vector2f(purple.getSize().x-1.f,purple.getSize().y));
      counter.setString(to_string(lp_purple+karma-1));
    }
  }
}

void life::Karma(Clock & karma1){
  if (karma>0){
    if (karma1.getElapsedTime().asSeconds()>1.f){
      karma-=1;
      lp_purple-=1;
      counter.setString(to_string(lp_purple));
      purple.setSize(Vector2f(purple.getSize().x-1.f,purple.getSize().y));
      karma1.restart();
    }
  }
}

void life::gainLife(int lifepoint2){
  difference=lp_purple-lp;
  if (lp_purple+lifepoint2<=92){
    lp_purple+=lifepoint2;
    lp+=lifepoint2;
    counter.setString(to_string(lp));
    lifepoint.setSize(Vector2f(lifepoint.getSize().x+lifepoint2,lifepoint.getSize().y));
    purple.setSize(Vector2f(purple.getSize().x+lifepoint2,purple.getSize().y));
  }
  else{
    lp=92-difference;
    lp_purple=92;
    counter.setString(to_string(lp));
    lifepoint.setSize(Vector2f(lp,lifepoint.getSize().y));
    purple.setSize(Vector2f(92.f,purple.getSize().y));
  }
}
