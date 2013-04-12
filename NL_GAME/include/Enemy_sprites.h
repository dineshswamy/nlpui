#ifndef ENEMY_SPRITES_H
#define ENEMY_SPRITES_H
#include<SFML/Graphics.hpp>
#include<vector>

class Enemy_sprites
{
    public:
        sf::Sprite enemyLook;
        std::vector<sf::IntRect> frame_stack;
        std::vector<sf::Vector2f> position;
        std::vector<sf::IntRect>::iterator frame_stack_index;
        std::vector<sf::Vector2f>::iterator position_stack_index;
        Enemy_sprites();
        void Draw(sf::RenderWindow &window);
        void setPosition(sf::Vector2f coords);
        void setImage(std::string,sf::IntRect rect_init);
        void showTrees(int j);
        void showTrainMovements();
        void positionGenerator(int xa,int ya, int xb,int yb);
       // void setFrames();
     //   checkConditions();
    protected:
    private:
};

#endif // ENEMY_SPRITES_H
