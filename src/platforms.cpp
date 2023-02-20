#include "hero.hpp"
#include "platforms.hpp"


extern int height;
extern int width;
extern int Scale;
extern View view;

bool PlatformNotAtDisplay(platforms& Platforms){
    if (Platforms.MyPlatforms[0]->y - view.getCenter().y >= height/2) {
        delete Platforms.MyPlatforms[0];
        Platforms.MyPlatforms.erase(Platforms.MyPlatforms.begin());
        Platforms.MyPlatformsSprite.erase(Platforms.MyPlatformsSprite.begin());
        return true;
    }
    return false;
};

platforms::platform::platform(double x, double y){

    PlatformWidth = 37;
    PlatformHeight = 8;

    image.loadFromFile("images/DoodleJumpTextures.png");
    image.createMaskFromColor(Color(255,255,255));
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(155,40,PlatformWidth, PlatformHeight));
    sprite.scale(Scale, Scale);
    sprite.setPosition(x, y);
    this->x = x;
    this->y = y;
}

platforms::platforms(){
    srand(time(NULL));
    reset();
}

void platforms::reset(){
    for (auto it = MyPlatforms.begin(); it != MyPlatforms.end(); it++) delete *it;
    MyPlatforms.clear();
    MyPlatformsSprite.clear();

    platform* temp = new platform(width/2, height - 100);
    temp->sprite.move(-1 * temp->PlatformWidth / 2 * Scale, 0);
    temp->x -= temp->PlatformWidth/2 * Scale;
    MyPlatforms.push_back(temp);
    MyPlatformsSprite.push_back(temp->sprite);
    MaxY = temp->y;

    for (int i = 0; i < 10; i++) newPlatform();
}



void platforms::newPlatform(){
    
    platform* temp = new platform(rand() % (width - 100), -1 * rand() % (height/4) + MaxY - 100);
    MyPlatforms.push_back(temp);
    MyPlatformsSprite.push_back(temp->sprite);
    MaxY = temp->y;
}

void platforms::update(){
    if (PlatformNotAtDisplay(*this)) this->newPlatform();
    
}

std::vector <Sprite>::iterator platforms:: getBegIt(){
    return MyPlatformsSprite.begin();
}
std::vector <Sprite>::iterator platforms:: getEndIt(){
    return MyPlatformsSprite.end();
}
