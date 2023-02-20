#ifndef HERO
#define HERO

#include <SFML/Graphics.hpp>

class platforms;
class coin;

using namespace sf;

class hero{
    friend coin;
    friend bool ScoreUpdate(hero& Hero, coin& Coin);
    friend bool OnThePlatform(hero& Hero, platforms& Platforms);
private:
    double x, y;
    double ySpeed, xSpeed;
    
    float SpaceKD;
    int dir;
    int Width, Height;
    Image image;
    Texture texture;
    Sprite sprite;
protected:
    double MaxY;
    

public:
    void Space(double time_as_microseconds);
    void reset();
    float GetSpaceKD();
    hero();
    Sprite getSprite();
    void update(signed long long time_as_microseconds);
    void setDir(int dir);
};




#endif