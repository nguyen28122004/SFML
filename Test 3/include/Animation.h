#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Animation
{
    public:
        Animation(Texture * , Vector2u imageCount, float switchTime);
        virtual ~Animation();

        void Update(float deltaTime , bool Rightface);

        IntRect uvRect;

    protected:

    private:
        Vector2u imageCount;
        Vector2u currentImage;

        float switchTime;
        float totalTime;
};

#endif // ANIMATION_H
