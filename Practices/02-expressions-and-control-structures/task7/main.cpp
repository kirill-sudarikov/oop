import std;

int main()
{
    std::print("Введите число [0, 999]: ");

    int num = 0;
    std::cin >> num;

    int tens = (num % 100) / 10;
    int hundreds = num / 100;

    if (num % 2 == 0)
    {
        std::print("чётное ");
    }
    else
    {
        std::print("нечётное ");
    }

    if (hundreds == 0 && tens != 0)
    {
        std::print("двузначное ");
    }
    else if (hundreds == 0 && tens == 0)
    {
        std::print("");
    }
    else
    {
        std::print("трёхзначное ");
    }

    std::println("число");

    return 0;
}