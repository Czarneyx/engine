all:
	g++ -c ./src/*.cpp
	g++ ./*.o -o application -lsfml-graphics -lsfml-window -lsfml-system
	./application