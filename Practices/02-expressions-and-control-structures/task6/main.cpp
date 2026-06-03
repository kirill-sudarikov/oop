import std;

int main()
{
    std::print("Введите номер года: ");

    int year = 0;
    std::cin >> year;

    bool is_leap = false;

    if ((year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0))
    {
        is_leap = true;
    }
    else
    {
        is_leap = false;
    }

    std::println("Количество дней в году: {}", is_leap ? 366 : 365);

    return 0;
}