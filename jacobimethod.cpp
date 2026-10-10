
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    double x = 0, y = 0, z = 0;
    double tolerance = 1e-6;
    int maxIter = 100;
    int i;

    cout << "JACOBI METHOD\n";
    cout << fixed << setprecision(6);
    cout << "Iter\tx\t\ty\t\tz\n";

    for (i = 1; i <= maxIter; i++) {
        double xn = (9 + y - z) / 8.0;
        double yn = (19 - 2*x + z) / 10.0;
        double zn = (32 - x - 2*y) / 9.0;

        double error = max({
            abs(xn - x),
            abs(yn - y),
            abs(zn - z)
        });

        cout << i << "\t"
             << xn << "\t"
             << yn << "\t"
             << zn << "\n";

        x = xn;
        y = yn;
        z = zn;

        if (error < tolerance)
            break;
    }

    cout << "\nFinal Solution:\n";
    cout << "x = " << x << "\n";
    cout << "y = " << y << "\n";
    cout << "z = " << z << "\n";
    cout << "Iterations = " << i << "\n";

    return 0;
}
