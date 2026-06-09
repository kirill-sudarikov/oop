export module BoundedCounter;

import std;
import ICounter;

export class BoundedCounter : public ICounter {
private:
  int _current = 0;
  int _max = 0;

public:
  BoundedCounter(int max_value) : _current(0), _max(max_value) {}

  void increment() override {
    if (_current < _max) {
      ++_current;
    }
  }

  void reset() override { _current = 0; }

  int getValue() const override { return _current; }

  int getMaxValue() const { return _max; };

  bool isLimitReached() const override { return _current == _max; }

  std::string getType() const override {
    return std::format(
        "Тип: BoundedCounter (счётчик с остановкой)\n"
        "Описание: значение увеличивается от 0 до максимального значения\n"
        "Параметры: max_value\n");
  }
};