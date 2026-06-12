export module character;
import std;
import constants;

export class Character
{
protected:
	float _health = 100.0f;
	float _armor = 50.0f;
	float _damage = 5.0f;

	std::random_device rd;
	std::mt19937 prng{ rd() };
	std::uniform_real_distribution<float> d{ 0.0f, 1.0f };

	int _cooldown = 0;
	int _skill_duration = 0;
	bool _is_skill_active = false;

	std::string _name;

public:
	virtual float calculate_damage(float input_damage) = 0;
	virtual float take_damage(float damage) = 0;
	virtual void use_special_skill() = 0;
	virtual void skill_update() = 0;
	virtual std::string to_string() = 0;
	int cooldown() const {
		return _cooldown;
	}
	float health() const {
		return _health;
	}
	float damage() const {
		return _damage;
	}
	bool is_skill_active() const {
		return _is_skill_active;
	}
};

