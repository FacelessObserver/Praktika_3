#include <iostream>
#include <vector>
#include <locale>
using namespace std;

int posled(int n)
{
    /**
    * n - номер элемента последовательности
    * Функция возвращает значение n-го элемента последовательности,нумерация начинается с единицы (1:n)
    */
    if (n < 3)
    {
        return 1;
    }
    int curr = 0, prev_1 = 1, prev_2 = 1;
    for (int i = 0; i < n-2; i++)
    {
        curr = prev_1 + prev_2;
        prev_1 = prev_2;
        prev_2 = curr;
    }
    return prev_2;
}
int main()
{
    int choise;
    setlocale(LC_ALL, "Russian");
    cout << "Введите номер элемента: ";
    cin >> choise;
    cout << "Значение выбранного элемента: " << posled(choise) << endl;
    return 0;
}
