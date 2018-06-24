CXX = gcc
LIBS = -lallegro -lallegro_ttf -lallegro_font -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_primitives
CFLAGS = -Wall

SRC = source/main.c source/menu.c source/tabuleiro.c source/player.c source/staticStack.c source/staticQueue.c source/carta.c

execute:
	$(CXX) -o PUBG.run $(SRC) $(LIBS) $(CFLAGS) $(INC)
	./PUBG.run

clear:
	rm PUBG.run
