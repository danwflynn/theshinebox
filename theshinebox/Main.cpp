#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1400, 1000), "SFML Window");
    Player p1 = Player(400, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(135, 206, 235));
        // Draw your SFML graphics here
        p1.draw(window);
        p1.update();
        window.display();
    }

    return 0;
}
