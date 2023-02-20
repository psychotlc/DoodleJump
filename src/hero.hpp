#ifndef HERO
#define HERO

#include <SFML/Graphics.hpp>

class platforms;

using namespace sf;

class hero{
    friend bool OnThePlatform(hero& Hero, platforms& Platforms);
private:
    double x, y, MaxY;
    double ySpeed, xSpeed;
    int dir;
    int Width, Height;
    Image image;
    Texture texture;
    Sprite sprite;
    

public:
    void reset();
    hero();
    Sprite getSprite();
    void update(signed long long time_as_microseconds);
    void setDir(int dir);
};



#endif