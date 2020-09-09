#ifndef WALL_H
#define WALL_H

#include <cstdlib>
#include <ctime>
#include <iostream> //logs

class Wall
{
    int position_x;
    int position_y;
    float velocity_x=5;

    int possibly_wall_position[9]={100,150,200,250,300,350,400,450,500}; //size=9

public:
    Wall();
    virtual ~Wall();

    void get_position(int &pos_x, int &pos_y) {pos_x=position_x; pos_y=position_y;}
    float get_velocity() {return velocity_x;}

    void moving() {position_x-=velocity_x;}
    void speed_up() {velocity_x+=2;}

};

#endif // WALL_H
