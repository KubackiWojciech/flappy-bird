#ifndef FRONT_END_H
#define FRONT_END_H

#include "Back_end.h"

#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>

#include <list>

class Front_end
{
    sf::RenderWindow *window;
    sf::Event event;
    sf::Font font;
    sf::Text text;

    Back_end tech_stuff;

    //walls stuff
    sf::Image           *wfirst_download;
    sf::Texture         *wsecond_download;
    sf::RectangleShape  *wlast_download;

    std::list<Wall> wall_coordinates;

    //chicken stuff
    sf::Image           *cfirst_download;
    sf::Texture         *csecond_download;
    sf::RectangleShape  *clast_download;

    friend void Back_end::update_everything(sf::RenderWindow *window); //I need *window in this function to sf::Mouse:getPosition and i can't do it in another way



public:
        Front_end();
        virtual ~Front_end();

        void run();
        void update();
        void updateSFMLEvents();
        void render();
};

#endif // FRONT_END_H
