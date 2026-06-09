import std;

class String {
private:
  char *_buffer = nullptr;
  std::size_t _length = 0;

  void str_copy(const char *str) {
    _length = std::strlen(str);
    _buffer = new char[_length + 1];
    std::strcpy(_buffer, str);
  }

public:
  String() = default;

  String(const char *str) { str_copy(str); }

  String(const String& other) { str_copy(other._buffer); }

  String(String&& other) : _buffer(other._buffer), _length(other._length) {
    other._buffer = nullptr;
    other._length = 0;

    /* крадём указатель у other до его удаления и обязательно чистим
    его, чтобы не было висячего указателя после удаления other */
  }

  String& operator=(const String& other) {
    if (this != &other) {
      delete[] _buffer;
      str_copy(other._buffer);
    }

    return *this;
  }

  String& operator=(String&& other) {
    if (this != &other) {
      delete[] _buffer;

      _buffer = other._buffer;
      _length = other._length;

      other._buffer = nullptr;
      other._length = 0;
    }

    return *this;
  }

  ~String() {
    delete[] _buffer;
    _buffer = nullptr;
    _length = 0;
  }

  std::size_t length() const { return _length; }

  const char *c_str() const {
    if (!_buffer) {
      return "";
    }

    return _buffer;
  }

  char operator[](std::size_t index) { return _buffer[index]; }
};

namespace std {
template <>
struct formatter<String, char> {
  constexpr auto parse(format_parse_context& ctx) {
    auto it = ctx.begin();

    while (it != ctx.end() && *it != '}') {
      ++it; // парсим строку, игнорируя спецификаторы
    }

    return it;
  }

  auto format(const String& str, format_context& ctx) const {
    const char *data = str.c_str();

    return std::copy(data, data + str.length(), ctx.out());
  }
};
} // namespace std

class StringBuilder {
private:
  std::string _buffer;

public:
  StringBuilder() = default;

  void reserve(std::size_t bytes) { _buffer.reserve(bytes); }

  StringBuilder& append(const std::string& str) {
    _buffer.append(str);
    return *this;
  }

  StringBuilder& append(int num) {
    _buffer.append(std::to_string(num));
    return *this;
  }

  StringBuilder& append(float num) {
    _buffer.append(std::to_string(num));
    return *this;
  }

  std::string build() const& { return _buffer; }

  std::string build() && { return std::move(_buffer); }

  std::size_t size() const { return _buffer.size(); }

  std::size_t capacity() const { return _buffer.capacity(); }
};

int main() {
  String s1("Привет, мир!");
  String s2(s1);
  String s3(std::move(s2));
  String s4 = s3;
  String s5 = std::move(s2);

  std::println("s1: {}", s1);
  std::println("s2: {}", s2);
  std::println("s3: {}", s3);
  std::println("s4: {}", s4);
  std::println("s5: {}", s5);

  std::print("Введите ваш возраст: ");
  int age;
  std::cin >> age;

  StringBuilder sb;
  sb.append("Ваш возраст: ").append(age);
  std::string res = sb.build();

  std::println("{}", res);

  float pi = 3.141592f;
  std::string str = StringBuilder().append("Число пи: ").append(pi).build();

  std::println("{}", str);
}