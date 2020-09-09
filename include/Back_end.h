#ifndef BACK_END_H
#define BACK_END_H

#include "wall.h"

#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/window.hpp>

#include <list>

class Back_end
{
    int         points;
    sf::Clock   time;
    float       time_sentry;
    int         fps=60;
    float       wall_spawn_time=1;
    float       time_since_last_wall=0;

    int chicken_x_position=200;
    int chicken_y_position;

    sf::RenderWindow* window;

    std::list<Wall> walls;

public:
    Back_end();
    virtual ~Back_end();

    bool time_checking();
    void making_walls();


    void update_wall();
    void update_chicken(sf::RenderWindow *window);
    void update_everything(sf::RenderWindow *window);

    bool collision_detection();
    void points_add();
    void reset();

    std::list<Wall> get_list() {return walls;}
    void get_chicken_pos(int &x,int &y) {x=chicken_x_position; y=chicken_y_position;}
    int get_points() {return points;}
};

#endif // BACK_END_H
