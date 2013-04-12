#ifndef ANIMATION_H
#define ANIMATION_H
#include<SFML/Graphics.hpp>
#include "Map_places.h"
#include<vector>
#include<cstdlib>
class Animation
{
    public:
        Animation();
        static std::vector<Map_places> places_collision;
        void Initialize(float x, float y,sf::IntRect ini_rect);
        void Update();
        void playerAnimations(sf::RenderWindow & window);
        void playerFire(sf::RenderWindow & window);
        void Draw(sf::RenderWindow &window);
        void setPosition(sf::Vector2i coords);
        void setImage(sf::Texture &player_texture);
        void setCurrentFrame(int y);
        void playerWalk(sf::RenderWindow &window);
        void playerWalkFront(sf::RenderWindow &window);
        void playerFireSideLeft(sf::RenderWindow &window);
        void playerFireSideLeftBackside(sf::RenderWindow &window);
        void positionGenerator(int xa,int ya, int xb,int yb);
        bool IsColliding(int x, int y);
        void showTrainMovements();
        void playerFrontWalk(sf::RenderWindow &window,int xb,int yb);
        void dieSprites(sf::RenderWindow &window);
        void writeDietoOtherplayer();
        void sayLatLong(sf::RenderWindow &window);
        std::string curr_position;
    protected:
    private:
        sf::Sprite playerLook;

        std::vector<sf::IntRect> frame_stack;
        std::vector<sf::Vector2i> position;
        std::vector<sf::IntRect>::iterator frame_stack_index;
        std::vector<sf::Vector2i>::iterator position_stack_index;
        int currentFrameX,currentFrameY;
        float x,y;
};

#endif // ANIMATION_H
