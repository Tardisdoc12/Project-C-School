//cadre.cpp
#include<functional>
#include "cadre.h"
using namespace std;
using namespace sf;

cadre::cadre(){
  if(!textureCadre.loadFromFile("../Sprite/testrect2.png")){
    throw std::runtime_error("loading of the texture failed !");
  }
  spriteCadre.setTexture(textureCadre);
  spriteCadre.setOrigin(0.5*spriteCadre.getLocalBounds().width,0.5*spriteCadre.getGlobalBounds().height);

  //spriteCadre.setTextureRect(rectcadre);
  spriteCadre.setPosition({400.f,450.f});
  spriteCadre.setScale(0.70f,0.42f);
  tailleX=0.70*textureCadre.getSize().x;
  tailleY=0.42*textureCadre.getSize().y;
}

void cadre::animationFinFight(Clock & Timer){
  if(Timer.getElapsedTime().asSeconds()>0.01f){
    //cout<<"test"<<endl;
    spriteCadre.setScale(0.70f,0.42f);
    //spriteCadre.setPosition({spriteCadre.getPosition().x,spriteCadre.getPosition().y+15.f});
  }
  Timer.restart();
  //spriteCadre.setTextureRect(rectcadre);
}


void cadre::animationDebutFight(Clock & Timer,int & groundheight, std::function<void(float,float)> setPosition){
  //while (rectcadre.left!=304){
    if(Timer.getElapsedTime().asSeconds()>0.1){
      spriteCadre.setScale(0.20f,0.40f);
      //spriteCadre.setPosition({spriteCadre.getPosition().x,spriteCadre.getPosition().y-15.f});
      }
      Timer.restart();
      groundheight=spriteCadre.getGlobalBounds().height/2+this->getY()-25.f;
      //spriteCadre.setTextureRect(rectcadre);

//  }

      setPosition(spriteCadre.getPosition().x,spriteCadre.getPosition().y);
}

void cadre::drawTo(RenderWindow & window){
  window.draw(spriteCadre);
}

float cadre::getY(){
  return spriteCadre.getPosition().y;
}

float cadre::getX(){
  return spriteCadre.getPosition().x;
}
