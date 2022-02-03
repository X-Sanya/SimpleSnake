#ifndef SNAKE
#define SNAKE

#include <iostream>
#include <vector>

typedef unsigned uint;

enum direction {
	up,
	down,
	left,
	right
};

struct coordinates {
public:
	uint x;
	uint y;
	bool operator==(coordinates& coord) {
		if (this->x == coord.x && this->y == coord.y)
			return true;
		return false;
	}
};

class fruit {
private:
	coordinates coord;
public:
	fruit();
	bool is_fruit(coordinates);
	void set_coord(coordinates);
	coordinates get_coord();
	void draw();
};

class snake {
private:
	std::vector<coordinates> body;
	coordinates field;
	direction dir;
public:
	snake(coordinates);
	~snake(){}
	void eat();
	bool is_body(coordinates);
	bool is_head(coordinates);
	void draw_head();
	void draw_body();
	void change_dir(direction);
	void go();
};
#endif //SNAKE
