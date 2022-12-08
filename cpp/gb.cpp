//gb.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>

#include "collision.h"
#include "gb.h"

using namespace std;

using namespace sf;

GB::GB(){
  if(!texture.loadFromFile("../Sprite/Sans_attack/attack sans.png")){
    cout<<"Load Failed!"<<endl;
    system("pause");
  }
  if(!tir.loadFromFile("../Sprite/tir.png")){
    cout<<"Load Failed!"<<endl;
    system("pause");
  }
  rayon_du_gaster.setTexture(tir);
  cadretir.top=0.f;
  cadretir.left=0.f;
  cadretir.width=60.f;
  cadretir.height=0.f;
  rayon_du_gaster.setTextureRect(cadretir);
  rayon_du_gaster.setOrigin({rayon_du_gaster.getLocalBounds().width/2,0.f});
  sprite.setTexture(texture);
  gasterblaster.top=0;
  gasterblaster.left=0;
  gasterblaster.width=45;
  gasterblaster.height=60;
  sprite.setTextureRect(gasterblaster);
  sprite.setScale(2.5f,2.5f);
  sprite.setOrigin({sprite.getLocalBounds().width/2,sprite.getLocalBounds().height});

  if (!tirtest.loadFromFile("../Music/gb.ogg")){
    cout<<"load Failed"<<endl;
  }
  tir1.setBuffer(tirtest);
  if (!damage.loadFromFile("../Music/damage.ogg")){
    cout<<"load failed"<<endl;
  }
  damage2.setBuffer(damage);
}

void GB::position(Vector2f Pos){
  sprite.setPosition(Pos);
  rayon_du_gaster.setPosition({sprite.getPosition().x,sprite.getPosition().y});
}

void GB::drawTo(RenderWindow & window){
  if (cadretir.height<1200){
    //cout<<"bizzare"<<endl;
    window.draw(rayon_du_gaster);
    window.draw(sprite);
  }
}

void GB::move(Vector2f distance){
    sprite.move(distance);
    rayon_du_gaster.move(distance);
}

void GB::play_attaque(){
  if (no==0){
    tir1.setVolume(15);
    tir1.play();
    no++;
  }
}

void GB::setScale(Vector2f taille){
  sprite.setScale(taille+sf::Vector2f(2.5f,2.5f));
  rayon_du_gaster.setScale(taille);
}

void GB::animation(Clock & Timer,int direction){
  //rayon_du_gaster.setPosition({this->getX(),this->getY()});
  if(Timer.getElapsedTime().asSeconds()>=0.08f){

    if(gasterblaster.left==250.f){
      if(cadretir.height<1200.f){

	       cadretir.height+=100.f;
      }
      if(rayon>=500){
        //sprite.getInverseTransform();
        if (direction==1){
          this->move({0.f,-50.f});
        }
        else if (direction==2){
          this->move({-50.f,0.f});
        }
        else if (direction==3){
          this->move({50.f,0.f});
        }
        else if (direction==4){
          this->move({0.f,50.f});
        }
        else if (direction==5){
          this->move({-40.f,-50.f});
        }
        else if (direction==6){
          this->move({40.f,-50.f});
        }
        else if (direction==7){
          this->move({-50.f,50.f});
        }
        else if (direction==8){
          this->move({50.f,45.f});
        }

      }
    }
    else{
      gasterblaster.left+=50.f;
    }
    rayon_du_gaster.setTextureRect(cadretir);
    sprite.setTextureRect(gasterblaster);
  }
}

float GB::getY(){
  return sprite.getPosition().y;
}

float GB::getX(){
  return sprite.getPosition().x;
}

void GB::rotation(float angle){ //angle en degrée
  sprite.setRotation(angle);
  rayon_du_gaster.setRotation(angle);
}

void GB::degat(Player & heart,Clock & perte_de_vie,Clock & intervalle_degat){
  if (Collision::PixelPerfectTest(rayon_du_gaster,heart.sprite) ){
      if (intervalle_degat.getElapsedTime().asSeconds()>0.05f){
	       if (cadretir.height<1200){
           if(no2%2==0){
             damage2.setVolume(100);
             damage2.play();
             no2++;
           }
           else{
             no2++;
           }
	          heart.lp_P.takedamage(perte_de_vie);
	           //intervalle_degat.restart();
	       }
    }
  }
}

void GB::reinitialisation(Vector2f newPos){
  rayon=0;
  gasterblaster.left=0.f;
  no=0;
  sprite.setTextureRect(gasterblaster);
  gb_block=false;
  this->position(newPos);
  cadretir.height=0.f;
  rayon_du_gaster.setTextureRect(cadretir);
  //rayon_du_gaster.setRotation(0);
}
