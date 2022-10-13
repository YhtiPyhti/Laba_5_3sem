#pragma once
#include "Entities.h"
class Bullet : public Entities
{
public:

	float real_x;
	float real_y;
	float step_x;
	float step_y;

	Bullet(float x_entities, float y_entities, std::string file);
	void draw_hero(sf::RenderWindow& i_window);
	void draw_enemy(sf::RenderWindow& i_window);
	sf::IntRect get_hitbox();
};