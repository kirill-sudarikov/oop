#include <SFML/Graphics.hpp>

import std;
import Planet;

int main() {
  sf::Vector2u window_scale(1920, 1080);
  sf::RenderWindow window(sf::VideoMode(window_scale), "Gravity Simulator");

  sf::Vector2f sun_pos({window_scale.x / 2.0f, window_scale.y / 2.0f});
  Planet sun(3.5e16f, 30.0f, sun_pos, {0.0f, 0.0f}, sf::Color::Black);

  sf::Vector2f earth_pos(sun_pos.x - 100.0f, sun_pos.y - 450.0f);
  Planet earth(10.0e4f, 10.0f, earth_pos, {35.0f, 20.0f}, sf::Color::Blue);

  sf::Vector2f mars_pos(sun_pos.x - 40.0f, sun_pos.y - 450.0f);
  Planet mars(5.0e4f, 7.0f, mars_pos, {30.0f, 15.0f}, sf::Color::Red);

  sf::Clock clock;

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    float dt = clock.restart().asSeconds();
    // if (dt > 0.02f) dt = 0.02f;

    earth.update(sun, dt);
    mars.update(sun, dt);

    window.clear(sf::Color(15, 15, 30));
    sun.draw(window);
    earth.draw(window);
    mars.draw(window);
    window.display();
  }
}
