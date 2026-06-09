import std;

import ICounter;
import BoundedCounter;
import CyclicCounter;
import StepCounter;

int main() {

  while (true) {

    std::print("---------------\n"
               "Тесты счётчиков\n"
               "---------------\n\n");

    std::print("[1] BoundedCounter\n"
               "[2] CyclicCounter\n"
               "[3] StepCounter\n"
               "[0] Выход\n\n");

    std::print("Выберите пункт меню: ");
    int choice = 0;
    std::cin >> choice;

    switch (choice) {
    case 1: {
      std::println("----------------------------");
      std::println("Тест счётчика BoundedCounter");
      std::println("----------------------------");

      BoundedCounter bc(10);

      std::print("{}", bc.getType());

      std::println("Начальное значение: {}", bc.getValue());
      std::println("Максимальное значение: {}", bc.getMaxValue());

      std::print("Значения: {} ", bc.getValue());
      while (!bc.isLimitReached()) {
        bc.increment();
        std::print("{} ", bc.getValue());
      }

      std::print("\n");
      std::println("Достигнут лимит!");

      bc.reset();
      if (bc.getValue() == 0) {
        std::println("Счётчик сброшен!");
      } else {
        std::println("Не удалось сбросить счётчик!");
      }
      break;
    }
    case 2: {
      std::println("---------------------------");
      std::println("Тест счётчика CyclicCounter");
      std::println("---------------------------");

      CyclicCounter cc(10);

      std::print("{}", cc.getType());

      std::println("Начальное значение: {}", cc.getValue());
      std::println("Максимальное значение: {}", cc.getMaxValue());

      std::print("Значения: {} ", cc.getValue());
      while (!cc.isLimitReached()) {
        cc.increment();
        std::print("{} ", cc.getValue());
      }

      std::print("\n");
      std::println("На следующем шаге счётчик будет автоматически сброшен!");

      cc.increment();
      if (cc.getValue() == 0) {
        std::println("Счётчик сброшен!");
      } else {
        std::println("Не удалось сбросить счётчик!");
      }
      break;
    }
    case 3: {
      std::println("-------------------------");
      std::println("Тест счётчика StepCounter");
      std::println("-------------------------");

      StepCounter sc(10, 3);

      std::print("{}", sc.getType());

      std::println("Начальное значение: {}", sc.getValue());
      std::println("Максимальное значение: {}", sc.getMaxValue());
      std::println("Шаг: {}", sc.getStep());

      std::print("Значения: {} ", sc.getValue());
      while (!sc.isLimitReached()) {
        sc.increment();
        std::print("{} ", sc.getValue());
      }

      std::print("\n");
      std::println("Достигнут лимит!");

      sc.reset();
      if (sc.getValue() == 0) {
        std::println("Счётчик сброшен!");
      } else {
        std::println("Не удалось сбросить счётчик!");
      }
      break;
    }
    case 0:
      std::println("Выход из программы...");
      return 0;
    default:
      std::println("Выбран неверный пункт меню! Попробуйте снова.");
      break;
    }
  }
  return 0;
}