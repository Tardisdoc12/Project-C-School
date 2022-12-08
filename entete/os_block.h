//os_block.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "os.h"
#include "player.h"
#include "cadre.h"
using namespace std;
using namespace sf;


#ifndef __os_block_h__
#define __os_block_h__

class Os_block:public Os{
public:
  Os_block();
  void degat(Player & heart,Clock & perte_de_vie,Clock & intervalle_degat,bool isJumping,bool blue,cadre & cadre1,int groundheight) override;
  void drawRect(RenderWindow & window);
  ~Os_block();
};
#endif
