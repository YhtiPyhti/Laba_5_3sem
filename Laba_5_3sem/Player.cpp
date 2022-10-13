#include "Player.h"
#include "Entities.h"
Player::Player() {

	texture.loadFromFile(HERO);

	sprite.setTexture(texture);

	speed = SPEED_HERO;

	x = SCREEN_WIDTH - BASE_SIZE;
	y = SCREEN_HEIGHT - 2 * BASE_SIZE;
}

void Player::draw(sf::RenderWindow& i_window)
{
	sprite.setPosition(x, y);
	i_window.draw(sprite);
}

 void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		x = std::max<int>(x - speed, BASE_SIZE);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		x = std::min<int>(x + speed, SCREEN_WIDTH*2 + BASE_SIZE);
	}
	
}


 sf::IntRect Player::get_hitbox()
 {
	 return sf::IntRect(x, y, 60, 60);
 }

bool Player::get_dead()
{
	return dead;
}

void Player::die() {
	dead = true;
}