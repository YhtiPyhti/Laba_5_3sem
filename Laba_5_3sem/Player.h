#pragma once
#include "Entities.h"

class Player : public Entities
{
public:
	
	Player();

	bool get_dead();
	void die();
	void draw(sf::RenderWindow& i_window);
	void update();
	sf::IntRect get_hitbox();

};

