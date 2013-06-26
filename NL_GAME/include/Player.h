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
        void Initialize(int x ,int y,sf::IntRect ini_rect,std::string filename,bool enemy);
        void LoadContent(std::string s);
        void Update(sf::RenderWindow &window,std::vector<sf::Vector2f> &position_players);
        void Draw(sf::RenderWindow &window);
        bool IsFileContentsChanged();
        bool is_recursive;
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
