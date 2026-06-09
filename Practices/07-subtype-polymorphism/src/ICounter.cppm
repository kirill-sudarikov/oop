export module ICounter;

import std;

export class ICounter {
public:
  virtual void increment() = 0;
  virtual void reset() = 0;
  virtual int getValue() const = 0;
  virtual bool isLimitReached() const = 0;
  virtual std::string getType() const = 0;
  virtual ~ICounter() = default;
};