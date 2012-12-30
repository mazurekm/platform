CC=g++
CFLAGS= -L./libs -lSDL -L./libs -lSDL_image -L./libs -lSDL_ttf
SRC=Application.cpp Character.cpp DynamicObject.cpp Enemy.cpp GlobalUtils.cpp main.cpp Map.cpp Menu.cpp Object.cpp Player.cpp StaticObject.cpp Timer.cpp
OBJ=$(addprefix obj/,$(addsuffix .o,$(SRC)))
TARGET=platformowa

$TARGET: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
obj/%.cpp.o: src/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm $(OBJ) $(TARGET)
