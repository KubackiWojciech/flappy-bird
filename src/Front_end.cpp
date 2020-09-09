#include "../include/Front_end.h"

#include <iostream> //logs

Front_end::Front_end()
{
    window=new sf::RenderWindow(sf::VideoMode(800,600),"flappy bird");
    window->setFramerateLimit(60);

    wfirst_download=new sf::Image;
    wsecond_download=new sf::Texture;
    wlast_download=new sf::RectangleShape(sf::Vector2f(100,1600));
    wlast_download->setOrigin(2,645);

    wfirst_download->loadFromFile("Images/wall.jpg");
        wfirst_download->createMaskFromColor(sf::Color::White);
    wsecond_download->loadFromImage(*wfirst_download);
    wlast_download->setTexture(wsecond_download);

    cfirst_download=new sf::Image;
    csecond_download=new sf::Texture;
    clast_download=new sf::RectangleShape(sf::Vector2f(50,50));
    cfirst_download->loadFromFile("Images/chicken.jpg");
        cfirst_download->createMaskFromColor(sf::Color::White);
    csecond_download->loadFromImage(*cfirst_download);
    clast_download->setTexture(csecond_download);
    clast_download->setOrigin(25,25);

    font.loadFromFile("font/Sketch 3D.otf");

    text.setFont(font);
    text.setCharacterSize(50);

}

Front_end::~Front_end()
{
    delete window;
}

void Front_end::updateSFMLEvents()
{
    while(window->pollEvent(event))
    {
        if(event.type==sf::Event::Closed) window->close();
    }
}

void Front_end::update()
{
    updateSFMLEvents();
    tech_stuff.update_everything(window);
    std::string str=std::to_string(tech_stuff.get_points());
    text.setString(str);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
}

void Front_end::render()
{
    window->clear(sf::Color(150,150,150));
    //chicken stuff:
    int chicken_x_pos;
    int chicken_y_pos;

    tech_stuff.get_chicken_pos(chicken_x_pos,chicken_y_pos);
        clast_download->setPosition(chicken_x_pos,chicken_y_pos);
        window->draw(*clast_download);

    //wall stuff:
    wall_coordinates=tech_stuff.get_list();

    int x,y;

    for(std::list<Wall>::iterator it=wall_coordinates.begin(); it!=wall_coordinates.end(); it++)
    {
        it->get_position(x,y);
        wlast_download->setPosition(x,y);

        window->draw(*wlast_download);
    }

    window->draw(text);

    window->display();
}

void Front_end::run()
{
    while(window->isOpen())
    {
        update();
        render();
    }
}
