import std;

import IEnumerator;
import IEnumerable;
import ICollection;

import List;
import HashSet;
import Dictionary;
import Stack;
import Queue;

void list_test() {
  std::println("=======================");
  std::print("-----------------------\n"
             "Тест контейнера List<T>\n"
             "-----------------------\n");

  List<int> list;

  list.Add(1);
  list.Add(2);
  list.Add(3);
  list.Add(4);
  list.Add(5);

  std::println("Добавлено элементов: {}", list.Count());

  auto it = list.GetEnumerator();

  std::print("Элементы: ");
  while (it->MoveNext()) {
    std::print("{} ", it->Current());
  }

  std::print("\n");

  std::println("0-ой элемент до применения .Insert(0, 6): {}", list[0]);

  list.Insert(0, 6);

  std::println("0-ой элемент после применения .Insert(0, 6): {}", list[0]);

  std::println("3-ий элемент до применения .RemoveAt(3): {}", list[3]);

  list.RemoveAt(3);

  std::println("3-ий элемент после применения .RemoveAt(3): {}", list[3]);

  std::println("Размер: {}", list.Count());
  std::println("Ёмкость: {}", list.Capacity());

  list.SetCapacity(25);

  std::println("Ёмкость после применения .SetCapacity(25): {}",
               list.Capacity());

  if (list.Contains(5)) {
    std::println("Проверка .Contains(5) прошла успешно");
  }

  std::println("1-ый элемент до применения list[1] = 7: {}", list[1]);

  list[1] = 7;

  std::println("1-ый элемент после применения list[1] = 7: {}", list[1]);

  if (list.Remove(6)) {
    std::println("Удалён элемент 6");
  }

  std::println("Размер после удаления: {}", list.Count());

  it = list.GetEnumerator();

  std::print("Элементы: ");
  while (it->MoveNext()) {
    std::print("{} ", it->Current());
  }

  list.Clear();

  std::print("\n");

  std::println("Размер после очистики: {}", list.Count());
  std::println("=======================");
}

void hashset_test() {
  std::println("==========================");
  std::print("--------------------------\n"
             "Тест контейнера HashSet<T>\n"
             "--------------------------\n");

  HashSet<std::string> names;

  names.Add("Иван");
  names.Add("Пётр");
  names.Add("Маша");
  names.Add("Андрей");
  names.Add("Миша");

  std::println("Добавлено элементов: {}", names.Count());

  auto it = names.GetEnumerator();

  std::print("Элементы: ");

  while (it->MoveNext()) {
    std::print("{} ", it->Current());
  }

  std::print("\n");

  std::println("Ёмкость: {}", names.Capacity());

  if (names.Contains("Иван")) {
    std::println("Проверка .Contains(\"Иван\") прошла успешно");
  }

  if (names.Remove("Пётр")) {
    std::println("Элемент Пётр удалён");
  }

  std::println("Размер после удаления: {}", names.Count());

  names.SetCapacity(25);

  std::println("Ёмкость после применения .SetCapacity(25): {}",
               names.Capacity());

  it = names.GetEnumerator();

  std::print("Элементы: ");

  while (it->MoveNext()) {
    std::print("{} ", it->Current());
  }

  std::print("\n");

  names.Clear();

  std::println("Размер после очистики: {}", names.Count());
  std::println("==========================");
}

void dictionary_test() {
  std::println("========================================");
  std::print("----------------------------------------\n"
             "Тест контейнера Dictionary<TKey, TValue>\n"
             "----------------------------------------\n");

  Dictionary<std::string, int> d;

  d.Add({"key1", 1});
  d.Add({"key2", 2});
  d.Add({"key3", 3});
  d.Add({"key4", 4});
  d.Add({"key5", 5});

  std::println("Добавлено элементов: {}", d.Count());

  auto it = d.GetEnumerator();

  std::print("Элементы: ");

  while (it->MoveNext()) {
    std::print("(\"{}\", {}), ", it->Current().Key(), it->Current().Value());
  }

  std::print("\n");

  std::println("0-ой элемент до применения d[\"key1\"] = 10: (\"key1\", {})",
               d["key1"]);

  d["key1"] = 10;

  std::println("0-ой элемент после применения d[\"key1\"] = 10: (\"key1\", {})",
               d["key1"]);

  if (d.Contains({"key1", 10})) {
    std::println("Содержит элемент (\"key1\", {})", d["key1"]);
  }

  if (d.Remove({"key2", 2})) {
    std::println("Удалён элемент (\"key2\", 2)");
  }

  std::println("Размер после удаления: {}", d.Count());

  std::println("Ёмскость до применения .SetCapacity(25): {}", d.Capacity());

  d.SetCapacity(25);

  std::println("Ёмскость после применения .SetCapacity(25): {}", d.Capacity());

  it = d.GetEnumerator();

  std::print("Элементы: ");

  while (it->MoveNext()) {
    std::print("(\"{}\", {}), ", it->Current().Key(), it->Current().Value());
  }

  std::print("\n");

  d.Clear();

  std::println("Размер после очистки: {}", d.Count());
  std::println("========================================");
}

void stack_test() {
  std::println("========================");
  std::print("------------------------\n"
             "Тест контейнера Stack<T>\n"
             "------------------------\n");

  Stack<int> stack;

  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Push(4);
  stack.Push(5);

  std::println("Добавлено элементов: {}", stack.Count());

  auto it = stack.GetEnumerator();

  std::print("Элементы: ");

  while (it->MoveNext()) {
    std::print("{} ", it->Current());
  }

  std::print("\n");

  std::println("Вершина: {}", stack.Peek());

  std::println("Удалённый элемент: {}", stack.Pop());

  std::println("Новая вершина после применения Pop(): {}", stack.Peek());

  std::println("Размер после удаления: {}", stack.Count());
  std::println("========================");
}

void queue_test() {
  std::println("========================");
  std::print("------------------------\n"
             "Тест контейнера Queue<T>\n"
             "------------------------\n");

  Queue<int> queue;

  queue.Enqueue(1);
  queue.Enqueue(2);
  queue.Enqueue(3);
  queue.Enqueue(4);
  queue.Enqueue(5);

  std::println("Добавлено элементов: {}", queue.Count());

  auto it = queue.GetEnumerator();

  std::print("Элементы: ");

  while (it->MoveNext()) {
    std::print("{} ", it->Current());
  }

  std::print("\n");

  std::println("Вершина: {}", queue.Peek());

  std::println("Удалённый элемент: {}", queue.Dequeue());

  std::println("Новая вершина после применения Pop(): {}", queue.Peek());

  std::println("Размер после удаления: {}", queue.Count());
  std::println("========================");
}

int main() {
  list_test();
  std::print("\n");

  hashset_test();
  std::print("\n");

  dictionary_test();
  std::print("\n");

  stack_test();
  std::print("\n");

  queue_test();
  std::print("\n");

  return 0;
}