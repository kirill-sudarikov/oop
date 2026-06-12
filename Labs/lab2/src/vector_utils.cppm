export module vector_utils;

import std;

std::vector<int> input_vector(std::size_t size) {
  int n = 0;
  std::vector<int> v;
  for (int i = 0; i < size; ++i) {
    std::cin >> n;
    v.push_back(n);
  }
  return v;
}

std::vector<int> random_vector(std::size_t size) {
  std::vector<int> v;

  std::mt19937 prng;
  std::uniform_int_distribution d(1, 100);

  for (int i = 0; i < size; ++i) {
    v.push_back(d(prng));
  }

  return v;
}

export std::vector<int> create_vector(std::size_t size, std::size_t mode) {
  std::vector<int> v;
  switch (mode) {
  case (1):
    return input_vector(size);
    break;
  case (2):
    return random_vector(size);
    break;
  default:
    return v;
  }
}

export void print_vector(const std::vector<int>& v) {
  if (v.size() == 0) {
    return;
  } else {
    for (int i = 0; i < v.size(); ++i) {
      std::print("{} ", v[i]);
    }
    std::println("");
  }
}