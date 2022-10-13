#include "Bullet.h"
Bullet::Bullet(float x_entities, float y_entities, std::string file) {
	texture.loadFromFile(file);
	sprite.setTexture(texture);

	x = x_entities;
	y = y_entities;

	speed = SPEED_BULLET;


}
sf::IntRect Bullet::get_hitbox()
{
	return sf::IntRect(x , y , 10, 30);
}

void Bullet::draw_hero(sf::RenderWindow& i_window) {
	y -= speed;
	sprite.setPosition(x, y);
	i_window.draw(sprite);
}

void Bullet::draw_enemy(sf::RenderWindow& i_window) {
	y += speed;
	sprite.setPosition(x, y);
	i_window.draw(sprite);
}