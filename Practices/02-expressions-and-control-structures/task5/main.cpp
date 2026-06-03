import std;

int main()
{
    std::print("Введите координаты x y первого поля: ");

    int x1 = 0;
    int y1 = 0;

    std::cin >> x1;
    std::cin >> y1;

    std::print("Введите координаты x y второго поля: ");

    int x2 = 0;
    int y2 = 0;

    std::cin >> x2;
    std::cin >> y2;

    bool rook_can_move = !(x2 - x1) || !(y2 - y1);

    std::println("Ладья может (true) / не может (false) "
                 "за один ход перейти с одного поля на другое: {}",
                 rook_can_move);

    return 0;
}