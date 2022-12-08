//menuFight.cpp
#include "menuFight.h"

menuFight::menuFight(SansTete st){
  if (!font.loadFromFile("../Font/DTM-Mono.otf")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  fight.setFont(font);
  fight.setString("* Sans");
  fight.setPosition({120.f,370.f});
  if (!Att.loadFromFile("../Sprite/Fight/attack_nous.png")){
    cout<<"EXIT_FAILURE"<<endl;
  }
  parole_sans.setPosition(st);
  Attack.setTexture(Att);
  Attack.setPosition({120.f,370.f});
  for (int i=0;i<8;i++){
    gaster.insert(gaster.end(),gb);
    os_wh.insert(os_wh.end(),os_wh2);
    os_bl.insert(os_bl.end(),os_bl2);
  }

}

void menuFight::Duree_tour(float duree,bool & ds_fight,bool & uTurn,Clock & combat,Clock & Timer,int & whereMenu,Player & heart,bool blue,bool & isJumping,bool & plafond,cadre & cadre1,int groundheight,Clock & bulle){
  if(!uTurn){
    nbr_bulle=0;
    if(combat.getElapsedTime().asSeconds()>duree){
      if((nbr_tour!=1)||(parole_sans.retour_normal)){
        uTurn=true;
        presse=0;
        whereMenu=4;
        cadre1.animationFinFight(Timer);
        ds_fight=false;
      }
      if((parole_sans.fin_de_tour)&&(!parole_sans.retour_normal)){
        parole_sans.setText("Huh. Always wondered\n why people never use\n their strongest\n attack first!",bulle,0.01f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
          if(parole_sans.fin_de_tour){
            parole_sans.retour_normal=true;
            parole_sans.fin_de_tour=false;
          }
        }
      }
    }
    heart.movement(blue,isJumping,plafond,groundheight,cadre1,p1.on_plateforme);
  }
}


void menuFight::select(Event event,Player & heart,bool & uTurn,cadre & cadre1,Clock & Timer,Clock & combat,slice & slice1,bool & animation_attack,Clock & time_phase_attack_1,Clock & red,int & groundheight){
  //on choisit qui on attack+sans parle avec le joueur:
  //out<<"try it"<<endl;
  if (event.type==sf::Event::KeyPressed){
    switch(event.key.code){
    case sf::Keyboard::Return:
      if (presse==0){
	presse=1;
	animation_attack=false;
      }
      else if ((presse==1)&&(!animation_attack)){
	nbr_tour+=1;
	animation_attack=true;
  parole_sans.effacement(event);
      }
      else if ((presse==2)&&(!sans_parle)){
	sans_parle=true;
	heart.setPosition({900.f,0.f});
      }
      if((presse==2)&&(sans_parle)&&(parole_sans.fini_parle)){
	animation_attack=false;
	if(nbr_tour==1){
	  if (nbr_bulle<2){
	    parole_sans.effacement(event);
	    parole_sans.parole1="";
	    nbr_bulle+=1;
	  }
	  else{
	    parole_sans.effacement(event);
	    sans_parle=false;
	    cadre1.animationDebutFight(Timer,groundheight,[&](float x, float y){
					       heart.setPosition({x,y});
					     });
	    presse=3;
	    uTurn=false;
	    combat.restart();
	    time_phase_attack_1.restart();
	    red.restart();
	    red_rect_bool=true;
	  }
	}
  if(nbr_tour==2){
	  if (nbr_bulle<1){
	    parole_sans.effacement(event);
	    parole_sans.parole1="";
	    nbr_bulle+=1;
	  }
	  else{
	    parole_sans.effacement(event);
	    sans_parle=false;
	    cadre1.animationDebutFight(Timer,groundheight,[&](float x, float y){
					       heart.setPosition({x,y});
					     });
	    presse=3;
	    uTurn=false;
	    combat.restart();
	    time_phase_attack_1.restart();
	    red.restart();
	    red_rect_bool=true;
	  }
	}
      }

    }
  }
  //les différents cas maintenant:
  if (presse==0){
    fight.setPosition({120.f,370.f});
    fight.setString("* Sans");
    fight.setFillColor(Color::White);
    heart.setPosition({100.f,380.f});
    viseur.setPosition({70.f,355.f});
    viseur.setSize(sf::Vector2f(20.f,cadre1.tailleY-0.2f));
  }
  else if ((presse==1)&&(!animation_attack)){
    heart.setPosition({900.f,0.f});
    Attack.setPosition({100.f,360.f});
    Attack.setScale({1.1f,1.58f});
    slice1.slice_anim.left=0.f;
    slice1.slice_sprite.setTextureRect(slice1.slice_anim);
  }
  else if(presse==2){
    sans_parle=true;
  }
}


void menuFight::turn_attack(cadre & cadre1,slice & slice1,Clock & slice_jouer,SansTete & sanshead,bool & animation_attack){
  if ((presse==1)&&(!animation_attack)){
    slice1.slice_sprite.setPosition({sanshead.getX()+5.f,sanshead.getY()-70.f});
    if (viseur.getPosition().x<=cadre1.getX()+0.45*cadre1.tailleX){
      viseur.setPosition({viseur.getPosition().x+5.f,viseur.getPosition().y});
    }
    else{
      animation_attack=true;
      nbr_tour+=1;
    }
  }
  if ((presse==1)&&(animation_attack)){
    slice1.animation(slice_jouer);
    if ((sanshead.getX()>150)&&(!fin_animation)){
      sanshead.move({-12.f,0.f});
    }
    if (slice1.slice_anim.left>=150){
      fin_animation=true;
    }
    if (fin_animation){
      if (sanshead.getX()<=325){
	sanshead.move({12.f,0.f});
      }
      else{
	fin_animation=false;
	presse=2;
	sans_parle=true;

      }
    }
  }
}

void menuFight::comeBack(bool & ds_fight,Event event){
  if(presse==0){
    if (event.type==sf::Event::KeyPressed){
      switch(event.key.code){
      case sf::Keyboard::Key::X:
	ds_fight=false;
      }
    }
  }
}

void menuFight::drawTo(RenderWindow & window,Player & heart,life & lp_P,cadre & cadre1,slice & slice1,bool & animation_attack, Os_block & block1,Sinus & sin){
  if(presse==0){
    window.draw(fight);
  }
  if (presse==1){
    window.draw(Attack);
    window.draw(viseur);
  }
  if((presse==1)&&(animation_attack)){
    slice1.drawTo(window);
  }
  if (sans_parle){
    parole_sans.drawTo(window);
  }
  //cout<<presse<<endl;
  if (presse==3){
    if(nbr_tour==1){
      if(!block1.test){
        if(red_rect_bool){
  	block1.drawRect(window);
        }
        else{
  	block1.Os::drawTo(window,cadre1);
        }
      }
      sin.drawTo(window,cadre1);
      if (affiche_gb){
        gaster[0].drawTo(window);
        gaster[1].drawTo(window);
        gaster[2].drawTo(window);
        gaster[3].drawTo(window);
      }
      if (affiche_gb){
        gaster[4].drawTo(window);
        gaster[5].drawTo(window);
        gaster[6].drawTo(window);
        gaster[7].drawTo(window);
      }
      if((nbr_tour==1)&&(parole_sans.fin_de_tour)){
        parole_sans.drawTo(window);
      }
    }
    if(nbr_tour==2){
      p1.drawTo(window,cadre1);
      os_bl[0].drawTo(window,cadre1);
      os_bl[1].drawTo(window,cadre1);
      os_wh[0].drawTo(window,cadre1);
      os_wh[1].drawTo(window,cadre1);
      gaster[0].drawTo(window);
      gaster[1].drawTo(window);
    }
  }
}

void menuFight::sansTalking(Clock & appear){
  if (sans_parle){
    if(nbr_tour==1){
      if(nbr_bulle==0){
	parole_sans.setText("It's a beautiful day \noutside. \nBirds are singing.",appear,0.01f);
      }
      else if (nbr_bulle==1){
	parole_sans.setText("Flowers are blooming.\n On days like this,\nkids like you...",appear,0.01f);
      }
      else if (nbr_bulle==2){
	parole_sans.setText("Should be\n burning in\n HELL !!!",appear,0.1f);
      }
    }
    else if (nbr_tour==2){
      if(nbr_bulle==0){
        parole_sans.setText("Don't forget!\nIf the bone is blue\ndon't move",appear,0.01f);
      }
      else if(nbr_bulle==1){
        parole_sans.setText("But please! Move!\nYou'll help me to kill\nyou!",appear,0.01f);
      }
    }
  }
}

void menuFight::phase_attack_1(cadre & cadre1, Clock & time_phase_attack_1, Os_block & block1,int groundheight,Clock & red_block,Player & heart,bool & blue,Clock & attack,Sinus & sin,Clock & sinus_move,Clock & gb_move,Clock & gb_attack,Clock & gb_move2,Clock & gb_attack2,int & copie_ground){
  if (presse==3){
    if (nbr_tour==1){
      if (time_phase_attack_1.getElapsedTime().asSeconds()<0.4f){
      	blue=true;
      	heart.block=true;
      	heart.couleur(blue);
      	red_block.restart();
      	block1.position({float(cadre1.getX()-0.135*cadre1.tailleX-5.f),groundheight+25.f});
      	sin.setPosition(cadre1,{float(cadre1.getX()-0.5*cadre1.spriteCadre.getGlobalBounds().width),groundheight+21.f});
      }
      else{
      	blue=false;
      	heart.couleur(blue);
      	if(red_block.getElapsedTime().asSeconds()>0.5f){
      	  red_rect_bool=false;
      	}
      	if(!red_rect_bool){
          block1.Os::son_lance();
      	  block1.Os::animation_v(attack,0.05f,-20.f);
      	}
      }
      if ((time_phase_attack_1.getElapsedTime().asSeconds()>1.7f)){
         sin.son_lance();
	       sin.move({3.5f,0.f},sinus_move);

         if (time_phase_attack_1.getElapsedTime().asSeconds()<2.3f){
           gaster[0].rotation(0.f);
           gaster[0].position({float(cadre1.getX()-0.14*cadre1.tailleX),0.f});
           gaster[1].rotation(-90.f);
           gaster[1].position({0.f,float(cadre1.getY()-0.4*cadre1.tailleY)});
           gaster[2].rotation(-270.f);
           gaster[2].position({800.f,float(cadre1.getY()+0.4*cadre1.tailleY)});
           gaster[3].rotation(180.f);
           gaster[3].position({float(cadre1.getX()+0.14*cadre1.tailleX),700.f});
           affiche_gb=true;
         }
      }
      if (time_phase_attack_1.getElapsedTime().asSeconds()>3.5f){
        this->attack_gaster_carre(gb_move,gb_attack,cadre1);
        if(time_phase_attack_1.getElapsedTime().asSeconds()<4.2f){
          gaster[6].position({0.f,700.f});
          gaster[6].rotation(-133+360);
          gaster[7].position({800.f,700.f});
          gaster[7].rotation(133);

        }
      }
      if((time_phase_attack_1.getElapsedTime().asSeconds()>5.5f)&&(time_phase_attack_1.getElapsedTime().asSeconds()<8.5f)){
        this->attack_gaster_diag(gb_move2,gb_attack2,cadre1);
        if ((time_phase_attack_1.getElapsedTime().asSeconds()>6.5f)&&(time_phase_attack_1.getElapsedTime().asSeconds()<7.f)){
          gaster[0].reinitialisation({float(cadre1.getX()-0.14*cadre1.tailleX),0.f});
          gaster[1].reinitialisation({0.f,float(cadre1.getY()-0.4*cadre1.tailleY)});

          gaster[2].reinitialisation({800.f,float(cadre1.getY()+0.4*cadre1.tailleY)});

          gaster[3].reinitialisation({float(cadre1.getX()+0.14*cadre1.tailleX),700.f});
        }
      }
      if ((time_phase_attack_1.getElapsedTime().asSeconds()<10.f)&&(time_phase_attack_1.getElapsedTime().asSeconds()>9.5f)){
        gaster[4].reinitialisation({0.f,cadre1.getY()});
        gaster[4].rotation(-90);
        gaster[4].setScale({2.f,1.f});
        gaster[5].reinitialisation({800.f,cadre1.getY()});
        gaster[5].rotation(90);
        gaster[5].setScale({2.f,1.f});
      }
      if (time_phase_attack_1.getElapsedTime().asSeconds()>10.f){
        if((gaster[4].getX()<cadre1.getX()-0.2*cadre1.tailleX)){
          if(!gaster[4].gb_block){
            gaster[4].move({5.f,0.f});
            //gb_attack2.restart();
          }
        }
        else{
          gaster[4].gb_block=true;
        }
        if(gaster[4].gb_block){
          gaster[4].play_attaque();

          gaster[4].animation(gb_attack2,2);
          //gb_attack2.restart();
        }
        if((gaster[5].getX()>cadre1.getX()+0.2*cadre1.tailleX)){
          if(!gaster[5].gb_block){
            gaster[5].move({-5.f,0.f});
          }
        }
        else{
          gaster[5].gb_block=true;
        }
        if(gaster[5].gb_block){
          gaster[5].play_attaque();
          gaster[5].animation(gb_attack2,3);
        }
        if (gb_attack2.getElapsedTime().asSeconds()>0.08f){
          gb_attack2.restart();
        }
      }
      if ((time_phase_attack_1.getElapsedTime().asSeconds()>15.f)&&(!parole_sans.fin_de_tour)){
        parole_sans.fin_de_tour=true;
      }
      //fin du tour1
    }
    if(nbr_tour==2){
      blue=true;
      heart.couleur(blue);
      if(time_phase_attack_1.getElapsedTime().asSeconds()<0.2f){
        red_block.restart();
        attack.restart();
        gb_move2.restart();
        sinus_move.restart();
        gb_attack.restart();
        gb_move.restart();
        p1.setPosition(float(cadre1.getX()-cadre1.spriteCadre.getGlobalBounds().width/2),cadre1.getY()+10.f);
        os_bl[0].setScale({1.7f,2.7f});
        os_bl[1].setScale({1.7,2.7f});
        os_bl[0].position({float(cadre1.getX()-0.7*cadre1.spriteCadre.getGlobalBounds().width),float(cadre1.getY()+0.35*cadre1.spriteCadre.getGlobalBounds().height+2.f+19.f)});
        os_bl[1].position({float(cadre1.getX()+0.7*cadre1.spriteCadre.getGlobalBounds().width),float(cadre1.getY()+0.35*cadre1.spriteCadre.getGlobalBounds().height+2.f+19.f)});
        os_wh[0].setScale({1.5f,1.f});
        os_wh[1].setScale({1.5,1.f});
        os_wh[0].position({float(cadre1.getX()-0.7*cadre1.spriteCadre.getGlobalBounds().width),float(cadre1.getY()+0.35*cadre1.spriteCadre.getGlobalBounds().height+2.f+19.f)});
        os_wh[1].position({float(cadre1.getX()+0.7*cadre1.spriteCadre.getGlobalBounds().width),float(cadre1.getY()+0.35*cadre1.spriteCadre.getGlobalBounds().height+2.f+19.f)});
        gaster[0].reinitialisation({0.f,float(groundheight+17.f)});
        gaster[0].rotation(-90.f);
        gaster[1].reinitialisation({800.f,float(groundheight+17.f)});
        gaster[1].rotation(90.f);
      }
      if(time_phase_attack_1.getElapsedTime().asSeconds()>0.2f){
        if(p1.rect_wh.getPosition().x<cadre1.getX()-0.1*cadre1.spriteCadre.getGlobalBounds().width){
          p1.move(heart, 0.01f,gb_move2,3.5f);
        }
        if (red_block.getElapsedTime().asSeconds()>0.1f){
          //os bleu
          os_bl[0].animation_h(attack,0.01f,2.8f);
          os_bl[1].animation_h(attack,0.01f,-2.8f);
          if(attack.getElapsedTime().asSeconds()>0.01f){
            attack.restart();
          }
        }
        if (red_block.getElapsedTime().asSeconds()>0.7f){
          //os_blanc
          os_wh[0].animation_h(sinus_move,0.01f,2.8f);
          os_wh[1].animation_h(sinus_move,0.01f,-2.8f);
          if(sinus_move.getElapsedTime().asSeconds()>0.01f){
            sinus_move.restart();
          }
        }
        if (red_block.getElapsedTime().asSeconds()>2.3f){
          os_wh[0].position({float(cadre1.getX()-0.7*cadre1.spriteCadre.getGlobalBounds().width),float(cadre1.getY()+0.35*cadre1.spriteCadre.getGlobalBounds().height+2.f+19.f)});
          os_wh[1].position({float(cadre1.getX()+0.7*cadre1.spriteCadre.getGlobalBounds().width),float(cadre1.getY()+0.35*cadre1.spriteCadre.getGlobalBounds().height+2.f+19.f)});
          os_bl[0].position({float(cadre1.getX()-0.7*cadre1.spriteCadre.getGlobalBounds().width),float(cadre1.getY()+0.35*cadre1.spriteCadre.getGlobalBounds().height+2.f+19.f)});
          os_bl[1].position({float(cadre1.getX()+0.7*cadre1.spriteCadre.getGlobalBounds().width),float(cadre1.getY()+0.35*cadre1.spriteCadre.getGlobalBounds().height+2.f+19.f)});
          red_block.restart();
        }
        if (gb_move.getElapsedTime().asSeconds()>0.7f){
          i2=0;
          if(gaster[0].getX()<cadre1.getX()-0.6*cadre1.spriteCadre.getGlobalBounds().width){
            gaster[0].move({3.5f,0.f});
          }
          else{
            i2++;
          }
          if(gaster[1].getX()>cadre1.getX()+0.6*cadre1.spriteCadre.getGlobalBounds().width){
            gaster[1].move({-3.5,0.f});
          }
          else{
            i2++;
          }
          if(i2==2){
            gaster[0].play_attaque();
            gaster[0].animation(gb_attack,9);
            gaster[1].play_attaque();
            gaster[1].animation(gb_attack,9);
            if (gb_attack.getElapsedTime().asSeconds()>0.08f){
              gb_attack.restart();
            }
          }
        }
        if(gb_move.getElapsedTime().asSeconds()>2.9f){
          gb_move.restart();
          gaster[0].reinitialisation({0.f,float(groundheight+17.f)});
          gaster[1].reinitialisation({800.f,float(groundheight+17.f)});
        }
      }
    }
  }
}

void menuFight::damage(Os_block & block1,Player & heart,Clock & perte_de_vie,Clock & intervalle_degat,bool isJumping,bool blue,cadre & cadre1,int groundheight,Sinus & sin){
  for (int h=0;h<gaster.size();h++){
    gaster[h].degat(heart,perte_de_vie,intervalle_degat);
    os_bl[h].degat(heart,perte_de_vie,intervalle_degat,isJumping,blue,cadre1,groundheight);
    os_wh[h].degat(heart,perte_de_vie,intervalle_degat,isJumping,blue,cadre1,groundheight);
  }
  block1.degat(heart,perte_de_vie,intervalle_degat,isJumping,blue,cadre1,groundheight);
  sin.degat(heart,perte_de_vie,intervalle_degat,isJumping,blue,cadre1,groundheight);
  if(intervalle_degat.getElapsedTime().asSeconds()>0.06f){
    intervalle_degat.restart();
  }

}

void menuFight::attack_gaster_carre(Clock & gb_move,Clock & gb_attack,cadre & cadre1){
  if (gb_move.getElapsedTime().asSeconds()>0.008f){
    i=0;
    if((gaster[0].getY()<cadre1.getY()-0.5*cadre1.tailleY)&&(!gaster[0].gb_block)){
      gaster[0].move({0.f,5.f});
    }
    else{
      gaster[0].gb_block=true;
      i+=1;
      //gb_attack.restart();
    }
    if((gaster[2].getX()>cadre1.getX()+0.2*cadre1.tailleX)&&(!gaster[2].gb_block)){
      gaster[2].move({-4.5f,0.f});
    }
    else{
      gaster[2].gb_block=true;
      i+=1;
      //gb_attack.restart();
    }
    if((gaster[3].getY()>cadre1.getY()+0.5*cadre1.tailleY)&&(!gaster[3].gb_block)){
      gaster[3].move({0.f,-4.5f});
    }
    else{
      gaster[3].gb_block=true;
      i+=1;
      //gb_attack.restart();
    }
    if((gaster[1].getX()<cadre1.getX()-0.2*cadre1.tailleX)&&(!gaster[1].gb_block)){
      gaster[1].move({5.f,0.f});
      //gb_attack.restart();
    }
    else{
      //cout<<gaster[1].rayon<<endl;
      gaster[1].gb_block=true;
      i+=1;
    }
    //cout<<i<<endl;
    if (i==4){
      gaster[0].play_attaque();
      gaster[1].play_attaque();
      gaster[2].play_attaque();
      gaster[3].play_attaque();
      gaster[0].animation(gb_attack,1);
      gaster[2].animation(gb_attack,3);
      gaster[3].animation(gb_attack,4);
      gaster[1].animation(gb_attack,2);
      if (gb_attack.getElapsedTime().asSeconds()>0.08f){
        gb_attack.restart();
      }
    }
    //gb_attack.restart();
    gb_move.restart();
  }
}

void menuFight::attack_gaster_diag(Clock & gb_move,Clock & gb_attack,cadre & cadre1){
  if (gb_move.getElapsedTime().asSeconds()>0.008f){
    i2=0;
    if((gaster[6].getY()>cadre1.getY()+0.6*cadre1.tailleY)&&(!gaster[6].gb_block)){
      gaster[6].move({6.5f,-3.5f});
    }
    else{
      gaster[6].gb_block=true;
      i2+=1;
    }
    if((gaster[7].getY()>cadre1.getY()+0.6*cadre1.tailleY)&&(!gaster[7].gb_block)){
      gaster[7].move({-6.5f,-3.5f});
    }
    else{
      gaster[7].gb_block=true;
      i2+=1;
    }
    //cout<<i2<<endl;
    if (i2==2){

      gaster[7].play_attaque();
      gaster[6].play_attaque();
      gaster[6].animation(gb_attack,7);
      gaster[7].animation(gb_attack,8);
      if (gb_attack.getElapsedTime().asSeconds()>0.08f){
        gb_attack.restart();
      }
    }
    //gb_attack.restart();
    gb_move.restart();
  }
}

void menuFight::restart(Os_block & block1){
  red_rect_bool=true;
  p1.setPosition(900.,900.f);
  block1.os_anim.height=0.f;
  block1.os_sprite.setTextureRect(block1.os_anim);
  block1.test=false;
  nbr_tour=0;
  parole_sans.retour_normal=false;
  parole_sans.fin_de_tour=false;
  p1.on_plateforme=false;
  for (int i=0;i<gaster.size();i++){
    gaster[i].reinitialisation({900.f,900.f});
  }
}
