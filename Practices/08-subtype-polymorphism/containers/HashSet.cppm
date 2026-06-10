export module HashSet;

import std;
import IEnumerator;
import IEnumerable;
import ICollection;

export template <typename T, typename Hash, typename KeyEqual>
class HashSetEnumerator : public IEnumerator<T> {
private:
  typename std::unordered_set<T, Hash, KeyEqual>::const_iterator _iter;
  typename std::unordered_set<T, Hash, KeyEqual>::const_iterator _end;
  bool _is_started = false;

public:
  HashSetEnumerator(const std::unordered_set<T, Hash, KeyEqual>& set)
      : _iter(set.begin()), _end(set.end()) {}

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
          "Ошибка в HashSetEnumerator Current(): неверный итератор");
    }

    return *_iter;
  }
};

export template <typename T, typename Hash = std::hash<T>,
                 typename KeyEqual = std::equal_to<T>>
class HashSet : public ICollection<T> {
private:
  std::unordered_set<T, Hash, KeyEqual> _set;

public:
  HashSet() = default;

  std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
    return std::make_unique<HashSetEnumerator<T, Hash, KeyEqual>>(_set);
  }

  std::size_t Count() const override { return _set.size(); }

  void Add(const T& item) override { _set.insert(item); }

  void Clear() override { _set.clear(); }

  bool Contains(const T& item) const override { return _set.contains(item); }

  bool Remove(const T& item) override { return _set.erase(item) > 0; }

  std::size_t Capacity() const { return _set.bucket_count(); }

  void SetCapacity(std::size_t capacity) { _set.reserve(capacity); }
};