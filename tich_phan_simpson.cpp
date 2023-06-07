#include <iostream>
#include <bits/stdc++.h>

// Tính tích phân của một hàm số bằng phương pháp Simpson
double integrate(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n; // Kích thước mỗi đoạn
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * (i % 2 == 0 ? 1 : 2) * f(x);
    }

    return sum * h / 3;
}

// Hàm số mẫu
double myFunction(double x) {
    return pow(sin(x),4)+x*x*x;
}

int main() {
    double a = 2.0; // Điểm bắt đầu tích phân
    double b = 6.0; // Điểm kết thúc tích phân
    int n = 20; // Số đoạn chia (chẵn số)

    double result = integrate(myFunction, a, b, n);

    std::cout << "Tích phân của hàm số là: " << result << std::endl;

    return 0;
}
