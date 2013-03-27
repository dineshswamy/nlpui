#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include<string>
#include "Animation.h"
#include<sys/stat.h>
#include<time.h>

class Player
{
    public:
        Player();
        ~Player();
        void Initialize(int x ,int y);
        void LoadContent(std::string s);
        void Update(sf::RenderWindow &window);
        void Draw(sf::RenderWindow &window);
        void isFileModified();
        Animation playerAnimation;

    protected:

    private:
        float x,y;
        sf::Texture playerImage;
        int CurrentFrameX,CurrentFrameY;
        float moveSpeed;
        struct stat attrib;
        struct tm* clock;
};

#endif // PLAYER_H
