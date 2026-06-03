import std;

int main()
{
    std::print("Введите номер дня года [1, 365]: ");

    int n = 0;
    std::cin >> n;

    std::print("Введите номер дня недели 1-го января [1, 7]: ");

    int k = 0;
    std::cin >> k;

    std::println("День недели: {}", (n % 7) + (k - 1));

    return 0;
}