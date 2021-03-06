#include "../include/Animation.h"
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<SFML/Audio.hpp>
#define FrameWidth 32
#define FrameHeight 48

Animation::Animation()
{
    //ctor
}
void Animation::Initialize(float a ,float b,sf::IntRect rect_init,bool enemy)
{
    x=a;
    y=b;
    currentFrameX=0;
    currentFrameY=0;
    this->enemy=enemy;
    playerLook.setPosition(x,y);
    playerLook.setTextureRect(rect_init);
    position_stack_index=position.begin();
    frame_stack_index=frame_stack.begin();
    enemy_objects_iterator=enemy_objects.begin();
}


void Animation::setImage(sf::Texture &player_texture)
{
    playerLook.setTexture(player_texture);

}

void Animation::setPosition(sf::Vector2i coords)
{
    playerLook.setPosition(coords.x,coords.y);
}

void Animation::Draw(sf::RenderWindow &window)
{
    if(!position.empty())
    {
       setPosition(*position_stack_index);
        position_stack_index++;
        position.erase(position.begin());
        //if(frame_stack_index!=frame_stack.end())
          //  frame_stack_index++;
        //else

            frame_stack_index=frame_stack.begin();

         //if(!frame_stack.empty())
         //{
            // if(playerLook.getTextureRect().width!=0 && playerLook.getTextureRect().height!=0)
                playerLook.setTextureRect(*frame_stack_index);
            //std::cout<<"w"<<playerLook.getTextureRect().width<<"h"<<playerLook.getTextureRect().height<<std::endl;

    }
    else
    {

        if(!frame_stack.empty())
        {
        frame_stack_index=frame_stack.begin();
        playerLook.setTextureRect(*frame_stack_index);
        //frame_stack.erase(frame_stack.begin());
        }
         //if(frame_stack_index<=frame_stack.end())
          //  frame_stack_index++;

    }
    if(playerLook.getTextureRect().width!=0 && playerLook.getTextureRect().height!=0)
    window.draw(playerLook);
}

void Animation::Update()
{
currentFrameX=currentFrameX+FrameWidth;
if(currentFrameX>=128)
    currentFrameX=0;
playerLook.setTextureRect(sf::IntRect(currentFrameX,currentFrameY*FrameHeight,FrameWidth,FrameHeight));
}

bool Animation::catchTheTrain()
{
//goto railway station

//for train , it is in index 1
enemy_objects_iterator=enemy_objects.begin();
enemy_objects_iterator++;
(**enemy_objects_iterator).start_recursive=true;

//std::cout<<"Train movement "<<(**enemy_objects_iterator).in_warehouse_left<<std::endl;


//std::cout<<"Train x"<<(**enemy_objects_iterator).enemyLook.getPosition().x<<"Train y"<<(**enemy_objects_iterator).enemyLook.getPosition().y<<std::endl;

if(playerLook.getPosition().x!=1296 && playerLook.getPosition().y!=1210)
{
if((**enemy_objects_iterator).moving && (**enemy_objects_iterator).in_warehouse_left)
{
setPosition(sf::Vector2i((**enemy_objects_iterator).enemyLook.getPosition().x,(**enemy_objects_iterator).enemyLook.getPosition().y));
std::cout<<"Player x"<<playerLook.getPosition().x<<"Player y"<<playerLook.getPosition().y<<std::endl;
//std::cout<<"Train x"<<(*enemy_objects_iterator).enemyLook.getPosition().x<<"Train y"<<(*enemy_objects_iterator).enemyLook.getPosition().y<<std::endl;
}
return true;
}
else
{
    setPosition(sf::Vector2i(1536,1337));
    //system("espeak \"I\\ can\\ get\\ a\\ shot\\ for\\ the\\ copter \"");
    return false;
}
}


void Animation::blowTheCopter()
{
    enemy_objects_iterator=enemy_objects.begin();
    (**enemy_objects_iterator).copter_frame(1);
}

void Animation::sayLatLong(sf::RenderWindow &window)
{

    std::string to_talk="\"i m  at " + curr_position + "\"";
    sf::Text text(to_talk);
    text.setPosition(playerLook.getPosition());
   // window.draw(text
    //system(std::string("espeak " +to_talk).c_str());
    //system(std::string("espeak" + to_talk).c_str());
}


void Animation::playerAnimations(sf::RenderWindow &window)
{

    int x_left=x,i;
    int x[8]={2,61,136,2,80,150,2,76};
    int y[8]={2,2,2,50,50,50,93,93};
    int width[8]={57,73,76,76,68,76,72,70};
    int height[8]={44,46,36,37,41,33,34,34};

    for(i=0;i<8;i++)
    {
        frame_stack.push_back(sf::IntRect(x[i],y[i],width[i],height[i]));
    }
}

void Animation::playerFire(sf::RenderWindow &window)
{

    int x_left=x,i;
    int x[]={135,223,274,315,366,412,456,2};
    int y[]={69,290,290,290,290,290,290,358};
    int width[]={33,49,39,49,44,42,53,38};
    int height[]={63,64,63,66,65,63,66,64};

    for(i=0;i<6;i++)
    {
        frame_stack.push_back(sf::IntRect(x[i],y[i],width[i],height[i]));
    }
}



void Animation::playerFrontWalk(sf::RenderWindow &window,int xb,int yb)
{
    int i;
    int x[]={428,465,2,42,79};
    int y[]={69,69,146,146,146};
    int width[]={35,33,38,35,34};
    int height[]={61,61,60,61,60};
    frame_stack.clear();
    position.clear();
    /*for(i=0;i<4;i++)
    {
        frame_stack.push_back(sf::IntRect(x[i],y[i],width[i],height[i]));
    } */
    frame_stack.push_back(sf::IntRect(x[0],y[0],width[0],height[0]));
    positionGenerator(playerLook.getPosition().x,playerLook.getPosition().y,xb,yb,1);
    frame_stack_index=frame_stack.begin();
    position_stack_index=position.begin();
}


void Animation::playerWalkFront(sf::RenderWindow &window)
{

    int i;
    int x[]={428,465,2,42,79};
    int y[]={69,69,146,146,146};
    int width[]={35,33,38,35,34};
    int height[]={61,61,60,61,60};

    for(i=0;i<5;i++)
    {
        frame_stack.push_back(sf::IntRect(x[i],y[i],width[i],height[i]));
    }

}

void Animation::playerFireSideLeft(sf::RenderWindow &window)
{
    int i;
    int x[]={115,171,227,281,337,390,449};
    int y[]={146,146,146,146,146,146,146};
    int width[]={54,54,52,54,51,57,45};
    int height[]={67,70,67,69,68,63,61};
    for(i=0;i<6;i++)
    {
        frame_stack.push_back(sf::IntRect(x[i],y[i],width[i],height[i]));
    }
    frame_stack_index=frame_stack.begin();
}

void Animation::writeDietoOtherplayer(int player_index)
{
std::string file_name;
if(!enemy)
{
    switch(player_index)
    {
        case 1:
                file_name="enemy/enemy";
                break;
        case 2:
                file_name="enemy/enemy_a";
                break;
        case 3:
                file_name="enemy/enemy_b";
                break;
        case 4:
                file_name="enemy/enemy_c";
                break;
    }
}
else
{
    switch(player_index)
    {
        case 1:
                file_name="team/bomber";
                break;
        case 2:
                file_name="team/sniper";
                break;
        case 3:
                file_name="team/jumper";
                break;
        case 4:
                file_name="team/firer";
                break;
        default:
            std::cout<<"No match found"<<std::endl;
    }


}
//std::cout<<"FILE"<<file_name<<std::endl;
std::ofstream fg(file_name.c_str());
fg<<("die");
fg.close();
}



void Animation::playerFireSideLeftBackside(sf::RenderWindow &window)
{
    int i;
    int x[]={2,59,107,164,219,266,305};
    int y[]={218,218,218,218,218,218,218};
    int width[]={55,46,55,53,45,37,40};
    int height[]={62,64,63,68,70,63,60};

    for(i=0;i<7;i++)
    {
        frame_stack.push_back(sf::IntRect(x[i],y[i],width[i],height[i]));
    }
    frame_stack_index=frame_stack.begin();
}

void Animation::dieSprites(sf::RenderWindow &window)
{
    sf::Music bullet;
    bullet.openFromFile("explosion.ogg");
    bullet.setVolume(40);
    bullet.play();
    frame_stack.clear();
    frame_stack.push_back(sf::IntRect(335,2,58,40));
    setPosition(sf::Vector2i(293,993));
    frame_stack_index=frame_stack.begin();
}


void Animation::clearPositionandFrames()
{
    frame_stack.clear();
    position.clear();
}


void Animation::setCurrentFrame(int y)
{
    currentFrameY=y;
}

void Animation::Takeposition(int xb,int yb)
{

    playerLook.setPosition(xb,yb);
    playerLook.setTextureRect(sf::IntRect(201,69,27,63));

}


std::vector<sf::Vector2f> Animation::getPosition()
{
//return sf::Vector2f(this->playerLook.getPosition().x,this->playerLook.getPosition().y);
}


bool Animation::checkInsideLOC(std::vector<sf::Vector2f> &position_players,sf::RenderWindow &window)
{
int j=0;
float lhs=0.0;
line_of_control.height=500;
line_of_control.width=500;
line_of_control.left=this->playerLook.getPosition().x-670;
line_of_control.top=this->playerLook.getPosition().y-670;
//std::cout<<"from LOC X"<<this->playerLook.getPosition().x<<"from  LOC  Y"<<this->playerLook.getPosition().y<<std::endl;
rectangle.setSize(sf::Vector2f(500,500));
rectangle.setOutlineColor(sf::Color::Red);
rectangle.setOutlineThickness(5);
rectangle.setPosition(line_of_control.left,line_of_control.top);
rectangle.setTextureRect(line_of_control);

for(loc_iterator=position_players.begin();loc_iterator!=position_players.end();loc_iterator++)
{
//std::cout<<" X "<<(*loc_iterator).x<<" Y "<<(*loc_iterator).y<<" J"<<j<<std::endl;
j++;
if(line_of_control.contains((*loc_iterator).x,(*loc_iterator).y))
{
        //std::cout<<" X "<<(*loc_iterator).x<<" Y "<<(*loc_iterator).y<<" J"<<j<<std::endl;
        writeDietoOtherplayer(j);
       // std::cout<<"J:"<<j<<std::endl;
        break;
}
}
std::cout<<"J"<<j<<std::endl;
if(j==4)
{
    j=0;
    setPosition(sf::Vector2i(playerLook.getPosition().x+10,playerLook.getPosition().y+10));
 //   return true;
}
return false;
}



void Animation::positionGenerator(int xa,int ya, int xb,int yb,int incr)
{
    int dx=0,dy=0,x_inc=0,y_inc=0,m=0,p=0,i=0,max_x_y=0;
    dx=xb-xa;
    dy=yb-ya;
    m=dy/dx;
    x_inc=dx>0?incr:-incr;
    y_inc=dy>0?incr:-incr;
    std::cout<<"x_incr"<<x_inc<<"y_incr"<<y_inc<<std::endl;
    dx=std::abs(dx);
    dy=std::abs(dy);
    if(m<1)
        max_x_y=dx;
    else
        max_x_y=dy;

    p=(2*dy)-(dx);
    if(!IsColliding(x,y))
    position.push_back(sf::Vector2i(x,y));

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

   // if(!IsColliding(xa,ya))
    //{
    position.push_back(sf::Vector2i(xa,ya));
    //std::cout<<"x"<<xa<<"y"<<ya<<std::endl;
    //}

    }
}

bool Animation::IsColliding(int x, int y)
{
   /* std::vector<Map_places>::iterator colliding_rect;
    int flag=0;
    Map_places rect;
    for(colliding_rect=places_collision.begin();colliding_rect<places_collision.end();colliding_rect++)
    {
     rect=*colliding_rect;

     if(rect.bounds.contains(x,y))
        flag=1;
     else
        flag=0;
    }
    if(flag==1)
        return true;
    else
        return false;
        */

}

std::vector<Enemy_sprites*> Animation::enemy_objects;






















