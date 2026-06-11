module;

#include <SFML/Graphics.hpp>

export module Planet;

import std;

constexpr float G = 6.67e-11f;
constexpr std::size_t MAX_TRAIL_SIZE = 25000;

export class Planet {
private:
  sf::CircleShape _shape;
  float _mass = 0.0f;

  std::vector<sf::Vertex> _trail;

public:
  sf::Vector2f _position;
  sf::Vector2f _velocity;

  Planet(float m, float r, const sf::Vector2f& pos, const sf::Vector2f& v,
         const sf::Color& color)
      : _mass(m), _position(pos), _velocity(v) {

    _shape.setRadius(r);
    _shape.setOrigin({r, r});
    _shape.setFillColor(color);
    _shape.setPosition(_position);
  }

  float mass() const { return _mass; }

  void update(const Planet& other, float dt) {
    sf::Vector2f direction = other._position - _position;
    float r_sq = direction.x * direction.x + direction.y * direction.y;

    if (r_sq < 25.0f) {
      r_sq = 25.0f;
    }

    float gravity_force = G * _mass * other.mass() / r_sq;

    float r = std::sqrtf(r_sq);
    sf::Vector2f force_direction = direction / r;

    sf::Vector2f acceleration = gravity_force * force_direction / _mass;

    _velocity += acceleration * dt;
    _position += _velocity * dt;

    _shape.setPosition(_position);

    _trail.push_back(sf::Vertex(_position, _shape.getFillColor()));

    if (_trail.size() > MAX_TRAIL_SIZE) {
      _trail.erase(_trail.begin());
    }

    if (!_trail.empty()) {
      std::size_t size = _trail.size();

      for (std::size_t i = 0; i < size; ++i) {
        float ratio = static_cast<float>(i) / size;

        _trail[i].color.a = ratio * 255.0f;
      }
    }
  }

  void draw(sf::RenderWindow& window) {
    if (!_trail.empty()) {
      window.draw(_trail.data(), _trail.size(), sf::PrimitiveType::LineStrip);
    }

    window.draw(_shape);
  }
};