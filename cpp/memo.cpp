      if(Timer.getElapsedTime().asSeconds()>0.1){
	if(gaster.gasterblaster.left==250.f){
	  if(rayon<600){
	    rayon+=100;
	  }
	}
	else{
	  gaster.gasterblaster.left+=50.f;
	}
	rect.setSize({50,rayon});
	gaster.sprite.setTextureRect(gaster.gasterblaster);
	Timer.restart();
      }

      if (rayon<600){
	window.draw(rect);
	gaster.drawTo(window);
      }


//life diminution

if (heart.lp_P.lp>12){
  heart.lp_P.takedamage(perte_vie);
 }
heart.lp_P.Karma(karma);
