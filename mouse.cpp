#include "mouse.h"

Mouse::Mouse()
{
    sf::Image defaultImage;
    defaultImage.loadFromFile("graphics/MS_Pointer.bmp");
    defaultImage.createMaskFromColor(sf::Color(255, 0, 255));
    defaultTexture.loadFromImage(defaultImage);

    sf::Image moveImage;
    moveImage.loadFromFile("graphics/MS_Move.bmp");
    moveImage.createMaskFromColor(sf::Color(255, 0, 255));
    moveTexture.loadFromImage(moveImage);

    sprite.setTexture(defaultTexture);
}


void Mouse::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite);
}

void Mouse::setPosition(const sf::Vector2f &point)
{
    sprite.setPosition(point);
}

void Mouse::setType(MouseType type)
{
    switch (type) {
    case MouseType::Default:
        sprite.setTexture(defaultTexture);
        break;
    case MouseType::Move:
        sprite.setTexture(moveTexture);
        break;
    case MouseType::Attack:
        sprite.setTexture(defaultTexture);
        break;
    default:
        break;
    }
}

#include "mouse.h"
