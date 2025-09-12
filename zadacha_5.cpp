#include <iostream>
#include <locale>

using namespace std;

int optimizer(int current = 1, int target = 100, int steps = 0)
{
    if (current > target)
    {
        return target;
    }

    else if (current == target)
    {
        return steps;
    }

    else
    {
        int op_1 = optimizer(current + 1, target, steps + 1);
        int op_2 = optimizer(current * 2, target, steps + 1);
        return min(op_1, op_2);
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Минимальное количество операций: " << optimizer() << endl;
    return 0;
}
