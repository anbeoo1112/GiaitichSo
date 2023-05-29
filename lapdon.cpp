#include <iostream>
#include <cmath>

using namespace std;

// Hàm f(x) của phương trình cần tìm nghiệm
double f(double x) {
    return -3*pow(x,3)+3*pow(x,2)-0.36*x+0.2465; // Ví dụ: tìm nghiệm của phương trình x^2 - 4 = 0
}

// Hàm tính nghiệm bằng phương pháp lặp đơn
double iterativeMethod(double x0, double epsilon, int maxIterations) {
    double x = x0;
    int iteration = 0;
    
    cout << "Lần 0: " << x << endl;
    
    while (iteration < maxIterations) {
        x = f(x); // Áp dụng công thức lặp đơn
        
        cout << "Lần " << iteration + 1 << ": " << x << endl;
        
        if (fabs(f(x)) < epsilon) {
            cout << "Đã tìm thấy nghiệm đáp ứng độ chính xác epsilon!" << endl;
            return x;
        }
        
        iteration++;
    }
    
    cout << "Không tìm thấy nghiệm sau " << maxIterations << " lần lặp." << endl;
    return x;
}

int main() {
    double x0 = 0.1; // Giá trị ban đầu x0
    double epsilon = 0.0001; // Độ chính xác epsilon
    int maxIterations = 10; // Số lần lặp tối đa
    
    cout << "Bắt đầu phương pháp lặp đơn..." << endl;
    
    double solution = iterativeMethod(x0, epsilon, maxIterations);
    
    cout << "Nghiệm cuối cùng: " << solution << endl;
    
    return 0;
}
