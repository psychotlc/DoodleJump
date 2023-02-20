#ifndef COIN
#define COIN
#include <SFML/Graphics.hpp>
using namespace sf;
#include "hero.hpp"

class coin{
    friend bool ScoreUpdate(hero& Hero, coin& Coin);
private:
    double x, y;
    int CoinWidth, CoinHeight;
    float AnimationTimeAsSeconds;
    bool Phase;
    Image image;
    Texture texture;
    Sprite sprite;
    
public:
    coin();
    void reset();
    void update(double time_as_microseconds);
    Sprite GetSprite();
    void CoinAnimation(double time_as_microseconds);
};

#endif