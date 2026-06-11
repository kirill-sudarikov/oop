export module Stack;

import std;
import IEnumerator;
import IEnumerable;

export template <typename T>
class QueueEnumerator : public IEnumerator<T> {
private:
  std::queue<T> _queue;
  bool _is_started = false;

public:
  explicit QueueEnumerator(std::queue<T> queue) : _queue(std::move(queue)) {}

  /*
  bool MoveNext() override {
    if (_is_started && !_queue.empty()) {
      _is_started = false;
      return true;
    }

    if (_queue.size() > 1) {
      _queue.pop();
      return true;
    }
    return false;
  }
  */

  const T& Current() const override {
    if (_queue.empty()) {
      throw std::out_of_range("Ошибка в Enumerator Current(): очередь пуста");
    }

    return _queue.front();
  }
};

export template <typename T>
class Queue : public IEnumerable<T> {
private:
  std::queue<T> _queue;

public:
  Stack() = default;

  std::size_t Count() const { return _queue.size(); }

  T Dequeue() {
    T peek = Peek();
    _queue.pop();
    return peek;
  }

  const T& Peek() const {
    if (_stack.empty()) {
      throw std::out_of_range("Ошибка в Queue Peek(): очередь пуста");
    }

    return _queue.front();
  }

  void Enqueue(T item) { _queue.push(item); }
}