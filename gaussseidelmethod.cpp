
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

    cout << "GAUSS-SEIDEL METHOD\n";
    cout << fixed << setprecision(6);
    cout << "Iter\tx\t\ty\t\tz\n";

    for (i = 1; i <= maxIter; i++) {
        double xo = x, yo = y, zo = z;

        x = (9 + y - z) / 8.0;
        y = (19 - 2*x + z) / 10.0;
        z = (32 - x - 2*y) / 9.0;

        double error = max({
            abs(x - xo),
            abs(y - yo),
            abs(z - zo)
        });

        cout << i << "\t"
             << x << "\t"
             << y << "\t"
             << z << "\n";

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
