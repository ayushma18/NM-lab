#include <iostream>
#include <cmath>
using namespace std;

float f(float x) {
    float f1;
    f1 = x * sin(x) + cos(x);
    return f1;
}

int main() {
    float a, b, c;
    int count = 0;

    cout << "Enter interval:" << endl;
    cin >> a >> b;

    if (f(a) * f(b) < 0) {
        do {
            c = (a + b) / 2;  // Calculate midpoint
            if (f(a) * f(c) < 0) {
                b = c;  // Root lies in [a, c]
            } else {
                a = c;  // Root lies in [c, b]
            }
            count++;

            if (count == 100) {
                cout << "The function is discontinuous or the root is not converging." << endl;
                return 0;
            }
        } while (fabs(f(c)) >= 0.005);  // Check the tolerance

        cout << "The required root is: " << c << endl;
    } else {
        cout << "Root does not lie in the given interval." << endl;
        return 0;
    }

    return 0;
}
