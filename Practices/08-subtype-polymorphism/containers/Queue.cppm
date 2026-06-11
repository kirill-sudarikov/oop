export module Queue;

import std;
import IEnumerator;
import IEnumerable;

export template <typename T>
class QueueEnumerator : public IEnumerator<T> {
private:
  typename std::deque<T>::const_iterator _iter;
  typename std::deque<T>::const_iterator _end;
  bool _is_started = false;

public:
  QueueEnumerator(const std::deque<T>& queue)
      : _iter(queue.begin()), _end(queue.end()) {}

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
          "Ошибка в QueueEnumerator Current(): очередь пуста");
    }

    return *_iter;
  }
};

export template <typename T>
class Queue : public IEnumerable<T> {
private:
  std::deque<T> _queue;

public:
  Queue() = default;

  std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
    return std::make_unique<QueueEnumerator<T>>(_queue);
  }

  std::size_t Count() const { return _queue.size(); }

  const T& Peek() const {
    if (_queue.empty()) {
      throw std::out_of_range("Ошибка в Queue Peek(): очередь пуста");
    }

    return _queue.front();
  }

  void Enqueue(T item) { _queue.push_back(std::move(item)); }

  T Dequeue() {
    T peek = Peek();
    _queue.pop_front();
    return peek;
  }
};