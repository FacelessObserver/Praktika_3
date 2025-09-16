#include <iostream>
#include <locale>
#include <chrono>

using namespace std;
using namespace std::chrono;

double factorial(int n)
{
    double res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
long int combs_r(int n, int m, long int &iters)
{
    iters ++;

    if (m == 0 || m == n)
    {
        return 1;
    }

    if (m == 1)
    {
        return n;
    }
    return combs_r(n - 1, m - 1, iters) + combs_r(n - 1, m, iters);
}

 long long combs_i(int n, int m, int &iters)
{
    iters = 2 * n;
    return (factorial(n) / (factorial(m) * factorial(n - m)));
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
    long int iters_r = 0;
    long int res_r = combs_r(n, m, iters_r);
    auto stop = high_resolution_clock::now();
    auto dur_r = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    int iters_i = 0;
    long long res_i = combs_i(n, m, iters_i);
    stop = high_resolution_clock::now();
    auto dur_i = duration_cast<microseconds>(stop - start);

    cout << "\nРезультаты:\nРекурсивный метод: " << res_r << "\nЧисло итераций: " << iters_r << "\nИтеративный метод: " << res_i
    << "\nЧисло итераций: " << iters_i << "\n\nВремя выполнения:\nРекурсивный метод: " << dur_r.count() << " микросекунд\nИтеративный метод: "
    << dur_i.count() << " микросекунд" << endl;
    return 0;
}
