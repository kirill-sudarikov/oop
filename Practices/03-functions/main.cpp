import std;

std::size_t invert_digits(std::size_t n) {
  if (n == 0)
    return 0;

  std::size_t inverted = 0;

  for (std::size_t i = n; i > 0; i /= 10) {
    inverted = inverted * 10 + (i % 10);
  }

  return inverted;
}

std::size_t add_right_digit(std::size_t n, std::size_t d) {
  if (n == 0)
    return d;

  return n * 10 + d;
}

bool is_prime(std::size_t n) {
  if (n == 0)
    return false;

  for (std::size_t i = 2; i < n / 2; ++i) {
    if (n % i == 0)
      return false;
  }

  return true;
}

std::size_t fact(std::size_t n) {
  if (n == 0)
    return 1;
  else
    return n * fact(n - 1);
}

std::size_t gcd(std::size_t a, std::size_t b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

std::size_t digit_sum(std::size_t n) {
  if (n / 10 == 0)
    return n;
  else
    return n % 10 + digit_sum(n / 10);
}

int main() {
  std::println("invert_digit(103) test: {}", invert_digits(103));

  std::println("add_right_digit(123, 4) test {}", add_right_digit(123, 4));

  std::println("is_prime(127), is_prime(156) test: {}, {}", is_prime(127),
               is_prime(156));

  std::println("fact(4) test: {}", fact(4));

  std::println("gcd(14, 42) test: {}", gcd(14, 42));

  std::println("digit_sum(123) test: {}", digit_sum(123));

  return 0;
}