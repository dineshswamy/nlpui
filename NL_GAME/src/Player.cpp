#include "../include/Player.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>


Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::Initialize(int x , int y)
{
    this->x=x;
    this->y=y;
    CurrentFrameX=0;
    CurrentFrameY=0;
    moveSpeed=3;
    playerAnimation.Initialize(x,y);
    moveSpeed++;
}

void Player::LoadContent(std::string image_location)
{
    if(playerImage.loadFromFile(image_location))
        playerAnimation.setImage(playerImage);

}

void Player::Update(sf::RenderWindow &window)
{
    std::string filename,hyp;
    std::ifstream fp;

    sf::FloatRect bound_tree(822,318,214,230);
    sf::FloatRect bound_building(207,594,214,248);
    hyp="";
    fp.open("hypothesis");
    std::getline(fp,hyp);

    fp.close();


        if(hyp=="run")
            moveSpeed=7;
        else if(hyp=="walk")
            moveSpeed=3;

		if(hyp=="up" || hyp=="run towards north" || hyp=="run upwards")
        {
            CurrentFrameY=3;
            moveSpeed=5;
            y-=moveSpeed;

        }
        else if(hyp=="down" || hyp=="walk towards south" || hyp=="walk downwards")
        {
            CurrentFrameY=0;
            moveSpeed=3;
            y+=moveSpeed;

        }

		if(hyp=="left" || hyp=="go to your left" || hyp=="run towards west")
        {
            CurrentFrameY=1;
            moveSpeed=7;
            x-=moveSpeed;

        }
        else if(hyp=="right"|| hyp=="go to your right")
        {

            CurrentFrameY=2;
            moveSpeed=3;
            x+=moveSpeed;
        }

        playerAnimation.setPosition(x,y);

        if(hyp=="fire")
        {
            //to be filled
            playerAnimation.playerFire(window);
        }

}

void Player::isFileModified()
{

}

void Player::Draw(sf::RenderWindow &window)
{
    playerAnimation.Draw(window);
}



