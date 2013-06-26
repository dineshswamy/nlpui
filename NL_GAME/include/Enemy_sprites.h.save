#ifndef ENEMY_SPRITES_H
#define ENEMY_SPRITES_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<vector>


class Enemy_sprites
{
    public:
        sf::Sprite enemyLook;
        sf::Clock clk;
        sf::Music bg_sound;
        bool in_warehouse_left;
        bool moving;
        bool start_recursive;
        std::vector<sf::IntRect> frame_stack;
        std::vector<sf::Vector2f> position;
        std::vector<sf::IntRect>::iterator frame_stack_index;
        std::vector<sf::Vector2f>::iterator position_stack_index;
        Enemy_sprites();
        void Draw(sf::RenderWindow &window);
        void setPosition(sf::Vector2f coords);
        void setImage(sf::Texture & ture,sf::IntRect rect_init,std::string m_loc);
        void showTrees(int j);
        void showTrainMovements();
        void setPositionIndex();
        void train_recursive();
        void copter_recursive();
        void positionGenerator(int xa,int ya, int xb,int yb);
        void  copter_frame(int x);
        void clearFrameandPosition();

       // void setFrames();
     //   checkConditions();
    protected:
    private:
};

#endif // ENEMY_SPRITES_H
