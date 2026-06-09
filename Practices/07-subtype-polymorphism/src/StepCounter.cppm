export module StepCounter;

import std;
import ICounter;

export class StepCounter : public ICounter {
private:
  int _current = 0;
  int _max = 0;
  int _step = 0;

public:
  StepCounter(int max_value, int step)
      : _current(0), _max(max_value), _step(step) {}

  void increment() override {
    if (_max - _current >= _step) {
      _current += _step;
    }
  }

  void reset() override { _current = 0; }

  int getValue() const override { return _current; }

  int getMaxValue() const { return _max; }

  int getStep() const { return _step; }

  bool isLimitReached() const override { return _max - _current < _step; }

  std::string getType() const override {
    return std::format("Тип: StepCounter (счётчик с шагом)\n"
                       "Описание: аналог BoundedCounter, но с возможностью "
                       "задать размер шага.\n"
                       "Параметры: max_value, step\n");
  }
};