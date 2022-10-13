#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <random>

const int SPEED_ENEMY = 2;
const int SPEED_BULLET = 10;
const int SPEED_HERO = 5;
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 900;
const int BASE_SIZE = 16;
const int RADIUS = 10;
const std::string BACKGROUND("C:\\Users\\Sergei\\source\\repos\\Laba_5_3sem\\Resours\\background.png");
const std::string TYPEFACE("C:\\Users\\Sergei\\source\\repos\\Laba_5_3sem\\Resours\\CyrilicOld.ttf");

const std::string BULLETHERO("C:\\Users\\Sergei\\source\\repos\\Laba_5_3sem\\Resours\\PlayerBullet.png");
const std::string BULLETENEMY("C:\\Users\\Sergei\\source\\repos\\Laba_5_3sem\\Resours\\Enemybullet.png");

const std::string HERO("C:\\Users\\Sergei\\source\\repos\\Laba_5_3sem\\Resours\\Player.png");
const std::string ALIENS0("C:\\Users\\Sergei\\source\\repos\\Laba_5_3sem\\Resours\\Enemy0.jpg");
const std::string ALIENS1("C:\\Users\\Sergei\\source\\repos\\Laba_5_3sem\\Resours\\Enemy1.jpg");
const std::string ALIENS2("C:\\Users\\Sergei\\source\\repos\\Laba_5_3sem\\Resours\\Enemy2.png");

class Entities {
public:
    bool dead = false;
    float x;
    float y;
    int direction;
    int speed;
    sf::Sprite sprite;
    sf::Texture texture;
    float get_X();
    float get_Y();
    void set_X(float value);
    void set_Y(float value);
};

