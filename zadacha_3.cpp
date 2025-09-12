#include <iostream>
#include <locale>
#include <chrono>

using namespace std;
using namespace std::chrono;

int max_del_r(int num_1, int num_2) // Алгоритмическая сложность O(max(num_1, num_2)
{
    if (num_1 == num_2)
    {
        return num_1;
    }

    else if (num_1 > num_2)
    {
        return max_del_r(num_1 - num_2, num_2);
    }

    else
    {
        return max_del_r(num_1, num_2 - num_1);
    }
}

int max_del_i(int num_1, int num_2) // Алгоритмическая сложность O(log(min(num_1, num_2)))
{
    while (num_1 != 0)
    {
        int t = num_1;
        num_1 = num_2 % num_1;
        num_2 = t;
    }
    return num_2;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int num_1, num_2;
    cout << "Введите число 1: ";
    cin >> num_1;
    cout << "Введите число 2: ";
    cin >> num_2;

    if (num_1 < 0 || num_2 < 0)
    {
        cout << "Неверный формат ввода, введите натуральные числа" << endl;
        return 1;
    }

    auto start = high_resolution_clock::now();
    int res_r = max_del_r(num_1, num_2);
    auto stop = high_resolution_clock::now();
    auto dur_r = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    int res_i = max_del_i(num_1, num_2);
    stop = high_resolution_clock::now();
    auto dur_i = duration_cast<microseconds>(stop - start);

    cout << "\nРезультаты:\nРекурсивный метод: " << res_r << "\nИтеративный метод: " << res_i
    << "\n\nВремя выполнения:\nРекурсивный метод: " << dur_r.count() << " микросекунд\nИтеративный метод: "
    << dur_i.count() << " микросекунд" << endl;
    return 0;
}
