export module Dictionary;

import std;
import IEnumerator;
import IEnumerable;
import ICollection;

export template <typename TKey, typename TValue>
class KeyValuePair {
private:
  TKey _key;
  TValue _value;

public:
  KeyValuePair(const TKey& key, const TValue& value)
      : _key(key), _value(value) {}

  const TKey& Key() const { return _key; }

  const TValue& Value() const { return _value; }
};

export template <typename TKey, typename TValue,
                 typename THash = std::hash<TKey>,
                 typename TKeyEqual = std::equal_to<TKey>>
class DictionaryEnumerator : public IEnumerator<KeyValuePair<TKey, TValue>> {
private:
  typename std::unordered_map<TKey, TValue, THash, TKeyEqual>::const_iterator
      _iter;
  typename std::unordered_map<TKey, TValue, THash, TKeyEqual>::const_iterator
      _end;
  bool _is_started = false;

  mutable KeyValuePair<TKey, TValue> _current;

public:
  DictionaryEnumerator(
      const std::unordered_map<TKey, TValue, THash, TKeyEqual>& dict)
      : _iter(dict.begin()), _end(dict.end()) {}

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

  const KeyValuePair<TKey, TValue>& Current() const override {
    if (!_is_started || _iter == _end) {
      throw std::logic_error(
          "Ошибка в DictionaryEnumerator Current(): неверный итератор");
    }

    _current = KeyValuePair<TKey, TValue>(_iter->first, _iter->second);
    return _current;
  }
};

export template <typename TKey, typename TValue,
                 typename THash = std::hash<TKey>,
                 typename TKeyEqual = std::equal_to<TKey>>
class Dictionary : public ICollection<KeyValuePair<TKey, TValue>> {
private:
  std::unordered_map<TKey, TValue, THash, TKeyEqual> _dict;

public:
  Dictionary() = default;

  std::unique_ptr<IEnumerator<KeyValuePair<TKey, TValue>>>
  GetEnumerator() const override {
    return std::make_unique<
        DictionaryEnumerator<TKey, TValue, THash, TKeyEqual>>(_dict);
  }

  std::size_t Count() const override { return _dict.size(); }

  void Add(const KeyValuePair<TKey, TValue>& item) override {
    auto added_item = _dict.insert({item.Key(), item.Value()});

    if (!added_item.second) {
      throw std::invalid_argument("Ошибка в Dictionary Add(): ключ " +
                                  std::string(item.Key()) + " уже существует");
    }
  }

  void Clear() override { _dict.clear(); }

  bool Contains(const KeyValuePair<TKey, TValue>& item) const override {
    auto it = _dict.find(item.Key());
    return it != _dict.end() && it->second == item.Value();
  }

  bool Remove(const KeyValuePair<TKey, TValue>& item) override {
    if (!Contains(item)) {
      throw std::out_of_range("Ошибка в Dictionary Remove(): ключ " +
                              std::string(item.Key()) + " не существует");
    }

    return _dict.erase(item.Key()) > 0;
  }

  std::size_t Capacity() const { return _dict.bucket_count(); }

  void SetCapacity(std::size_t capacity) { _dict.reserve(capacity); }

  TValue& operator[](const TKey& key) { return _dict[key]; }

  const TValue& operator[](const TKey& key) const { return _dict.at(key); }
};
