#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include<sys/stat.h>
#include<time.h>
#include<fstream>
#include<string>

class Player
{
    public:
        Player();
        ~Player();
        void Initialize(int x ,int y,sf::IntRect ini_rect,std::string filename);
        void LoadContent(std::string s);
        void Update(sf::RenderWindow &window);
        void Draw(sf::RenderWindow &window);
        bool IsFileContentsChanged();
        Animation playerAnimation;

    protected:

    private:
        float x,y;
        sf::Texture playerImage;
        std::string  instr_file;
        std::string instructions;
        std::ifstream fp;
        int CurrentFrameX,CurrentFrameY;
        float moveSpeed;
        struct stat file_access;
        time_t last_modified_time;
};

#endif // PLAYER_H
