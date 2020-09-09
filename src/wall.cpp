#include "../include/wall.h"
#include "../include/wyhash.h"

Wall::Wall()
{
    wysrand((time(NULL))*10);
    position_x=800;
    position_y=possibly_wall_position[(wygrand())%9];
}

Wall::~Wall()
{

}

