#include <SFML/Graphics.hpp>

import std;
import Planet;

int main() {
  sf::Vector2u window_scale(1920, 1080);
  sf::RenderWindow window(sf::VideoMode(window_scale), "Gravity Simulator");

  sf::Vector2f sun_pos({window_scale.x / 2.0f, window_scale.y / 2.0f});
  Planet sun(3.5e15f, 30.0f, sun_pos, {0.0f, 0.0f}, sf::Color::Yellow);

  sf::Vector2f mercury_pos(sun_pos.x, sun_pos.y - 60.0f);
  sf::Color mercury_color(100, 100, 100);
  Planet mercury(600.0f, 4.0f, mercury_pos, {65.0f, 0.0f}, mercury_color);

  sf::Vector2f venus_pos(sun_pos.x, sun_pos.y - 120.0f);
  sf::Color venus_color(255, 255, 200);
  Planet venus(3.5e4f, 9.0f, venus_pos, {45.0f, 0.0f}, venus_color);

  sf::Vector2f earth_pos(sun_pos.x, sun_pos.y - 180.0f);
  Planet earth(3.5e4f, 10.0f, earth_pos, {35.0f, 0.0f}, sf::Color::Blue);

  sf::Vector2f mars_pos(sun_pos.x, sun_pos.y - 220.0f);
  Planet mars(1.0e4f, 7.0f, mars_pos, {33.0f, 0.0f}, sf::Color::Red);

  sf::Vector2f jupiter_pos(sun_pos.x, sun_pos.y - 345.0f);
  sf::Color jupiter_color(255, 200, 150);
  Planet jupiter(350.0e4f, 15.0f, jupiter_pos, {25.5f, 0.0f}, jupiter_color);

  sf::Vector2f saturn_pos(sun_pos.x, sun_pos.y - 410.0f);
  sf::Color saturn_color(210, 200, 175);
  Planet saturn(150.0e4f, 13.5f, saturn_pos, {23.5f, 0.0f}, saturn_color);

  sf::Vector2f uranus_pos(sun_pos.x, sun_pos.y - 475.0f);
  sf::Color uranus_color(175, 220, 245);
  Planet uranus(70.0e4f, 8.0f, uranus_pos, {21.8f, 0.0f}, uranus_color);

  sf::Vector2f neptune_pos(sun_pos.x, sun_pos.y - 535.0f);
  sf::Color neptune_color(64, 224, 208);
  Planet neptune(70.0e4f, 8.0f, neptune_pos, {21.0f, 0.0f}, neptune_color);

  sf::Clock clock;

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    float dt = clock.restart().asSeconds();
    // if (dt > 0.02f) dt = 0.02f;

    mercury.update(sun, dt);
    venus.update(sun, dt);
    earth.update(sun, dt);
    mars.update(sun, dt);
    jupiter.update(sun, dt);
    saturn.update(sun, dt);
    uranus.update(sun, dt);
    neptune.update(sun, dt);

    window.clear(sf::Color(15, 15, 30));
    sun.draw(window);
    venus.draw(window);
    mercury.draw(window);
    earth.draw(window);
    mars.draw(window);
    jupiter.draw(window);
    saturn.draw(window);
    uranus.draw(window);
    neptune.draw(window);
    window.display();
  }
}
