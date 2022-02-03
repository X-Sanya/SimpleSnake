#include "snake.h"
#include <random>
#include <ctime>

snake::snake(coordinates f): field(f ), dir(right) {
	body.push_back({ 0,0 });
}
void snake::draw_head() {
	std::cout << "@";
}
void snake::draw_body() {
	std::cout << "*";
}
void snake::eat(){}
bool snake::is_head(coordinates coord) {
	return coord == this->body[0];
}
void snake::go() {
	switch (this->dir)
	{
	case up:
		if (this->body[0].y == 0)
			this->body[0].y = this->field.y - 1;
		else
			this->body[0].y--;
		break;
	case down:
		this->body[0].y++;
		if (this->body[0].y == this->field.y)
			this->body[0].y = 0;
		break;
	case left:
		if (this->body[0].x == 0)
			this->body[0].x = this->field.x - 1;
		else
			this->body[0].x--;
		break;
	case right:
		this->body[0].x++;
		if (this->body[0].x == this->field.x)
			this->body[0].x = 0;
		break;
	}
}
void snake::change_dir(direction new_dir) {
	this->dir = new_dir;
}


void fruit::draw() {
	std::cout << "$";
}
fruit::fruit() {
	this->set_coord({1,1});
}
void fruit::set_coord(coordinates field) {
	std::srand(std::time(nullptr));
	this->coord.x = std::rand() % field.x;
	this->coord.y = std::rand() % field.y;
}
bool fruit::is_fruit(coordinates coord) {
	return (this->coord == coord);
}
coordinates fruit::get_coord() {
	return this->coord;
}