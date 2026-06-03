import std;

class Fraction {
private:
  int _numerator = 0;
  int _denominator = 0;

  void normalize() {
    if (_numerator == 0) {
      _denominator = 1;
    }

    int gcd = std::gcd(_numerator, _denominator);

    _numerator /= gcd;
    _denominator /= gcd;

    if (_denominator < 0) {
      _denominator = std::abs(_denominator);
    }

    if (_denominator == 0) {
      _denominator = 1;
    }
  }

public:
  Fraction(int num) : _numerator(num), _denominator(1) { normalize(); }

  Fraction(int numerator, int denominator)
      : _numerator(numerator), _denominator(denominator) {
    normalize();
  }

  int numerator() const { return _numerator; }

  int denominator() const { return _denominator; }

  Fraction& operator+=(const Fraction& rhs) {
    int new_num =
        _numerator * rhs.denominator() + rhs.numerator() * _denominator;
    int new_denom = _denominator * rhs.denominator();

    _numerator = new_num;
    _denominator = new_denom;

    normalize();

    return *this;
  }

  Fraction& operator-=(const Fraction& rhs) {
    int new_num =
        _numerator * rhs.denominator() - rhs.numerator() * _denominator;
    int new_denom = _denominator * rhs.denominator();

    _numerator = new_num;
    _denominator = new_denom;

    normalize();

    return *this;
  }

  Fraction& operator*=(const Fraction& rhs) {
    _numerator *= rhs.numerator();
    _denominator *= rhs.denominator();

    normalize();

    return *this;
  }

  Fraction& operator++() {
    _numerator += _denominator;
    return *this;
  }

  Fraction operator++(int) {
    Fraction copy(*this);
    _numerator += _denominator;
    return copy;
  }
};

Fraction operator+(Fraction lhs, const Fraction& rhs) { return lhs += rhs; }

Fraction operator-(Fraction lhs, const Fraction& rhs) { return lhs -= rhs; }

Fraction operator*(Fraction lhs, const Fraction& rhs) { return lhs *= rhs; }

Fraction frac_sum(const Fraction& a, const Fraction& b) {
  Fraction c(a.numerator() * b.denominator() + a.denominator() * b.numerator(),
             a.denominator() * b.denominator());
  return c;
}

Fraction frac_sub(const Fraction& a, const Fraction& b) {
  Fraction c(a.numerator() * b.denominator() - a.denominator() * b.numerator(),
             a.denominator() * b.denominator());
  return c;
}

Fraction frac_mul(const Fraction& a, const Fraction& b) {
  Fraction c(a.numerator() * b.numerator(), a.denominator() * b.denominator());
  return c;
}

std::string frac_to_str(const Fraction& f) {
  return std::format("{}/{}", f.numerator(), f.denominator());
}

int main() {
  std::print("Введите первую дробь (числитель знаменатель): ");

  int numerator1 = 0;
  int denominator1 = 0;

  std::cin >> numerator1 >> denominator1;

  std::print("Введите вторую дробь (числитель знаменатель): ");

  int numerator2 = 0;
  int denominator2 = 0;

  std::cin >> numerator2 >> denominator2;

  Fraction frac1(numerator1, denominator1);
  Fraction frac2(numerator2, denominator2);

  std::println("Сумма дробей: {}", frac_to_str(frac1 + frac2));
  std::println("Разность дробей (первая - вторая): {}",
               frac_to_str(frac1 - frac2));
  std::println("Разность дробей (вторая - первая): {}",
               frac_to_str(frac2 - frac1));
  std::println("Произведение дробей: {}", frac_to_str(frac1 * frac2));

  return 0;
}