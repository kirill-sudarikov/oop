export module Knight;
import std;
import constants;
import character;

export class Knight final : public Character
{
	float _reduce_damage_chance = 0.0f;
	float _original_armor = 0.0f;
	float _original_damage = 0.0f;
public:
	Knight(std::string name = "",
		float health = knight::KNIGHT_HEALTH,
		float armor = knight::KNIGHT_ARMOR,
		float damage = knight::KNIGHT_DAMAGE,
		float reduce_damage_chance = knight::KNIGHT_CHANCE) :
		_reduce_damage_chance(reduce_damage_chance)
	{
		_name = name;
		_health = health;
		_armor = armor;
		_damage = damage;
	}
	float calculate_damage(float input_damage) override {
		return input_damage * 100.0f / (100.0f + _armor);
	}
	float take_damage(float damage) override {
		if (d(prng) < _reduce_damage_chance) {
			damage *= 0.5f;
		}
		_health -= damage;
		if (_health < 0.001f) { _health = 0.0f; }
		return damage;
	}
	void use_special_skill() override {
		if (_cooldown != 0) { return; }

		_original_armor = _armor;
		_original_damage = _damage;

		_armor *= (1.0f + ARMOR_BUFF);
		_damage *= DAMAGE_DEBUFF;

		_is_skill_active = true;
		_cooldown = COOLDOWN;
		_skill_duration = SKILL_DURATION;
	}
	void skill_update() override {
		if (_cooldown > 0) { _cooldown -= 1; }
		if (_is_skill_active) {

			_skill_duration -= 1;

			if (_skill_duration <= 0) {
				_armor = _original_armor;
				_damage = _original_damage;
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
			"\n - вероятность снизить урон вдвое: {:.1f}",
			_name, _health, _armor, _damage,
			_reduce_damage_chance
		);
	}
};