#include "../include/Player.h"
#include<iostream>
#include<cstdlib>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<vector>


Player::Player()
{

}

Player::~Player()
{
    //dtor
}

void Player::Initialize(int x , int y,sf::IntRect ini_rect,std::string filename)
{
    this->x=x;
    this->y=y;
    instr_file=filename;
    CurrentFrameX=0;
    CurrentFrameY=0;
    moveSpeed=3;
    playerAnimation.Initialize(x,y,ini_rect);
    moveSpeed++;
    if(!stat(instr_file.c_str(),&file_access))
        last_modified_time=file_access.st_mtime;
}

void Player::LoadContent(std::string image_location)
{
    if(playerImage.loadFromFile(image_location))
        playerAnimation.setImage(playerImage);

}

void Player::Update(sf::RenderWindow &window)
{
    instructions="";
    fp.open(instr_file.c_str());
    std::getline(fp,instructions);
    fp.close();

        if(instructions=="run")
            moveSpeed=7;
        else if(instructions=="walk")
            moveSpeed=3;


        if(instructions=="fire the tower guy")
        {
        system("espeak fire");
        playerAnimation.writeDietoOtherplayer();
        }
        else if (instructions=="die")
            playerAnimation.dieSprites(window);
        else if (instructions=="leftfire")
            playerAnimation.playerFireSideLeft(window);
        else if(instructions=="leftfirebackside")
            playerAnimation.playerFireSideLeftBackside(window);
        else if(instructions=="walkfront to the mango tree")
        {
            system("espeak mangotree");
            playerAnimation.playerFrontWalk(window,750,1290);
            playerAnimation.curr_position="mango tree";
        }

        else if(instructions=="walkfront to the neem tree")
        {
            system("espeak neemtree");
            playerAnimation.playerFrontWalk(window,870,1330);
            playerAnimation.curr_position="neem tree";
        }

        else if(instructions=="walkfront to the coconut tree")
        {
            playerAnimation.playerFrontWalk(window,930,1405);
            playerAnimation.curr_position="coconut tree";
        }

        else if(instructions=="where are you")
        {
         playerAnimation.sayLatLong(window);
        }


}

bool Player::IsFileContentsChanged()
{
    stat(instr_file.c_str(),&file_access);
    if(difftime(last_modified_time,file_access.st_mtime))
    {
        last_modified_time=file_access.st_mtime;
        return true;
    }
    else{
        return false;
    }

}

void Player::Draw(sf::RenderWindow &window)
{
    playerAnimation.Draw(window);
}



