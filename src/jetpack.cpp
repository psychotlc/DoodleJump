#include "jetpack.hpp"

extern int Scale;
extern int width;
extern int height;
extern View view;

jetpack::jetpack(){
    srand(time(NULL));
    JetpackWidth = 22;
    JetpackHeight = 27;
    image.loadFromFile("images/DoodleJumpTextures.png");
    image.createMaskFromColor(Color(255,255,255));
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(46,94,JetpackWidth,JetpackHeight));
    sprite.scale(Scale, Scale);
    reset();
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
    
}

void jetpack::reset(){
    sprite.setPosition(rand()%(width - this->JetpackWidth * Scale), -1 * rand() % 5000 - height/2 + view.getCenter().y);
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
}

void jetpack::update(){
    if (JetpackNotAtDisplay(*this)) reset();
}

bool JetpackNotAtDisplay(jetpack& Jetpack){
    if (Jetpack.y - view.getCenter().y >= height/2) return true;
    return false;
}

Sprite jetpack::getSprite(){
    return this->sprite;
}