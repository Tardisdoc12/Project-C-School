//parole.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "parole.h"
#include "sanstete.h"
using namespace std;
using namespace sf;

parole::parole(){
  parole1=" ";
  if (!font.loadFromFile("../Font/pixel-comic-sans-undertale-sans-font.ttf")){
    cout<<"load failed"<<endl;
  }
  if (!text_b.loadFromFile("../Sprite/Bulle_dialogue.png")){
    cout<<"load failed"<<endl;
  }
  bulle.setTexture(text_b);
  bulle.setScale(0.30f,0.36f);
  texte.setFont(font);
  texte.setFillColor(Color::Black);
  texte.setCharacterSize(20);
  texte.setString(parole1);
}
void parole::setPosition(SansTete st){
  bulle.setPosition({st.getX()+120.f, st.getY()+40.f});
  texte.setPosition({this->getX()+60.f,this->getY()+10.f});
}
void parole::setText(string say,Clock & appear,float speed){
  if (appear.getElapsedTime().asSeconds()>speed){
    if(nbr_lettre<say.size()){
      parole1=parole1+say[nbr_lettre];
      texte.setString(parole1);
    }
    else if(nbr_lettre>=say.size()){
      fini_parle=true;
    }
    nbr_lettre++;
    appear.restart();
  }
}

void parole::effacement(Event event){
  if (fini_parle){
    if (event.type==sf::Event::KeyPressed){
      switch(event.key.code){
      case sf::Keyboard::Return:
	parole1="";
	texte.setString(parole1);
	fini_parle=false;
	nbr_lettre=0;
      }
    }
  }
}

void parole::drawTo(RenderWindow & window){
  window.draw(bulle);
  window.draw(texte);
}

void parole::setPosition(Vector2f newPos){
  texte.setPosition(newPos);
}

void parole::setPosition(float x, float y){
  texte.setPosition({x,y});
}

int parole::getY(){
  return bulle.getPosition().y;
}
int parole::getX(){
  return bulle.getPosition().x;
}
