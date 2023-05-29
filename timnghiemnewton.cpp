#include <iostream>
#include <cmath>

using namespace std;

// Hàm f(x) của phương trình cần tìm nghiệm
double f(double x) {
    return -1*pow(x,3)-0.25*pow(x,2)+2.9375; // Ví dụ: tìm nghiệm của phương trình x^2 - 4 = 0
}

// Hàm tính đạo hàm của f(x)
double fPrime(double x) {
    return -3*x*x-0.5*x; // Đạo hàm của x^2 - 4 là 2x
}

// Hàm tính nghiệm bằng phương pháp Newton
double newtonMethod(double x0, double epsilon, int maxIterations) {
    double x = x0;
    int iteration = 0;
    
    cout << "Lần 0: " << x << endl;
    
    while (iteration < maxIterations) {
        double delta = f(x) / fPrime(x); // Tính delta (bước nhảy)
        x -= delta; // Cập nhật giá trị x
        
        cout << "Lần " << iteration + 1 << ": " << x << endl;
        
        if (fabs(delta) < epsilon) {
            cout << "Đã tìm thấy nghiệm đáp ứng độ chính xác epsilon!" << endl;
            return x;
        }
        
        iteration++;
    }
    
    cout << "Không tìm thấy nghiệm sau " << maxIterations << " lần lặp." << endl;
    return x;
}

int main() {
    double x0 = 1.0; // Giá trị ban đầu x0
    double epsilon = 0.0000000001; // Độ chính xác epsilon
    int maxIterations = 10; // Số lần lặp tối đa
    
    cout << "Bắt đầu phương pháp Newton..." << endl;
    
    double solution = newtonMethod(x0, epsilon, maxIterations);
    
    cout << "Nghiệm cuối cùng: " << solution << endl;
    
    return 0;
}
