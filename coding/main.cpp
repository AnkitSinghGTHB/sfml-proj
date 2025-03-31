#include <SFML/Graphics.hpp>
#include <optional> // For std::optional

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML TUTORIAL");
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Blue);

    // Center the circle in the window
    shape.setPosition(sf::Vector2f(
        (window.getSize().x - shape.getRadius() * 2) / 2.0f,
        (window.getSize().y - shape.getRadius() * 2) / 2.0f
    ));

    while (window.isOpen())
    {
        std::optional<sf::Event> eventOpt;
        while ((eventOpt = window.pollEvent()))
        {
            // Check if the event is of type Closed
            if (eventOpt && eventOpt->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}