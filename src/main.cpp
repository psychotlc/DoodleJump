#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "view.hpp"

using namespace sf;

#include "hero.hpp"
#include "platforms.hpp"
#include "coin.hpp"
#include "jetpack.hpp"

hero Hero;
platforms Platforms;
coin Coin;
jetpack Jetpack;


int Scale = 3;

int Score = 0;
int width = 624;
int height = 1000;

void setScorePosition(Text& text);
bool ScoreUpdate(hero& Hero, coin& Coin);
void setSpaceKDPosition(Text& text);

int main(){
    RenderWindow window(VideoMode(width, height), "DoodleJump");
    view.reset(FloatRect(0, 0, width, height));

    Font font;
    font.loadFromFile("src/CyrilicOld.TTF");

    String ScoreString = "Score: " + std::to_string(Score);
    Text ScoreText(ScoreString,font, 50);
    ScoreText.setFillColor(Color(0, 0, 0));

    Text SpaceKDText("JumpKD: " + std::to_string(Hero.GetSpaceKD()), font, 50);
    SpaceKDText.setFillColor(Color(0, 0, 0));

    
    Clock clock;

    while (window.isOpen()){
        Event event;
        if (window.pollEvent(event)) if(event.type == Event::Closed) window.close();
        signed long long time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        if (Keyboard::isKeyPressed(Keyboard::R)){
            Hero.reset();
            Platforms.reset();
            Coin.reset();
            Score = 0;
            ScoreText.setString("Score: " + std::to_string(Score));
        }

        if (Keyboard::isKeyPressed(Keyboard::A)) Hero.setDir(1);
        else if (Keyboard::isKeyPressed(Keyboard::D)) Hero.setDir(2);
        else Hero.setDir(0);
        if (Keyboard::isKeyPressed(Keyboard::Space)) Hero.Space(time);
        Coin.update(time);
        Hero.update(time);
        Jetpack.update();
        Platforms.update();
        window.setView(view);

        if (ScoreUpdate(Hero, Coin)) 
        {
            ScoreText.setString("Score: " + std::to_string(Score));
        }
        
        setScorePosition(ScoreText);
        setSpaceKDPosition(SpaceKDText);
        
        window.clear(Color(255, 255, 255));

        window.draw(ScoreText);

        SpaceKDText.setString("JumpKD: " + std::to_string(int(Hero.GetSpaceKD())));

        window.draw(SpaceKDText);
        

        window.draw(Coin.GetSprite());
        for(auto it = Platforms.getBegIt(); it != Platforms.getEndIt(); it++){
            window.draw(*it);    
        }

        window.draw(Hero.getSprite());
        window.draw(Jetpack.getSprite());

        window.display();
    }
    
}

void setScorePosition(Text& text){
    text.setPosition(width / 2 + 100, view.getCenter().y - height/2);
}

void setSpaceKDPosition(Text& text){
    text.setPosition(0, view.getCenter().y - height/2);
}

bool ScoreUpdate(hero& Hero, coin& Coin){
    if ((Hero.x <= (Coin.x + Coin.CoinWidth * Scale) && (Hero.x + Hero.Width * Scale) >= Coin.x) 
    && (Coin.y <= (Hero.y + Hero.Height * Scale) && Coin.y >= Hero.y)){
        Coin.reset();
        Score++;
        return true;
        
    }
    else return false;
}