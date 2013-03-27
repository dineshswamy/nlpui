#include<SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "include/Player.h"
#include "include/Camera.h"
#define screenWidth 500
#define screenheight 500

#include<sys/stat.h>
#include<time.h>

using namespace std;
bool IsFileContentsChanged();
int rec_size_x=100,rec_size_y=50;
float rec_x=0.0,rec_y=0.0;
sf::RectangleShape position_collision ;
struct stat file_access;
time_t last_modified_time;

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(1024,768,desktop.bitsPerPixel),"Natural language based game");
    window.setFramerateLimit(5);
    Camera camera_view(0,0);
    float top=0.0,left=0.0,width=0.0,height=0.0,x=70.f,y=70.f;


    Player player_bomber;
    Player player_sniper;
    Player player_jumper;
    Player player_firer;
    sf::Texture game_map;
    if(!game_map.loadFromFile("map_new.png"))
    {
        std::cout<<"Error! map cannot be loaded";
    }
    sf::Sprite map_sprite(game_map);





   player_bomber.Initialize(x,y);
   player_bomber.LoadContent("soldier_green.png");

    //player_sniper.Initialize(10.f,10.f);
    //player_sniper.LoadContent("rpg_boy.png");

    //player_jumper.Initialize(120.f,90.f);
   //player_jumper.LoadContent("player.png");

    // player_firer.Initialize(110.f,30.f);
    //player_firer.LoadContent("rpg_boy.png");

    if(!stat("hypothesis",&file_access))
        last_modified_time=file_access.st_mtime;



    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event :: Closed)
                window.close();
             if(event.type==sf::Event :: KeyPressed && event.key.code == sf::Keyboard:: Escape)
                window.close();

            if( sf::Keyboard::isKeyPressed(sf::Keyboard:: O))
            {
                x++;
                player_bomber.playerAnimation.setPosition(x,y);
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard:: P))
            {
                y++;
                player_bomber.playerAnimation.setPosition(x,y);
            }


            if( sf::Keyboard::isKeyPressed(sf::Keyboard:: A))
             {
                rec_x=rec_x-15;
             }
             else if( sf::Keyboard::isKeyPressed(sf::Keyboard:: D))
             {
                rec_x=rec_x+15;
             }
             else if( sf::Keyboard::isKeyPressed(sf::Keyboard:: W))
             {
                rec_y=rec_y-15;
             }
             else if( sf::Keyboard::isKeyPressed(sf::Keyboard:: S))
             {
                rec_y=rec_y+15;

             }

             if(rec_x<0)
                rec_x=0;
             if(rec_y<0)
                rec_y=0;

            camera_view.Update(rec_x,rec_y);
            window.setView(camera_view.getView());

        }


    window.draw(map_sprite);

        /*
        player_jumper.Update();
        player_jumper.Draw(window);


        player_firer.Update();
        player_firer.Draw(window);
        */



        if(IsFileContentsChanged())
        {
            player_bomber.Update(window);
        }
        player_bomber.Draw(window);


       //player_sniper.Draw(window);


       /* player_sniper.Update(position_collision);
        player_sniper.Draw(window);

        player_jumper.Update(position_collision);
        player_jumper.Draw(window);

        player_firer.Update(position_collision);
        player_firer.Draw(window);

        */



    window.display();
    window.clear();

    }
    return 0;
}


bool IsFileContentsChanged()
{
    stat("hypothesis",&file_access);
    if(difftime(last_modified_time,file_access.st_mtime))
    {
        last_modified_time=file_access.st_mtime;
            return true;
    }
    else

            return false;
}
