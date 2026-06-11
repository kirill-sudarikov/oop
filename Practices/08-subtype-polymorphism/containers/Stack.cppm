export module Stack;

import std;
import IEnumerator;
import IEnumerable;

export template <typename T>
class StackEnumerator : public IEnumerator<T> {
private:
  typename std::vector<T>::const_iterator _iter;
  typename std::vector<T>::const_iterator _end;
  bool _is_started = false;

public:
  StackEnumerator(const std::vector<T>& stack)
      : _iter(stack.begin()), _end(stack.end()) {}

  bool MoveNext() override {
    if (!_is_started) {
      _is_started = true;
      return _iter != _end;
    }

    if (_iter != _end) {
      ++_iter;
    }

    return _iter != _end;
  }

  const T& Current() const override {
    if (!_is_started || _iter == _end) {
      throw std::logic_error(
          "Ошибка в StackEnumerator Current(): неверный итератор");
    }

    return *_iter;
  }
};

export template <typename T>
class Stack : public IEnumerable<T> {
private:
  std::vector<T> _stack;

public:
  Stack() = default;

  std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
    return std::make_unique<StackEnumerator<T>>(_stack);
  }

  std::size_t Count() const { return _stack.size(); }

  void Push(T item) { _stack.push_back(std::move(item)); }

  const T& Peek() const {
    if (_stack.empty()) {
      throw std::out_of_range("Ошибка в Stack Peek(): стeк пуст");
    }

    return _stack.back();
  }

  T Pop() {
    T peek = Peek();
    _stack.pop_back();
    return peek;
  }
};