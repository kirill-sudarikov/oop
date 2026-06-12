export module upload_file;

import std;

std::string str_normalize(const std::string& s) {
  if (s.empty()) {
    return "";
  }

  std::string res(s);

  for (char& ch : res) {
    ch = std::tolower(static_cast<unsigned char>(ch));
  }

  while (!res.empty() &&
         !std::isalpha(static_cast<unsigned char>(res.front()))) {
    res.erase(0, 1);
  }

  while (!res.empty() &&
         !std::isalpha(static_cast<unsigned char>(res.back()))) {
    res.pop_back();
  }

  if (res.empty()) {
    return "";
  }

  bool prev_is_hyphen = false;

  for (char ch : res) {
    if (!std::isalpha(static_cast<unsigned char>(ch)) && ch != '-') {
      return "";
    }

    if (ch == '-') {
      if (prev_is_hyphen) {
        return "";
      }
      prev_is_hyphen = true;
    } else {
      prev_is_hyphen = false;
    }

    if (res.front() == '-' || res.back() == '-') {
      return "";
    }
  }

  return res;
}

export std::vector<std::string> upload_file(const std::string& path) {
  std::vector<std::string> words;
  std::ifstream stream(path);

  if (!stream.is_open()) {
    throw std::runtime_error("file not found \"" + path + "\"");
  }

  std::string current;

  while (stream >> current) {
    std::string normalized = str_normalize(current);
    if (!normalized.empty()) {
      words.push_back(std::move(normalized));
    }
  }

  stream.close();

  return words;
}