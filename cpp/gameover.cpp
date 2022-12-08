//gameover.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "button.h"
#include "player.h"
#include "gameover.h"
using namespace std;
using namespace sf;


Gameover::Gameover(){
  if(!font.loadFromFile("../Font/DTM-Sans.otf")){
    throw runtime_error("loading failed!");
  }
  if(!font2.loadFromFile("../Font/MonsterFriendFore.otf")){
    throw std::runtime_error("loading of the font failed");
  }
  Gameover_text.setFont(font2);
  Gameover_text.setCharacterSize(100);
  Gameover_text.setPosition(250.f,120.f);
  Gameover_text.setFillColor(Color::White);
  Gameover_text.setString("GAME \nOVER");

  tmort.setFont(font);
  tmort.setCharacterSize(40);
  tmort.setPosition(200.f,440.f);
  tmort.setFillColor(Color::White);

}



void Gameover::changetext(Event event, int & next){
  if(event.type==sf::Event::KeyPressed){
    switch(event.key.code){
    case sf::Keyboard::Return:
      next=(next+1)%3;
    }
  }
}


void Gameover::drawTo(RenderWindow & window, int & next, bool & isPlaying, bool & ds_gameover,Player & heart){
  if (next==0){
    tmort.setString("You cannot give \nup just yet...");
    window.draw(Gameover_text);
    window.draw(tmort);
  }
  else if (next==1){
    tmort.setString("Stay determined..");
    window.draw(Gameover_text);
    window.draw(tmort);
  }
  else if (next==2){
    heart.lp_P.setMaxLife(92);
    ds_gameover=false;
    isPlaying=false;
    next=0;
  }
}
