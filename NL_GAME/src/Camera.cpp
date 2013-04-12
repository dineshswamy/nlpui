#include "../include/Camera.h"


Camera::Camera(float x , float y)
{
    Camera::camera_x=x;
    Camera::camera_y=y;
    Camera::cameraPosition.setViewport(sf::FloatRect(x,y,800,800));
}

void Camera::Update(float x,float y)
{
    Camera::camera_x=x;
    Camera::camera_y=y;
    Camera::cameraPosition.reset(sf::FloatRect(x,y,800,800));
    Camera::cameraPosition.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));

}

void Camera::setView(sf::View view)
{
    Camera::cameraPosition=view;
}

sf::View Camera::getView()
{
    return Camera::cameraPosition;
}


void Camera::setRotation(float angle)
{
    Camera::cameraPosition.setRotation(angle);
}
