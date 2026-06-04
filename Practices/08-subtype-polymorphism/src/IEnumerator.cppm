export module IEnumerator;

export template <typename T>
class IEnumerator {
public:
  virtual bool MoveNext() = 0;
  virtual T Current() = 0;
};