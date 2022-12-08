#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <SFML/Window.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "parole.h"
#include "sanstete.h"
#include "gb.h"
#include "sanscorps.h"
#include "menuItem.h"
#include "menustart.h"
#include "life.h"
#include "button.h"
#include "player.h"
#include "cadre.h"
#include "menuDefaut.h"
#include "menuact.h"
#include "menuMercy.h"
#include "menuFight.h"
#include "slice.h"
#include "os.h"
#include "os_block.h"
#include "os_bl.h"
#include "gameover.h"
#include "plateforme.h"
#include "sinus.h"
using namespace std;
using namespace sf;


int main(){
  srand(static_cast<unsigned int>(time(NULL)));
  //création des attacks:
  Os_block os;
  Sinus sin;
  Clock sin_move;

  //Bouton de combat:
  Button Fight("../Sprite/Fight/fight.png");
  Button Items("../Sprite/item/item.png");
  Button Act("../Sprite/act/act.png");
  Button Mercy("../Sprite/mercy/mercy.png");
  Fight.setTextureRect(0,0,115,43);
  Items.setTextureRect(0,0,115,43);
  Act.setTextureRect(0,0,113,43);
  Mercy.setTextureRect(0,0,115,43);
  Fight.setPosition({100.f,600.f});
  Act.setPosition({250.f,600.f});
  Items.setPosition({400,600.f});
  Mercy.setPosition({550.f,600.f});
  DefautMenu FMenu(Fight,Act,Items,Mercy);
  bool uTurn=true;

  //Cadre de combat test:
  cadre cadre1;



  //constante nécessaire:
  int gameWidth = 800;
  int gameHeight = 700;
  Vector2f paddlesize(30,30);
  float deltaTime;
  RectangleShape rect({100,50});
  rect.setFillColor(Color::White);
  float rayon=0;

  //Gravity Constant:
  const float gravityspeed=0.15;
  bool isJumping=false;

  //definition de la fenêtre:
  Image icon;
  if(!icon.loadFromFile("../Sprite/Sans/spr_sans_bface_5.png")){
    return EXIT_FAILURE;
  }
  RenderWindow window(VideoMode(gameWidth, gameHeight,32), "Undertale", Style::Titlebar |Style::Resize |Style::Close);
  window.setIcon(30,28,icon.getPixelsPtr());
  window.setVerticalSyncEnabled(true);


  //Definition des personnages:
  Player heart(92,99,99,2,"../Sprite/heart/spr_heart_0.png");
  SansTete sanstete("../Sprite/Sans/sans_head.png");
  SansCorps sanscorps("../Sprite/Sans/sans_body.png");
  sanstete.sprite.setScale(3.f,3.f);
  sanscorps.sprite.setScale(3.f,3.f);
  sanstete.setTextureRect(34,0,35,30);
  sanstete.setPosition({325.f,100.f});
  sanscorps.setTextureRect(0,0,56,50);
  sanscorps.setPosition({sanstete.getX()-38.f,sanstete.getY()+75.f});


  //ça marche!!
  sf::SoundBuffer over;
  if(!over.loadFromFile("../Music/GameOver2.ogg")){
    cout<<"ERROR"<<endl;
  }
  sf::Sound game(over);
  game.setVolume(30);
  int no_replay2=0;
  sf::SoundBuffer test;
  if(!test.loadFromFile("../Music/fight.ogg")){
    cout<<"ERROR"<<endl;
  }
  sf::Sound music(test);
  sf::SoundBuffer title;
  if(!title.loadFromFile("../Music/menu.ogg")){
    cout<<"error"<<endl;
  }
  sf::Sound screen(title);
  int replay=0;

  GB gaster;
  gaster.position({250.f,60.f});
  //rect.setPosition({10.f,0.f});
  Clock gb_timer;
  // Création des Menus de combat et autres :
  //Message de base
  menustart Start;
  //menuItem:
  menuItem menu;
  //menu Act:
  menuact menuAct;
  //menu Mercy:
  menuMercy menu_Mercy;
  //menu de Combat:
  menuFight menu_fight(sanstete);
  //menu de gameover
  Gameover menu_gameover;

  //Proprieties:
  Time AITime=seconds(0.1f);
  bool isPlaying=false;
  bool PlayButtonSelected=true;
  bool ExitButtonSelected=false;
  bool PlayButtonPressed=false;
  bool ExitButtonPressed=false;
  Text pauseMessage;
  bool ds_item=false;
  bool ds_act=false;
  bool ds_mercy=false;
  bool ds_fight=false;
  bool ds_gameover=false;
  int tmort_next=0;
  int presse=4;
  bool plafond=false;
  bool blue=false;
  int Button=0;
  //durée:
  Clock clock;
  Clock Timer;
  Clock viseur_move;
  Clock combat;
  //pour les paroles :
  Clock appear;
  Clock bulle;
  //pour les points de vie:
  Clock perte_vie;
  Clock karma;
  Clock intervalle_degat;
  //slice:
  slice slice1;
  Clock slice_jouer;
  //os & block:
  Clock os_block_timer2;
  Clock os_block_timer;
  Clock red;
  //gasterblaster:
  Clock gb_move;
  Clock gb_attack;
  Clock gb_move2;
  Clock gb_attack2;
  bool animation_attack=false;
  int groundheight=cadre1.getY()+0.25*cadre1.tailleY;
  int copie_ground=cadre1.getY()+0.35*cadre1.spriteCadre.getGlobalBounds().height+2.f;
  int i=0;
  while(window.isOpen()){
    sanscorps.setPosition({sanstete.getX()-38.f,sanstete.getY()+75.f});
    Event event;
    if(isPlaying){
      screen.stop();
      if (i==0){
        music.setVolume(20);
        music.play();
        i++;
      }
      //fais les animations de l'attack du JOUEUR:
      menu_fight.turn_attack(cadre1,slice1,slice_jouer,sanstete,animation_attack);
      //restreint la durée d'un tour:
      //pour chaque tour, on peut changer la durée avec le 10.f qui va pouvoir varier! le reste c'est que pour les mouvement/positions des décors:
      menu_fight.Duree_tour(15.f,ds_fight,uTurn,combat,Timer,presse,heart,blue,isJumping,plafond,cadre1,groundheight,bulle);
      //parole:
      menu_fight.sansTalking(appear);
      //application karma
      heart.lp_P.Karma(karma);
      if(clock.getElapsedTime().asSeconds()>0.5f){
	       if(sanscorps.body.left==224){
	          sanscorps.body.left=0;
	       }
	       else{
	         sanscorps.body.left+=56;
	       }
         sanscorps.sprite.setTextureRect(sanscorps.body);
	       clock.restart();
      }
    }
    else{
      game.stop();
      no_replay2=0;
      if(replay==0){
        screen.setVolume(20);
        screen.play();
        replay++;
      }
      heart.couleur(blue);
    }
    while(window.pollEvent(event)){
      // Window closed or escape key pressed: exit
      if ((event.type == sf::Event::Closed) ||  ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
	      window.close();
        break;
      }
      if(ds_gameover){
	menu_gameover.changetext(event, tmort_next);
      }
      //retour du menu act jusque dans le menu par défaut:
      menuAct.comeback(event,ds_act,presse);
      //retour du menu Mercy jusque dans le menu par défaut:
      menu_Mercy.comeback(event,ds_mercy,presse);
      //retour du menu item dans le menu par défaut:
      menu.comeBack(event,ds_item,presse);
      //retour du menu Fight dans le menu par défaut:
      menu_fight.comeBack(ds_fight,event);

      if((!isPlaying)&&(!ds_gameover)){
	Start.etatmenu(PlayButtonSelected,ExitButtonSelected,PlayButtonPressed,ExitButtonPressed,event);
  menu_fight.restart(os);
  cadre1.animationFinFight(Timer);
      }
      if(isPlaying){
	if(!uTurn){
	  heart.released(event,isJumping,groundheight);
	}
	if(uTurn){
	  if((!ds_item)&&(!ds_fight)&&(!ds_act)&&(!ds_mercy)){
	    Button=FMenu.selectedButton(Button, heart.sprite,event,presse);
	  }
	  //on entre dans les différents menus:
	  if(ds_item){
	    menu.selected(heart,event);
	    menu.takeItem(event,heart,heart.lp_P,ds_item,presse);
	  }
	  if(ds_act){
	    menuAct.select(heart,event,ds_act,presse);
	  }
	  if(ds_mercy){
	    menu_Mercy.select(heart,event,ds_mercy,presse);
	  }
	  if(ds_fight){
	    menu_fight.select(event,heart,uTurn,cadre1,Timer,combat,slice1,animation_attack,os_block_timer,red,groundheight);
	  }
	}
      }
    }
    if(!isPlaying){
      Start.selected(window,PlayButtonPressed,ExitButtonPressed,isPlaying,PlayButtonSelected,ExitButtonSelected);
    }
    if (heart.lp_P.lp_purple<=0){
      music.stop();
      if(no_replay2==0){
        game.play();
        no_replay2++;
      }
      ds_gameover=true;
    }
    if(isPlaying){
      if(!uTurn){
        menu_fight.p1.hitbox(groundheight,heart,copie_ground);
	       heart.gravity(groundheight,plafond,isJumping,blue);
      }
      if((uTurn)&&(!ds_item)&&(!ds_act)&&(!ds_mercy)&&(!ds_fight)){
	//etat du jeu quand c'est à notre tour sans etre dans un menu quelconque
	FMenu.EtatDuMenu(Button,heart);
	pauseMessage.setFont(heart.lp_P.font);
	pauseMessage.setString("*You are going to have a \n very bad Time.");
	pauseMessage.setPosition({cadre1.spriteCadre.getPosition().x-320.f,cadre1.spriteCadre.getPosition().y-90.f});
	pauseMessage.setCharacterSize(40);
	if(presse==0){
	  combat.restart();
	  pauseMessage.setPosition({50.f,50.f});
	  pauseMessage.setString("");
	  ds_fight=true;
	  FMenu.buttons[0].etat.left=0;
	  FMenu.buttons[0].sprite.setTextureRect(FMenu.buttons[0].etat);
	}
	else if(presse==1){
	  ds_act=true;
	  pauseMessage.setString("");
	  FMenu.buttons[1].etat.left=0;
	  FMenu.buttons[1].sprite.setTextureRect(FMenu.buttons[1].etat);
	}
	else if(presse==2){
	  pauseMessage.setString("");
	  ds_item=true;
	  FMenu.buttons[2].etat.left=0;
	  FMenu.buttons[2].sprite.setTextureRect(FMenu.buttons[2].etat);
	}
	else if(presse==3){
	  ds_mercy=true;
	  pauseMessage.setString("");
	  FMenu.buttons[3].etat.left=0;
	  FMenu.buttons[3].sprite.setTextureRect(FMenu.buttons[3].etat);
	}
      }
      if(ds_fight){
	       menu_fight.phase_attack_1(cadre1,combat,os,groundheight,red,heart,blue,os_block_timer2,sin,sin_move,gb_move,gb_attack,gb_move2,gb_attack2,copie_ground);
         menu_fight.damage(os,heart,perte_vie,intervalle_degat,isJumping,blue,cadre1,groundheight,sin);

      }
      window.clear(Color(Color::Black));

      if ((!ds_gameover)&&(isPlaying)){
	window.draw(pauseMessage);
	cadre1.drawTo(window);
	sanscorps.drawTo(window);
	sanstete.drawTo(window);
	FMenu.drawTo(window,heart);
	heart.lp_P.drawTo(window);
	if (ds_item){
	  menu.drawTo(window,heart,ds_item,presse);

	}
	if (ds_act){
	  menuAct.drawTo(window,heart,ds_act,presse);
	}
	if (ds_mercy){
	  menu_Mercy.drawTo(window,heart,ds_mercy,presse);
	}
	heart.drawTo(window);
	if (ds_fight){
	  menu_fight.drawTo(window,heart,heart.lp_P,cadre1,slice1,animation_attack,os,sin);
	}
      }
      if ((ds_gameover)&&(isPlaying)){
	menu_gameover.drawTo(window,tmort_next, isPlaying, ds_gameover,heart);
	uTurn=true;
	menu_fight.nbr_tour=0;
	ds_fight=false;
	ds_item=false;
	ds_act=false;
	ds_mercy=false;
	presse=4;
  menu_fight.presse=0;
  i=0;
  replay=0;
      }
    }

    window.display();
  }
  return EXIT_FAILURE;
 }
