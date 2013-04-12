#include "../include/Enemy_sprites.h"
#include<string>
#include<iostream>
Enemy_sprites::Enemy_sprites()
{
    //ctor

}
void Enemy_sprites::setImage(std::string imagename,sf::IntRect rect_init)
{
sf::Texture ture;
if(!ture.loadFromFile(imagename))
    std::cout<<"Error reading file ."<<std::endl;
enemyLook.setTexture(ture);
enemyLook.setTextureRect(sf::IntRect(100,100,569,327));
enemyLook.setPosition(100,100);
}
void  Enemy_sprites::setPosition(sf::Vector2f coords)
{
enemyLook.setPosition(coords);
}

void Enemy_sprites::Draw(sf::RenderWindow &window)
{
 //if(!frame_stack.empty())
  // enemyLook.setTextureRect(*frame_stack_index);
  // if(frame_stack_index!=frame_stack.end())
  //  frame_stack_index++;
// else
  //  frame_stack_index=frame_stack.begin();

 // if(enemyLook.getTextureRect().width!=0 && enemyLook.getTextureRect().height!=0)
    window.draw(enemyLook);
}

void Enemy_sprites::showTrees(int j)
{
    if(j==1)
    {
        //banyan tree
        frame_stack.push_back(sf::IntRect(2,2,113,143));
        position.push_back(sf::Vector2f(770,1205));
    }
    else if(j==2)
    {
        //neem tree
        frame_stack.push_back(sf::IntRect(106,297,101,134));
        position.push_back(sf::Vector2f(680,1345));

    }
    else if(j==3)
    {
            //coconut tree
            frame_stack.push_back(sf::IntRect(2,147,164,148));
            position.push_back(sf::Vector2f(1040,945));
    }
    else if(j==4)
    {
            //mango tree
            frame_stack.push_back(sf::IntRect(2,297,102,136));
            position.push_back(sf::Vector2f(780,865));
    }

    frame_stack_index=frame_stack.begin();
    position_stack_index=position.begin();
}


void Enemy_sprites::showTrainMovements()
{
enemyLook.setPosition(720,590);
positionGenerator(720,590,1320,1290);
position_stack_index=position.begin();
}


void Enemy_sprites::positionGenerator(int xa,int ya, int xb,int yb)
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
   // if(!IsColliding(x,y))
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

    //if(!IsColliding(xa,ya))
    position.push_back(sf::Vector2f(xa,ya));
    }


}






