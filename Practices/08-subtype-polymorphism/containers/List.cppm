export module List;

import std;
import IEnumerator;
import IEnumerable;
import ICollection;

export template <typename T>
class ListEnumerator : public IEnumerator<T> {
private:
  typename std::vector<T>::const_iterator _iter;
  typename std::vector<T>::const_iterator _end;
  bool _is_started = false;

public:
  ListEnumerator(const std::vector<T>& list)
      : _iter(list.begin()), _end(list.end()) {}

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
          "Ошибка в ListEnumerator Current(): неверный итератор");
    }

    return *_iter;
  }
};

export template <typename T>
class List : public ICollection<T> {
private:
  std::vector<T> _list;

public:
  List() = default;

  std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
    return std::make_unique<ListEnumerator<T>>(_list);
  }

  std::size_t Count() const override { return _list.size(); }

  void Add(const T& item) override { _list.push_back(item); }

  void Clear() override { _list.clear(); }

  bool Contains(const T& item) const override {
    return std::find(_list.begin(), _list.end(), item) != _list.end();
  }

  bool Remove(const T& item) override {
    auto it = std::find(_list.begin(), _list.end(), item);

    if (it == _list.end()) {
      return false;
    }

    _list.erase(it);
    return true;
  }

  std::size_t Capacity() const { return _list.capacity(); }

  void SetCapacity(std::size_t capacity) { _list.reserve(capacity); }

  const T& operator[](std::size_t index) const {
    if (index >= _list.size()) {
      throw std::out_of_range("Ошибка в List operator[]: неверный индекс");
    }

    return _list[index];
  }

  T& operator[](std::size_t index) {
    if (index >= _list.size()) {
      throw std::out_of_range("Ошибка в List operator[]: неверный индекс");
    }

    return _list[index];
  }
};