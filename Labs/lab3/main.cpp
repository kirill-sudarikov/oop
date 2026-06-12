import std;
import constants;
import input;
import random;
import character;

int main() {

	std::println("-------------------------");
	std::println("   ЛР №: 3");
	std::println(" Группа: 6112");
	std::println("  Автор: Судариков Кирилл");
	std::println("Вариант: 18(*)");
	std::println("-------------------------");
	std::println();

	std::println("-----------");
	std::println("Ввод данных");
	std::println("-----------");

	float computer_health = get_random_num(MIN_HEALTH, MAX_HEALTH);
	float computer_armor = get_random_num(MIN_ARMOR, MAX_ARMOR);
	float computer_damage = get_random_num(MIN_DAMAGE, MAX_DAMAGE);
	float computer_chance = get_random_num(MIN_CHANCE, MAX_CHANCE);
	int computer_choice = 0;

	float user_health = 0.0f;
	float user_armor = 0.0f;
	float user_damage = 0.0f;
	float user_chance = 0.0f;
	int user_choice = 0;

	int current_round = 1;
	bool game_over = false;

	Character computer_knight(
		computer_health,
		computer_armor,
		computer_damage,
		computer_chance
	);

	std::println("Создание персонажа");
	std::print("Введите здоровье [{};{}]: ", MIN_HEALTH, MAX_HEALTH);
	user_health = input_num("Введите здоровье ещё раз: ", MIN_HEALTH, MAX_HEALTH);

	std::print("Введите броню [{};{}]: ", MIN_ARMOR, MAX_ARMOR);
	user_armor = input_num("Введите броню ещё раз: ", MIN_ARMOR, MAX_ARMOR);

	std::print("Введите урон [{};{}]: ", MIN_DAMAGE, MAX_DAMAGE);
	user_damage = input_num("Введите урон ещё раз: ", MIN_DAMAGE, MAX_DAMAGE);

	std::print("Введите шанс снизить входящий урон вдвое [{};{}]: ", MIN_CHANCE, MAX_CHANCE);
	user_chance = input_num("Введите шанс ещё раз: ", MIN_CHANCE, MAX_CHANCE);

	Character user_knight(user_health, user_armor, user_damage, user_chance);
	std::println("Персонаж создан!");
	std::println();

	std::println("--------------------------------");
	std::println("Характеристики вашего персонажа:\n{:.1f} здоровья\n{:.1f} брони\n{:.1f} урона\n{:.0f}% шанс снизить урон вдвое.",
		user_knight.health(),
		user_knight.armor(),
		user_knight.damage(),
		user_knight.reduce_damage_chance() * 100.0f
	);
	std::println("--------------------------------");
	std::println();

	std::println("---------------------------------");
	std::println("Характеристики вашего противника:\n{:.1f} здоровья\n{:.1f} брони\n{:.1f} урона\n{:.0f}% шанс снизить урон вдвое.",
		computer_knight.health(),
		computer_knight.armor(),
		computer_knight.damage(),
		computer_knight.reduce_damage_chance() * 100.0f
	);
	std::println("---------------------------------");
	std::println();

	std::println("-------------");
	std::println("НАЧИНАЕМ БОЙ!");
	std::println("-------------");
	std::println();

	while (!game_over) {
		
		user_knight.skill_update();
		computer_knight.skill_update();

		std::println("-------------");
		std::println("РАУНД {}", current_round);
		std::println("-------------");
		std::println();

		std::println("--------");
		std::println("ВАШ ХОД!");
		std::println("--------");
		std::println();

		std::println("[1] Применить обычную атаку");
		if (user_knight.cooldown() == 0) {
			std::println("[2] Применить особое умение (умение готово)");
		}
		else {
			std::println("[2] Применить особое умение (осталось раундов: {})", user_knight.cooldown());
		}
		std::println();

		std::print("Выберите действие:");
		std::cin >> user_choice;

		switch (user_choice) {
		case(1): {
			std::println("Вы нанесли {:.1f} урона.", computer_knight.take_damage(user_knight.damage()));

			if ((computer_knight.health() - 0.0f) < 1.0e-10f) {
				std::println("ПРОТИВНИК ПОВЕРЖЕН! ПОБЕДА!");
				game_over = true;
				break;
			}

			std::println("У противника осталось {:.1f} здоровья.", computer_knight.health());
			break;
		}
		case(2): {
			if (user_knight.cooldown() == 0) {
				if (user_knight.use_special_skill(current_round)) {
					std::println("Вы применили особое умение!");
					std::println("Ваша броня увеличилась в {:.1f} раз, а урон уменьшился в {:.1f} раз.", ARMOR_BUFF, 1 - DAMAGE_DEBUFF);
					std::println("Умение будет действовать {} раундов", SKILL_DURATION);
				}
				else {
					std::println("Произошла ошибка применения умения!!!");
				}
				
			}
			else {
				std::println("Ваше умение на перезарядке! Применена обычная атака.");
				std::println("Вы нанесли {:.1f} урона.", computer_knight.take_damage(user_knight.damage()));
				
				if ((computer_knight.health() - 0.0f) < 1.0e-10f) {
					std::println("ПРОТИВНИК ПОВЕРЖЕН! ПОБЕДА!");
					game_over = true;
					break;
				}

				std::println("У противника осталось {:.1f} здоровья.", computer_knight.health());
			}
			break;
		}
		default: {
			std::println("Ошибка! Выбран несуществующий пукнт меню!");
			continue;
		}
		}

		if (game_over) {
			break;
		}

		std::println();

		std::println("---------------");
		std::println("ХОД ПРОТИВНИКА!");
		std::println("---------------");
		std::println();

		switch (get_random_num(1, 2)) {
		case(1): {
			std::println("Противник нанес {:.1f} урона.", user_knight.take_damage(computer_knight.damage()));
			
			if ((user_knight.health() - 0.0f) < 1.0e-10f) {
				std::println("ПРОТИВНИК ПОБЕДИЛ! ВЫ ПРОИГРАЛИ!");
				game_over = true;
				break;
			}

			std::println("У Вас осталось {:.1f} здоровья.", user_knight.health());
			break;
		}
		case(2): {
			if (computer_knight.is_skill_active() == false && computer_knight.cooldown() == 0) {
				if (computer_knight.use_special_skill(current_round)) {
					std::println("Противник применил особое умение!");
				}
			}
			else {
				std::println("Противник нанес {:.1f} урона.", user_knight.take_damage(computer_knight.damage()));
				
				if ((user_knight.health() - 0.0f) < 1.0e-10f) {
					std::println("ПРОТИВНИК ПОБЕДИЛ! ВЫ ПРОИГРАЛИ!");
					game_over = true;
					break;
				}

				std::println("У Вас осталось {:.1f} здоровья.", user_knight.health());
			}
			break;
		}
		default: {
			std::println("Ошибка! Выбран несуществующий пукнт меню!");
		}
		}
		std::println();

		current_round += 1;
	}

	return 0;
}