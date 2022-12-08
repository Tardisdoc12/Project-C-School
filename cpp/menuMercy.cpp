//menuMercy.cpp
#include "menuMercy.h"

menuMercy::menuMercy(){
  if(!font.loadFromFile("../Font/DTM-Mono.otf")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  Flee.setString("* Flee");
  Mercy.setString("* Spare");
  Flee.setFont(font);
  Mercy.setFont(font);
  Flee.setFont(font);
  Flee.setFillColor(Color::White);
  Mercy.setFillColor(Color::Yellow);
  Mercy.setPosition({120.f,370.f});
  Flee.setPosition({120.f,405.f});
}

void menuMercy::select(Player & heart,Event event,bool & ds_mercy,int & presse){
    if (event.type==sf::Event::KeyPressed){
      switch(event.key.code){
      case sf::Keyboard::Return:
	if (selected==1){
	  selected=0;
	}
	else if (selected==0){
	  ds_mercy=false;
	  selected=1;
	  presse=4;
	}
      case sf::Keyboard::Up:
	if((FleeOrMercy==1) && (selected==1)){
	  FleeOrMercy=0;
	}
	if ((FleeOrMercy==0) && (selected==1)){
	  FleeOrMercy=1;
	}
      case sf::Keyboard::Down:
	if (selected==1){
	  FleeOrMercy=(FleeOrMercy+1)%2;
	}
      }
    }
    if ((FleeOrMercy==1)&&(selected==1)){
      Flee.setFillColor(Color::Yellow);
      Mercy.setFillColor(Color::White);
      heart.setPosition({100.f,415.f});
    }
    else if ((FleeOrMercy==0)&&(selected==1)){
      Flee.setFillColor(Color::White);
      Mercy.setFillColor(Color::Yellow);
      heart.setPosition({100.f,380.f});
    }
}

void menuMercy::comeback(Event event,bool & ds_mercy,int & presse){
    if (event.type==sf::Event::KeyPressed){
    switch(event.key.code){
    case sf::Keyboard::Key::X:
      if (selected==1){
	ds_mercy=false;
	presse=4;
      }
      if (selected==0){
	selected=1;
      }
    }
  }
}


void menuMercy::drawTo(RenderWindow & window, Player & heart, bool & ds_mercy,int & presse){
  if(ds_mercy){
    if ((selected==0)&&(FleeOrMercy==1) && (presse==3)){
      Mercy.setFillColor(Color::White);
      Mercy.setString("* Do you believe in Santa?\n  It will be the same answer for\n  your escape!");
      Flee.setString("");
      window.draw(Mercy);
      window.draw(Flee);
      heart.setPosition({900.f,0.f});
      heart.drawTo(window);
    }
    else if ((selected==0)&&(FleeOrMercy==0)&&(presse==3)){
      Flee.setFillColor(Color::White);
      Mercy.setString("");
      Flee.setString("You can spare him!\nIt's too late!");
      Flee.setPosition({120.f,370.f});
      window.draw(Mercy);
      window.draw(Flee);
      heart.setPosition({900.f,0.f});
      heart.drawTo(window);
    }
    else if (selected==1){
      FleeOrMercy==0;
      Mercy.setString("* Spare");
      Flee.setString("* Flee");
      Flee.setPosition({120.f,405.f});
      window.draw(Mercy);
      window.draw(Flee);
      heart.drawTo(window);
    }
  }
}
