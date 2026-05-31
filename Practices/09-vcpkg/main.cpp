#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

import std;

class PngImage {
  std::vector<std::uint8_t> _data;
  int _w = 0;
  int _h = 0;

public:
  PngImage(int w, int h) : _data(w * h), _w(w), _h(h) {}

  int w() const { return _w; }

  int h() const { return _h; }

  std::uint8_t operator[](int x, int y) const { return _data[y * _w + x]; }

  std::uint8_t &operator[](int x, int y) { return _data[y * _w + x]; }

  void save(const std::string &path) const {
    stbi_write_png(path.c_str(), _w, _h, 1, _data.data(), _w);
  }
};

bool is_in_mandelbrot(const std::complex<double> &c, int n) {
  std::complex<double> z = 0;

  for (int i = 0; i < n; ++i) {
    z = z * z + c;

    if (std::abs(z) > 2) {
      return false;
    }
  }

  return true;
}

int main() {
  constexpr int n = 800;
  constexpr int n_of_iter = 100;

  PngImage mandelbrot_set(n, n);
  {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {

        double a = 4.0 * x / (n - 1) - 2.0;
        double b = 2.0 - 4.0 * y / (n - 1);

        std::complex<double> c(a, b);

        if (is_in_mandelbrot(c, n_of_iter)) {
          mandelbrot_set[x, y] = 0;
        } else {
          mandelbrot_set[x, y] = 255;
        }
      }
    }

    mandelbrot_set.save("mandelbrot_set.png");
  }
}
