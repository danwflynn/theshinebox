#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Camera.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1400, 1000), "SFML Window");
    Camera camera(window);
    Map map;
    Player p1 = Player(400, 850, &map);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(9, 28, 59));
        map.draw_backside(window);
        p1.draw(window);
        map.draw_frontside(window);
        p1.update();
        camera.update(p1.x, p1.y);
        p1.draw_attributes(window, camera.getCenter().x - 750, camera.getCenter().y - 530);
        window.display();
    }

    return 0;
}
