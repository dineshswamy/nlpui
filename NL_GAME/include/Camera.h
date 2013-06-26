#ifndef CAMERA_H
#define CAMERA_H

#include<SFML/Graphics.hpp>
class Camera
{
    public:
        Camera(float x,float y);
        float camera_x,camera_y;
        sf::View cameraPosition;
        void setView(sf::View view);
        void setRotation(float angle);
        sf::View getView();
        void Update(float x , float y);
    protected:
    private:
};

#endif // CAMERA_H
