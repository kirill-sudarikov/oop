import std;

import vector_utils;
import vector_analysis;

int main() {

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
  int element_count = 0;
  std::cin >> element_count;

  while (element_count <= 0) {
    std::print("Ошибка! Количество элементов должно быть > 0: ");
    std::cin >> element_count;
  }

  std::print("Выберите способ заполнения (1 - вручную, 2 - случайно): ");
  int choice = 0;
  std::cin >> choice;

  while (choice > 2 || choice < 1) {
    std::print("Ошибка! Выбран несуществующий способ заполнения: ");
    std::cin >> choice;
  }

  auto subsequence = create_vector(element_count, choice);

  std::print("Введите целое число: ");
  int num = 0;
  std::cin >> num;

  std::size_t rez = count_less_than(subsequence, num);

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