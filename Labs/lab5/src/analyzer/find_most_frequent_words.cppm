export module find_most_frequent_words;

import std;

export struct MostFrequentWords {
  int _count = 0;
  std::set<std::string> _words;

  MostFrequentWords(int count, std::set<std::string> words)
      : _count(count), _words(words) {}
};

export MostFrequentWords
find_most_frequent_words(const std::vector<std::string>& words,
                         const std::unordered_set<std::string>& stopwords) {
  std::unordered_map<std::string, int> frequency;

  for (const std::string& word : words) {
    if (stopwords.find(word) == stopwords.end()) {
      ++frequency[word];
    }
  }

  int count = 0;
  std::set<std::string> most_frequent;

  for (const auto& pair : frequency) {
    if (pair.second > count) {
      count = pair.second;
    }
  }

  for (const auto& pair : frequency) {
    if (pair.second == count) {
      most_frequent.insert(pair.first);
    }
  }

  return MostFrequentWords(count, most_frequent);
}