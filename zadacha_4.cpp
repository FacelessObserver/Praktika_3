#include <iostream>
#include <string>
#include <cmath>
#include <locale>

using namespace std;

int algo(int num)
{
    if (num % 3 != 0)
    {
        return 0;
    }

    int iters = 0;

    while (num != 153)
    {
        string num_s = to_string(num);
        int sum = 0;

        for (char digit_c : num_s)
        {
            int digit = digit_c - '0';
            sum += pow(digit, 3);
        }

        num = sum;
        iters++;
    }

    return iters;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Количество итераций для чисел:" << endl;
    cout << "algo(6): " << algo(6)<< endl;
    cout << "algo(21): " << algo(21) << endl;
    cout << "algo(369): " << algo(369) << endl;
    cout << "algo(1485): " << algo(1485) << endl;
    return 0;
}
