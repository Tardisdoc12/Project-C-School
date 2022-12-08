//os_bl.cpp
#include"os_bl.h"
#include"collision.h"

Os_bl::Os_bl():Os(){
  //os bleu
  if (!os_texture.loadFromFile("../Sprite/Sans_attack/os_bl.png")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  os_sprite.setTexture(os_texture);
  os_sprite.setOrigin({os_sprite.getLocalBounds().width/2,os_sprite.getLocalBounds().height});
}

void Os_bl::degat(Player & heart,Clock & perte_de_vie,Clock & intervalle_degat,bool isJumping,bool blue,cadre & cadre1,int groundheight){
  //si on est mobile, on doit prendre des dégats(chute+appuie de touche)!!!
  if ( ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& heart.getX() > cadre1.getX()-0.5*cadre1.spriteCadre.getGlobalBounds().width)
	 || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && heart.getX() < cadre1.getX()+0.5*cadre1.spriteCadre.getGlobalBounds().width)
	 || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && heart.getY()<groundheight+6)
	 || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&  heart.getY() >=cadre1.getY()-0.5*cadre1.spriteCadre.getGlobalBounds().height) )
         || ((blue)&&(isJumping)) ){
    if (Collision::PixelPerfectTest(heart.sprite,os_sprite)){
      if(afficher){
        sound.play();
	       heart.lp_P.takedamage(perte_de_vie);
      }
    }
  }
}

Os_bl::~Os_bl(){
}
