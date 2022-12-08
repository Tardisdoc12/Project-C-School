SFML_PATH=../../SFML-2.5.1/
ENTETE_PATH=../entete
undertale2:CFLAGS=-I$(SFML_PATH)include
CFLAGS2 = -I$(ENTETE_PATH)

%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS) $(CFLAGS2)

undertale2:collision.o sinus.o plateforme.o gameover.o os.o os_block.o os_bl.o os_wh.o slice.o player.o gb.o sanstete.o sanscorps.o menuDefaut.o button.o undertale1.o cadre.o menuItem.o life.o menustart.o parole.o menuact.o menuMercy.o menuFight.o
	g++ collision.o sinus.o plateforme.o gameover.o os.o os_block.o os_bl.o os_wh.o slice.o parole.o player.o menustart.o life.o gb.o sanstete.o sanscorps.o button.o menuDefaut.o cadre.o menuItem.o menuact.o menuMercy.o menuFight.o undertale1.o -o undertale2 -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -L$(SFML_PATH)lib
	rm *.o
	export LD_LIBRARY_PATH=$(SFML_PATH)lib && ./undertale2

undertale1: collision.o sinus.o plateforme.o gameover.o os.o os_block.o os_bl.o os_wh.o slice.o player.o gb.o sanstete.o sanscorps.o menuDefaut.o button.o undertale1.o cadre.o menuItem.o life.o menustart.o parole.o menuact.o menuMercy.o menuFight.o

	g++ collision.o sinus.o plateforme.o gameover.o os.o os_block.o os_bl.o os_wh.o slice.o parole.o player.o menustart.o life.o gb.o sanstete.o sanscorps.o button.o menuDefaut.o cadre.o menuItem.o menuact.o menuMercy.o menuFight.o undertale1.o -o undertale1 -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
	rm *.o
	./undertale1
