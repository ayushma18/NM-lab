#include <iostream>
#include <cmath>
using namespace std;

// Function definition
float func(float x, float y) {
    return (x * x + y);
}

// Euler's method implementation
void euler(float x0, float y0, float n, float xn) {
    float h, y, x;
    h = (xn - x0) / n; // Step size
    cout << "Euler's Method" << endl;
    cout << "x\t\ty" << endl;

    for (int i = 0; i < n; i++) {
        y = y0 + h * func(x0, y0);
        cout << x0 << "\t" << y0 << endl;
        x = x0 + h;
        if (x > xn) {
            break;
        } else {
            x0 = x;
            y0 = y;
        }
    }
}

// Runge-Kutta (RK4) method implementation
void RK4(float x0, float y0, float n, float xn) {
    cout << "Runge-Kutta 4th Order Method (RK4)" << endl;
    float h, k1, k2, k3, k4, k, x, y;
    h = (xn - x0) / n; // Step size
    cout << "x\t\ty" << endl;

    for (int i = 0; i < n; i++) {
        cout << x0 << "\t" << y0 << endl;
        k1 = h * func(x0, y0);
        k2 = h * func(x0 + h / 2, y0 + k1 / 2);
        k3 = h * func(x0 + h / 2, y0 + k2 / 2);
        k4 = h * func(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y = y0 + k;
        x = x0 + h;
        x0 = x;
        y0 = y;
    }
}

int main() {
    float x0, y0, n, xn;

    cout << "Enter initial values (x0, y0), number of steps (n), and xn:" << endl;
    cin >> x0 >> y0 >> n >> xn;

    euler(x0, y0, n, xn);
    RK4(x0, y0, n, xn);

    return 0;
}
