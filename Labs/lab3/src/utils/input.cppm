export module input;
import std;

export int input_num(const char* s, int b1, int b2) {
	int n = 0;

	while (true) {
		std::cin >> n;

		if (n >= b1 && n <= b2) {
			return n;
		}
		std::println("Ошибка!");
		std::print("{}", s);
	}
}

export float input_num(const char* s, float b1, float b2) {
	float n = 0;

	while (true) {
		std::cin >> n;

		if (n >= b1 && n <= b2) {
			return n;
		}
		std::println("Ошибка!");
		std::print("{}", s);
	}
}