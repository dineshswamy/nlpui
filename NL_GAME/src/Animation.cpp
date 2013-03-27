#include "../include/Animation.h"
#include<iostream>

#define FrameWidth 32
#define FrameHeight 48

Animation::Animation()
{
    //ctor
}
void Animation::Initialize(float a , float b)
{
    x=a;
    y=b;
    currentFrameX=0;
    currentFrameY=0;
    playerLook.setPosition(x,y);
    playerLook.setTextureRect(sf::IntRect(2,2,57,44));
}

void Animation::setImage(sf::Texture &player_texture)
{
    playerLook.setTexture(player_texture);

}

void Animation::setPosition(int x , int y)
{
    playerLook.setPosition(x,y);
}

void Animation::Draw(sf::RenderWindow &window)
{
    if(!frame_stack.empty())
    {
        frame_stack_index=frame_stack.begin();
        playerLook.setTextureRect(*frame_stack_index);
        frame_stack.erase(frame_stack.begin());
    }
    window.draw(playerLook);
}

void Animation::Update()
{
currentFrameX=currentFrameX+FrameWidth;
if(currentFrameX>=128)
    currentFrameX=0;
playerLook.setTextureRect(sf::IntRect(currentFrameX,currentFrameY*FrameHeight,FrameWidth,FrameHeight));
}

void Animation::playerAnimations(sf::RenderWindow &window)
{

    int x_left=x,i;
    int x[8]={2,61,136,2,80,150,2,76};
    int y[8]={2,2,2,50,50,50,93,93};
    int width[8]={57,73,76,76,68,76,72,70};
    int height[8]={44,46,36,37,41,33,34,34};

    for(i=0;i<7;i++)
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

    for(i=0;i<7;i++)
    {
        frame_stack.push_back(sf::IntRect(x[i],y[i],width[i],height[i]));
    }
}





void Animation::setCurrentFrame(int y)
{
    currentFrameY=y;
}
























