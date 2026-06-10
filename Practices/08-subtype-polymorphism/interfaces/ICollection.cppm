export module ICollection;

import std;
import IEnumerable;

export template <typename T>
class ICollection : public IEnumerable<T> {
public:
  virtual std::size_t Count() const = 0;
  virtual void Add(const T& item) = 0;
  virtual void Clear() = 0;
  virtual bool Contains(const T& item) const = 0;
  virtual bool Remove(const T& item) = 0;
  virtual ~ICollection() = default;
};