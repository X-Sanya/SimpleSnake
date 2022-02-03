#include <iostream>
#include "snake.h"
#include <conio.h>

coordinates field = {40, 20};
snake* my_snake;
fruit my_fruit;

void start_game();
void menu();
void game_over();
void win();
void draw_field(coordinates);

int main() {
	//snake* my_snake = new snake();
	start_game();
	if (my_snake != nullptr)
		delete my_snake;
	return 0;
}

void game_over() {
	if(my_snake!=nullptr)
	delete my_snake;
}
void win() {
	if (my_snake != nullptr)
	delete my_snake;
}

void start_game() {
	my_snake = new snake(field);
	my_fruit.set_coord(field);
	while (true) {
		system("cls");
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
		draw_field(field);
		if (my_snake->is_head(my_fruit.get_coord())) {
			my_snake->eat();
			my_fruit.set_coord(field);
		}
		my_snake->go();
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