//os_block.cpp
#include "os_block.h"

Os_block::Os_block():Os(){
  //bloc os blanc
  if (!os_texture.loadFromFile("../Sprite/Sans_attack/spr_s_bonestab_v_wide_0.png")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  rect_red.setSize(sf::Vector2f(190,70));
  rect_red.setOutlineColor(Color::Red);
  rect_red.setOutlineThickness(2);
  rect_red.setFillColor(sf::Color(250,250,250,0));
  os_sprite.setTexture(os_texture);
  os_anim.top=0;
  os_anim.left=0;
  os_anim.width=190;
  os_anim.height= 0;
  os_sprite.setTextureRect(os_anim);
}

Os_block::~Os_block(){
}


void Os_block::degat(Player & heart,Clock & perte_de_vie,Clock & intervalle_degat,bool isJumping,bool blue,cadre & cadre1,int groundheight){
  sound.play();
  //si on est sur l'os ou pas
  if (intervalle_degat.getElapsedTime().asSeconds()>0.05f){
    if(heart.sprite.getGlobalBounds().intersects(this->os_sprite.getGlobalBounds())){
      if(afficher){
        heart.lp_P.takedamage(perte_de_vie);
      }
    }
    //intervalle_degat.restart();
  }
}

void Os_block::drawRect(RenderWindow & window){
  window.draw(rect_red);
}
