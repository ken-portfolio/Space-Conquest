#pragma once
#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>

// A mix of mathematical constructs and
// helper functions for game development.
//Does NOT require SFML to work, however
//is intended to be used with it.

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;
const int NORTHEAST = 4;
const int SOUTHEAST = 5;
const int SOUTHWEST = 6;
const int NORTHWEST = 7;

const int INVALID = -1;

void randomize();
int getRandomInt(const int);
bool chance(const int);
void hideConsole();
void showConsole();
double dist(const float, const float, const float, const float);
template<typename t> std::string cstr(const t& val);

class Dice {
private:
	int _sides;
public:
	Dice() : _sides(6) {};
	Dice(const int sides) : _sides(sides) {};
	int roll() const {
		return (rand() % _sides) + 1;
	}
};

struct Point {
	float x = 0.0f;
	float y = 0.0f;
	Point() {};
	Point(float x, float y) : x(x), y(y) {};
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

struct Cell {
	float x = INVALID;
	float y = INVALID;
	int width = INVALID;
	int height = INVALID;
	int column = INVALID;
	int row = INVALID;
	int index = INVALID;
};

class Grid {
private:
	int _cols, _rws;
	int _cellW, _cellH;
	float _x, _y;
public:
	Grid(const int, const int, const int, const int);

	int columns() const { return _cols; }
	int rows() const { return _rws; }
	int cellWidth() const { return _cellW; }
	int cellHeight() const { return _cellH; }

	int width() const { return _cols * _cellW; }
	int height() const { return _rws * _cellH; }
	int size() const { return _cols * _rws; }
	
	void setPosition(const float, const float);
	void move(const float, const float);
	Point at() const { return Point(_x, _y); }

	Cell cell(const int) const;
	Cell cell(const float, const float) const;
	Cell neighbor(const Cell&, const int);

};



void randomize() { srand(static_cast<unsigned int>(time(NULL))); }

int getRandomInt(const int maxValue) {
		return static_cast<int>(rand() % maxValue);
}

bool chance(const int percentage) {
	if (percentage <= 0) return false;
	if (percentage >= 100) return true;
	int r = (rand() * 100) + 1;
	return (r <= percentage);
}

void hideConsole() { ShowWindow(GetConsoleWindow(), SW_HIDE); }
void showConsole() { ShowWindow(GetConsoleWindow(), SW_SHOW); }

double dist(const float x1, const float y1, const float x2, const float y2) {
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}


template<typename t> std::string cstr(const t& val) {
	std::stringstream ss;
	ss << val;
	return ss.str();
}


std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

Grid::Grid(const int columns, const int rows, const int cellWidth, const int cellHeight) :
	_cols(columns), _rws(rows), _cellW(cellWidth), _cellH(cellHeight), _x(0.0f), _y(0.0f) {};

void Grid::setPosition(const float x, const float y) {
	_x = x;
	_y = y;
}
void Grid::move(const float x, const float y) {
	_x += x;
	_y += y;
}

Cell Grid::cell(const int index) const {
	Cell c;
	if (index < 0 || index > size() - 1) return c;
	c.index = index;
	c.height = cellHeight();
	c.width = cellWidth();
	c.column = c.index % columns();
	c.row = static_cast<int>(floor(c.index / columns()));
	c.x = at().x + (c.column * c.width);
	c.y = at().y + (c.row * c.height);
	return c;
}

Cell Grid::cell(const float x, const float y) const {
	Cell c;
	if (x < at().x || x >= (at().x + width())) return c;
	if (y < at().y || y >= (at().y + height())) return c;
	c.height = cellHeight();
	c.width = cellWidth();
	c.column = static_cast<int>(floor((x - at().x) / c.width));
	c.row = static_cast<int>(floor((y - at().y) / c.height));
	c.index = c.row * columns() + c.column;
	c.x = at().x + (c.column * c.width);
	c.y = at().y + (c.row * c.height);
	return c;
}

Cell Grid::neighbor(const Cell& srcCell, const int direction) {
	Cell c;
	if (direction < 0 || direction > 7) return c;
	if (srcCell.index == NULL) return c;
	if (srcCell.index < 0 || srcCell.index > size() - 1) return c;

	int idx = srcCell.index;
	switch (direction) {

	case (NORTH):
		idx -= columns();
		if (idx >= 0) c = cell(idx);
		break;

	case (SOUTH):
		idx += columns();
		if (idx < size()) c = cell(idx);
		break;

	case(EAST):
		idx += 1;
		if (idx % columns() != 0) c = cell(idx);
		break;

	case (WEST):
		if (idx % columns() != 0) c = cell(idx - 1);
		break;

	case (NORTHWEST):
		if (idx % columns() != 0) {
			idx -= (columns() + 1);
			if (idx >= 0) c = cell(idx);
		}
		break;

	case (SOUTHWEST):
		if (idx % columns() != 0) {
			idx += (columns() - 1);
			if (idx < size()) c = cell(idx);
		}
		break;

	case (NORTHEAST):
		idx -= (columns() - 1);
		if ((idx >= 0) && (idx % columns() != 0)) c = cell(idx);
		break;

	case (SOUTHEAST):
		idx += (columns() + 1);
		if ((idx < size()) && (idx % columns() != 0)) c = cell(idx);
		break;
	}

	return c;
}




#endif
