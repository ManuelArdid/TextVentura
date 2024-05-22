OBJECTS=$(OBJ)/command.o $(OBJ)/game.o $(OBJ)/game_management.o $(OBJ)/graphic_engine.o $(OBJ)/screen.o $(OBJ)/space.o $(OBJ)/object.o $(OBJ)/player.o $(OBJ)/set.o $(OBJ)/die.o $(OBJ)/link.o $(OBJ)/inventory.o $(OBJ)/dialogue.o
SPACETEST=$(OBJ)/space.o $(OBJ)/set.o $(OBJ)/link.o
GAMETEST=$(OBJ)/game.o $(OBJ)/command.o $(OBJ)/die.o $(OBJ)/object.o $(OBJ)/player.o $(OBJ)/inventory.o $(OBJ)/set.o $(OBJ)/space.o $(OBJ)/link.o $(OBJ)/game_test.o $(OBJ)/dialogue.o $(OBJ)/game_management.o
CFLAGS=-Wall -pedantic -g
INCLUDE=-I./include
INC=./include
OBJ=./obj
SRC=./src

# Use "gcc -MM -I./include ./src/*.c" to get the dependencies

.PHONY: clear clean

###################################################
# Main game
###################################################
all: game
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./game data.dat -l fchlog

run_without_log: game 
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./game data.dat

run_auto_definite_game: game clear
	./game data.dat < autorun
	
run_auto_game1: game clear
	./game data.dat < ./FileTests/Recorrido1.oca
	
run_auto_game2: game clear
	./game data.dat < ./FileTests/Recorrido2.oca

run_auto_game3: game clear
	./game data.dat < ./FileTests/Recorrido3.oca

run_auto_game4: game clear
	./game data.dat < ./FileTests/Recorrido4.oca

run_game_with_test1: game
	valgrind -s --leak-check=full --track-origins=yes --show-leak-kinds=all ./game ./FileTests/test1.dat

run_game_with_test2: game
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./game ./FileTests/test2.dat

run_game_with_test3: game
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./game ./FileTests/test3.dat

game: $(OBJ)/game_loop.o $(OBJECTS)
	gcc $(OBJ)/game_loop.o $(OBJECTS) -o game

$(OBJ)/game_loop.o: src/game_loop.c include/game.h include/command.h \
 include/types.h include/die.h include/object.h include/player.h \
 include/inventory.h include/set.h include/space.h include/link.h \
 include/dialogue.h include/game_management.h include/game.h \
 include/graphic_engine.h
	gcc $(CFLAGS) -c $(SRC)/game_loop.c -o $@ $(INCLUDE)

$(OBJ)/command.o: src/command.c include/command.h include/types.h
	gcc $(CFLAGS) -c $(SRC)/command.c -o $@ $(INCLUDE)

$(OBJ)/game.o: src/game.c include/game.h include/command.h include/types.h \
 include/die.h include/object.h include/player.h include/inventory.h \
 include/set.h include/space.h include/link.h include/dialogue.h \
 include/game_management.h include/game.h
	gcc $(CFLAGS) -c $(SRC)/game.c -o $@ $(INCLUDE)
	
$(OBJ)/game_management.o: src/game_management.c include/game_management.h \
 include/game.h include/command.h include/types.h include/die.h \
 include/object.h include/player.h include/inventory.h include/set.h \
 include/space.h include/link.h include/dialogue.h
	gcc $(CFLAGS) -c $(SRC)/game_management.c -o $@ $(INCLUDE)
	
$(OBJ)/graphic_engine.o: src/graphic_engine.c include/graphic_engine.h \
 include/game.h include/command.h include/types.h include/die.h \
 include/object.h include/player.h include/inventory.h include/set.h \
 include/space.h include/link.h include/dialogue.h include/command.h \
 include/dialogue.h include/screen.h
	gcc $(CFLAGS) -c $(SRC)/graphic_engine.c -o $@ $(INCLUDE)
	
$(OBJ)/screen.o: src/screen.c include/screen.h
	gcc $(CFLAGS) -c $(SRC)/screen.c -o $@ $(INCLUDE)
	
$(OBJ)/space.o: src/space.c include/space.h include/types.h include/link.h \
 include/object.h include/set.h include/types.h
	gcc $(CFLAGS) -c $(SRC)/space.c -o $@ $(INCLUDE)

$(OBJ)/object.o: src/object.c include/object.h include/types.h
	gcc $(CFLAGS) -c $(SRC)/object.c -o $@ $(INCLUDE)
	 
$(OBJ)/player.o: src/player.c include/player.h include/types.h \
 include/inventory.h include/set.h include/object.h include/inventory.h
	gcc $(CFLAGS) -c $(SRC)/player.c -o $@ $(INCLUDE)

$(OBJ)/set.o: src/set.c include/set.h include/types.h
	gcc $(CFLAGS) -c $(SRC)/set.c -o $@ $(INCLUDE)
	
$(OBJ)/die.o: src/die.c include/die.h include/types.h
	gcc $(CFLAGS) -c $(SRC)/die.c -o $@ $(INCLUDE)

$(OBJ)/link.o: src/link.c include/link.h include/types.h
	gcc $(CFLAGS) -c $(SRC)/link.c -o $@ $(INCLUDE)

$(OBJ)/inventory.o: src/inventory.c include/inventory.h include/set.h \
 include/types.h include/object.h
	gcc $(CFLAGS) -c $(SRC)/inventory.c -o $@ $(INCLUDE)

$(OBJ)/dialogue.o: src/dialogue.c include/dialogue.h include/types.h \
 include/command.h include/space.h include/link.h
	gcc $(CFLAGS) -c $(SRC)/dialogue.c -o $@ $(INCLUDE)
	
###################################################
# Clean up
###################################################
clean:
	rm -rf *_test game fchlog


###################################################
# Directory
###################################################
directory:
	mv -i *.c src
	mv -i *.h include
	mv -i *.o obj
	
	
###################################################
# Space test 
###################################################
run_space_test: space_test clear
	valgrind -s --leak-check=full ./space_test

space_test: $(OBJ)/space_test.o $(SPACETEST)
	gcc $^ -o space_test

$(OBJ)/space_test.o: src/space_test.c include/space.h include/link.h \
 include/types.h include/set.h include/space_test.h include/test.h
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)


###################################################
# Die test 
###################################################
run_die_test: die_test clear
	valgrind -s --leak-check=full ./die_test

die_test: $(OBJ)/die_test.o $(OBJ)/die.o
	gcc $^ -o die_test

$(OBJ)/die_test.o: src/die_test.c include/die.h include/types.h \
 include/die_test.h include/test.h
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)


###################################################
# Set test 
###################################################
run_set_test: set_test clear
	valgrind -s --leak-check=full ./set_test

set_test: $(OBJ)/set_test.o $(OBJ)/set.o
	gcc $^ -o set_test

$(OBJ)/set_test.o: src/set_test.c include/set.h include/types.h \
 include/set_test.h include/test.h
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)


###################################################
# Link test 
###################################################
run_link_test: link_test clear
	valgrind -s --leak-check=full ./link_test

link_test: $(OBJ)/link_test.o $(OBJ)/link.o
	gcc $^ -o link_test

$(OBJ)/link_test.o: src/link_test.c include/link_test.h include/link.h \
 include/types.h include/test.h
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)


###################################################
# Player test
###################################################
run_player_test: player_test clear
	valgrind -s --leak-check=full ./player_test

player_test: $(OBJ)/player_test.o $(OBJ)/player.o $(OBJ)/set.o $(OBJ)/inventory.o
	gcc $^ -o player_test

$(OBJ)/player_test.o: src/player_test.c include/player_test.h include/player.h \
 include/types.h include/inventory.h include/set.h include/object.h \
 include/test.h include/types.h
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)


###################################################
# Inventory test 
###################################################
run_inventory_test: inventory_test 
	valgrind -s --leak-check=full ./inventory_test

inventory_test: $(OBJ)/inventory_test.o $(OBJ)/inventory.o $(OBJ)/set.o
	gcc $^ -o inventory_test

$(OBJ)/inventory_test.o: src/inventory_test.c include/inventory_test.h \
 include/inventory.h include/set.h include/types.h include/object.h \
 include/test.h include/types.h
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)
	
	
###################################################
# Object test 
###################################################
run_object_test: object_test clear
	valgrind -s --leak-check=full ./object_test

object_test: $(OBJ)/object_test.o $(OBJ)/object.o
	gcc $^ -o object_test

$(OBJ)/object_test.o: src/object_test.c include/object.h include/types.h \
 include/object_test.h include/test.h
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)


###################################################
# Game test 
###################################################
run_game_test: game_test 
	valgrind -s --leak-check=full ./game_test

game_test: $(OBJ)/game_test.o $(GAMETEST)
	gcc $^ -o game_test

$(OBJ)/game_test.o: src/game_test.c include/game.h include/command.h \
 include/types.h include/die.h include/object.h include/player.h \
 include/inventory.h include/set.h include/space.h include/link.h \
 include/dialogue.h include/game_test.h include/test.h
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)
	
	
###################################################
# Doxygen 
###################################################
doxygen:
	doxygen Doxyfile
	
	
