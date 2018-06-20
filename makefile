CXX = gcc
LIBS = -lallegro -lallegro_ttf -lallegro_font -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_primitives
CFLAGS = -Wall -Wextra

SRC = source/main.c source/menu.c source/tabuleiro.c

execute:
	$(CXX) -o PUBG.run $(SRC) $(LIBS) $(CFLAGS) $(INC)
	./PUBG.run

clear:
	rm PUBG.run