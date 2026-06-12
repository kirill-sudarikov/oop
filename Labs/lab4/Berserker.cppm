export module Berserker;
import std;
import constants;
import character;

export class Berserker final : public Character
{
	float _triple_damage_chance = 0.0f;
	float _original_damage = 0.0f;
	float _original_armor = 0.0f;
	float _original_triple_damage_chance = 0.0f;
public:
	Berserker(std::string name = "",
		float health = berserker::BERSERKER_HEALTH,
		float armor = berserker::BERSERKER_ARMOR,
		float damage = berserker::BERSERKER_DAMAGE,
		float triple_damage_chance = berserker::BERSERKER_CHANCE) :
		_triple_damage_chance(triple_damage_chance)
	{
		_name = name;
		_health = health;
		_armor = armor;
		_damage = damage;
	}
	float calculate_damage(float input_damage) override {
		float effective_armor = _armor * (1.0f + ARMOR_BONUS_PERCENTAGE);
		if (d(prng) < _triple_damage_chance) { input_damage *= 3.0f; }
		return input_damage * 100.0f / (100.0f + effective_armor);
	}
	float take_damage(float damage) override {
		_health -= damage;
		if (_health < 0.001f) { _health = 0.0f; }
		return damage;
	}
	void use_special_skill() override {
		if (_cooldown != 0) { return; }

		_original_damage = _damage;
		_damage *= (1.0f + DAMAGE_BUFF);

		_original_triple_damage_chance = _triple_damage_chance;
		_triple_damage_chance += TRIPLE_DAMAGE_CHANCE_BUFF;

		_original_armor = _armor;
		_armor *= (1.0f - ARMOR_DEBUFF);

		_is_skill_active = true;
		_cooldown = COOLDOWN;
		_skill_duration = SKILL_DURATION;
	}
	void skill_update() override {
		if (_cooldown > 0) { _cooldown -= 1; }
		if (_is_skill_active) {

			_skill_duration -= 1;

			if (_skill_duration <= 0) {
				_damage = _original_damage;
				_triple_damage_chance = _original_triple_damage_chance;
				_armor = _original_armor;
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
			"\n - вероятность утроенного урона: {:.1f}",
			_name, _health, _armor, _damage,
			_triple_damage_chance
		);
	}
};