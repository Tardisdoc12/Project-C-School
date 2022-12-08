#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "test2.h"
using namespace std;
using namespace sf;


int main(){
  srand(static_cast<unsigned int>(time(NULL)));




  //constante nécessaire:
  int gameWidth = 800;
  int gameHeight = 700;


  //definition de la fenêtre:
  Image icon;
  if(!icon.loadFromFile("../Sprite/Sans/spr_sans_bface_5.png")){
    return EXIT_FAILURE;
  }
  RenderWindow window(VideoMode(gameWidth, gameHeight,32), "test_fonctionne", Style::Titlebar |Style::Resize |Style::Close);
  window.setIcon(30,28,icon.getPixelsPtr());
  window.setVerticalSyncEnabled(true);

  Sinus2 test(1000);
  sf::Transform transform;
  sf::RenderStates states;

  sf::Clock timer;
  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      // Window closed or escape key pressed: exit
      if ((event.type == sf::Event::Closed) ||  ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
	       window.close();
         break;
      }
    }
    if (timer.getElapsedTime().asSeconds()>0.5f){
      transform.translate(5,0);
      states.transform= transform;
      states.texture=&test.m_os;
      timer.restart();
    }

    window.clear(Color(Color::Black));
    window.draw(test,states);
    window.display();
  }
  return EXIT_FAILURE;
 }
