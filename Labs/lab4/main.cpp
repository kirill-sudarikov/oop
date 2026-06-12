import std;
import constants;
import random;
import character;
import Knight;
import Assassin;
import Berserker;

int main()
{
	std::string user_name;
	std::string bot_name = "Противник";
	int bot_choice = 0;
	bool game_over = false;
	int current_round = 1;


	std::shared_ptr<Character> user = nullptr;
	std::shared_ptr<Character> bot = nullptr;

	std::println("-------------------------");
	std::println("   ЛР №: 4");
	std::println(" Группа: 6112");
	std::println("  Автор: Судариков Кирилл");
	std::println("Вариант: 18(*)");
	std::println("-------------------------");
	std::println();

	std::println("-----------");
	std::println("Ввод данных");
	std::println("-----------");

	std::println();
	std::print("Введите имя Вашего персонажа: ");
	std::cin >> user_name;

	while (true)
	{
		int user_choice = 0;
		std::println();
		std::println("[1] Рыцарь");
		std::println("[2] Ассассин");
		std::println("[3] Берсерк");

		std::print("Выберите класс: ");
		std::cin >> user_choice;

		switch (user_choice) {
		case(1):
			std::println("Рыцарь создан!");
			user = std::make_shared<Knight>(user_name);
			break;
		case(2):
			std::println("Ассассин создан!");
			user = std::make_shared<Assassin>(user_name);
			break;
		case(3):
			std::println("Берсерк создан!");
			user = std::make_shared<Berserker>(user_name);
			break;
		default:
			std::println("Ошибка! Выбран несуществующий пукнт меню!");
			continue;
		}

		user_choice = 0;
		break;
	}

	bot_choice = get_random_num(1, 3);
	switch (bot_choice)
	{
	case(1):
		std::println("Противник выбрал Рыцаря!");
		bot = std::make_shared<Knight>(bot_name);
		break;
	case(2):
		std::println("Противник выбрал Ассассина!");
		bot = std::make_shared<Assassin>(bot_name);
		break;
	case(3):
		std::println("Противник выбрал Берсерка!");
		bot = std::make_shared<Berserker>(bot_name);
		break;
	default:
		std::println("Ошибка! Выбран несуществующий пукнт меню!");
		break;
	}

	std::println();
	std::println("{}", user->to_string());
	std::println();
	std::println("{}", bot->to_string());
	std::println();

	std::println(
		"-------------\n"
		"НАЧИНАЕМ БОЙ!\n"
		"-------------\n"
	);
	std::println();

	while (!game_over)
	{
		user->skill_update();
		bot->skill_update();

		std::println("-------------");
		std::println("РАУНД {}", current_round);
		std::println("-------------");
		std::println();

		std::println("--------");
		std::println("ВАШ ХОД!");
		std::println("--------");
		std::println();

		std::println("[1] Применить обычную атаку");
		if (user->cooldown() == 0) {
			std::println("[2] Применить особое умение (умение готово)");
		}
		else {
			std::println("[2] Применить особое умение (осталось раундов: {})", user->cooldown());
		}
		std::println();

		std::print("Выберите действие:");
		int user_choice = 0;
		std::cin >> user_choice;

		switch (user_choice) {
		case(1): {
			std::println("Вы нанесли {:.1f} урона.", bot->take_damage(bot->calculate_damage(user->damage())));

			if ((bot->health() - 0.0f) < 1.0e-10f) {
				std::println("ПРОТИВНИК ПОВЕРЖЕН! ПОБЕДА!");
				game_over = true;
				break;
			}

			std::println("У противника осталось {:.1f} здоровья.", bot->health());

			break;
		}
		case(2): {
			if (user->cooldown() == 0) {
				user->use_special_skill();
				std::println("Вы применили особое умение!");
				std::println("Умение будет действовать {} раундов", SKILL_DURATION);
			}
			else {
				std::println("Ваше умение на перезарядке! Применена обычная атака.");
				std::println("Вы нанесли {:.1f} урона.", bot->take_damage(bot->calculate_damage(user->damage())));

				if ((bot->health() - 0.0f) < 1.0e-10f) {
					std::println("ПРОТИВНИК ПОВЕРЖЕН! ПОБЕДА!");
					game_over = true;
					break;
				}

				std::println("У противника осталось {:.1f} здоровья.", bot->health());
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
			std::println("Противник нанес {:.1f} урона.", user->take_damage(user->calculate_damage(bot->damage())));

			if ((user->health() - 0.0f) < 1.0e-10f) {
				std::println("ПРОТИВНИК ПОБЕДИЛ! ВЫ ПРОИГРАЛИ!");
				game_over = true;
				break;
			}

			std::println("У Вас осталось {:.1f} здоровья.", user->health());
			break;
		}
		case(2): {
			if (bot->is_skill_active() == false && bot->cooldown() == 0) {
				bot->use_special_skill();
				std::println("Противник применил особое умение!");
			}
			else {
				std::println("Противник нанес {:.1f} урона.", user->take_damage(user->calculate_damage(bot->damage())));

				if ((user->health() - 0.0f) < 1.0e-10f) {
					std::println("ПРОТИВНИК ПОБЕДИЛ! ВЫ ПРОИГРАЛИ!");
					game_over = true;
					break;
				}

				std::println("У Вас осталось {:.1f} здоровья.", user->health());
			}
			break;
		}
		default: {
			std::println("Ошибка! Выбран несуществующий пукнт меню!");
		}
		}

		if (game_over) {
			break;
		}

		std::println();
		std::println("{}", user->to_string());
		std::println();
		std::println("{}", bot->to_string());
		std::println();

		current_round += 1;
	}
	return 0;
}