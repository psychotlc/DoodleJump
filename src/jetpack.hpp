#ifndef JETPACK
#define JETPACK
#include <SFML/Graphics.hpp>

using namespace sf;

class hero;

class jetpack{
    friend bool IfEncounteredJetpack(hero& Hero, jetpack& Jetpack);
    friend bool JetpackNotAtDisplay(jetpack& Jetpack); 
private:
    double x, y;
    int JetpackWidth, JetpackHeight;
    Image image;
    Texture texture;
    Sprite sprite;
public:
    Sprite getSprite();
    void reset();
    void update();
    jetpack();
};

#endif