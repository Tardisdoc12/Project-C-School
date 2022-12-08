//menuItem.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "menuItem.h"

using namespace std;
using namespace sf;

menuItem::menuItem(){
  if(!font.loadFromFile("../Font/DTM-Mono.otf")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  Item.setFont(font);
  Item.setCharacterSize(30);
  Item.setFillColor(Color::White);
  Item.setString("Pie");
  items.insert(items.end(),Item);
  Item.setString("Instant Noodles");
  items.insert(items.end(),Item);
  Item.setString("Steak");
  items.insert(items.end(),Item);
  Item.setString("L.Hero");
  items.insert(items.end(),Item);
  items.insert(items.end(),Item);
  Item.setString("Snow Piece");
  items.insert(items.end(),Item);
  items.insert(items.end(),Item);
  items.insert(items.end(),Item);
  items[0].setPosition({120.f,370.f});
  items[1].setPosition({400.f,370.f});
  items[2].setPosition({120.f,405.f});
  items[3].setPosition({400.f,405.f});
  items[4].setPosition({120.f,440.f});
  items[5].setPosition({400.f,440.f});
  items[6].setPosition({120.f,475.f});
  items[7].setPosition({400.f,475.f});
}



void menuItem::selected(Player & heart, Event event){
  if (item_pris==8){
    if (event.type==sf::Event::KeyPressed){
      switch(event.key.code){
      case sf::Keyboard::Right:
	if (selectH==0){
	  selectH+=1;
	}
	else{
	  selectH=0;
	}
	break;
      case sf::Keyboard::Left:
	if (selectH==1){
	  selectH-=1;
	}
	else{
	  selectH=1;
	}
	break;
      case sf::Keyboard::Up:
	if(selectV!=0){
	  selectV-=1;
	}
	else{
	  selectV=3;
	}
	break;
      case sf::Keyboard::Down:
	selectV=(selectV+1)%4;
	break;
      }
    }
    //Les cas avec position:
    if (selectH==0){
      if(selectV==0){
	items[0].setFillColor(Color::Yellow);
	items[1].setFillColor(Color::White);
	items[2].setFillColor(Color::White);
	items[3].setFillColor(Color::White);
	items[4].setFillColor(Color::White);
	items[5].setFillColor(Color::White);
	items[6].setFillColor(Color::White);
	items[7].setFillColor(Color::White);
	heart.setPosition({100.f,380.f});
      }
      else if(selectV==1){
	items[2].setFillColor(Color::Yellow);
	items[1].setFillColor(Color::White);
	items[0].setFillColor(Color::White);
	items[3].setFillColor(Color::White);
	items[4].setFillColor(Color::White);
	items[5].setFillColor(Color::White);
	items[6].setFillColor(Color::White);
	items[7].setFillColor(Color::White);
	heart.setPosition({100.f,415.f});
      }
      else if(selectV==2){
	items[4].setFillColor(Color::Yellow);
	items[1].setFillColor(Color::White);
	items[2].setFillColor(Color::White);
	items[3].setFillColor(Color::White);
	items[0].setFillColor(Color::White);
	items[5].setFillColor(Color::White);
	items[6].setFillColor(Color::White);
	items[7].setFillColor(Color::White);
	heart.setPosition({100.f,450.f});
      }
      else if(selectV==3){
	items[6].setFillColor(Color::Yellow);
	items[1].setFillColor(Color::White);
	items[2].setFillColor(Color::White);
	items[3].setFillColor(Color::White);
	items[4].setFillColor(Color::White);
	items[5].setFillColor(Color::White);
	items[0].setFillColor(Color::White);
	items[7].setFillColor(Color::White);
	heart.setPosition({100.f,485.f});
      }
    }
    else{
      if(selectV==0){
	items[1].setFillColor(Color::Yellow);
	items[0].setFillColor(Color::White);
	items[2].setFillColor(Color::White);
	items[3].setFillColor(Color::White);
	items[4].setFillColor(Color::White);
	items[5].setFillColor(Color::White);
	items[6].setFillColor(Color::White);
	items[7].setFillColor(Color::White);
	heart.setPosition({380.f,380.f});
      }
      else if(selectV==1){
	items[3].setFillColor(Color::Yellow);
	items[1].setFillColor(Color::White);
	items[0].setFillColor(Color::White);
	items[2].setFillColor(Color::White);
	items[4].setFillColor(Color::White);
	items[5].setFillColor(Color::White);
	items[6].setFillColor(Color::White);
	items[7].setFillColor(Color::White);
	heart.setPosition({380.f,415.f});
      }
      else if(selectV==2){
	items[5].setFillColor(Color::Yellow);
	items[1].setFillColor(Color::White);
	items[2].setFillColor(Color::White);
	items[3].setFillColor(Color::White);
	items[0].setFillColor(Color::White);
	items[4].setFillColor(Color::White);
	items[6].setFillColor(Color::White);
	items[7].setFillColor(Color::White);
	heart.setPosition({380.f,450.f});
      }
      else if(selectV==3){
	items[7].setFillColor(Color::Yellow);
	items[1].setFillColor(Color::White);
	items[2].setFillColor(Color::White);
	items[3].setFillColor(Color::White);
	items[4].setFillColor(Color::White);
	items[5].setFillColor(Color::White);
	items[0].setFillColor(Color::White);
	items[6].setFillColor(Color::White);
	heart.setPosition({380.f,485.f});
      }
    }
  }
}

void menuItem::takeItem(Event event,Player & heart,life & p_life,bool & ds_item, int & whereMenu){
    if (event.type==sf::Event::KeyPressed){
      switch(event.key.code){
      case sf::Keyboard::Return:
	presse=8;
	if (item_pris==8){
	  presse=8;
	  if (selectH==0){
	    if (selectV==0){
	      presse=0;
	    }
	    else if (selectV==1){
	      presse=1;
	    }
	    else if (selectV==2){
	      presse=2;
	    }
	    else if (selectV==3){
	      presse=3;
	    }
	  }
	  else{
	    if (selectV==0){
	      presse=4;
	    }
	    else if (selectV==1){
	      presse=5;
	    }
	    else if (selectV==2){
	      presse=6;
	    }
	    else if (selectV==3){
	      presse=7;
	    }
	  }
	}
	else{
	  ds_item=false;
	  whereMenu=4;
	  item_pris=8;
	}
      }
    }
    if ((presse==0)&&(items[0].getString()!="")){
      items[0].setString("");
      item_pris=0;
      p_life.gainLife(92);
    }
    else if((presse==1)&&(items[2].getString()!="")){
      items[2].setString("");
      item_pris=1;
      p_life.gainLife(60);
    }
    else if((presse==2)&&(items[4].getString()!="")){
      items[4].setString("");
      item_pris=2;
      p_life.gainLife(40);
    }
    else if((presse==3)&&(items[6].getString()!="")){
      items[6].setString("");
      item_pris=3;
      p_life.gainLife(45);
    }
    else if((presse==4)&&(items[1].getString()!="")){
      items[1].setString("");
      item_pris=4;
      p_life.gainLife(90);
    }
    else if((presse==5)&&(items[3].getString()!="")){
      items[3].setString("");
      item_pris=5;
      p_life.gainLife(40);
    }
    else if((presse==6)&&(items[5].getString()!="")){
      items[5].setString("");
      item_pris=6;
      p_life.gainLife(45);
    }
    else if((presse==7)&&(items[7].getString()!="")){
      items[7].setString("");
      item_pris=7;
      p_life.gainLife(45);
    }
}

void menuItem::drawTo(RenderWindow & window,Player & heart,bool & ds_item,int & whereMenu){
  if (item_pris==8){
    heart.drawTo(window);
    window.draw(items[0]);
    window.draw(items[1]);
    window.draw(items[2]);
    window.draw(items[3]);
    window.draw(items[4]);
    window.draw(items[5]);
    window.draw(items[6]);
    window.draw(items[7]);
  }
  else if (item_pris==0){
    Item.setString("* You eat the pie.\n  Your Hp was maxed out.");
    Item.setPosition({100.f,370.f});
    window.draw(Item);
    heart.sprite.setPosition({900.f,0.f});
    heart.drawTo(window);
  }
  else if (item_pris==1){
    Item.setString("* You eat the Steak.\n  You gained 60 Hp.");
    Item.setPosition({100.f,370.f});
    window.draw(Item);
    heart.sprite.setPosition({900.f,0.f});
    heart.drawTo(window);
  }
  else if (item_pris==2){
    Item.setString("* You eat the Legendary Hero.\n  You gained 40 Hp.");
    Item.setPosition({100.f,370.f});
    window.draw(Item);
    heart.sprite.setPosition({900.f,0.f});
    heart.drawTo(window);
  }
  else if (item_pris==3){
    Item.setString("* You eat the Snowman Piece.\n  You gained 45 Hp.");
    Item.setPosition({100.f,370.f});
    window.draw(Item);
    heart.sprite.setPosition({900.f,0.f});
    heart.drawTo(window);
  }
  else if (item_pris==4){
    Item.setString("* You eat the Instant Noodles.\n  You gained 90 Hp.");
    Item.setPosition({100.f,370.f});
    window.draw(Item);
    heart.sprite.setPosition({900.f,0.f});
    heart.drawTo(window);
  }
  else if (item_pris==5){
    Item.setString("* You eat the Legendary Hero.\n  You gained 40 Hp.");
    Item.setPosition({100.f,370.f});
    window.draw(Item);
    heart.sprite.setPosition({900.f,0.f});
    heart.drawTo(window);
  }
  else if (item_pris==6){
    Item.setString("* You eat the Snowman Piece.\n  You gained 45 Hp.");
    Item.setPosition({100.f,370.f});
    window.draw(Item);
    heart.sprite.setPosition({900.f,0.f});
    heart.drawTo(window);
  }
  else if (item_pris==7){
    Item.setString("* You eat the Snowman Piece.\n  You gained 45 Hp.");
    Item.setPosition({100.f,370.f});
    window.draw(Item);
    heart.sprite.setPosition({900.f,0.f});
    heart.drawTo(window);
  }
}

void menuItem::comeBack(Event event,bool & ds_item,int & whereMenu){
  if (event.type==sf::Event::KeyPressed){
    switch(event.key.code){
    case sf::Keyboard::Key::X:
      ds_item=false;
      whereMenu=4;
      item_pris=8;
    }
  }
}
