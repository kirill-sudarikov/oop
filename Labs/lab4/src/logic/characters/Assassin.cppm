export module Assassin;
import std;
import constants;
import character;

export class Assassin final : public Character
{
	float _double_attack_chance = 0.0f;
public:
	Assassin(std::string name = "",
		float health = assassin::ASSASSIN_HEALTH,
		float armor = assassin::ASSASSIN_ARMOR,
		float damage = assassin::ASSASSIN_DAMAGE,
		float double_attack_chance = assassin::ASSASSIN_CHANCE) :
		_double_attack_chance(double_attack_chance)
	{
		_name = name;
		_health = health;
		_armor = armor;
		_damage = damage;
	}
	float calculate_damage(float input_damage) override {
		float effective_armor = _armor * (1.0f - ARMOR_IGNOR_PERCENTAGE);
		if (d(prng) < _double_attack_chance) { input_damage *= 2.0f; }
		return input_damage * 100.0f / (100.0f + effective_armor);
	}
	float take_damage(float damage) override {
		if (_is_skill_active) { return 0.0f; }
		_health -= damage;
		if (_health < 0.001f) { _health = 0.0f; }
		return damage;
	}
	void use_special_skill() override {
		if (_cooldown != 0) { return; }
		_is_skill_active = true;
		_cooldown = COOLDOWN;
		_skill_duration = SKILL_DURATION;
	}
	void skill_update() override {
		if (_cooldown > 0) { _cooldown -= 1; }
		if (_is_skill_active) {

			_skill_duration -= 1;

			if (_skill_duration <= 0) {
				_is_skill_active = false;
			}
		}
	}
	std::string to_string() override {
		return std::format(
			"{}: "
			"\n - здоровье: {:.1f}"
			"\n - броня: {:.1f}"
			"\n - урон: {:.1f}"
			"\n - вероятность повторной атаки в тот же ход: {:.1f}",
			_name, _health, _armor, _damage,
			_double_attack_chance
		);
	}
};