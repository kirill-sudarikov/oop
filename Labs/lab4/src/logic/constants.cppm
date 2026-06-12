export module constants;

export constexpr int COOLDOWN = 3;
export constexpr int SKILL_DURATION = 2;
export constexpr float ARMOR_BUFF = 0.5f;
export constexpr float ARMOR_DEBUFF = 0.5f;
export constexpr float DAMAGE_DEBUFF = 0.7f;
export constexpr float DAMAGE_BUFF = 0.3f;

export constexpr float MIN_HEALTH = 1.0f;
export constexpr float MAX_HEALTH = 100.0f;
export constexpr float MIN_ARMOR = 1.0f;
export constexpr float MAX_ARMOR = 50.0f;
export constexpr float MIN_DAMAGE = 1.0f;
export constexpr float MAX_DAMAGE = 30.0f;
export constexpr float MIN_CHANCE = 0.0f;
export constexpr float MAX_CHANCE = 0.5f;

export constexpr float ARMOR_IGNOR_PERCENTAGE = 0.45f;
export constexpr float ARMOR_BONUS_PERCENTAGE = 0.35f;
export constexpr float TRIPLE_DAMAGE_CHANCE_BUFF = 0.3f;

export namespace knight {
	constexpr float KNIGHT_HEALTH = 100.0f;
	constexpr float KNIGHT_ARMOR = 50.0f;
	constexpr float KNIGHT_DAMAGE = 10.0f;
	constexpr float KNIGHT_CHANCE = 0.5f;
}

export namespace assassin {
	constexpr float ASSASSIN_HEALTH = 60.0f;
	constexpr float ASSASSIN_ARMOR = 5.0f;
	constexpr float ASSASSIN_DAMAGE = 10.0f;
	constexpr float ASSASSIN_CHANCE = 0.5f;
}

export namespace berserker {
	constexpr float BERSERKER_HEALTH = 80.0f;
	constexpr float BERSERKER_ARMOR = 30.0f;
	constexpr float BERSERKER_DAMAGE = 15.0f;
	constexpr float BERSERKER_CHANCE = 0.5f;
}
