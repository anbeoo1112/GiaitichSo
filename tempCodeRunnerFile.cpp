#include <iostream>
#include <cmath>
#include <vector>

// Phương pháp Jacobi
std::vector<double> solveByGauss_Seidel(const std::vector<std::vector<double>>& A, const std::vector<double>& b, const double epsilon, const int maxIterations) {
    int n = A.size();
    std::vector<double> x(n, 0.0);
    std::vector<double> prevX(n, 0.0);
    int iteration = 0;
    double error = 0.0;
    
    while (iteration < maxIterations) {
        prevX = x;
        
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            
            x[i] = (b[i] - sum) / A[i][i];
        }
        
        iteration++;
        
        // Tính sai số
        error = 0.0;
        for (int i = 0; i < n; i++) {
            error += std::abs(x[i] - prevX[i]);
        }
        
        if (error < epsilon) {
            break;
        }
    }
    
    std::cout << "Số lần lặp: " << iteration << std::endl;
    std::cout << "Nghiệm gần đúng: ";
    for (int i = 0; i < n; i++) {
        std::cout << "x" << i << " = " << x[i] << " ";
    }
    std::cout << std::endl;
    
    return x;
}

int main() {
    std::vector<std::vector<double>> a;
    std::vector<double> b;
    freopen("INP.TXT","r",stdin);
    freopen("OUT.TXT","w",stdout);
    int n, m;
    std::cin >> n >> m;
    
    a.resize(n, std::vector<double>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    
    b.resize(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    
    const double epsilon = 0.0001;
    const int maxIterations = 100;
    std::vector<double> solution = solveByGauss_Seidel(a, b, epsilon, maxIterations);
    return 0;
}
