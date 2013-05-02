#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include<fstream>
#include <string>
#include "include/Player.h"
#include "include/Map_places.h"
#include "include/Camera.h"
#include "include/Animation.h"
#include "include/Enemy_sprites.h"
#include<vector>
#define screenWidth 500
#define screenheight 500
#include<cstdlib>
#include<sys/stat.h>
#include<time.h>

using namespace std;
void positionGenerator(int xa,int ya, int xb,int yb,std::vector<sf::Vector2f>  &position );
int rec_size_x=150,rec_size_y=150;
float rec_x=0.0,rec_y=0.0,angle=0.0,rec_x_h=0.0,rec_y_h=0.0;
int hostage_steps=0,hostage_steps_check=0;
sf::RectangleShape position_collision;

std::vector<sf::Vector2f> rescue_team;
std::vector<sf::Vector2f> enemy_team;

std::vector<Map_places> places_in_map;

std::vector<sf::Vector2f> train_pos;
std::vector<sf::Vector2f>::iterator train_pos_itr;

std::vector<sf::Vector2f> hostage_pos;
std::vector<sf::Vector2f>::iterator hostage_pos_itr;

std::vector<sf::Vector2f> guards_a;
std::vector<sf::Vector2f>::iterator guards_pos_itr_a;

std::vector<sf::Vector2f> guards_b;
std::vector<sf::Vector2f>::iterator guards_pos_itr_b;

std::vector<sf::Vector2f> guards_c;
std::vector<sf::Vector2f>::iterator guards_pos_itr_c;

std::vector<sf::Vector2f> guards_d;
std::vector<sf::Vector2f>::iterator guards_pos_itr_d;

std::vector<sf::Vector2f> guards_e;
std::vector<sf::Vector2f>::iterator guards_pos_itr_e;
sf::Music train_sound;

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(1024,768,desktop.bitsPerPixel),"Natural language based game");
    window.setFramerateLimit(15);
    Camera camera_view(0,0);
    float top=0.0,left=0.0,width=0.0,height=0.0,x=70.f,y=70.f;
    //train_sound.openFromFile("train.ogg");


    train_sound.setVolume(40);
    train_sound.setLoop(true);
    train_sound.play();

    sf::Sprite mango_tree_spr;
    sf::Texture mango_tree_tex;


    sf::Sprite neem_tree_spr;
    sf::Texture neem_tree_tex;


    sf::Sprite coconut_tree_spr;
    sf::Texture coconut_tree_tex;


    sf::Sprite hostage_spr ;
    sf::Texture hostage_tex ;

     sf::Sprite guards_a_spr;
    sf::Texture guards_a_tex ;

       sf::Sprite guards_b_spr;
    sf::Texture guards_b_tex ;

       sf::Sprite guards_c_spr;
    sf::Texture guards_c_tex ;

       sf::Sprite guards_d_spr;
    sf::Texture guards_d_tex ;

       sf::Sprite guards_e_spr;
    sf::Texture guards_e_tex ;



//train and helicopter sprites
    Enemy_sprites enemy_train,enemy_copter;
    sf::Texture texture_train,texture_copter;
    sf::Music copter , train;
    //train.openFromFile("train.ogg");
    //copter.openFromFile("copter.ogg");
    //copter.setLoop(true);


    if(texture_train.loadFromFile("train_moving.png"))
        enemy_train.setImage(texture_train,sf::IntRect(0,0,191,111),"train.ogg");


    if(texture_copter.loadFromFile("copter_sprite.png"))
        enemy_copter.setImage(texture_copter,sf::IntRect(2,90,68,79),"copter.ogg");


    positionGenerator(696,648,1296,1210,enemy_train.position);
    positionGenerator(1296,1210,696,648,enemy_train.position);


    positionGenerator(1502,1018,1504,830,enemy_copter.position);
    positionGenerator(1504,830,1167,464,enemy_copter.position);
    positionGenerator(1167,464,1123,716,enemy_copter.position);
    positionGenerator(1123,716,1502,1018,enemy_copter.position);

    enemy_train.setPositionIndex();
    enemy_copter.setPositionIndex();



  if(hostage_tex.loadFromFile("rpg_boy_sprites.png"))
    hostage_spr.setTexture(hostage_tex);
    hostage_spr.setTextureRect(sf::IntRect(138,2,32,48));
    hostage_spr.setPosition(1166,349);

  if(mango_tree_tex.loadFromFile("mango_tree.png"))
    mango_tree_spr.setTexture(mango_tree_tex);
    mango_tree_spr.setTextureRect(sf::IntRect(0,0,102,136));
    mango_tree_spr.setPosition(750,1290);

if(neem_tree_tex.loadFromFile("neem_tree.png"))
    neem_tree_spr.setTexture(neem_tree_tex);
    neem_tree_spr.setTextureRect(sf::IntRect(0,0,102,136));
    neem_tree_spr.setPosition(870,1330);


if(coconut_tree_tex.loadFromFile("coconut_tree.png"))
    coconut_tree_spr.setTexture(coconut_tree_tex);
    coconut_tree_spr.setTextureRect(sf::IntRect(0,0,164,148));
    coconut_tree_spr.setPosition(930,1405);

        //Adding places to ma
   // Map_places grey_mountains(sf::IntRect(651,506,536,433),001,"grey_mountains");
    //places_in_map.push_back(grey_mountains);

Animation::enemy_objects.push_back(&enemy_copter);
Animation::enemy_objects.push_back(&enemy_train);

    Player player_bomber;
    Player player_sniper;
    Player player_jumper;
    Player player_firer;
    Player player_runner;

    Player player_enemy;
    Player player_enemy_a;
    Player player_enemy_b;
    Player player_enemy_c;

hostage_pos_itr=hostage_pos.begin();

    sf::Texture game_map;
    if(!game_map.loadFromFile("map_new.png"))
    {
        std::cout<<"Error! map cannot be loaded";
    }
    sf::Sprite map_sprite(game_map);

   player_bomber.LoadContent("soldier_green.png");

   player_bomber.Initialize(1046,1623,sf::IntRect(38,2,32,65),"team/bomber",false);

   player_sniper.LoadContent("soldier_blue.png");
   player_sniper.Initialize(1072,1643,sf::IntRect(38,2,32,65),"team/sniper",false);

   player_jumper.LoadContent("soldier_lightgreen.png");
   player_jumper.Initialize(1092,1650,sf::IntRect(38,2,32,65),"team/jumper",false);

   player_firer.LoadContent("soldier_orange.png");
   player_firer.Initialize(1016,1603,sf::IntRect(38,2,32,65),"team/firer",false);

   player_enemy.LoadContent("soldier_pink.png");
   player_enemy.Initialize(375,810,sf::IntRect(2,2,34,62),"enemy/enemy",true);


   player_enemy_a.LoadContent("soldier_pink.png");
   player_enemy_a.Initialize(1028,202,sf::IntRect(201,69,27,63),"enemy/enemy_c",true);


   player_enemy_b.LoadContent("soldier_pink.png");
   player_enemy_b.Initialize(1282,919,sf::IntRect(94,358,50,68),"enemy/enemy_a",true);


   player_enemy_c.LoadContent("soldier_pink.png");
   player_enemy_c.Initialize(1699,981,sf::IntRect(94,358,50,68),"enemy/enemy_b",true);

   //player_runner.LoadContent("soldier_green.png");
   //player_runner.Initialize(1016,1603,sf::IntRect(90,290,41,63),"team/runner");


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
                player_bomber.playerAnimation.setPosition(sf::Vector2i(x,y));
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard:: P))
            {
                y++;
                player_bomber.playerAnimation.setPosition(sf::Vector2i(x,y));
            }

            if( sf::Keyboard::isKeyPressed(sf::Keyboard:: L))
            {
                --x;
                player_bomber.playerAnimation.setPosition(sf::Vector2i(x,y));
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard:: K))
            {
                --y;
                player_bomber.playerAnimation.setPosition(sf::Vector2i(x,y));
            }


             if( sf::Keyboard::isKeyPressed(sf::Keyboard:: G))
                angle--;
              if( sf::Keyboard::isKeyPressed(sf::Keyboard:: H))
                angle++;

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

           // std::cout<<"X"<<x<<"Y"<<y<<std::endl;
            if( sf::Keyboard::isKeyPressed(sf::Keyboard:: M))
             {
                rec_x_h=rec_x_h+5;
             }
             else if( sf::Keyboard::isKeyPressed(sf::Keyboard:: N))
             {
                rec_x_h=rec_x_h-5;
             }
             else if( sf::Keyboard::isKeyPressed(sf::Keyboard:: V))
             {
                rec_y_h=rec_y_h+5;
             }
             else if( sf::Keyboard::isKeyPressed(sf::Keyboard:: C))
             {
                rec_y_h=rec_y_h-5;

             }
            camera_view.Update(rec_x,rec_y);
            camera_view.setRotation(angle);
            window.setView(camera_view.getView());

        }
    //end of events




    //checking if the rescue team is under enemys circle
     rescue_team.push_back(player_bomber.playerAnimation.playerLook.getPosition());
     rescue_team.push_back(player_sniper.playerAnimation.playerLook.getPosition());
     rescue_team.push_back(player_jumper.playerAnimation.playerLook.getPosition());
     rescue_team.push_back(player_firer.playerAnimation.playerLook.getPosition());

    enemy_team.push_back(player_enemy.playerAnimation.playerLook.getPosition());
    enemy_team.push_back(player_enemy_a.playerAnimation.playerLook.getPosition());
    enemy_team.push_back(player_enemy_b.playerAnimation.playerLook.getPosition());
    enemy_team.push_back(player_enemy_c.playerAnimation.playerLook.getPosition());


//        enemy_train.setImage(texture,sf::IntRect(0,0,192,111));




        window.draw(map_sprite);

        if(player_bomber.IsFileContentsChanged())
            player_bomber.Update(window,enemy_team);

        if(player_sniper.IsFileContentsChanged())
        player_sniper.Update(window,enemy_team);

        if(player_jumper.IsFileContentsChanged())
        player_jumper.Update(window,enemy_team);

        if(player_firer.IsFileContentsChanged())
        player_firer.Update(window,enemy_team);


         if(player_enemy.IsFileContentsChanged())
            player_enemy.Update(window,rescue_team);

         if(player_enemy_a.IsFileContentsChanged())
            player_enemy_a.Update(window,rescue_team);

         if(player_enemy_b.IsFileContentsChanged())
            player_enemy_b.Update(window,rescue_team);

         if(player_enemy_c.IsFileContentsChanged())
            player_enemy_c.Update(window,rescue_team);



        enemy_train.train_recursive();
        enemy_copter.copter_recursive();

        /*
        if(ck.getElapsedTime().asSeconds()>20)
        {
            enemy_copter.copter_frame(1);
        }
        */

        window.draw(enemy_train.enemyLook);
        window.draw(enemy_copter.enemyLook);

      // window.draw(player_bomber.playerAnimation.rectangle);
        player_firer.Draw(window);
        player_jumper.Draw(window);
        player_sniper.Draw(window);
        player_bomber.Draw(window);

        player_enemy.Draw(window);
        player_enemy_a.Draw(window);
        player_enemy_b.Draw(window);
        player_enemy_c.Draw(window);

        window.draw(hostage_spr);
        window.draw(mango_tree_spr);
        window.draw(neem_tree_spr);
        window.draw(coconut_tree_spr);
        //player_enemy.playerAnimation.checkInsideLOC(rescue_team,window);
        window.display();
        window.clear();

    }
    return 0;
}



void positionGenerator(int xa,int ya, int xb,int yb,std::vector<sf::Vector2f>  &position )
{
    int dx=0,dy=0,x_inc=0,y_inc=0,m=0,p=0,i=0;
    dx=xb-xa;
    dy=yb-ya;
    m=dy/dx;
    x_inc=dx>0?2:-2;
    y_inc=dy>0?2:-2;
    dx=abs(dx);
    dy=abs(dy);

    p=(2*dy)-(dx);

    position.push_back(sf::Vector2f(xa,ya));

    for(i=1;((xa!=xb) && (ya!=yb));i++)
    {
        if(p>0)
        {
            xa=xa+x_inc;
            ya=ya+y_inc;
            p=p+(2*dy)-(2*dx);
        }
        else
        {
            if(m<1)
            {
                xa=xa+x_inc;
                p=p+(2*dy);
            }
            else
            {
                ya=ya+y_inc;
                p=p-(2*dx);
            }

        }
    position.push_back(sf::Vector2f(xa,ya));

    }


}
