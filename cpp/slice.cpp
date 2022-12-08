//slice.cpp
#include "slice.h"

slice::slice(){
  if(!slice_texture.loadFromFile("../Sprite/slice/slice_anim.png")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  slice_anim.top=0.f;
  slice_anim.left=0.f;
  slice_anim.width=25.f;
  slice_anim.height=110.f;
  slice_sprite.setTexture(slice_texture);
  slice_sprite.setTextureRect(slice_anim);
  slice_sprite.setScale(2.f,2.5f);
}

void slice::animation(Clock & slice_jouer){
  if (slice_jouer.getElapsedTime().asSeconds()>0.1f){
    if (slice_anim.left<=125.f){
      slice_anim.left+=25.f;
    }
    slice_jouer.restart();
  }
  slice_sprite.setTextureRect(slice_anim);
}

void slice::setPosition(Vector2f newPos){
  slice_sprite.setPosition(newPos);
}

void slice::drawTo(RenderWindow & window){
  window.draw(slice_sprite);
}
