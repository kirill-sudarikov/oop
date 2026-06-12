#pragma once

import std;
import task;

int main() {
	int element_count = 0;
	int choice = 0;
	int num = 0;
	int rez = 0;

	std::println("-------------------------");
	std::println("   ЛР №: 2");
	std::println(" Группа: 6112");
	std::println("  Автор: Судариков Кирилл");
	std::println("Вариант: 26");
	std::println("-------------------------");

	std::println("-----------");
	std::println("Ввод данных");
	std::println("-----------");

	std::print("Введите количество элементов: ");
	std::cin >> element_count;

	while (element_count <= 0) {
		std::print("Ошибка! Количество элементов должно быть > 0: ");
		std::cin >> element_count;
	}

	std::print("Выберите способ заполнения (1 - вручную, 2 - случайно): ");
	std::cin >> choice;

	while (choice > 2 || choice < 1) {
		std::print("Ошибка! Выбран несуществующий способ заполнения: ");
		std::cin >> choice;
	}

	std::vector<int> subsequence = create_vector(static_cast<size_t>(element_count), static_cast<size_t>(choice));

	std::print("Введите целое число: ");
	std::cin >> num;

	rez = task(subsequence, num);

	
	std::println("-----");
	std::println("Ответ");
	std::println("-----");

	std::print("Элементы: ");
	print_vector(subsequence);
	std::println("Количество элементов: {}", element_count);
	std::println("Число: {}", num);
	std::println("Количество элементов, меньших заданного числа: {}", rez);

	return 0;
}