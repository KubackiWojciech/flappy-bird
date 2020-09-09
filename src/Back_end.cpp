#include "../include/Back_end.h"

#include <iostream> //logs
#include <windows.h> //logs

Back_end::Back_end()
{
    points=0;
}

Back_end::~Back_end()
{
    //dtor
}

bool Back_end::time_checking()
{
    time_sentry=time.restart().asSeconds();
    time_since_last_wall+=time_sentry;

    return (static_cast<float>(time_sentry>=1/fps));
}

void Back_end::update_wall()
{
    int x,y;

    if(time_since_last_wall>=wall_spawn_time)
    {
        time_since_last_wall=0;
        Wall new_wall;
        walls.push_back(new_wall);
    }

    for(std::list<Wall>::iterator it=walls.begin(); it!=walls.end();)
    {
        it->moving();
        it->get_position(x,y);

        if (x < 0)
        {
            walls.erase(it);
            it = walls.begin();
            continue;
        }
        it++;
    }
}

void Back_end::update_chicken(sf::RenderWindow *window)
{
     sf::Vector2i mouse_pos;

    mouse_pos=sf::Mouse::getPosition(*window);

    chicken_y_position=mouse_pos.y;
}

bool Back_end::collision_detection()
{
    static int wall_x_pos=300;
    static int wall_y_pos=0;

    if (walls.empty()) return false;

    std::list<Wall>::iterator it=walls.begin();//TODO: loop works until chicken meet tube
    it->get_position(wall_x_pos,wall_y_pos);
    while(wall_x_pos<84)
    {
        it++;
        it->get_position(wall_x_pos,wall_y_pos);
    }
    if(chicken_x_position>=wall_x_pos-25&&chicken_x_position<=wall_x_pos+25+91)
    if      (chicken_y_position<wall_y_pos+25) {return true;}
    else if (chicken_y_position>wall_y_pos+97) {return true;}
    return false;
    //TODO: Make wall_spawn_time and velocity dependent
}

void Back_end::reset()
{
    walls.clear();
    points=0;
}

void Back_end::points_add()
{
    if (walls.empty()) return;

    int wall_x_pos=0;
    int wall_y_pos;
    std::list<Wall>::iterator it=walls.begin();
    it->get_position(wall_x_pos,wall_y_pos);

    while(wall_x_pos<=chicken_x_position-25-91-(it->get_velocity()))
    {
        it++;
        it->get_position(wall_x_pos,wall_y_pos);
    }
    if(wall_x_pos<chicken_x_position-25-91&&wall_x_pos>chicken_x_position-25-91-(it->get_velocity())*2) ++points;
}

void Back_end::update_everything(sf::RenderWindow *window)
{
    update_chicken(window);
    if(time_checking()) update_wall();
    if(collision_detection()) {reset();}
    else points_add();
}

