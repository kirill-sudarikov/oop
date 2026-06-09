export module CyclicCounter;

import std;
import ICounter;

export class CyclicCounter : public ICounter {
private:
  int _current = 0;
  int _max = 0;

public:
  CyclicCounter(int max_value) : _current(0), _max(max_value) {}

  void increment() override {
    if (_current == _max) {
      _current = 0;
    } else {
      ++_current;
    }
  }

  void reset() override { _current = 0; }

  int getValue() const override { return _current; }

  int getMaxValue() const { return _max; };

  bool isLimitReached() const override { return _current == _max; }

  std::string getType() const override {
    return std::format(
        "Тип: CyclicCounter (циклический счётчик)\n"
        "Описание: значение увеличивается от 0 до максимального значения,\n"
        "после чего сбрасывается в 0 и продолжает рост.\n"
        "Параметры: max_value\n");
  }
};