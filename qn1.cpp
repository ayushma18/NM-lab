#include <iostream>
using namespace std;

int main() {
    int n;
    float a, b, sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;

    cout << "\nEnter the number of readings: ";
    cin >> n;

    
    float x[n], y[n];

    cout << "Enter data for x and y:" << endl;

    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        sumx += x[i];
        sumy += y[i];
        sumx2 += (x[i] * x[i]);
        sumxy += (x[i] * y[i]);
    }

        b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
        a = (sumy - b * sumx) / n;
    

   
    cout << "\nThe best fitting equation is: \n";
    cout << "y = " << a << "+"  << b << "x"<<endl;

    return 0;
}
