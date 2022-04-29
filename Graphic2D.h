#pragma once
#ifndef _GRAPHIC_2D_H
#define _GRAPHIC_2D_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Graphic2D : public sf::Drawable {
private:

	sf::RenderTexture * _rTexture;
	sf::Sprite * _displaySprite;
	unsigned int _tileW, _tileH, _tile = 0;

	void initGraphic(const int, const int);
	void initFromFile(const char*);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

public:
	Graphic2D(const int, const int);
	Graphic2D(const char*);
	Graphic2D(const char*, const unsigned int, const unsigned int);
	~Graphic2D();

	//Setters
	void setPosition(const sf::Vector2f&);
	void setPosition(const sf::Vector2i&);
	void setPosition(const float, const float);
	void setTile(const unsigned int);
	void setTileWidth(const unsigned int);
	void setTileHeight(const unsigned int);
	void resize(const unsigned int, const unsigned int);
	void smooth() { _rTexture->setSmooth(!_rTexture->isSmooth()); }

	//Getters
	sf::Sprite* getSprite() const { return _displaySprite; }
	sf::RenderTexture* getRenderTexture() const { return _rTexture; }
	unsigned int width() const { return _rTexture->getSize().x; }
	unsigned int height() const { return _rTexture->getSize().y; }
	sf::Vector2f getPosition() const { return _displaySprite->getPosition(); }
	sf::IntRect getIntRect() const { return sf::IntRect(sf::Vector2i((int)getPosition().x, (int)getPosition().y), sf::Vector2i(static_cast<int>(_displaySprite->getScale().x * width()), static_cast<int>(_displaySprite->getScale().y * height()))); }

	//Getters for tile sheets
	unsigned int tileWidth() const { return _tileW; }
	unsigned int tileHeight() const { return _tileH; }
	unsigned int columns() const { return (width() / tileWidth()); }
	unsigned int rows() const { return (height() / tileHeight()); }
	unsigned int size() const { return (columns() * rows()); }
	unsigned int getTile() const { return _tile; }

	//Primitives
	void clear(const sf::Color&);
	void drawLine(const sf::Vector2f&, const sf::Vector2f&, const sf::Color&);
	void setPixel(const sf::Vector2f&, const sf::Color&);
	sf::Color getPixel(const sf::Vector2f&) const;

	//Public Draw Routines
	void draw(const sf::Drawable&);
	void draw(const Graphic2D&);
};


void Graphic2D::initGraphic(const int w, const int h) {
	_rTexture = new sf::RenderTexture();
	_rTexture->create(w, h);
	_rTexture->display();
	_displaySprite = new sf::Sprite();
	_displaySprite->setTexture(_rTexture->getTexture());
	_tileW = _rTexture->getSize().x;
	_tileH = _rTexture->getSize().y;
}
void Graphic2D::initFromFile(const char* fName) {
	sf::Texture* tmpTexture = new sf::Texture();
	sf::Sprite* tmpSprite = new sf::Sprite();
	tmpTexture->loadFromFile(fName);
	tmpSprite->setTexture(*tmpTexture);

	initGraphic(tmpTexture->getSize().x, tmpTexture->getSize().y);
	this->draw(*tmpSprite);

	delete tmpSprite;
	delete tmpTexture;
}


Graphic2D::Graphic2D(const int width, const int height) {
	initGraphic(width, height);
}
Graphic2D::Graphic2D(const char* fileName) {
	initFromFile(fileName);
}
Graphic2D::Graphic2D(const char* fileName, const unsigned int eachTileWidth, const unsigned int eachTileHeight) {
		initFromFile(fileName);
		_tileW = eachTileWidth;
		_tileH = eachTileHeight;
		if (_tileW <= 0 || _tileW > width()) _tileW = width();
		if (_tileH <= 0 || _tileH > height()) _tileH = height();
		_tile = 0;
}

Graphic2D::~Graphic2D() {
	delete _displaySprite;
	delete _rTexture;
}


void Graphic2D::setPosition(const sf::Vector2f& v) {
	_displaySprite->setPosition(v);
}
void Graphic2D::setPosition(const sf::Vector2i& v) {
	_displaySprite->setPosition(static_cast<sf::Vector2f>(v));
}
void Graphic2D::setPosition(const float x, const float y) {
	setPosition(sf::Vector2f(x, y));
}
void Graphic2D::setTile(const unsigned int tileIndex) {
	_tile = tileIndex;
	if (_tile > size() - 1) _tile = size() - 1;
	int column = _tile % columns();
	int row = _tile / columns();
	int x = column * tileWidth();
	int y = row * tileHeight();
	_displaySprite->setTextureRect(sf::IntRect(x, y, tileWidth(), tileHeight()));
}

void Graphic2D::setTileWidth(const unsigned int tileWidth) {
	_tileW = tileWidth; 
	if (_tileW <= 0 || _tileW > width()) _tileW = width();
}
void Graphic2D::setTileHeight(const unsigned int tileHeight) {
	_tileH = tileHeight;
	if (_tileH <= 0 || _tileH > height()) _tileH = height();
}

void Graphic2D::resize(const unsigned int wdth, const unsigned int hght) {
	float wScale = ((float)columns() * wdth) / width();
	float hScale = ((float)rows() * hght) / height();
	_displaySprite->setScale(sf::Vector2f(wScale, hScale));
}

//Primitives
void Graphic2D::clear(const sf::Color& clr) {
	_rTexture->clear(clr);
}
void Graphic2D::drawLine(const sf::Vector2f& v1, const sf::Vector2f& v2, const sf::Color& clr) {
	sf::Vertex line[] = {
		sf::Vertex(v1, clr),
		sf::Vertex(v2, clr)
	};
	_rTexture->draw(line, 2, sf::Lines);
}
void Graphic2D::setPixel(const sf::Vector2f& v, const sf::Color& clr) {
	sf::Image* tmpImage = new sf::Image();
	sf::Texture* tmpTexture = new sf::Texture();
	sf::Sprite* tmpSprite = new sf::Sprite();

	tmpImage->create(width(), height(), sf::Color::Transparent);
	tmpImage->setPixel(static_cast<unsigned int>(v.x), static_cast<unsigned int>(v.y), clr);
	tmpTexture->loadFromImage(*tmpImage);
	tmpSprite->setTexture(*tmpTexture);
	this->draw(*tmpSprite);

	delete tmpSprite;
	delete tmpTexture;
	delete tmpImage;
}
sf::Color Graphic2D::getPixel(const sf::Vector2f& v) const {
	sf::Image* tmpImage = new sf::Image(_rTexture->getTexture().copyToImage());
	sf::Color clr = tmpImage->getPixel(static_cast<unsigned int>(v.x), static_cast<unsigned int>(v.y));
	delete tmpImage;
	return clr;
}

//Draw Routines
void Graphic2D::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*_displaySprite, states);
}

void Graphic2D::draw(const sf::Drawable& drawable) {
	_rTexture->draw(drawable);
}

void Graphic2D::draw(const Graphic2D& graphic) {
	_rTexture->draw(*graphic.getSprite());
}


#endif 
