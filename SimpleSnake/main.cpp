#include <iostream>
#include "snake.h"
#include <conio.h>

char over_game[12][23] = {
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ','#','#','#',' ',' ',' ','#','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#','#','#'},
	{' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' '},
	{' ','#',' ','#','#',' ',' ','#','#','#','#',' ',' ','#',' ','#',' ','#',' ',' ','#','#','#'},
	{' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' '},
	{' ',' ','#','#','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ','#','#','#'},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ','#','#',' ',' ',' ','#',' ',' ','#',' ',' ','#','#','#',' ',' ','#','#','#',' ',' '},
	{' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' '},
	{' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#','#','#',' ',' ','#','#',' ',' ',' '},
	{' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' '},
	{' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ','#','#','#',' ',' ','#',' ','#',' ',' '}
};
char win_game[6][18] = {
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#','#',' ',' ','#'},
	{' ','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#'},
	{' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ','#',' ','#'},
	{' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ','#'},
	{' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ',' ','#','#'},
};
coordinates field = {30, 20};
snake* my_snake;
fruit my_fruit;

uint max(coordinates);
void start_game();
void menu();
void game_over();
void win();
void event_handler();
void draw_field(coordinates);

int main() {
	start_game();
	if (my_snake != nullptr)
		delete my_snake;
	my_snake = nullptr;
	system("pause");
	return 0;
}

void game_over() {
	if (my_snake != nullptr)
		delete my_snake;
	my_snake = nullptr;
	//system("cls");
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 23; j++) {
			std::cout << over_game[i][j];
		}
		std::cout << "\n";
	}
}
void win() {
	if (my_snake != nullptr)
		delete my_snake;
	my_snake = nullptr;
	//system("cls");
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 18; j++) {
			std::cout << win_game[i][j];
		}
		std::cout << "\n";
	}
}

void start_game() {
	my_snake = new snake(field);
	my_fruit.set_coord(field);
	try {
	while (true) {
		system("cls");
		event_handler();
		
			draw_field(field);
			if (my_snake->is_head(my_fruit.get_coord())) {
				my_snake->eat();
				my_fruit.set_coord(field);
			}
			if (my_snake->get_size() == max(field))
				throw true;
			my_snake->go();
	}
	}
	catch (bool e) {
		if (e)
			win();
		else
			game_over();
	}
}
void draw_field(coordinates field) {

	std::cout << "\n ";
	for (uint i = 0; i < field.x + 2; i++) {
		std::cout << "#";
	}
	std::cout << "\n";
	for (uint i = 0; i < field.y; i++) {
		std::cout << " #";
		for (uint j = 0; j < field.x; j++) {
			if (my_snake->is_head({ j, i }))
				my_snake->draw_head();
			else if (my_snake->is_body({ j, i }))
				my_snake->draw_body();
			else if (my_fruit.is_fruit({ j, i }))
				my_fruit.draw();
			else
				std::cout << " ";
		}
		std::cout << "#\n";
	}
	std::cout << " ";
	for (uint i = 0; i < field.x + 2; i++) {
		std::cout << "#";
	}
}
void event_handler() {
	if (_kbhit()) {
		auto key = _getch();
		if (key == 0 || key == 224) {
			auto s = _getch();
 			switch (s)
			{
			case 75:
				my_snake->change_dir(left);
				break;
			case 72:
				my_snake->change_dir(up);
				break;
			case 77:
				my_snake->change_dir(right);
				break;
			case 80:
				my_snake->change_dir(down);
				break;
			default:
				break;
			}
		}
	}
}
uint max(coordinates c) {
	return (c.x >= c.y) ? c.x : c.y;
}