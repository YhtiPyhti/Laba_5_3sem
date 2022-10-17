#include "Entities.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <iostream>


using namespace sf;

std::string to_string(int n)
{
    char buf[40];
    sprintf_s(buf, "%d", n);
    return buf;
}

int main(int argc, char** argv) {
    RenderWindow renderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Invaders", sf::Style::Fullscreen);
    renderWindow.setVerticalSyncEnabled(true);

    sf::Texture background_texture;
    sf::Sprite background_sprite;

    background_texture.loadFromFile(BACKGROUND);
    background_sprite.setTexture(background_texture);

    //текст
    std::string socer = "Socer: ";
    Font font; 
    font.loadFromFile(TYPEFACE);
    int number = 0;

    socer += to_string(number);

    Event event;

    //Герой
    Player hero;

    //Злодей
    std::vector<Enemy> cont_enemy;

    Enemy aliens0(ALIENS0, SCREEN_HEIGHT / 6);
    cont_enemy.push_back(aliens0);

    Enemy aliens1(ALIENS1, SCREEN_HEIGHT / 6 + 50);
    cont_enemy.push_back(aliens1);

    Enemy aliens2(ALIENS2, SCREEN_HEIGHT / 6 + 100);
    cont_enemy.push_back(aliens2);

    ManyEnemy manyAliens0(cont_enemy);

    //Пуля
    Bullet bullet(hero.get_X(),hero.get_Y(), BULLETHERO);
    Bullet bullet_enemy(manyAliens0.get()[0][0].get_X(), manyAliens0.get()[0][0].get_Y(), BULLETENEMY);
    bool shoot = false, shoot_enemy = false;

    srand(time(0));
    int rand_stolb, rand_str;

    //Время
    Clock clc;

    while (renderWindow.isOpen()) {

        while (renderWindow.pollEvent(event)) {
            if (event.type == Event::EventType::Closed)
                renderWindow.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
            renderWindow.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Space)&& !shoot) {
            //Пуля
            bullet.set_X(hero.get_X() + 38);
            bullet.set_Y(hero.get_Y());
            shoot = true;
        }

        rand_stolb = rand() % manyAliens0.get()[manyAliens0.get().size() - 1].size();
        rand_str = rand_stolb % manyAliens0.get().size();

        for (int j = 0; j < manyAliens0.get().size(); j++) {
            for (int i = 0; i < manyAliens0.get()[j].size(); i++) {
                if (!(manyAliens0.get()[j][i].dead)) {
                    if (rand_stolb == i && rand_str == j && !shoot_enemy) {
                        bullet_enemy.set_X(manyAliens0.get()[j][i].get_X() + BASE_SIZE);
                        bullet_enemy.set_Y(manyAliens0.get()[j][i].get_Y() + BASE_SIZE * 3);
                        shoot_enemy = true;
                    }

                }

            }
        }

        if(bullet.get_Y() < 50) shoot = false;

        if (bullet_enemy.get_Y() > SCREEN_HEIGHT) shoot_enemy = false;

        if (bullet_enemy.get_hitbox().intersects(hero.get_hitbox())) {
            hero.die();
            shoot_enemy = false;
        }

        for (int j = 0; j < manyAliens0.get().size();j++)
        {
            for (int i = 0; i < manyAliens0.get()[j].size(); i++) 
            {
                if (bullet.get_hitbox().intersects(manyAliens0.get()[j][i].get_hitbox()) && shoot && !manyAliens0.get()[j][i].get_dead())
                {
                    manyAliens0.get()[j][i].die();
                    number++;
                    shoot = false;
                    socer = "Socer: " + to_string(number);
                }
                if(manyAliens0.get()[j][i].get_Y() >= hero.get_Y()) hero.die();
            }
        }

        if (!hero.get_dead() && !manyAliens0.dead_all() ) {
            renderWindow.clear();

            renderWindow.draw(background_sprite);

            Text text(socer, font, 40);
            text.setStyle(sf::Text::Bold | sf::Text::Underlined);
            renderWindow.draw(text);

           
            hero.draw(renderWindow);
            hero.update();

            manyAliens0.draw_cont(renderWindow);
            manyAliens0.move();

            if (shoot)bullet.draw_hero(renderWindow);

            if (shoot_enemy)bullet_enemy.draw_enemy(renderWindow);

            renderWindow.display();
        }
        else if(hero.get_dead()) {
            Text text("GAME OVER!\n YOU DEAD(\n\t " + socer, font, 100);
            text.setPosition(SCREEN_HEIGHT / 2 + BASE_SIZE * 10, SCREEN_WIDTH / 3 + BASE_SIZE * 4);
            text.setStyle(sf::Text::Bold);

            renderWindow.clear();

            renderWindow.draw(text);

            renderWindow.display();
        }
        else {
            Text text("YOU WIN\n\t " + socer, font, 100);
            text.setPosition(SCREEN_HEIGHT / 2 + BASE_SIZE * 10, SCREEN_WIDTH / 3 + BASE_SIZE * 4);
            text.setStyle(sf::Text::Bold);

            renderWindow.clear();

            renderWindow.draw(text);

            renderWindow.display();
        }
        
       
    }
}