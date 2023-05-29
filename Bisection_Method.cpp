#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.000000000000000000001

double g(double x) {
    return pow((x+1),1/3.0);
}

double findRoot(double a) {
    double x0 = a; // Giả sử điểm bắt đầu là trung điểm của đoạn [a, b]

    while (fabs(g(x0) - x0) > EPSILON) {
        x0 = g(x0);
    }

    return x0;
}

int main() {
    double a;
    cin >> a;
    cout << findRoot(a);
}
