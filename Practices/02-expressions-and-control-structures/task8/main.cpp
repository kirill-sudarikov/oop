import std;

int main() {
	std::println("Введите целое число [100; 999]: ");
	
	int num = 0;
	std::cin >> num;
	
	int digits = num % 10;
	int tens = (num % 100) / 10;
	int hundreds = num / 100;
	
	switch(hundreds) {
	case(1):
		std::print("Сто");
		break;
	case(2):
		std::print("Двести");
		break;
	case(3):
		std::print("Триста");
		break;
	case(4):
		std::print("Четыреста");
		break;
	case(5):
		std::print("Пятьсот");
		break;
	case(6):
		std::print("Шестьсот");
		break;
	case(7):
		std::print("Семьсот");
		break;
	case(8):
		std::print("Восемьсот");
		break;
	case(9):
		std::print("Девятьсот");
		break;
	}
	
	if(tens != 0) {
		std::print(" ");
		
		switch(tens) {
		case(1): {
			switch(digits) {
			case(0):
				std::print("десять");
				break;
			case(1):
				std::print("одиннадцать");
				break;
			case(2):
				std::print("двенадцать");
				break;
			case(3):
				std::print("тринадцать");
				break;
			case(4):
				std::print("четырнадцать");
				break;
			case(5):
				std::print("пятнадцать");
				break;
			case(6):
				std::print("шестнадцать");
				break;
			case(7):
				std::print("семнадцать");
				break;
			case(8):
				std::print("восемнадцать");
				break;
			case(9):
				std::print("девятнадцать");
				break;
			}
			break;
		}
		case(2):
			std::print("двадцать");
			break;
		case(3):
			std::print("тридцать");
			break;
		case(4):
			std::print("сорок");
			break;
		case(5):
			std::print("пятьдесят");
			break;
		case(6):
			std::print("шестьдесят");
			break;
		case(7):
			std::print("семьдесят");
			break;
		case(8):
			std::print("восемьдесят");
			break;
		case(9):
			std::print("девяносто");
			break;
		}
	}
	
	
	
	
	
	if(tens != 1 && digits != 0) {
		std::print(" ");
	
		switch(digits) {
		case(1):
			std::print("один");
			break;
		case(2):
			std::print("два");
			break;
		case(3):
			std::print("три");
			break;
		case(4):
			std::print("четыре");
			break;
		case(5):
			std::print("пять");
			break;
		case(6):
			std::print("шесть");
			break;
		case(7):
			std::print("семь");
			break;
		case(8):
			std::print("восемь");
			break;
		case(9):
			std::print("девять");
			break;
		}
	}
	
	return 0;
}