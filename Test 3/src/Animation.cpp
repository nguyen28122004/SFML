#include "Animation.h"
#include <SFML/Graphics.hpp>


Animation::Animation(sf::Texture *texture , Vector2u imageCount , float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;

    uvRect.width = texture->getSize().x / imageCount.x;
    uvRect.height = texture->getSize().y / imageCount.y;

    totalTime = 0.0f;

    currentImage.x = 0 ;
    currentImage.y = 0;

}

Animation::~Animation()
{
    //dtor
}

void Animation::Update(float deltaTime , bool Rightface){

    totalTime += deltaTime;

    if(totalTime > switchTime){

        totalTime -= switchTime;
        currentImage.x ++;

    }
    if(currentImage.x >= imageCount.x){
        currentImage.x = 0;
        currentImage.y++;
    }
    if(currentImage.y >= imageCount.y){
        currentImage.y = 0 ;
        currentImage.x = 0;
    }

    uvRect.top = currentImage.y * uvRect.height;

    if(Rightface == true){
        uvRect.left = currentImage.x * abs(uvRect.width);

    }
    else{
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }

}
