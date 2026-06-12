export module character;
import std;
import constants;

export class Character {

	float _health = 100.0f;
	float _armor = 50.0f;
	float _damage = 5.0f;
	float _reduce_damage_chance = 0.1f;

	std::random_device rd;
	std::mt19937 prng{ rd() };
	std::uniform_real_distribution<float> d{ 0.0f, 1.0f };

	int _cooldown = 0;
	int _skill_duration = 0;

	float _original_armor = 0.0f;
	float _original_damage = 0.0f;
	bool _skill_active = false;
public:

	Character() = default;

	Character(float health, float armor, float damage, float reduce_damage_chance)
		: _health(health),
		_armor(armor),
		_damage(damage),
		_reduce_damage_chance(reduce_damage_chance)
	{
	}

	float health() const { return _health; }
	float armor() const { return _armor; }
	float damage() const { return _damage; }
	float reduce_damage_chance() const { return _reduce_damage_chance; }
	bool is_skill_active() const { return _skill_active; }
	int cooldown() const { return _cooldown; }

	float take_damage(float input_damage) {

		float final_damage = input_damage * 100.0f / (100.0f + _armor);

		if (d(prng) < _reduce_damage_chance) {
			final_damage *= 0.5f;
		}

		_health -= final_damage;

		return final_damage;
	}

	bool use_special_skill(int current_round) {
		if (_skill_active || _cooldown != 0) {
			return false;
		}

		_original_armor = _armor;
		_original_damage = _damage;

		_armor *= ARMOR_BUFF;
		_damage *= DAMAGE_DEBUFF;

		_skill_active = true;
		_cooldown = COOLDOWN;
		_skill_duration = SKILL_DURATION;


		return true;
	}

	void skill_update() {

		if (_cooldown > 0) {
			_cooldown -= 1;
		}

		if (_skill_active) {
			_skill_duration -= 1;

			if (_skill_duration <= 0) {
				_armor = _original_armor;
				_damage = _original_damage;
				_skill_active = false;
			}
		}
	}
};