#include "snake.h"
#include <random>
#include <ctime>

snake::snake(coordinates f): field(f ) {
	coordinates temp = { 0,0 };
	this->body.push_back(std::make_pair(temp,right));
}
uint snake::get_size() {
	return this->body.size();
}
void snake::draw_head() {
	std::cout << "@";
}
void snake::draw_body() {
	std::cout << "*";
}
void snake::eat(){
	auto last = this->body.rbegin();
	coordinates coord = last->first;
	switch (last->second) {
	case up:
		coord.y++;
		if (coord.y == this->field.y)
			coord.y = 0;
		break;
	case down:
		coord.y--;
		if (coord.y < 0)
			coord.y = this->field.y - 1;
		break;
	case left:
		coord.x++;
		if (coord.x == this->field.x)
			coord.x = 0;
		break;
	case right:
		coord.x--;
		if (coord.x < 0)
			coord.y = this->field.x - 1;
		break;
	}
	if (this->is_head(coord))
		throw false;

	this->body.push_back(std::make_pair(coord, last->second));
}
bool snake::is_head(coordinates coord) {
	return coord == this->body[0].first;
}
void snake::go() {
	std::vector<std::pair<coordinates, direction>>::iterator it = this->body.begin();
	this->go(it);
	direction next = it->second;
	it++;
	for (auto before_it = this->body.begin(); it != this->body.end(); it++, before_it++) {
		this->go(it);
		direction temp = it->second;
		it->second = next;
		next = temp;
		if (this->is_head(it->first))
			throw false;
	}
}
void snake::go(std::vector<std::pair<coordinates, direction>>::iterator it) {
	switch (it->second)
	{
	case up:
		if (it->first.y == 0)
			it->first.y = this->field.y - 1;
		else
			it->first.y--;
		break;
	case down:
		it->first.y++;
		if (it->first.y == this->field.y)
			it->first.y = 0;
		break;
	case left:
		if (it->first.x == 0)
			it->first.x = this->field.x - 1;
		else
			it->first.x--;
		break;
	case right:
		it->first.x++;
		if (it->first.x == this->field.x)
			it->first.x = 0;
		break;
	}
}
void snake::change_dir(direction new_dir) {
	switch (new_dir)
	{
	case up:
		if (body[0].second == down)
			return;
		break;
	case down:
		if (body[0].second == up)
			return;
		break;
	case left:
		if (body[0].second == right)
			return;
		break;
	case right:
		if (body[0].second == left)
			return;
		break;
	default:
		break;
	}
	this->body[0].second = new_dir;
}
bool snake::is_body(coordinates coord) {
	auto it = this->body.begin();
	it++;
	for (; it != this->body.end(); it++) {
		if (it->first == coord) {
			return true;
		}
	}
	return false;
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