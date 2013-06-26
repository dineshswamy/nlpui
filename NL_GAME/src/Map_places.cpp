#include "../include/Map_places.h"

Map_places::Map_places()
{

}

Map_places::Map_places(sf::IntRect bounds,int id,std::string name)
{
    this->bounds=bounds;
    this->id=id;
    place_name=name;
}

sf::IntRect Map_places::getIntRect()
{
    return bounds;
}

void  Map_places::setIntRect(sf::IntRect rect)
{
    this->bounds=rect;
}

int Map_places::getId()
{
    return id;
}



std::string Map_places::getName()
{
    return place_name;
}
