#include <iostream>
#include <locale>

using namespace std;

int optimizer(int target, int current, int steps)
{
    cout << current << endl;

    if (current == target)
    {
        cout << "Минимальное количество операций: " << steps;
        return steps;
    }

    steps++;

    if (current % 2 == 0 && current / 2 >= target)
    {
        return optimizer(target, current / 2, steps);
    }

    else
    {
        return optimizer(target, current - 1, steps);
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    optimizer(1, 100, 0);
    return 0;
}
