#include "test2.h"

Sinus2::Sinus2(int nbr_os){
  if (!m_os.loadFromFile("spr_s_bonewall_0.png")){
    cout<<"ERROR"<<endl;
  }

  m_vertices.setPrimitiveType(sf::Quads);
  m_vertices.resize(nbr_os* 4);

  for (unsigned int j = 0; j < nbr_os; ++j){
    sf::Vertex* quad = &m_vertices[j * 4];

    //on definit les positions des cotés
    quad[0].position = sf::Vector2f(j*10+0,0);
    quad[1].position = sf::Vector2f(j*10+10, 0);
    quad[2].position = sf::Vector2f(j*10+10, (j%2)*50+50);
    quad[3].position = sf::Vector2f(j*10+0, (j%2)*50+50);

    // on définit ses quatre coordonnées de texture
    quad[0].texCoords = sf::Vector2f(0,0);
    quad[1].texCoords = sf::Vector2f(10,0);
    quad[2].texCoords = sf::Vector2f(10,50);
    quad[3].texCoords = sf::Vector2f(0,50);
  }
}



void Sinus2::draw(sf::RenderTarget & target, sf::RenderStates states) const{
  // on applique la transformation
  states.transform *= getTransform();

  // on applique la texture du tileset
  states.texture = &m_os;

  // et on dessine enfin le tableau de vertex
  target.draw(m_vertices, states);
}
