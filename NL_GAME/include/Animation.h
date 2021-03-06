#ifndef ANIMATION_H
#define ANIMATION_H
#include<SFML/Graphics.hpp>
#include "Map_places.h"
#include "Enemy_sprites.h"
#include<vector>
#include<cstdlib>
class Animation
{
    public:
        Animation();
        static std::vector<Enemy_sprites*> enemy_objects;
        void Initialize(float x, float y,sf::IntRect ini_rect,bool enemy);
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
        void positionGenerator(int xa,int ya, int xb,int yb,int incr);
        bool IsColliding(int x, int y);
        void playerFrontWalk(sf::RenderWindow &window,int xb,int yb);
        void dieSprites(sf::RenderWindow &window);
        void writeDietoOtherplayer(int player_index);
        void clearPositionandFrames();
        bool checkInsideLOC(std::vector<sf::Vector2f> &position_players,sf::RenderWindow &window);
        void sayLatLong(sf::RenderWindow &window);
        bool catchTheTrain();
        void blowTheCopter();
        void Takeposition(int xb,int yb);
        std::vector<sf::Vector2f> getPosition();
        std::string curr_position;
        sf::Sprite playerLook;
        sf::IntRect line_of_control;
        sf::RectangleShape rectangle;
    protected:
    private:
        std::vector<sf::IntRect> frame_stack;
        std::vector<sf::Vector2i> position;
        std::vector<sf::IntRect>::iterator frame_stack_index;
        std::vector<sf::Vector2i>::iterator position_stack_index;
        std::vector<sf::Vector2f>::iterator loc_iterator;
        std::vector<Enemy_sprites*>::iterator enemy_objects_iterator;

        int currentFrameX,currentFrameY;
        float x,y;
        bool enemy;
};

#endif // ANIMATION_H
