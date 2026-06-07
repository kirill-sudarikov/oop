import std;
import ICollection;

export module List;

export template <typename T>
class List : public ICollection<T> {
private:
  std::vector<T> _list;

public:
  int Count() const override { return _list.size(); }

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
};