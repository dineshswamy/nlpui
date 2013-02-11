#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#define setScreenWidth 800
#define setScreenHeight 800

#define st_down 0
#define st_left 62
#define st_right 186
#define st_up 124

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,800),"NLP_GAME_UI");

    sf::Texture im_texture;

    sf::Sprite im_sprite;

    sf::Text recognised;

    recognised.setColor(sf::Color::Black);
    std::string hyp;
    std::ifstream fp;
    int stop=1;


    if(!im_texture.loadFromFile("sprites_king.png"))
        std::cout<<"Image cannot be loaded";

    int vel_x=0,vel_y=0,x=20,y=20,sprite_x=0,sprite_y=0;
    int move_speed=1;

    im_sprite.setTexture(im_texture);


    im_sprite.setTextureRect(sf::IntRect(0,0,30,62));
    im_sprite.setColor(sf::Color(255, 255, 255, 200));
    window.setFramerateLimit(0);




	while (window.isOpen())
	{
		sf::Event event;
		hyp="";
        fp.open("hypothesis");
        std::getline(fp,hyp);
        fp.close();


		while (window.pollEvent(event))
		{
			if(event.type== sf :: Event :: Closed)
			window.close();
		}
        if(hyp=="stop")
        stop=0;
        else
            stop=1;

		if(hyp=="up")
        {

            sprite_y=st_up;
            vel_y=-move_speed;


        }
        else if(hyp=="down")
        {

            sprite_y=st_down;
            vel_y=move_speed;

        }
        else
            vel_y=0;


		if(hyp=="left")
        {

            sprite_y=st_left;
            vel_x=-move_speed;

        }
        else if(hyp=="right")
        {

             sprite_y=st_right;
             vel_x=move_speed;

        }
        else
            vel_x=0;

        x=x+vel_x;
        y=y+vel_y;

        if(vel_x!=0 && vel_y!=0)
            sprite_x+=32;
        else
            sprite_x=0;
        if(sprite_x==im_texture.getSize().x)
            sprite_x=0;

        im_sprite.setTextureRect(sf::IntRect(sprite_x,sprite_y,30,62));
        window.clear(sf::Color::White);
        im_sprite.setPosition(x,y);


            recognised.setString(hyp);


        window.draw(recognised);
        window.draw(im_sprite);


        window.display();
    }
	return 0 ;
}
