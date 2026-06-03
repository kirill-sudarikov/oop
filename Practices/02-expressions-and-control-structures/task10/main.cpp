import std;

int main() {
	std::print("Введите число a: ");
	
	double a = 0.0;
	std::cin >> a;
	
	std::print("Введите целое число n: ");
	
	int n = 0;
	std::cin >> n;
	
	std::println("Все целые степени числа a от 1 до n:");
	
	double res = 1.0;
	
	for(int i = 1; i <= n; ++i) {
		res *= a;
		
		std::print("{} ", res);
	}
	
	return 0;
}