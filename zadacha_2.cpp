#include <iostream>
#include <locale>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long combs_r(int n, int m)
{
    if (m == 0 || m == n)
    {
        return 1;
    }
    if (m == 1)
    {
        return n;
    }
    return combs_r(n - 1, m - 1) + combs_r(n - 1, m);
}

long long combs_i(int n, int m)
{
    long long result = 1;

    for (int i = 1; i <= m; i++)
    {
        result = result * (n - m + i) / i;
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n, m;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите m: ";
    cin >> m;

    if (n < m)
    {
        cout << "Неверный ввод данных, n < m" << endl;
        return 1;
    }

    auto start = high_resolution_clock::now();
    long long res_r = combs_r(n, m);
    auto stop = high_resolution_clock::now();
    auto dur_r = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    long long res_i = combs_i(n, m);
    stop = high_resolution_clock::now();
    auto dur_i = duration_cast<microseconds>(stop - start);

    cout << "\nРезультаты:\nРекурсивный метод: " << res_r << "\nИтеративный метод: " << res_i
    << "\n\nВремя выполнения:\nРекурсивный метод: " << dur_r.count() << " микросекунд\nИтеративный метод: "
    << dur_i.count() << " микросекунд" << endl;
    return 0;
}
