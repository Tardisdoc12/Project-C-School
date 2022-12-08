//menuFight.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <SFML/Window.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "sanstete.h"
#include "player.h"
#include "life.h"
#include "cadre.h"
#include "gb.h"
#include "plateforme.h"
#include "menuDefaut.h"
#include "parole.h"
#include "slice.h"
#include "os_block.h"
#include "os.h"
#include "os_bl.h"
#include "os_wh.h"
#include "sinus.h"


using namespace std;
using namespace sf;

#ifndef __menuFight_h__
#define __menuFight_h__

class menuFight{
public:
  vector<GB> gaster;
  GB gb;
  vector<Os_bl> os_bl;
  Os_bl os_bl2;
  vector<Os_wh> os_wh;
  Os_wh os_wh2;
  bool affiche_gb=false;
  sf::RectangleShape viseur;
  Font font;
  bool fin_animation=false;
  Text fight;
  Sprite Attack;
  parole parole_sans;
  Texture Att;
  int nbr_tour=0;
  int presse=0;
  bool sans_parle=false;
  int nbr_bulle=0;
  bool red_rect_bool=true;
  int i=0;
  int i2=0;
  Plateforme p1;
  menuFight(SansTete st);

  void select(Event event,Player & heart,bool & uTurn,cadre & cadre1,Clock & Timer, Clock & combat,slice & slice1,bool & animation_attack, Clock & time_phase_attack_1,Clock & red,int & groundheight);

  void Duree_tour(float duree,bool & ds_fight,bool & uTurn,Clock & combat,Clock & Timer,int & whereMenu,Player & heart,bool blue,bool & isJumping,bool & plafond,cadre & cadre1,int groundheight,Clock & bulle);

  void turn_attack(cadre & cadre1,slice & slice1,Clock & slice_jouer,SansTete & sanshead,bool & animation_attack);

  void comeBack(bool & ds_fight,Event event);

  void drawTo(RenderWindow & window,Player & heart,life & lp_P,cadre & cadre1,slice & slice1,bool & animation_attack, Os_block & block1,Sinus & sin);

  void sansTalking(Clock & appear);

  void phase_attack_1(cadre & cadre1, Clock & time_phase_attack_1, Os_block & block1, int groundheight,Clock & red_block,Player & heart,bool & blue,Clock & attack,Sinus & sin,Clock & sinus_move,Clock & gb_move,Clock & gb_attack,Clock & gb_move2,Clock & gb_attack2,int & copie_ground);

  void damage(Os_block & block1,Player & heart,Clock & perte_de_vie,Clock & intervalle_degat,bool isJumping,bool blue,cadre & cadre1,int groundheight,Sinus & sin);

  void attack_gaster_carre(Clock & gb_move, Clock & gb_attack,cadre & cadre1);

  void attack_gaster_diag(Clock & gb_move,Clock & gb_attack,cadre & cadre1);

  void restart(Os_block & block1);
};
#endif
