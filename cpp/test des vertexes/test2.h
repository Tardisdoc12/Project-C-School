#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
using namespace std;
using namespace sf;

#ifndef __test2_h__
#define __test2_h__


class Sinus2: public sf::Drawable, public sf::Transformable{
private:
  sf::VertexArray m_vertices;

public:
  sf::Texture m_os;
Sinus2(int nbr_os);
virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};




#endif
