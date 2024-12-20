#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

double func(double x) // 3x^3 - 2x - 2
{
    return 3 * x * x * x - 2 * x - 2;
}

double e = 0.00001;

double bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "Incorrect value of a and b.";
        return NAN;
    }

    int iteration = 1;
    double c, update;
    string remark = "";

    cout << fixed << setprecision(6);
    cout << "=============================================================================\n";
    cout << " |  Iteration |     a      |      b     |      c     |    f(c)    |  remark  |\n";
    cout << "=============================================================================\n";

    while (true)
    {
        c = (a + b) / 2;

        if (func(a) * func(c) < 0)
        {
            b = c;
            remark = "b = c";
        }
        else
        {
            a = c;
            remark = "a = c";
        }

        cout << " | " << setw(10) << iteration << " | "
             << setw(10) << a << " | "
             << setw(10) << b << " | "
             << setw(10) << c << " | "
             << setw(10) << func(c) << " | "
             << setw(10) << remark << " |\n";

        if (fabs(func(c)) < e)
        {
            break;
        }

        iteration++;
    }

    cout << "=============================================================================\n";
    return c;
}

int main()
{
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    cout << "Function used: 3x^3 - 2x - 2\n";
    cout << "Initial a = " << a << "\nAnd b = " << b << endl;
    double root = bisection(a, b);
    if (!isnan(root))
    {
        cout << "Accurate value is: " << root;
    }
}
