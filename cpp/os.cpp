//os.cpp
#include "os.h"
#include "cadre.h"


Os::Os(){
  if(!buffer.loadFromFile("../Music/damage.ogg")){
    cout<<"ERROR"<<endl;
  }
  sound.setBuffer(buffer);
  if(!buffer_os.loadFromFile("../Music/bone.ogg")){
    cout<<"ERROR"<<endl;
  }
  sound_os.setBuffer(buffer_os);
}

void Os::drawTo(RenderWindow & window,cadre & cadre1){
  afficher=true;
  if (cadre1.spriteCadre.getGlobalBounds().contains(this->getX(),this->getY())){
    window.draw(os_sprite);
  }
}

void Os::move(Vector2f distance){
  os_sprite.move(distance);
}

void Os::position(Vector2f Pos){
  os_sprite.setPosition(Pos);
  rect_red.setPosition({Pos.x,Pos.y-70});
}

void Os::animation_h(Clock & Timer,float vitesse,float direction){
  if (Timer.getElapsedTime().asSeconds()>vitesse){
    this->move({direction,0});
    //Timer.restart();
  }
}

void Os::son_lance(){
  if (sound1==0){
    sound_os.play();
    sound1++;
  }
}

void Os::animation_v(Clock & Timer,float vitesse,float direction){
  if(os_anim.height<70){
    if (Timer.getElapsedTime().asSeconds()>vitesse){
      this->move({0,direction});
      os_anim.height+=abs(direction);
      Timer.restart();
    }
    os_sprite.setTextureRect(os_anim);

  }
  if(os_anim.height>=70){
    if(Timer.getElapsedTime().asSeconds()>1.f){
      test=true;
      afficher=false;
    }
  }
}
float Os::getX(){
  return os_sprite.getPosition().x;
}

float Os::getY(){
  return os_sprite.getPosition().y;
}

void Os::setScale(Vector2f taille){
  os_sprite.setScale(taille);
}


void Os::rotation(float angle){ //en degré
  os_sprite.setRotation(angle);
}


Os::~Os(){}
