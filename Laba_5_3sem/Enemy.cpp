#include "Enemy.h"

Enemy::Enemy(std::string picture, float value) {

	texture.loadFromFile(picture);

	sprite.setTexture(texture);

	speed = SPEED_ENEMY;

	y = value;

	direction = 1;

	dead = false;
}

void Enemy::draw(sf::RenderWindow& i_window)
{
		sprite.setPosition(x, y);
		i_window.draw(sprite);
}

void Enemy::update()
{
	x += speed * direction;
}

void Enemy::move()
{
	x += speed * direction;

}

sf::IntRect Enemy::get_hitbox()
{
	return sf::IntRect(x, y , 45, 45);
}

bool Enemy::get_dead()
{
	return dead;
}

void Enemy::die() {
	dead = 1;
}


ManyEnemy::ManyEnemy(std::vector<Enemy>& aliens0) {
	for (Enemy enemy : aliens0) {
		for (size_t i = 0; i < 11; i++)
		{
			enemy.set_X(BASE_SIZE + i * 70 + 1);

			manyAliens.push_back(enemy);
		}
		contAliens.push_back(manyAliens);
	}
}

void ManyEnemy::draw_cont(sf::RenderWindow& i_window) {

	for (int j = 0; j < contAliens.size(); j++) {
		for (int i = 0; i < contAliens[j].size(); i++) {
			if (!(contAliens[j][i].dead)) {
				contAliens[j][i].draw(i_window);
			}
		}
	}
}

void ManyEnemy::move()
{
	x_end_cont = BASE_SIZE + 1;
	x_begin_cont = SCREEN_WIDTH * 2;

	for (int j = 0; j < contAliens.size(); j++) 
	{
		for (int i = contAliens[j].size() - 1; i > 0; i--)
		{
			if (!contAliens[j][i].get_dead()) {
				x_end = contAliens[j][i].get_X();
				break;
			}
		}
		if (x_end > x_end_cont) x_end_cont = x_end;
	}

	for (int j = 0; j < contAliens.size(); j++) {
	
		for (int i = 0; i < contAliens[j].size(); i++)
		{
			if (!contAliens[j][i].get_dead()) {
				x_begin = contAliens[j][i].get_X();
				break;
			}
		}
		if (x_begin < x_begin_cont ) x_begin_cont = x_begin;
	}

	for (int j = 0; j < contAliens.size(); j++) 
	{
		for (int i = 0; i < contAliens[j].size(); i++)
		{
			if (x_end_cont >= SCREEN_WIDTH * 2 + BASE_SIZE) 
			{
				for (int a = 0; a < contAliens.size(); a++)
				{
					for (int b = 0; b < contAliens[a].size(); b++)
					{
						contAliens[a][b].y += 1;
						contAliens[a][b].direction = -1;
					}
				}
			}
			if (x_begin_cont <= BASE_SIZE) 
			{
				for (int a = 0; a < contAliens.size(); a++)
				{
					for (int b = 0; b < contAliens[a].size(); b++)
					{
						contAliens[a][b].y += 1;
						contAliens[a][b].direction = 1;
					}
				}
			}
			contAliens[j][i].move();

		}
	}
}

std::vector <std::vector<Enemy>>& ManyEnemy::get()
{
	return contAliens;
}

void ManyEnemy::set(std::vector<Enemy>& value) {
	manyAliens = value;
}

bool ManyEnemy::dead_all() {
	for (int j = 0; j < contAliens.size(); j++) {
		for (int i = 0; i < contAliens[j].size(); i++) {
			dead_all_enemy = dead_all_enemy & contAliens[j][i].get_dead();
		}
	}
	return dead_all_enemy;
}