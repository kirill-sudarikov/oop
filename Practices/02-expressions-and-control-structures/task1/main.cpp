import std;

int main()
{
    std::print("Введите трёхзначное число: ");

    int num = 0;
    std::cin >> num;

    int digits = num % 10;
    int tens = (num % 100) / 10;
    int hundreds = num / 100;

    std::println("Сумма цифр: {}", digits + tens + hundreds);
    std::println("Произведение цифр: {}", digits * tens * hundreds);

    return 0;
}
