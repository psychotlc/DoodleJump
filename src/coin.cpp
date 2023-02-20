#include "coin.hpp"

extern View view;

extern int width;
extern int height;
extern int Scale;
extern int Score;


coin::coin(){
    srand(time(NULL));
    x = rand() % (width - 100) + 50;
    y = 500;
    CoinHeight = 14;
    CoinWidth = 8;

    image.loadFromFile("images/DoodleJumpTextures.png");
    image.createMaskFromColor(Color(255, 255, 255));
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(16, 97, CoinWidth, CoinHeight));
    sprite.scale(Scale, Scale);
    sprite.setPosition(x, y);
    AnimationTimeAsSeconds = 1;
    Phase = 1;  
}


Sprite coin::GetSprite(){
    return this->sprite;
}

void coin::update(double time_as_microseconds){
    CoinAnimation(time_as_microseconds);
    if (y - view.getCenter().y >= height/2) this->reset();
}

void coin::CoinAnimation(double time_as_microseconds){
    double time_as_seconds = time_as_microseconds / 1e6;
    AnimationTimeAsSeconds += time_as_seconds;
    if (AnimationTimeAsSeconds >= 0.5){
        AnimationTimeAsSeconds = 0;
        if (Phase) {
            CoinWidth = 14;
            sprite.setTextureRect(IntRect(27, 97, CoinWidth, CoinHeight));
            
        }
        else {
            CoinWidth = 8;
            sprite.setTextureRect(IntRect(16, 97, CoinWidth, CoinHeight));
        }
        Phase = !Phase;
    }
}

void coin::reset(){
    y = -1 * rand() % 1500 + view.getCenter().y - height/2; 
    x = rand() % (width - 100) + 50;
    sprite.setPosition(x, y);
}

