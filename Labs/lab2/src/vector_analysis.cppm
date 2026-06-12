export module vector_analysis;

import std;

export std::size_t count_less_than(const std::vector<int>& v, int n) {
  if (v.size() == 0) {
    return -1;
  }

  int result_count = 0;

  for (int i = 0; i < v.size(); ++i) {
    if (v[i] < n) {
      result_count++;
    }
  }

  return result_count;
}