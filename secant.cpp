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

double secantMethod(double x0, double x1) {
    double x2;
    int iteration = 1;
    string update = "";

    cout << "=====================================================================================\n";
    cout << " | Iteration |     x0     |     x1     |     x2     |     f(x2)    |     update    |\n";
    cout << "=====================================================================================\n";

    while (true)
    {
        x2 = x1 - (func(x1) * (x1 - x0)) / (func(x1) - func(x0));

        cout << fixed << setprecision(6);
        cout << " | " << setw(9) << iteration << " | "
             << setw(10) << x0 << " | "
             << setw(10) << x1 << " | "
             << setw(10) << x2 << " | "
             << setw(12) << func(x2) << " | "
             << setw(13) << "x0 = x1, x1 = x2" << " | \n";

        if (fabs(func(x2)) < e)
        {
            break;
        }

        x0 = x1;
        x1 = x2;
        iteration++;
    }

    cout << "======================================================================================\n";
    return x2;
}

int main() {
    double x0, x1;
    cout << "Enter the initial guesses x0 and x1: ";
    cin >> x0 >> x1;

    cout << "The function used is 2x^3 - 2x - 1\n";
    cout << "Initially x0 = " << x0 << "\tAnd x1 = " << x1 << endl;

    double root = secantMethod(x0, x1);
    if (!isnan(root))
        cout << "Root is approximately = " << root;
}

