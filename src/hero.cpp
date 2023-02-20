
#include "hero.hpp"
#include "platforms.hpp"

extern View view;
void NewView(double x, double y);
extern platforms Platforms;
extern int height;
extern int width;

extern int Scale;
double g = 4;

bool OnThePlatform(double x, double y);

hero::hero(){
    Width = 25;
    Height = 28;
    dir = 1;
    xSpeed = 400;
    reset();

    image.loadFromFile("images/DoodleJumpTextures.png");
    image.createMaskFromColor(Color(255,255,255));
    texture.loadFromImage(image);

    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(16,39,this->Width,this->Height));
    sprite.scale(Scale, Scale);
    sprite.setPosition(x ,y);
    
}

void hero::reset(){
    ySpeed = 0;
    x = width/2 - 2 * Width;
    y = height - Height * Scale - 300; 
    sprite.setPosition(x, y);
    MaxY = y;
    NewView(view.getCenter().x, y);
}

Sprite hero::getSprite(){
    return this->sprite;
}

void hero::setDir(int dir){
    this->dir = dir;
}

void hero::update(signed long long time_as_microseconds){
    double time_as_seconds = time_as_microseconds / 1e6 ;
    if (ySpeed < 3) this->ySpeed += time_as_seconds*g;
    int dir = 0;

    if (this->dir == 1) {
        dir = -1;
        sprite.setTextureRect(IntRect(16,39,this->Width,this->Height));
    }
    else if(this->dir == 2) {
        dir = 1;
        sprite.setTextureRect(IntRect(72, 39, Width, Height));
    }

    sprite.move(dir * xSpeed * time_as_seconds, ySpeed);
    
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;

    if (OnThePlatform(*this, Platforms) && ySpeed > 0) ySpeed = -2;
    if (y <= MaxY) MaxY = y;
    if (MaxY == y){
        NewView(view.getCenter().x, y);
    }
}

bool OnThePlatform(hero& Hero, platforms& Platforms){
    for (auto it = Platforms.MyPlatforms.begin(); it != Platforms.MyPlatforms.end(); it++){
        auto platform = *it;
        if ((Hero.x <= (platform->x + platform->PlatformWidth * Scale) && (Hero.x + Hero.Width * Scale) >= platform->x) && 
        (platform->y <= (Hero.y + Hero.Height * Scale) && platform->y >= Hero.y)) return true;
    }
    return false;
};