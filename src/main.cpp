#include <SFML/Graphics.hpp>
#include <vector>
#include "view.hpp"

using namespace sf;

#include "hero.hpp"
#include "platforms.hpp"

hero Hero;
platforms Platforms;

int Scale = 3;

int width = 624;
int height = 1000;

int main(){
    RenderWindow window(VideoMode(width, height), "DoodleJump");
    view.reset(FloatRect(0, 0, width, height));

    
    Clock clock;

    while (window.isOpen()){
        Event event;
        if (window.pollEvent(event)) if(event.type == Event::Closed) window.close();
        signed long long time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        if (Keyboard::isKeyPressed(Keyboard::Space)){
            Hero.reset();
            Platforms.reset();
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) Hero.setDir(1);
        else if (Keyboard::isKeyPressed(Keyboard::D)) Hero.setDir(2);
        else Hero.setDir(0);

        Hero.update(time);
        Platforms.update();
        window.setView(view);
        window.clear(Color(255, 255, 255));
        for(auto it = Platforms.getBegIt(); it != Platforms.getEndIt(); it++){
            window.draw(*it);    
        }
        window.draw(Hero.getSprite());
        window.display();
    }
    
}