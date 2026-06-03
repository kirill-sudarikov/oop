import std;

int main()
{
    std::print("Введите трёхзначное число: ");

    int num = 0;
    std::cin >> num;

    int digits = num % 10;
    int tens = (num % 100) / 10;
    int hundreds = num / 100;

    bool is_inc_sequence = (tens / hundreds) && (digits / tens);

    std::println("Последовательность цифр числа возрастающая (true) / "
                 "убывающая (false): {}",
                 is_inc_sequence);

    return 0;
}