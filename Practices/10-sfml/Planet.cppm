module;

#include <SFML/Graphics.hpp>

export module Planet;

import std;

constexpr float G = 6.67e-11f;

export class Planet {
private:
  sf::CircleShape _shape;
  float _mass = 0.0f;

  sf::VertexArray _trail{sf::PrimitiveType::LineStrip};

public:
  sf::Vector2f _position;
  sf::Vector2f _velocity;

  Planet(float m, float r, const sf::Vector2f &pos, const sf::Vector2f &v,
         const sf::Color &color)
      : _mass(m), _position(pos), _velocity(v) {

    _shape.setRadius(r);
    _shape.setOrigin({r, r});
    _shape.setFillColor(color);
    _shape.setPosition(_position);
  }

  float mass() const { return _mass; }

  void update(const Planet &other, float dt) {
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

    _trail.append(sf::Vertex(_position));

    if (_trail.getVertexCount() > 500) {
      for (std::size_t i = 0; i < 50; ++i) {
        _trail[i].color = sf::Color(15, 15, 30);
      }

      for (std::size_t i = 1; i < _trail.getVertexCount(); ++i) {
        _trail[i - 1] = _trail[i];
      }
      _trail.resize(_trail.getVertexCount() - 1);
    }
  }

  void draw(sf::RenderWindow &window) {
    window.draw(_trail);
    window.draw(_shape);
  }
};