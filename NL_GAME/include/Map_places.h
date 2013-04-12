#ifndef MAP_PLACES_H
#define MAP_PLACES_H
#include<string>
#include<SFML/Graphics.hpp>

class Map_places
{
    public:
        Map_places(sf::IntRect bounds,int id,std::string name);
        Map_places();
        sf::IntRect getIntRect();
        void setIntRect(sf::IntRect rect);
        int getId();
        std::string getName();
        sf::IntRect bounds;
        int id;
        std::string place_name;
    protected:
    private:

};

#endif // MAP_PLACES_H
