#ifndef ANIMATION_H
#define ANIMATION_H
#include<SFML/Graphics.hpp>
#include<vector>
class Animation
{
    public:
        Animation();
        void Initialize(float x, float y);
        void Update();
        void playerAnimations(sf::RenderWindow & window);
        void playerFire(sf::RenderWindow & window);
        void Draw(sf::RenderWindow &window);
        void setPosition(int x , int y);
        void setImage(sf::Texture &player_texture);
        void setCurrentFrame(int y);

    protected:
    private:
        sf::Sprite playerLook;
        std::vector<sf::IntRect> frame_stack;
        std::vector<sf::IntRect>::iterator frame_stack_index;
        int currentFrameX,currentFrameY;
        float x,y;
};

#endif // ANIMATION_H