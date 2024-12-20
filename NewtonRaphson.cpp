#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

double func(double x) // 2x^3 - 2x - 1
{
    return 2 * x * x * x - 2 * x - 1;
}

double dfunc(double x) // Derivative: 6x^2 - 2
{
    return 6 * x * x - 2;
}

double e = 0.00001;

double newtonRaphson(double x0)
{
    int iteration = 1;
    double x1;
    string update = "";

    cout << "=====================================================================\n";
    cout << " | Iteration |     x0     |     x1     |     f(x1)    |   update    |\n";
    cout << "=====================================================================\n";

    while (true)
    {
        x1 = x0 - func(x0) / dfunc(x0);
        update = "x0 = x1";

        cout << fixed << setprecision(6);
        cout << " | " << setw(9) << iteration << " | "
             << setw(10) << x0 << " | "
             << setw(10) << x1 << " | "
             << setw(12) << func(x1) << " | "
             << setw(11) << update << " | \n";

        if (fabs(func(x1)) < e)
        {
            break;
        }

        x0 = x1;
        iteration++;
    }

    cout << "===================================================================\n";
    return x1;
}

int main()
{
    double a, b;
    cout << "Enter the interval [a, b]:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    // Calculate initial guess x0 as the midpoint of the interval
    double x0 = (a + b) / 2;

    cout << "The function used is 2x^3 - 2x - 1\n";
    cout << "Initially x0 = " << x0 << " (midpoint of [" << a << ", " << b << "])\n";

    double root = newtonRaphson(x0);
    cout << "Root is approximately = " << root;
}

