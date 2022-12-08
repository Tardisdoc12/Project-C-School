//sinus.cpp
#include "sinus.h"


Sinus::Sinus(){
  if(!lance.loadFromFile("../Music/bone.ogg")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  vu.setBuffer(lance);
  if(!os1.os_texture.loadFromFile("../Sprite/Sans_attack/spr_os_0.png")){
    cout<<"Exit_Failure"<<endl;
  }
  os1.os_anim.left=6.f;
  os1.os_anim.top=6.f;
  os1.os_anim.height=26.f;
  os1.os_anim.width=13.f;
  os1.os_sprite.setTexture(os1.os_texture);
  os1.os_sprite.setTextureRect(os1.os_anim);
  os1.os_sprite.setOrigin({0.f,os1.os_sprite.getLocalBounds().height});
  cache_misere.setFillColor(Color::Black);
  cache_misere.setSize({300.f,190.f});
  cache_misere.setOrigin({300.f,0.f});
  //os du bas:
  os1.os_sprite.setScale({1.5f,2.5f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,3.f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,3.5f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,4.f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,4.5f});
  sin.insert(sin.end(),os1);
  /* os1.os_sprite.setScale({1.5f,4.f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,4.3f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,4.6f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,4.3f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,4.f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,3.7f});
  sin.insert(sin.end(),os1);*/
  os1.os_sprite.setScale({1.5f,4.f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,3.5f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,3.f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,2.5f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,3.f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,3.5f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,4.f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,4.5f});
  sin.insert(sin.end(),os1);
  //os du haut:
  os1.os_sprite.setOrigin({0.f,6.f});
  os1.os_sprite.setScale({1.5f,3.f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,2.5f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,2.f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,1.5f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,1.f});
  sin2.insert(sin2.end(),os1);
  /*os1.os_sprite.setScale({1.5f,1.4f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,1.1f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,0.8f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,1.1f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,1.4f});
  sin.insert(sin.end(),os1);
  os1.os_sprite.setScale({1.5f,1.7f});
  sin.insert(sin.end(),os1);*/
  os1.os_sprite.setScale({1.5f,1.5f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,2.f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,2.5f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,3.f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,2.5f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,2.f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,1.5f});
  sin2.insert(sin2.end(),os1);
  os1.os_sprite.setScale({1.5f,1.f});
  sin2.insert(sin2.end(),os1);
}

void Sinus::setPosition(cadre & cadre1, Vector2f Pos){
  cache_misere.setPosition({float(cadre1.getX()-0.135*cadre1.tailleX-7),float(cadre1.getY()-0.5*cadre1.tailleY)});
  //os du bas:
  sin[0].position(Pos);
  sin[1].position({sin[0].getX()-45.f,sin[0].getY()});
  sin[2].position({sin[1].getX()-45.f,sin[1].getY()});
  sin[3].position({sin[2].getX()-45.f,sin[2].getY()});
  sin[4].position({sin[3].getX()-45.f,sin[3].getY()});
  sin[5].position({sin[4].getX()-45.f,sin[4].getY()});
  sin[6].position({sin[5].getX()-45.f,sin[5].getY()});
  sin[7].position({sin[6].getX()-45.f,sin[6].getY()});
  sin[8].position({sin[7].getX()-45.f,sin[7].getY()});
  sin[9].position({sin[8].getX()-45.f,sin[8].getY()});
  sin[10].position({sin[9].getX()-45.f,sin[9].getY()});
  sin[11].position({sin[10].getX()-45.f,sin[10].getY()});
  sin[12].position({sin[11].getX()-45.f,sin[11].getY()});
  /*sin[13].position({sin[12].getX()-45.f,sin[12].getY()});
  sin[14].position({sin[13].getX()-45.f,sin[13].getY()});
  sin[15].position({sin[14].getX()-45.f,sin[14].getY()});
  sin[16].position({sin[15].getX()-45.f,sin[15].getY()});
  sin[17].position({sin[16].getX()-45.f,sin[16].getY()});
  sin[18].position({sin[17].getX()-45.f,sin[17].getY()});*/
  //os du haut:
  sin2[0].position({sin[0].getX(),float(cadre1.getY()-0.4*cadre1.tailleY)});
  sin2[1].position({sin2[0].getX()-45.f,sin2[0].getY()});
  sin2[2].position({sin2[1].getX()-45.f,sin2[1].getY()});
  sin2[3].position({sin2[2].getX()-45.f,sin2[2].getY()});
  sin2[4].position({sin2[3].getX()-45.f,sin2[3].getY()});
  sin2[5].position({sin2[4].getX()-45.f,sin2[4].getY()});
  sin2[6].position({sin2[5].getX()-45.f,sin2[5].getY()});
  sin2[7].position({sin2[6].getX()-45.f,sin2[6].getY()});
  sin2[8].position({sin2[7].getX()-45.f,sin2[7].getY()});
  sin2[9].position({sin2[8].getX()-45.f,sin2[8].getY()});
  sin2[10].position({sin2[9].getX()-45.f,sin2[9].getY()});
  sin2[11].position({sin2[10].getX()-45.f,sin2[10].getY()});
  sin2[12].position({sin2[11].getX()-45.f,sin2[11].getY()});
  /*sin2[13].position({sin2[12].getX()-45.f,sin2[12].getY()});
  sin2[14].position({sin2[13].getX()-45.f,sin2[13].getY()});
  sin2[15].position({sin2[14].getX()-45.f,sin2[14].getY()});
  sin2[16].position({sin2[15].getX()-45.f,sin2[15].getY()});
  sin2[17].position({sin2[16].getX()-45.f,sin2[16].getY()});
  sin2[18].position({sin2[17].getX()-45.f,sin2[17].getY()});*/
}

void Sinus::degat(Player & heart,Clock & intervalle_degat,Clock & perte_de_vie,bool isJumping,bool blue,cadre & cadre1,int groundheight){
  for (int i=0;i<sin.size();i++){
    sin[i].degat(heart,perte_de_vie,intervalle_degat,isJumping,blue,cadre1,groundheight);
  }
}


void Sinus::move(Vector2f Frame,Clock & movement){
  if (movement.getElapsedTime().asSeconds()>0.2f){
    //os du bas:
    sin[0].move(Frame);
    sin[1].move(Frame);
    sin[2].move(Frame);
    sin[3].move(Frame);
    sin[4].move(Frame);
    sin[5].move(Frame);
    sin[6].move(Frame);
    sin[7].move(Frame);
    sin[8].move(Frame);
    sin[9].move(Frame);
    sin[10].move(Frame);
    sin[11].move(Frame);
    sin[12].move(Frame);
    /*sin[13].move(Frame);
    sin[14].move(Frame);
    sin[15].move(Frame);
    sin[16].move(Frame);
    sin[17].move(Frame);
    sin[18].move(Frame);*/
    //os du haut:
    sin2[0].move(Frame);
    sin2[1].move(Frame);
    sin2[2].move(Frame);
    sin2[3].move(Frame);
    sin2[4].move(Frame);
    sin2[5].move(Frame);
    sin2[6].move(Frame);
    sin2[7].move(Frame);
    sin2[8].move(Frame);
    sin2[9].move(Frame);
    sin2[10].move(Frame);
    sin2[11].move(Frame);
    sin2[12].move(Frame);
    /*sin2[13].move(Frame);
    sin2[14].move(Frame);
    sin2[15].move(Frame);
    sin2[16].move(Frame);
    sin2[17].move(Frame);
    sin2[18].move(Frame);*/
  }

}

void Sinus::son_lance(){
  if(no==0){
    vu.play();
    no++;
  }
}

void Sinus::drawTo(RenderWindow & window,cadre & cadre1){
  //os du bas
  sin[0].drawTo(window,cadre1);
  sin[1].drawTo(window,cadre1);
  sin[2].drawTo(window,cadre1);
  sin[3].drawTo(window,cadre1);
  sin[4].drawTo(window,cadre1);
  sin[5].drawTo(window,cadre1);
  sin[6].drawTo(window,cadre1);
  sin[7].drawTo(window,cadre1);
  sin[8].drawTo(window,cadre1);
  sin[9].drawTo(window,cadre1);
  sin[10].drawTo(window,cadre1);
  sin[11].drawTo(window,cadre1);
  sin[12].drawTo(window,cadre1);
  /*sin[13].drawTo(window);
  sin[14].drawTo(window);
  sin[15].drawTo(window);
  sin[16].drawTo(window);
  sin[17].drawTo(window);
  sin[18].drawTo(window);*/
  //os du haut:
  sin2[0].drawTo(window,cadre1);
  sin2[1].drawTo(window,cadre1);
  sin2[2].drawTo(window,cadre1);
  sin2[3].drawTo(window,cadre1);
  sin2[4].drawTo(window,cadre1);
  sin2[5].drawTo(window,cadre1);
  sin2[6].drawTo(window,cadre1);
  sin2[7].drawTo(window,cadre1);
  sin2[8].drawTo(window,cadre1);
  sin2[9].drawTo(window,cadre1);
  sin2[10].drawTo(window,cadre1);
  sin2[11].drawTo(window,cadre1);
  sin2[12].drawTo(window,cadre1);
  /*  sin2[13].drawTo(window);
  sin2[14].drawTo(window);
  sin2[15].drawTo(window);
  sin2[16].drawTo(window);
  sin2[17].drawTo(window);
  sin2[18].drawTo(window);*/
  window.draw(cache_misere);
}
