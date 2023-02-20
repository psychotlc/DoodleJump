#ifndef PLATFORMS
#define PLATFORMS

#include <SFML/Graphics.hpp>
#include <vector>

class hero;

using namespace sf;

class platforms{
    friend bool OnThePlatform(hero& Hero, platforms& Platforms);
    friend bool PlatformNotAtDisplay(platforms& Platforms);
private:

    class platform{
    public:
        double x, y;
        int PlatformWidth, PlatformHeight;
        Image image;
        Texture texture;
        Sprite sprite;

        platform(double x, double y);
    };

    
    void newPlatform();
    std::vector <platform*> MyPlatforms;
    std::vector <Sprite> MyPlatformsSprite;
    double MaxY;
public:

    platforms();
    void reset();
    void update();
    std::vector <Sprite>::iterator getBegIt();
    std::vector <Sprite>::iterator getEndIt();
};


#endif