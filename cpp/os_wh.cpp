//os_wh.cpp
#include "os_wh.h"
#include "collision.h"

Os_wh::Os_wh():Os(){
  //os blanc
  if (!os_texture.loadFromFile("../Sprite/Sans_attack/spr_s_boneloop_0.png")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  os_sprite.setTexture(os_texture);
  os_sprite.setOrigin({os_sprite.getGlobalBounds().width/2,os_sprite.getGlobalBounds().height});
}

Os_wh::~Os_wh(){
}


void Os_wh::degat(Player & heart,Clock & perte_de_vie,Clock & intervalle_degat,bool isJumping,bool blue,cadre & cadre1,int groundheight){
  //si on est sur l'os ou pas
  if (intervalle_degat.getElapsedTime().asSeconds()>0.05f){
    if(Collision::PixelPerfectTest(heart.sprite,os_sprite)){
      if(afficher){
        if(sound2%2==0){
          sound.play();
          sound2++;
        }
        else{
          sound2++;
        }
        heart.lp_P.takedamage(perte_de_vie);
        heart.lp_P.takedamage(perte_de_vie);
      }
    }
    //intervalle_degat.restart();
  }
}
