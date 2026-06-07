export module IEnumerable;

import IEnumerator;

export template <typename T>
class IEnumerable {
public:
  virtual IEnumerator<T> GetEnumerator() = 0;
  virtual ~IEnumerable() = 0;
};