#pragma once
#include "Entities.h"
#include "Bullet.h"

class Enemy : public Entities
{
public:

	sf::Texture bullet_texture;
	sf::Sprite bullet_sprite;
	
	Enemy(std::string picture, float value);

	void move();
	bool get_dead();
	void die();
	void draw(sf::RenderWindow& i_window);
	void update();

	sf::IntRect get_hitbox();

};

class ManyEnemy : public Entities
{
public:
	float x_end_cont;
	float x_begin_cont;
	float x_end;
	float x_begin;

	std::vector<Enemy> manyAliens;
	std::vector<std::vector<Enemy>> contAliens;

	ManyEnemy(std::vector<Enemy>& aliens0);

	void draw_cont(sf::RenderWindow& i_window);

	void move();

	std::vector<std::vector<Enemy>>& get();

	void set(std::vector<Enemy>& value);
};