//menuact.cpp
#include "menuact.h"

menuact::menuact(){
  if (!font.loadFromFile("../Font/DTM-Mono.otf")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  Act.setString("Sans");
  Act.setFont(font);
  Act.setFillColor(Color::Yellow);
  Act.setPosition({120.f,370.f});
}


void menuact::select(Player & heart,Event event,bool & ds_act,int & presse){
  if (event.type==sf::Event::KeyPressed){
    switch(event.key.code){
    case sf::Keyboard::Return:
      if (selected==2){
	selected=1;
      }
      else if (selected==1){
	selected=0;
      }
      else if (selected==0){
	ds_act=false;
	selected=2;
	presse=4;
      }
    }
  }
}


void menuact::comeback(Event event,bool & ds_act,int & presse){
  if (event.type==sf::Event::KeyPressed){
    switch(event.key.code){
    case sf::Keyboard::Key::X:
      if (selected==2){
	ds_act=false;
	presse=4;
      }
      if (selected==1){
	selected=2;
      }
    }
  }
}

void menuact::drawTo(RenderWindow & window, Player & heart, bool & ds_act,int & presse){
  if(ds_act){
    if (selected==2){
      Act.setFillColor(Color::Yellow);
      Act.setString("Sans");
      heart.setPosition({100.f,380.f});
      window.draw(Act);
      heart.drawTo(window);
    }
    else if (selected==1){
      Act.setFillColor(Color::Yellow);
      Act.setString("Check");
      heart.setPosition({100.f,380.f});
      window.draw(Act);
      heart.drawTo(window);
    }
    else if (selected==0){
      Act.setFillColor(Color::White);
      Act.setString("* 1 Atk\n* 1 Def\n* The easiest ennemy.");
      heart.setPosition({900.f,0.f});
      window.draw(Act);
    }
  }
}


