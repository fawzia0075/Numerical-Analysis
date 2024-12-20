
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>

using namespace std;

double func(double x) // 2x^3 - 2x - 1
{
    return 2 * x * x * x - 2 * x - 1;
}

double e = 0.00001;

double falsePosition(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "Incorrect value of a and b. We should take the value of a and b that contains opposite signs.";
        return NAN;
    }

    int iteration = 1;
    double c;
    string update = "";
    cout << "=====================================================================================\n";
    cout << " | Iteration |     a      |      b      |      c      |     f(c)     |    update     |\n";
    cout << "=====================================================================================\n";

    while (true)
    {
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        if (func(a) * func(c) < 0)
        {
            update = "b = c";
            b = c;
        }
        else
        {
            update = "a = c";
            a = c;
        }

        cout << fixed << setprecision(6);
        cout << " | " << setw(9) << iteration << " | "
             << setw(10) << a << " | "
             << setw(10) << b << " | "
             << setw(10) << c << " | "
             << setw(12) << func(c) << " | "
             << setw(13) << update << " | \n";

        if (fabs(func(c)) < e)
        {
            break;
        }
        iteration++;
    }

    cout << "======================================================================================\n";
    return c;
}

int main()
{
    int a, b;
    cout << "Enter the value of a and b: ";
    cin >> a >> b;

    cout << "The function used is 2x^3 - 2x - 1\n";
    cout << "Initially a = " << a << "\tAnd b = " << b << endl;

    double root = falsePosition(a, b);
    if (!isnan(root))
        cout << "Root is approximately = " << root;
}
