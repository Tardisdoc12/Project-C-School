//menustart.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "menustart.h"
using namespace std;
using namespace sf;

menustart::menustart(){
  if(!texture.loadFromFile("../Sprite/heart/spr_heart_0.png")){
    throw runtime_error("loading of the texture failed succesfuly !");
  }
  heart.setTexture(texture);
  heart.setScale(2.f,2.f);
  if(!font.loadFromFile("../Font/MonsterFriendFore.otf")){
    throw runtime_error("loading failed!");
  }
  square2.setSize(Vector2f(30,30)- Vector2f(3,3));
  square2.setOutlineThickness(1);
  square2.setOutlineColor(Color::Red);
  square2.setFillColor(Color::Red);
  square2.setOrigin(Vector2f(30,30)/2.f);
  square2.setPosition(420.f,110.f);
  
  pauseMessage.setFont(font);
  pauseMessage.setCharacterSize(60);
  pauseMessage.setPosition(140.f,80.f);
  pauseMessage.setFillColor(Color::White);
  pauseMessage.setString("UNdERTaLE");
  
  play.setFont(font);
  play.setCharacterSize(40);
  play.setPosition(40.f,350.f);
  play.setFillColor(Color::Yellow);
  play.setString("  Play");

  exit.setFont(font);
  exit.setCharacterSize(40);
  exit.setPosition(40.f,470.f);
  exit.setFillColor(Color::White);
  exit.setString("  Exit");

}

void menustart::etatmenu(bool & PlayButtonSelected, bool & ExitButtonSelected,bool & PlayButtonPressed,bool & ExitButtonPressed,Event event){
  if (event.type==sf::Event::KeyPressed){
    switch(event.key.code){
    case sf::Keyboard::Up:{
      if(!PlayButtonSelected){
	PlayButtonSelected=true;
	ExitButtonSelected=false;
      }
      else{
	PlayButtonSelected=false;
	ExitButtonSelected=true;
      }
      break;
    }
    case sf::Keyboard::Down:{
      if (!ExitButtonSelected){
	PlayButtonSelected=false;
	ExitButtonSelected=true;
      }
      else{
	PlayButtonSelected=true;
	ExitButtonSelected=false;
      }
      break;
    }
    case sf::Keyboard::Return:{
      PlayButtonPressed=false;
      ExitButtonPressed=false;
      if(PlayButtonSelected){
	PlayButtonPressed=true;
      }
      else{
	ExitButtonPressed=true;
      }
      break;
    }
    default:{
      break;
    }  
    }
  }
}

void menustart::selected(RenderWindow & window,bool & PlayButtonPressed, bool & ExitButtonPressed,bool & isPlaying,bool & PlayButtonSelected,bool & ExitButtonSelected){
  if(PlayButtonSelected){
    play.setFillColor(Color::Yellow);
    exit.setFillColor(Color::White);
    heart.setPosition({20.f,355.f});
    window.clear(Color(Color::Black));
    this->drawTo(window);
  }
  else{
    exit.setFillColor(Color::Yellow);
    play.setFillColor(Color::White);
    heart.setPosition({20.f,475.f});
    window.clear(Color(Color::Black));
    this->drawTo(window);
  } 
  if(PlayButtonPressed){
    isPlaying=true;
    PlayButtonPressed=false;
  }
  else if(ExitButtonPressed){
    window.close();
  }

}

void menustart::drawTo(RenderWindow & window){
  window.draw(square2);
  window.draw(pauseMessage);
  window.draw(heart);
  window.draw(play);
  window.draw(exit);
}
