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

std::ostream& operator<<(std::ostream& os, const Fraction& obj) {
  os << obj.numerator() << '/' << obj.denominator();
  return os;
}

Fraction frac_sum(Fraction a, const Fraction& b) { return a + b; }

Fraction frac_sub(Fraction a, const Fraction& b) { return a - b; }

Fraction frac_mul(Fraction a, const Fraction& b) { return a * b; }

std::string frac_to_str(const Fraction& f) {
  std::stringstream ss;
  ss << f;
  return ss.str();
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

  std::cout << "Сумма дробей: " << frac_to_str(frac1 + frac2) << std::endl;
  std::cout << "Разность дробей (первая - вторая): "
            << frac_to_str(frac1 - frac2) << std::endl;
  std::cout << "Разность дробей (вторая - первая): "
            << frac_to_str(frac2 - frac1) << std::endl;
  std::cout << "Произведение дробей: " << frac_to_str(frac1 * frac2)
            << std::endl;

  std::print("\n");

  std::print("Сохранить результат в файл?\n"
             "Выберите действие (1 - да, 2 - нет): ");

  int choice = 0;
  std::cin >> choice;

  switch (choice) {
  case (1): {
    std::print("Введите путь к файлу: ");

    std::string filename;
    std::cin >> filename;

    std::fstream fs(filename, std::ios::out);

    if (!fs.is_open()) {
      std::println("не удалось открыть файл {}", filename);
    } else {
      fs << "Первая дробь: " << frac1 << "\n";
      fs << "Вторая дробь: " << frac2 << "\n";
      fs << "Сумма дробей: " << frac_to_str(frac1 + frac2) << std::endl;
      fs << "Разность дробей (первая - вторая): " << frac_to_str(frac1 - frac2)
         << std::endl;
      fs << "Разность дробей (вторая - первая): " << frac_to_str(frac2 - frac1)
         << std::endl;
      fs << "Произведение дробей: " << frac_to_str(frac1 * frac2) << std::endl;

      std::println("Результат успешно сохранён в файл {}", filename);
    }

    break;
  }
  case (2):
    std::println("До свидания!");
    break;
  default:
    std::println("Выбран несущетсвующий пукнт меню. Повторите попытку.");
    std::print("Сохранить результат в файл?\n"
               "Выберите действие (1 - да, 2 - нет): ");
    std::cin >> choice;
    break;
  }

  return 0;
}