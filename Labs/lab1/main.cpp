import std;

int main() {
	std::println("-------------------------");
	std::println("   ЛР №: 1");
	std::println(" Группа: 6112");
	std::println("  Автор: Судариков Кирилл");
	std::println("Вариант: 26");
	std::println("-------------------------");

	std::println("-----------");
	std::println("Ввод данных");
	std::println("-----------");

	std::print("Введите целое число: ");
	int num = 0;
	std::cin >> num;

	std::print("Введите количество элементов: ");
	int elem_count = 0;
	std::cin >> elem_count;

	while (elem_count <= 0) {
		std::print("Ошибка! Введено отрицательное значение! Попробуйте ввести ещё раз: ");
		std::cin >> elem_count;
	}

	std::print("Введите элементы: ");

	int rez_count = 0;
	int current = 0;

	for (int i = 0; i < elem_count; i++) {
		std::cin >> current;
		if (current < num) {
			rez_count++;
		}
	}

	std::println("-----");
	std::println("Ответ");
	std::println("-----");

	std::println("Количество элементов: {}", elem_count);
	std::println("Количество элементов, меньших заданного числа: {}", rez_count);

	return 0;
}