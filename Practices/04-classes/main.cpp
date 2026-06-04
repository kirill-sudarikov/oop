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
      _numerator *= -1;
      _denominator *= -1;
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
};

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

  std::println("Сумма дробей: {}", frac_to_str(frac_sum(frac1, frac2)));
  std::println("Разность дробей (первая - вторая): {}",
               frac_to_str(frac_sub(frac1, frac2)));
  std::println("Разность дробей (вторая - первая): {}",
               frac_to_str(frac_sub(frac2, frac1)));
  std::println("Произведение дробей: {}", frac_to_str(frac_mul(frac1, frac2)));

  return 0;
}
