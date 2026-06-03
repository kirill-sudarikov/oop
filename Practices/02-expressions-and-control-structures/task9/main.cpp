import std;

int main() {
	std::print("Введите целое число a: ");
	
	int a = 0;
	std::cin >> a;
	
	std::print("Введите целое число b: ");
	
	int b = 0;
	std::cin >> b;
	
	int n = 0;
	
	std::println("Целые числа, расположенне в промежутке [a; b]:");
	
	for(int i = a; i <= b; ++i) {
		std::print("{} ", i);
		n += 1;
	}
	
	std::print("\n");
	
	std::println("Количество чисел: {}", n);
	
	return 0;
}