#ifndef VIEW
#define VIEW

#include <SFML/Graphics.hpp>
using namespace sf;

View view;

void NewView(double x, double y){
    view.setCenter(x, y);
}


#endif